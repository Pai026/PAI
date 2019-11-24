#include<pthread.h>
#include<semaphore.h>
#include <stdio.h>
int mutex=1;
int full=0;
int empty=10;
int buffer[20];
int wait(int s){
    while(s<0);
    return (--s);
}
int post(int s){
    return (++s);
}
void *producer()
{  
    while(1)
    {
        if(empty!=0)
        {
       mutex=wait(mutex);
       empty=wait(empty);
       mutex=post(mutex);
       full=post(full);
       printf("\nProducer produces %d item",full);
        sleep(1);
        }
     else{
         printf("\nBuffer full");
          sleep(10);
     }  
     
    }
   
    
}
void *consumer()
{
   
    while(1)
    {   
        if(full!=0){
        mutex=wait(mutex);
        printf("\nConsumer consumes %d item",full);
        full=wait(full);
        mutex=post(mutex);
        empty=post(empty);
        }
        else{
            printf("\nCannot Consume");
        }
       sleep(3);
    }
     
}
int main()
{
    int i;
    pthread_t p1,p;
    pthread_create(&p,NULL,producer,NULL);
    pthread_create(&p1,NULL,consumer,NULL);   
    pthread_join(p,NULL);
    pthread_join(p1,NULL);
    
    return 0;
}
