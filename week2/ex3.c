#include <stdio.h>


void print_right_side_up_triangle(int n){
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n - i; ++j){
            printf(" ");
        }
        for (int j = 1; j <= i * 2 - 1; ++j){
            printf("*");
        }
        printf("\n");
    }
}


void print_square(int n){
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            printf("*");
        }
        printf("\n");
    }
}


void print_right_triangle(int n){
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= i; ++j){
            printf("*");
        }
        printf("\n");
    }
}


void print_isosceles_triangle(int n){
    for (int i = 1; i <= n/2; ++i){
        for (int j = 1; j <= i; ++j){
            printf("*");
        }
        printf("\n");
    }

    if (n % 2 == 1){
        for (int i = 1; i <= n/2 + 1; ++i){
            printf("*");
        }
        printf("\n");
    }

    for (int i = n/2; i >= 1; --i){
        for (int j = i; j >= 1; --j){
            printf("*");
        }
        printf("\n");
    }
}


int main(int argc, char* argv[]){

    int n;
    sscanf(argv[1], "%d", &n);

    print_right_side_up_triangle(n);
    printf("\n\n\n");
    print_right_triangle(n);
    printf("\n\n\n");
    print_square(n);
    printf("\n\n\n");
    print_isosceles_triangle(n);

    return 0;
}