#include <stdio.h>

void swap(int *a, int *b){
    int c = *a;
    *a = *b;
    *b = c;
}

int main(){

    int a, b;

    printf("Enter two numbers:\n");
    scanf("%d%d", &a, &b);

    swap(&a, &b);

    printf("Now they are swapped: %d %d\n", a, b);

    return 0;
}