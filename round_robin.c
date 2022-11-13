#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int i, pid, status;
    int n = 5;
    int time, time_quantum = 2;
    int burst_time[10] = {5, 3, 1, 2, 3};
    int wait_time[10], turnaround_time[10], flag[10];
    int remaining_time[10] = {5, 3, 1, 2, 3};
    int total_wait_time = 0, total_turnaround_time = 0;
    float average_wait_time, average_turnaround_time;
    for (i = 0; i < n; i++)
    {
        flag[i] = 1;
    }
    time = 0;
    while (1)
    {
        int done = 1;
        for (i = 0; i < n; i++)
        {
            if (flag[i] == 1)
            {
                done = 0;
                if (remaining_time[i] > time_quantum)
                {
                    time += time_quantum;
                    remaining_time[i] -= time_quantum;
                }
                else
                {
                    time += remaining_time[i];
                    wait_time[i] = time - burst_time[i];
                    remaining_time[i] = 0;
                    flag[i] = 0;
                }
            }
        }
        if (done == 1)
        {
            break;
        }
    }
    for (i = 0; i < n; i++)
    {
        turnaround_time[i] = wait_time[i] + burst_time[i];
        total_wait_time += wait_time[i];
        total_turnaround_time += turnaround_time[i];
    }
    average_wait_time = (float)total_wait_time / (float)n;
    average_turnaround_time = (float)total_turnaround_time / (float)n;
    printf("Process\t\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\n", i + 1, burst_time[i], wait_time[i], turnaround_time[i]);
    }
    printf("Average Waiting Time: %f\n", average_wait_time);
    printf("Average Turnaround Time: %f", average_turnaround_time);
    return 0;
}
