#include <stdio.h>
#include <stdlib.h>


int main(){

    int N;
    printf("Enter the size of the array: ");
    scanf("%d", &N);

    int *arr = calloc(sizeof(int), N);

    for (int i = 0; i < N; ++i){
        arr[i] = i;
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    free(arr);

    return 0;
}