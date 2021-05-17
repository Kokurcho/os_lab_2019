#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>
#include <signal.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>

#include <pthread.h>

//This program executes in order, have a look

pthread_mutex_t lock1, lock2;

void *resource1(){

    pthread_mutex_lock(&lock1);

    printf("Job started in Resource 1..\n");
    sleep(2);

    printf("Trying to get Resource 2\n");
    pthread_mutex_lock(&lock2); 
    printf("Aquired Resource 2\n");
    pthread_mutex_unlock(&lock2);

    printf("Job finished in Resource 1..\n");

    pthread_mutex_unlock(&lock1);

    pthread_exit(NULL);

}

void *resource2(){

    pthread_mutex_lock(&lock2);

    printf("Job started in Resource 2..\n");
    sleep(2);

    printf("Trying to get Resource 1\n");
    pthread_mutex_lock(&lock1); 
    printf("Aquired Resource 1\n");
    pthread_mutex_unlock(&lock1);

    printf("Job finished in Resource 2..\n");

    pthread_mutex_unlock(&lock2);

    pthread_exit(NULL);

}



int main() {

    pthread_mutex_init(&lock1,NULL);
    pthread_mutex_init(&lock2,NULL);

    pthread_t t1,t2;

    pthread_create(&t1,NULL,resource1,NULL);
    pthread_create(&t2,NULL,resource2,NULL);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

    return 0;

}