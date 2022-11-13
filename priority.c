#include <stdio.h>

struct Process
{
    int pid;
    int bt;
    int priority;
};
int comparison(struct Process a, struct Process b)
{
    return (a.priority > b.priority);
}
void sort(struct Process procs[], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            if (comparison(procs[i], procs[j]))
            {
                struct Process temp = procs[i];
                procs[i] = procs[j];
                procs[j] = temp;
            }
        }
}
void findWaitingTime(struct Process proc[], int n,
                     int wait_time[])
{
    wait_time[0] = 0;
    for (int i = 1; i < n; i++)
        wait_time[i] = proc[i - 1].bt + wait_time[i - 1];
}
void findTurnAroundTime(struct Process proc[], int n,
                        int wait_time[], int tat[])
{
    for (int i = 0; i < n; i++)
        tat[i] = proc[i].bt + wait_time[i];
}
void findavgTime(struct Process proc[], int n)
{
    int wait_time[n], tat[n], total_wt = 0, total_tat = 0;
    findWaitingTime(proc, n, wait_time);
    findTurnAroundTime(proc, n, wait_time, tat);
    printf("\nProcesses   Burst time   Waiting time   Turn around time\n");
    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wait_time[i];
        total_tat = total_tat + tat[i];
        printf(" %d\t\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].bt, wait_time[i], tat[i]);
    }
    printf("\nAverage waiting time = %f\n", (float)total_wt / (float)n);
    printf("\nAverage turn around time = %f\n", (float)total_tat / (float)n);
}

void priorityScheduling(struct Process proc[], int n)
{
    sort(proc, n);
    printf("Order in which processes gets executed \n");
    for (int i = 0; i < n; i++)
        printf("%d ", proc[i].pid);
    findavgTime(proc, n);
}
int main()
{
    struct Process proc[] = {{1, 10, 2}, {2, 5, 0}, {3, 8, 1}};
    int n = sizeof proc / sizeof proc[0];
    priorityScheduling(proc, n);
    return 0;
}
