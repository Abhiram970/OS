#include <stdio.h>

void implimentFirstFit(int blockSize[], int blocks, int processSize[], int processes)
{
    int allocate[processes];
  
    for(int i = 0; i < processes; i++)
    {
        allocate[i] = -1;
    }
    
    for (int i = 0; i < processes; i++)
    {
        for (int j = 0; j < blocks; j++) { 
            if (blockSize[j] >= processSize[i])
            {
               
                allocate[i] = j;
 
                blockSize[j] -= processSize[i];
 
                break;
            }
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < processes; i++)
    {
        printf("%d \t\t\t %d \t\t\t", i+1, processSize[i]);
        if (allocate[i] != -1)
            printf("%d\n",allocate[i] + 1);
        else
            printf("Not Allocated\n");
    }
}
void main()
{
    int blockSize[] = {15, 12, 10};
    int processSize[] = {10, 12,5};
    int m = sizeof(blockSize)/sizeof(blockSize[0]);
    int n = sizeof(processSize)/sizeof(processSize[0]);
    
    implimentFirstFit(blockSize, m, processSize, n);
}
