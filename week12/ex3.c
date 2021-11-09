#include <stdio.h>
#include <stdlib.h>
#include <linux/input.h>


#define INPUT "/dev/input/by-path/platform-i8042-serio-0-event-kbd"
#define OUTPUT "./ex3.txt"


int main() {

	FILE *inFile = fopen(INPUT, "r");
	FILE *outFile = fopen(OUTPUT, "a+");

    int *key = calloc(100, sizeof(int));
    // This array stores states of the keys
	
    printf("Try these shortcuts:\nP + E\nC + A + P\nF + S + C + K\n");
    fprintf(outFile, "Try these shortcuts:\nP + E\nC + A + P\nF + S + C + K\n");
    fflush(outFile);

    while(1) {

        struct input_event ev;

        fread(&ev, sizeof(struct input_event), 1, inFile);

        if (ev.type == EV_KEY) {
            
            key[ev.code] = ev.value;
            // When key is pressed, it's ev.value is non-zero
            // and zero otherwise

            if (key[KEY_P] && key[KEY_E]) {
                printf("\nI passed the Exam!\n");
                fputs("\nI passed the Exam!\n", outFile);
            }

            if (key[KEY_C] && key[KEY_A] && key[KEY_P]) {
                printf("\nGet some cappuccino!\n");
                fputs("\nGet some cappuccino!\n", outFile);
            }
            
            if (key[KEY_F] && key[KEY_S] && key[KEY_C] && key[KEY_K]) {
                printf("\nFile System Check\n");
                fputs("\nFile System Check\n", outFile);
            }

            fflush(outFile);
        }
    }


    return 0;
}