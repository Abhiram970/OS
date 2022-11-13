#include<stdio.h>
void firstFit(int bz[], int m, int pro[], int n)
{
    int flag = 0;
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            if(pro[i]<=bz[j])
            {
                printf("process size: %d  Block No: %d\n", pro[i],j);
                bz[j] = 0;
                flag = 1;
                break;
            }
        }
        if(flag==0)
        {
            printf("Nat passibal\n");
        }
        flag = 0;
    }
}
int main()
{
    int blockSize[] = {30, 5, 10};
    int processSize[] = {10, 6, 9};
    int m = sizeof(blockSize)/sizeof(blockSize[0]);
    int n = sizeof(processSize)/sizeof(processSize[0]);
    firstFit(blockSize, m, processSize, n);
}