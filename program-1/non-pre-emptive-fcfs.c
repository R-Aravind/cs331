/** 
 * @file program-1/non-prememptive-fcfs.c
 * @author R-Aravind
 * 
 * cs331 System Software Lab 
 * 
 * Implementation of Non-Pre-Emptive First Come First Serve (FCFS)
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

int main(void)
{
    int n_process;
    Process arr[MAXN_PROCESSES];
    printf("enter no of processes: ");
    scanf("%d", &n_process);

    system("cls");

    for (int i = 0; i < n_process; i++)
    {
        arr[i].pid = i;
        printf("\n pid: %d", i);
        printf("\n enter arrival time: ");
        scanf("%d", &arr[i].arrival_time);
        printf(" enter burst time: ");
        scanf("%d", &arr[i].burst_time);
        system("cls");
    }

    for (int i = 0; i < n_process; i++)
    {
        printf("\n pid: %d", i);
        printf("\n arrival time: %d", arr[i].arrival_time);
        printf("\n burst time: %d\n", arr[i].burst_time);
    }

    return 0;
}