#ifndef SHARED
#define SHARED
#define BLOCK_SIZE sizeof(char)*50
#define SHARED_MEM_NAME "/my_shared_memory"
#include<stdbool.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>

static int get_shared_block(char* filename, int size){
    key_t key;
    key = ftok(filename, 0);    
    return(shmget(key, size, 0644|IPC_CREAT));
}

void* attach_memory_block(char* filename, int size){
    int shared_block_id = get_shared_block(filename, size);
    void *res;
    res = shmat(shared_block_id, NULL, 0);
    return res;
}

void detach_memory_block(void* block){
    shmdt(block);
}

void destroy_memory_block(char* filename){
    int shared_block_id = get_shared_block(filename, 0);
    shmctl(shared_block_id, IPC_RMID, NULL);
}


#endif
