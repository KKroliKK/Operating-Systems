#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_THREADS 10


void *print_hello_world(void *tid){

    printf("Hey! Thread #%d is in touch!\n\n", tid);
    pthread_exit(NULL);
}


int main(int argc, char *argv[]){

    pthread_t threads[NUMBER_OF_THREADS];
    int status, i;

    for(i = 0; i < NUMBER_OF_THREADS; i++) {
        printf("Main here. Creating thread #%d\n\n", i);
        status = pthread_create(&threads[i], NULL, print_hello_world, (void *)i);
        pthread_join(threads[i], NULL); // this function makes the order to be strictly thread 1 created, thread 1 prints message, thread 1 exits and so on

        if (status != 0) {
            printf("Oops. Pthread create returned error code %d\n", status);
            exit(-1);
        }
    }
    exit(NULL);
}
