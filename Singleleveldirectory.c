#include <stdio.h>
#include <math.h>
#include<stdlib.h>
#include<string.h>
struct file
{
    char fname[20][20];
    int fcnt;
}dir;
int main()
{
    char filename[20];
    int i,n,ch,flag=0;
  dir.fcnt=0;
  while(ch!=5){
  printf("\n1.Create\n2.Delete\n3.Search\n4.Display\n5.Exit\nEnter your choice");
  scanf("%d",&ch);
  switch(ch)
  {
      case 1: printf("\nEnter the file name to be created");
                scanf("%s",dir.fname[dir.fcnt]);
               dir.fcnt++;
                break;
        case 2:printf("\nEnter the file to be deleted");
                scanf("%s",filename);
                for(i=0;i<dir.fcnt;i++)
                {
                    if(strcmp(dir.fname[i],filename)==0)
                    {
                        strcpy(dir.fname[i],dir.fname[dir.fcnt-1]);
                        dir.fcnt--;
                        break;
                    }
                    
                }
                if(i==dir.fcnt)
                {
                    printf("\nFile not found");
                }
                break;
                case 3:printf("\nEnter the file to be searched");
                scanf("%s",filename);
                for(i=0;i<dir.fcnt;i++)
                {
                    if(strcmp(dir.fname[i],filename)==0)
                    {
                        printf("File found");
                        flag=1;
                        break;
                    }
                    
                }
                if(i==dir.fcnt)
                {
                    printf("\nFile not found");
                }
                break;
     case 4: for(i=0;i<dir.fcnt;i++)
                printf("\n%s",dir.fname[i]);
            break;
     case 5:exit(0);
            
  }
  }
    
            
}
