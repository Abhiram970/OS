#include <stdio.h>
#include <pthread.h>

int n = 5;
int forks[] = {1,1,1,1,1};

void take_fork(int i) {
    if(forks[i]) {
        forks[i] = 0;
    }
    else {
        printf("Fork is already taken...\n");
    }
}

void put_fork(int i) {
    forks[i]++;
}

void* philosopher(int* index) {
    printf("Philosopher %d is thinking...\n", index);
    int i = (int *)index;
    take_fork(i);
    printf("Philosopher %d has taken fork %d\n", index, i);
    take_fork((i+1)%n);
    printf("Philosopher %d has taken fork %d\n", index, (i+1)%n);
    printf("Philosopher %d is eating...\n", i);
    put_fork(i);
    put_fork((i+1)%n);
    return NULL;
}

int main() {
    pthread_t pthread[n];
    for(int i = 0; i < n; i++) {
        pthread_create(&pthread[i], NULL, philosopher, i+1);
    }
    for(int i = 0; i < n; i++) {
        pthread_join(pthread[i], NULL);
    } 
    exit(0);
}

