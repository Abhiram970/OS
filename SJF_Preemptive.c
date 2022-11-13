#include <stdio.h>

int main()
{
    int time, bt[10], at[10];
    int sum_bt = 0, smallest, rem;
    int n, i, rt[10];
    int sumt = 0, sumw = 0;
    printf("no of processes : ");
    scanf("%d", &n);
    rem = n;

    printf("AT BT\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &at[i]);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    rt[9] = bt[9] = 9999;
    printf("P_id\t|Arrival_time   |Burst_time     |Waiting_time   |Turn_Around_Time\n");
    for (time = 0; rem != 0; time++)
    {
        smallest = 9;
        for (i = 0; i < n; i++)
        {
            if (at[i] <= time && rt[i] > 0 && rt[i] < rt[smallest])
                smallest = i;
        }
        rt[smallest]--;
        if (rt[smallest] == 0)
        {
            rem--;
            printf("P[%d]\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t\n", smallest + 1, at[smallest], bt[smallest], time + 1 - bt[smallest] - at[smallest], time + 1 - at[smallest]);
            sumt += time + 1 - bt[smallest] - at[smallest];
            sumw += time + 1 - at[smallest];
        }
    }
    printf("\naverage waiting time = %f", (float)sumw/ n);
    printf("\naverage turnaround time = %f", (float)sumt/ n);
    return 0;
}