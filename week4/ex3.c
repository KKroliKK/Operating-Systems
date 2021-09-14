#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>


int main(){
    
    char command[100];

    
    while (1){
        
        scanf("%s", &command);

        system(command);
        
    }

    return 0;
}