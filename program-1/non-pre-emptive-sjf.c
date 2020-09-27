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
int n_process;
float avg_turnaround_time, avg_waiting_time;

void sjf();
void computeAverages();
void sort();
void swap(Process *x, Process *y);

int main(void)
{

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

    sjf();
    computeAverages();

    printf("\naverage turnaround time: %0.2f", avg_turnaround_time);
    printf("\naverage waiting time: %0.2f", avg_waiting_time);
    return 0;
}

void sjf()
{
    sort();
    int prev_completion = 0;

    for (int i = 0; i < n_process; i++)
    {
        int min_bt = arr[i].burst_time;
        int min_bt_pos = i;
        int next_arrival = prev_completion > arr[i].arrival_time ? prev_completion : arr[i].arrival_time;
        if (i != n_process)
        {
            for (int j = i + 1; j < n_process; j++)
            {
                if (arr[j].arrival_time > next_arrival)
                    break;
                if (arr[j].burst_time < min_bt)
                {
                    min_bt_pos = j;
                    min_bt = arr[j].burst_time;
                }
            }

            if (min_bt_pos != i)
                swap(&arr[i], &arr[min_bt_pos]);
        }
        arr[i].completion_time = arr[i].burst_time + next_arrival;

        arr[i].turnaround_time = arr[i].completion_time - arr[i].arrival_time;
        arr[i].waiting_time = arr[i].turnaround_time - arr[i].burst_time;

        prev_completion = arr[i].completion_time;
    }
}

void computeAverages()
{
    for (int i = 0; i < n_process; i++)
    {
        avg_turnaround_time += arr[i].turnaround_time;
        avg_waiting_time += arr[i].waiting_time;
    }
    avg_turnaround_time /= n_process;
    avg_waiting_time /= n_process;
}

void sort()
{
    for (int i = 0; i < n_process - 1; i++)
        for (int j = 0; j < n_process - i - 1; j++)
        {
            if (arr[j].arrival_time > arr[j + 1].arrival_time)
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
}

void swap(Process *x, Process *y)
{
    Process temp = *x;
    *x = *y;
    *y = temp;
}