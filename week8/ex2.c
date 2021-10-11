#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <unistd.h>


#define N 256 * 1024 * 1024


int main(){

    for(int i = 0; i < 10; ++i){
        int *ptr = malloc(N);
        memset(ptr, 0, N);
        printf("10 MB of memory were allocated!\nNow sleep for 1 second\n");
        sleep(1);
    }

    return 0;
}

// as we can see amount of free memory decreases during process execution