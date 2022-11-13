#include <stdio.h>
#include <conio.h>

void main()
{
    int i, n = 4, sum = 0, count = 0, y, quant = 5, wt = 0, tat = 0;
    int arrival_time[10] = {0, 1, 2, 3};
    int burst_time[10] = {9, 5, 3, 4};
    float avg_wt, avg_tat;
    int temp[10] = {9, 5, 3, 4};
    y = n;
    printf("\n Process No \t\t Burst Time \t\t Turn Around Time \t\t Waiting Time ");
    for (sum = 0, i = 0; y != 0;)
    {
        if (temp[i] <= quant && temp[i] > 0)
        {
            sum = sum + temp[i];
            temp[i] = 0;
            count = 1;
        }
        else if (temp[i] > 0)
        {
            temp[i] = temp[i] - quant;
            sum = sum + quant;
        }
        if (temp[i] == 0 && count == 1)
        {
            y--;
            if (sum - arrival_time[i] - burst_time[i] < 0)
            {
                wt += 0;
            }
            else
            {
                wt = wt + sum - arrival_time[i] - burst_time[i];
            }
            printf("\nProcess No[%d] \t\t %d\t\t\t\t %d\t\t\t %d", i + 1, burst_time[i], sum - arrival_time[i], wt);
            tat = tat + sum - arrival_time[i];
            count = 0;
        }
        if (i == n - 1)
        {
            i = 0;
        }
        else if (arrival_time[i + 1] <= sum)
        {
            i++;
        }
        else
        {
            i = 0;
        }
    }
    avg_wt = wt * 1.0 / n;
    avg_tat = tat * 1.0 / n;
    printf("\nAverage Turn Around Time: \t%f", avg_wt);
    printf("\nAverage Waiting Time: \t%f", avg_tat);
}
