#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *a, int n){

    if (n <= 1){
        return;
    }

    for (int j = 0; j < n - 1; ++j){
        for (int i = 1; i < n; ++i){

            if (a[i-1] > a[i]){
                int tmp = a[i-1];
                a[i-1] = a[i];
                a[i] = tmp;
            }

        }
    }

}


int main(){

    printf("Enter the size of the array\n");

    int n;
    scanf("%d", &n);

    int *a = (int*) malloc(n * sizeof(int));

    printf("\nEnter the values  separated by space\n");

    for (int i = 0 ; i < n; ++i){
        scanf("%d", &a[i]);
    }

    bubble_sort(a, n);

    printf("\nSorted array:\n");

    for (int i = 0 ; i < n; ++i){
        printf("%d ", a[i]);
    }

}