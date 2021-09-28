#include <stdio.h>
#include <stdlib.h>


#define N 10
#define QUANTUM 3

struct Process{
    int number;
    int arrivalTime;
    int burstTime;
    int exitTime;
    int turnaroundTime;
    int waitingTime;
    int currentCpuTime;
    int cpuTime;
    int finished;
};


void sort(struct Process *p, int size){
    for(int i = 1; i < size; i++) {
        for(int j = i + 1; j <= size; j++) {
            if (p[i].arrivalTime > p[j].arrivalTime){
                struct Process tmp = p[i];
                p[i] = p[j];
                p[j] = tmp;
            } 
        }
    }
}


void sort_by_number(struct Process *p, int size){
    for(int i = 1; i < size; i++) {
        for(int j = i + 1; j <= size; j++) {
            if (p[i].number > p[j].number){
                struct Process tmp = p[i];
                p[i] = p[j];
                p[j] = tmp;
            } 
        }
    }
}


int main(){

    int n, finished = 0;
    struct Process p[N];

    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("\n\nEnter Arrival time and Burst time for each process:\n");

    for(int i = 1; i <= n; ++i){
        printf("\nArrival time of process [%d]: ", i);
        scanf("%d", &p[i].arrivalTime);
        printf("Burst time of process [%d]: ", i);
        scanf("%d", &p[i].burstTime);
        p[i].currentCpuTime = 0;
        p[i].cpuTime = 0;
        p[i].number = i;
        p[i].finished = 0;
    }


    sort(p, n);
    
    
    int index = 1;
    p[1].waitingTime = p[1].arrivalTime;

    for(int i = p[1].arrivalTime; finished != n ; ++i){

        if (p[index].arrivalTime > i){
            index = 1;
            continue;
        }


        if (p[index].finished == 1){
            i--;
            continue;
        }
        else if (p[index].cpuTime == p[index].burstTime){
            p[index].exitTime = i;
            p[index].turnaroundTime = i - p[index].arrivalTime;
            p[index].waitingTime = p[index].turnaroundTime - p[i].burstTime;
            p[index].finished = 1;
            finished++;

            index++;
            p[index].waitingTime = i - p[index].arrivalTime;
        }

        else if (p[index].currentCpuTime == QUANTUM){
            p[index].currentCpuTime = 0;
            index++;
        }


        p[index].currentCpuTime++;
        p[index].cpuTime++;

    }


    printf("\n\nP#       AT      BT      ET      TAT      WT\n\n");
    sort_by_number(p, n);
    for (int i = 1; i <= n; ++i){
        printf("P%-8d", i);
        printf("%-8d", p[i].arrivalTime);
        printf("%-8d", p[i].burstTime);
        printf("%-8d", p[i].exitTime);
        printf("%-9d", p[i].turnaroundTime);
        printf("%-8d\n", p[i].waitingTime);
    }


    double avarageTurnaroundTime = 0;
    double avarageWaitngTime = 0;

    for (int i = 1; i <= n; ++i){
        avarageTurnaroundTime += p[i].turnaroundTime;
        avarageWaitngTime += p[i].waitingTime;
    } 

    printf("\n\n\nAverage Turnaround Time: = %lf", avarageTurnaroundTime / n);
    printf("\nAverage Wating Time = %lf", avarageWaitngTime / n);

    return 0;
}


/*
10
0 1
0 2
0 4
0 6
0 8
11 8
11 6
11 4
11 2
11 1

*/