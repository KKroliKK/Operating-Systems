#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <unistd.h>


#define N 10 * 1024 * 1024


int main(){

    for(int i = 0; i < 10; ++i){
        int *ptr = malloc(N);
        memset(ptr, 0, N);
        sleep(1);
    }

    return 0;
}

// as we can see amount of free memory decreases during process execution