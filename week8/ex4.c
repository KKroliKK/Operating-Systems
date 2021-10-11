#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>


#define N 10 * 1024 * 1024


int main(){

    for(int i = 0; i < 10; ++i){
        int *ptr = malloc(N);
        memset(ptr, 0, N);
        struct rusage p;
        getrusage(RUSAGE_SELF, &p);
        printf("Memory usage: %ld\n\n", p.ru_maxrss);
        sleep(1);
    }

    return 0;
}