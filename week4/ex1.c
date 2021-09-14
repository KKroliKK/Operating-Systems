#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define N 3

int main(){

   

   int pid = fork(), i;
   if (pid > 0){
      for (i = 0; i < N; ++i){
         printf("Hello from parent %d - %d\n", pid, i);
         //pid = fork();
      }
   }
   else if (pid == 0){
      for (int j = 0; j < N; ++j){
         printf("Hello from child %d - %d\n", pid, j);
      }
   }
   else{
      return -1;
   }
   

   return 0;
}