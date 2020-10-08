#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
int mutex=1,full=0,empty=10,buffer[20];
int wait(int s)
{	while(s<0);
	return(--s);
}
int signal(int s)
{
	return(++s);
}
void *producer()
{	while(1){
	if(empty!=0)
	{
	mutex=wait(mutex); 
	empty=wait(empty);
	mutex=signal(mutex);
	full=signal(full);
	buffer[full]=1;
	printf("\nProducer produces %d item",full);
	sleep(1);
	}
	else{
		printf("\nBuffer is full");
		sleep(4);
	}
	
}
}
void *consumer()
{	while(1){
	if(full!=0){
	mutex=wait(mutex);
	buffer[full]=0;
	printf("\nConsumer consumes %d item",full);
	full=wait(full);
	mutex=signal(mutex);
	empty=signal(empty);
	sleep(5);
	}
	else
	{	printf("\nBuffer is empty");
		sleep(1);}
	
}
}
int main()
{
	int i;
	pthread_t t1,t2;
		pthread_create(&t1,NULL,producer,NULL);
		pthread_create(&t2,NULL,consumer,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	for(i=0;i<10;i++)
	printf("\n%d",buffer[i]);
	
	
return 0;
}
