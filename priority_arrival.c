#include<stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define totalprocess 5
typedef struct process
{
    int at,bt,pr,pno;
}process;  

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void sort(int arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(&arr[min_idx], &arr[i]);
    }
}
process proc[50]; 
bool comp(process a,process b)
{
    if(a.at == b.at)
    {
        return a.pr<b.pr;
    }
    else
    {
        return a.at<b.at;
    }
}
void get_wait_time(int wait_time[])
{
    int service[50];
    service[0] = proc[0].at;
    wait_time[0]=0;
    for(int i=1;i<totalprocess;i++)
    {
        service[i]=proc[i-1].bt+service[i-1];
        wait_time[i]=service[i]-proc[i].at;
        if(wait_time[i]<0)
        {
            wait_time[i]=0;
        }
    }
}
void get_tat_time(int tat[],int wait_time[])
{
    for(int i=0;i<totalprocess;i++)
    {
        tat[i]=proc[i].bt+wait_time[i];
    }
}
void findGantt()
{
    int wait_time[50],tat[50];
    int wavg=0,tavg=0;
    get_wait_time(wait_time);
    get_tat_time(tat,wait_time);
    int start_time[50],comp_time[50];
    start_time[0] = proc[0].at;
    comp_time[0]=start_time[0]+tat[0];
    for(int i=1;i<totalprocess;i++)
    {
        start_time[i]=comp_time[i-1];
        comp_time[i]=start_time[i]+tat[i]-wait_time[i];
    }
    printf("Process_no\tStart_time\tComplete_time\tTurn_Around_Time\tWaiting_Time\n");
    for(int i=0;i<totalprocess;i++)
    {
        wavg += wait_time[i];
        tavg += tat[i];
        printf("%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n",proc[i].pno,start_time[i],comp_time[i],tat[i],wait_time[i]);
    }
    double w = wavg/(float)totalprocess;
    double t = tavg/(float)totalprocess;
    printf("Average waiting time is : ");
    printf("%f\n",w);
    printf("average turnaround time : ");
    printf("%f\n",t);
}
int main()
{
    int arrivaltime[] = { 1, 2, 3, 4, 5 };
    int bursttime[] = { 3, 5, 1, 7, 4 };
    int priority[] = { 3, 4, 1, 7, 8 };
    for(int i=0;i<totalprocess;i++)
    {
        proc[i].at=arrivaltime[i];
        proc[i].bt=bursttime[i];
        proc[i].pr=priority[i];
        proc[i].pno=i+1;
    }
    qsort(proc,totalprocess,sizeof(process),comp);
    findGantt();
    return 0;
}
