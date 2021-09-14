#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define N 3

int main(){
    for (int i = 0; i < N; ++i){
        fork();
        sleep(5);
    }
    return 0;
}