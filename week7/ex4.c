#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>


void *my_realloc(void *ptr, int size){
    
    if (ptr == NULL){
        ptr = malloc(size);
    }
    else if (size == 0){
        free(ptr);
    }
    else{
        void *tmp = malloc(size);
        int used_sells_number = malloc_usable_size(ptr);
        memcpy(tmp, ptr, used_sells_number);
        free(ptr);
        ptr = tmp;
    }

    return ptr;
}


int main(){

    //Allows you to generate random number
	srand(time(NULL));

	// Allows user to specify the original array size, stored in variable n1.
	printf("Enter original array size: ");
	int n1 = 0;
	scanf("%d", &n1);

	//Create a new array of n1 ints
	int* a = calloc(sizeof(int), n1);
	for(int i = 0; i < n1; ++i){
		a[i] = 100;
		//Print each element out (to make sure things look right)
		printf("%d ", a[i]);
	}

	//User specifies the new array size, stored in variable n2.
	printf("\nEnter new array size: ");
	int n2 = 0;
	scanf("%d", &n2);

	//Dynamically change the array to size n2
	a = my_realloc(a, n2);

	//If the new array is a larger size, set all new members to 0. Reason: dont want to use uninitialized variables.

    for (int i = n1; n2 > n1 && i < n2; ++i){
        a[i] = 0;
    }


	for (int i = 0; i < n2; ++i){
		printf("%d ", a[i]);
	}
	printf("\n");
	
	//Done with array now, done with program :D
	

    return 0;
}