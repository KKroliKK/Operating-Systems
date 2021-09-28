#include <stdio.h>
#include <stdlib.h>


#define N 10


struct Process{
    int number;
    int arrivalTime;
    int burstTime;
    int exitTime;
    int turnaroundTime;
    int waitingTime;
    int cpuTime;
};


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

    int n;
    struct Process p[N];

    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("\n\nEnter Arrival time and Burst time for each process:\n");

    for(int i = 1; i <= n; ++i){
        printf("\nArrival time of process [%d]: ", i);
        scanf("%d", &p[i].arrivalTime);
        printf("Burst time of process [%d]: ", i);
        scanf("%d", &p[i].burstTime);
        p[i].cpuTime = 0;
        p[i].number = i;
    }



    for(int i = 1; i < n; i++) {
        for(int j = i + 1; j <= n; j++) {
            if (p[i].arrivalTime > p[j].arrivalTime){
                struct Process tmp = p[i];
                p[i] = p[j];
                p[j] = tmp;
            } 
        }
    }

    
    int index = 1;
    p[1].waitingTime = p[1].arrivalTime;

    for(int i = p[1].arrivalTime; index <= n ; ++i){

        if (p[index].cpuTime == p[index].burstTime){
            p[index].exitTime = i;
            p[index].turnaroundTime = i - p[index].arrivalTime;

            index++;
            p[index].waitingTime = i - p[index].arrivalTime;
        }

        if (p[index].arrivalTime > i){
            p[index].waitingTime++;
            continue;
        }

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