#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include"shm.h"
#define SEMAPHORE_NAME1 "/my_semaphore1"
#define SEMAPHORE_NAME2 "/my_semaphore2"

int main()
{
    sem_t *sem_prod = sem_open(SEMAPHORE_NAME1, O_CREAT, 0666, 0);
    sem_t *sem_cons = sem_open(SEMAPHORE_NAME2, O_CREAT, 0666, 0);
    char* c = (char*)attach_memory_block(SHARED_MEM_NAME,BLOCK_SIZE);
    sem_post(sem_cons);
    for(int i = 0; i<5; i++){
        sem_wait(sem_cons);
        sprintf(c, "sending message № %d", i+1);
        sleep(2);
        sem_post(sem_prod);
    }
    sem_close(sem_prod);
    sem_close(sem_cons);
    sem_unlink(SEMAPHORE_NAME1);
    sem_unlink(SEMAPHORE_NAME2);
    detach_memory_block(c);
    destroy_memory_block(SHARED_MEM_NAME);
    return 0;
}
