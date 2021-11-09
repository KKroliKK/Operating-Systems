#include <stdio.h>
#include <stdlib.h>
#include <linux/input.h>


#define INPUT "/dev/input/by-path/platform-i8042-serio-0-event-kbd"
#define OUTPUT "./ex2.txt"


int main() {

    FILE *inFile = fopen(INPUT, "r");
	FILE *outFile = fopen(OUTPUT, "a+");

	while(1) {

		struct input_event ev;

		fread(&ev, sizeof(struct input_event), 1, inFile);

		if (ev.type == EV_KEY) {
			char str[100];

			switch (ev.value) {

				case 0:
					sprintf(str, "RELEASED 0x%04x (%d)\n\n", ev.code, ev.code);
					break;

				case 1:
					sprintf(str, "PRESSED 0x%04x (%d)\n\n", ev.code, ev.code);
					break;
			}

			fputs(str, outFile);
			fflush(outFile);
		}
	}


    return 0;
}