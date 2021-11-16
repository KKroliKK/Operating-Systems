#include <stdio.h>
#include <stdlib.h>


//#define INPUT "input_ok.txt"
#define INPUT "input_dl.txt"
#define M 3
#define N 5


int E[M], A[M], C[N][M], R[N][M];
int terminated = 0;


int RlessOrEqualA(int index){
// Checks if needs of procees smaller
// than or equal to A

    if (C[index][0] == -1) // Checks if process has
        return 0;          // already terminated

    for(int i = 0; i < M; ++i)
        if (R[index][i] > A[i])
            return 0;

    return 1;
}


void markTerminated(int index){

    for (int i = 0; i < M; ++i){
        A[i] += C[index][i];
        C[index][i] = -1;
        R[index][i] = -1;
    }

    terminated++;
}


int main(){
    
    FILE *input = fopen(INPUT, "r");

    for (int i = 0; i < M; ++i)
        fscanf(input, "%d", &E[i]);

    for (int i = 0; i < M; ++i)
        fscanf(input, "%d", &A[i]);

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            fscanf(input, "%d", &C[i][j]);

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            fscanf(input, "%d", &R[i][j]);

    fclose(input);


    for (int k = 0; k <= N; ++k){
        // After N^2 iterations all the
        // processes will be marked terminated
        // if there is no deadlock

        for(int i = 0; i < N; ++i)
            if (RlessOrEqualA(i))
                markTerminated(i);

    }
    

    if (terminated < N){
        printf("DeadLock\n");
    }
    else{
       printf("Ok\n") ;
    }

    return 0;
}