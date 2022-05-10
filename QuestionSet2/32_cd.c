//  Program number 32
//  Chinmay Parekh - IMT2020069
//  Date - 22-04-2022
// Write a program to implement semaphore to protect any critical section.
// a. rewrite the ticket number creation program using semaphore
// b. protect shared memory from concurrent write access
// c. protect multiple pseudo resources ( may be two) using counting semaphore
// d. remove the created semaphore
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/msg.h>

union semun
{
  int val;                   // value for SETVAL
  struct semid_ds *buf;      // buffer for IPC_STAT, IPC_SET
  unsigned short int *array; // array for GETALL, SETALL
};

int main()
{
  key_t key = ftok(".", 'b');
  int semid = semget(key, 2, 0);

  struct sembuf s[2] = {{0, -1, 0 | SEM_UNDO}, {1, -1, 0 | SEM_UNDO}};

  printf("locking semaphore1\n");
  semop(semid, &s[0], 1);
  printf("Inside critical section :----semaphore1\n");
  printf("ENTER to unlock semaphore1\n");
  getchar();
  s[0].sem_op = 1;
  semop(semid, &s[0], 1);
  printf("semaphore1 unlocked\n");

  printf("locking semaphore2\n");
  semop(semid, &s[1], 1);
  printf("Inside critical section :----semaphore2\n");
  printf("ENTER to unlock semaphore2\n");
  getchar();
  s[1].sem_op = 1;
  semop(semid, &s[1], 1);
  printf("semaphore2 unlocked\n");

  semctl(semid, IPC_RMID, 0); // removing shm
}