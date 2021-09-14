#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


#define N 100

int main(){
    
    
    while (1){
        
        char input[N];
        char *arg[N];

        fgets(input, sizeof(input), stdin);

        arg[0] = strtok(input, " \n");

        for(int i = 1; i == 1 || arg[i] != NULL; ++i){
            arg[i] = strtok(NULL, " \n");
        }

        int pid = fork();
        if (pid == 0){
            execvp(arg[0], arg);
        }
        
        
    }



    return 0;
}