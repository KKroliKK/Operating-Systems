#include <stdio.h>
#include <stdlib.h>


#define NUMBER_BITS 16
#define NUMBER_PAGE_FRAMES 10
#define FILENAME "input.txt"


struct Page{
    int pageNumber;
    int pageID;
    int counter;
};


void decreaseCounter(struct Page *pages) {
    for (int j = 0; j < NUMBER_PAGE_FRAMES; ++j) {
        pages[j].counter >>= 1;
    }
}


void assignPage(struct Page *pages, int index, int tmp) {
    decreaseCounter(pages);
    pages[index].counter = 0;
    pages[index].counter |= 1 << (NUMBER_BITS - 1);
    pages[index].pageNumber = tmp;
}


int findHit(struct Page *pages, int tmp) {
    for(int i = 0; i < NUMBER_PAGE_FRAMES; ++i) {
        if (pages[i].pageNumber == tmp) {
            return i;
        }
    }
    return -1;
}


int findEmptyPage(struct Page *pages) {
    for(int i = 0; i < NUMBER_PAGE_FRAMES; ++i) {
        if (pages[i].pageNumber == -1) {
            return i;
        }
    }
    return -1;
}


int findMinCounter(struct Page *pages) {
    int index = 0;
    for (int i = 1; i < NUMBER_PAGE_FRAMES; ++i) {
        if (pages[i].counter < pages[index].counter) {
            index = i;
        }
    }
    return index;
}


void printInfo(struct Page *pages, int tmp, int hit, int miss) {
    printf("Page to insert: %d\n", tmp);
    for (int i = 0; i < NUMBER_PAGE_FRAMES; ++i) {
        printf("Page ID: %-3d Stored page: %-4d Counter: %d\n", pages[i].pageID, pages[i].pageNumber, pages[i].counter);
    }
    printf("Hits: %-4d Misses: %-4d", hit, miss);
    printf("\n\n");
}


void finalPrint(struct Page *pages) {
    for (int i = 0; i < NUMBER_PAGE_FRAMES; ++i) {
        printf("Page ID: %d; Stored page: %d; Counter: %d\n", pages[i].pageID, pages[i].pageNumber, pages[i].counter);
    }
}


int main(){

    int hit = 0;
    int miss = 0;


    struct Page pages[NUMBER_PAGE_FRAMES];
    for(int i = 0; i < NUMBER_PAGE_FRAMES; ++i) {
        pages[i].pageNumber = -1;
        pages[i].pageID = i;
        pages[i].counter = 0;
    }


    FILE *fp = fopen(FILENAME, "r");
    if (!fp) {
        fprintf(stderr, "Error opening file '%s'\n", FILENAME);
        return EXIT_FAILURE;
    }


    int tmp;
    while(fscanf(fp, "%d", &tmp) != EOF) {
        printInfo(pages, tmp, hit, miss);

        int index[3];
        index[0] = findHit(pages, tmp);
        index[1] = findEmptyPage(pages);
        index[2] = findMinCounter(pages);

        if (index[0] != -1) {
            assignPage(pages, index[0], tmp);
            hit++;
            continue;
        }

        miss++;
        if (index[1] != -1) {
            assignPage(pages, index[1], tmp);
            continue;
        }
        assignPage(pages, index[2], tmp);
    }


    finalPrint(pages);
    printf("\n\nHit/Miss = %lf\n", (double) hit / miss);

    fclose(fp);
    return 0;
}
