#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(){

    int max_int = INT_MAX;
    float max_float = FLT_MAX;
    double max_double = DBL_MAX;
    
    printf("Size of integer: %d\n Maximum value of integer: %d\n\n", sizeof(max_int), max_int);
    printf("Size of float: %d\n Maximum value of float: %f\n\n", sizeof(max_float), max_float);
    printf("Size of double: %d\n Maximum value of double: %lf\n\n", sizeof(max_double), max_double);
}