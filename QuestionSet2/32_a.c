//  Program number 32
//  Chinmay Parekh - IMT2020069
//  Date - 22-04-2022
// Write a program to implement semaphore to protect any critical section.
// a. rewrite the ticket number creation program using semaphore
// b. protect shared memory from concurrent write access
// c. protect multiple pseudo resources ( may be two) using counting semaphore
// d. remove the created semaphore
#include <sys/sem.h>
#include <sys/ipc.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int ticket_num = 0;

union semun
{
  int val;                   // value for SETVAL
  struct semid_ds *buf;      // buffer for IPC_STAT, IPC_SET
  unsigned short int *array; // array for GETALL, SETALL
};

int main()
{

  int ticket_no;
  int fd = open("ticket.txt", O_RDWR);
  key_t key = ftok(".", 'c');
  int semid = semget(key, 1, 0);
  union semun arg;
  int read_check;

  printf("Checking if any process is writing or not. Will wait if any process is writing\n");
  while (1)
  {
    read_check = semctl(semid, 0, GETVAL, 0);

    if (read_check == 1)
      break;
  }

  printf("Reading\n");

  read(fd, &ticket_no, sizeof(ticket_no));
  getchar();
  printf("Read finished\n");
  ticket_no++;

  struct sembuf s = {0, -1, 0 | SEM_UNDO}; // first is which semaphore in the set,-1 is lock/1 is unlock,0 is the flag representing,0 means other process waits it current process is writing,IPC_NOWAIT wont wait wont wait,SEM UNDO -if the process locks the semaphore and abnormally exits the lock is released
  //  s.sem_op = -1;
  lseek(fd, 0, SEEK_SET);

  semop(semid, &s, 1); // everytime it is 1
  printf("Writing\n");
  write(fd, &ticket_no, sizeof(ticket_no));
  getchar();
  printf("Writing done\n");

  s.sem_op = 1; // releasing the lock
  semop(semid, &s, 1);
}