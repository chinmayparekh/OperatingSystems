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
  union semun arg;
  key_t key = ftok(".", 'c');
  int semid = semget(key, 1, IPC_CREAT | 0644); // 1 is the number of semaphores in the set
  int val = 1, val1;

  arg.val = val;

  semctl(semid, 0, SETVAL, val); // semid points to the set of semaphores,0 represents the 0th element of the set

  val1 = semctl(semid, 0, GETVAL, 0);
  printf("%d\n", val1);
}