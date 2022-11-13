#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortArrival(int AT[], int BT[], int PID[], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            if (AT[j] < AT[i])
            {
                swap(&AT[i], &AT[j]);
                swap(&BT[i], &BT[j]);
                swap(&PID[i], &PID[j]);
            }
            else if (AT[j] == AT[i] && PID[j] < PID[i])
            {
                swap(&AT[i], &AT[j]);
                swap(&BT[i], &BT[j]);
                swap(&PID[i], &PID[j]);
            }
        }
}

void sortId(int AT[], int BT[], int PID[], int wt[], int tat[], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            if (PID[j] < PID[i])
            {
                swap(&AT[i], &AT[j]);
                swap(&BT[i], &BT[j]);
                swap(&PID[i], &PID[j]);
                swap(&wt[i], &wt[j]);
                swap(&tat[i], &tat[j]);
            }
        }
}

void findWaitingTime(int processes[], int n,
                     int bt[], int at[], int wt[])
{
    // waiting time for first process is it's arrival time
    wt[0] = at[0];

    // calculating waiting time
    for (int i = 1; i < n; i++)
    {
        wt[i] = (at[i - 1] + bt[i - 1] + wt[i - 1]) - at[i];
        wt[i] = (wt[i] > 0) ? wt[i] : 0;
    }
}

// Function to calculate turn around time
void findTurnAroundTime(int processes[], int n,
                        int bt[], int at[], int wt[], int tat[])
{
    // calculating turnaround time by adding
    // bt[i] + wt[i]
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

void printAvgTime(int processes[], int n, int bt[], int at[], int wt[], int tat[], int total_wt, int total_tat)
{
    printf("PID\tArrival Time\tBurst Time\tWaiting Time\tTurn Around Time\n");
    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf("%d\t\t", processes[i]);
        printf("%d\t\t", at[i]);
        printf("%d\t\t", bt[i]);
        printf("%d\t\t", wt[i]);
        printf("%d\n", tat[i]);
    }
    float s = (float)total_wt / (float)n;
    float t = (float)total_tat / (float)n;
    printf("Average waiting time = %f ms", s);
    printf("\n");
    printf("Average turn around time = %f ms", t);
}

// Function to calculate average time
void findavgTime(int processes[], int n, int bt[], int at[])
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    // Function to find waiting time of all processes
    findWaitingTime(processes, n, bt, at, wt);

    // Function to find turn around time for all processes
    findTurnAroundTime(processes, n, bt, at, wt, tat);

    sortId(at, bt, processes, wt, tat, n);
    printAvgTime(processes, n, bt, at, wt, tat, total_wt, total_tat);
}

int main()
{
    // process id's
    int processes[] = {1, 2, 3, 4, 5};
    int n = sizeof processes / sizeof processes[0];

    int arrival_time[] = {3, 5, 0, 5, 4};
    // Burst time of all processes
    int burst_time[] = {4, 3, 2, 1, 3};

    // Taking inputs
    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("PID AT BT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", i + 1);
        processes[i] = i + 1;
        scanf("%d %d", &arrival_time[i], &burst_time[i]);
    }

    sortArrival(arrival_time, burst_time, processes, n);

    findavgTime(processes, n, burst_time, arrival_time);
    return 0;
}
