/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include<pthread.h>
#include<semaphore.h>
#include <stdio.h>
#define N 5
#define Hungry 1
#define Eating 0
#define Thinking 2
#define LEFT (phnum+4)%N
#define Right (phnum+1)%N
int state[5];
int phil[N]={1,2,3,4};
sem_t mutex;
sem_t s[N];
void test(int phnum)
{
    if((state[phnum]==Hungry)&&(state[LEFT]!=Eating)&&(state[Right]!=Eating))
    {
        state[phnum]=Eating;
        sleep(2);
        printf("\nPhilosopher %d takes fork %d and %d \n",phnum+1,LEFT+1,phnum+1);
        printf("\nPhilosopher %d is Eating",phnum+1);
        sem_post(&s[phnum]);
    }
    
    
}
void take_fork(int phnum)
{
    sem_wait(&mutex);
    state[phnum]=Hungry;
    printf("\nPhilosopher %d is Hungry\n",phnum+1);
    test(phnum);
    sem_post(&mutex);
    sem_wait(&s[phnum]);
    sleep(1);
}
void put_fork(int phnum)
{
    sem_wait(&mutex);
    state[phnum]=Thinking;
    printf("\nPhilosopher %d putting fork %d and %d down \n",phnum+1,LEFT+1,phnum+1);
    printf("\nPhilosopher %d is Thinking\n",phnum+1);
    test(LEFT);
    test(Right);
    sem_post(&mutex);
    
}
void *philosopher(void *num)
{
    while(1)
    {
        int *i=num;
        sleep(1);
        take_fork(*i);
        sleep(0);
        put_fork(*i);
    }
}
int main()
{
    int i;
    pthread_t philthread[N];
    sem_init(&mutex,0,1);
    for(i=0;i<N;i++)
    {
        sem_init(&s[i],0,0);
    }
    for(i=0;i<N;i++)
    {
        pthread_create(&philthread[i],NULL,philosopher,&phil[i]);
        
        printf("\nPhilosopher %d is thinking",i+1);
    }
    for(i=0;i<N;i++)
    {
        pthread_join(philthread[i],NULL);
    }
    return 0;
}
