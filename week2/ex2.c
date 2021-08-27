#include <stdio.h>
#include <string.h>


int main(){

    printf("Enter a string:\n");

    char word[512];
    
    scanf("%s", word);

    for (int i = 0; i < strlen(word)/2; ++i){
        char tmp = word[i];
        word[i] = word[strlen(word)-1 - i];
        word[strlen(word)-1 - i] = tmp;
    }

    printf("\nReversed string:\n%s\n", word);
}