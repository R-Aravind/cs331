/** 
 * @file program-1/non-prememptive-sjf.c
 * @author R-Aravind
 * 
 * cs331 System Software Lab 
 * 
 * Implementation of Non-Pre-Emptive Shortest Job First (SJF)
 * CPU Scheduling Algorithm for finding turnaround time and waiting time.
 *  
 * source : https://github.com/r-aravind/cs331  
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXN_PROCESSES 100

typedef struct Process
{
    int pid;
    int burst_time;
    int arrival_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;

} Process;

Process arr[MAXN_PROCESSES];
int avg_turnaround_time, avg_waiting_time;

int main(void)
{
    int n_process;
    printf("\nenter no of processes: ");
    scanf("%d", &n_process);

    printf("enter arrival time and burst time:");
    printf("\n\npid arrival_time burst_time\n");

    for (int i = 0; i < n_process; i++)
    {
        arr[i].pid = i;
        printf("%d ", i);
        scanf("%d %d", &arr[i].arrival_time, &arr[i].burst_time);
    }

    // TODO: sjf algorithm
    // TODO: compute averages

    printf("\naverage turnaround time: %d", avg_turnaround_time);
    printf("\naverage waiting time: %d", avg_waiting_time);
    return 0;
}