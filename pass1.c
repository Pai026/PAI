#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
	int n,i,j,x,op3,lc,loc,sa;
	char op[20],mne[20],lab[20],op2[20],lab2[20],len;
	FILE *fp1,*fp2,*fp3,*fp4,*fp5;
	fp1=fopen("input.txt","r");
	fp2=fopen("symtab.txt","w+");	
	fp4=fopen("ouput.txt","w");
	fscanf(fp1,"%s %s %x",lab,mne,&op3);
	if(strcmp(mne,"START")==0)
	{
		sa=op3;
		loc=sa;

	}
	else
	{
		loc=0;
	}
	fprintf(fp4,"-\t%s\t%s\t%x\n",lab,mne,op3);
		fscanf(fp1,"%s%s",lab,mne);
	while(!feof(fp1))
	{
		fscanf(fp1,"%s",op);
		fprintf(fp4,"%x\t%s\t%s\t%s\n",loc,lab,mne,op);
		if(strcmp(lab,"-")!=0)
		{

				fprintf(fp2,"%s%x",lab,loc);
		}
		fp3=fopen("optab.txt","r");
		fscanf(fp3,"%s%s",lab2,op2);
		while(!feof(fp3))
		{
			if(strcmp(mne,lab2)==0)
				{loc=loc+3;
				break;}
			fscanf(fp3,"%s%s",lab2,op2);		
		}
		fclose(fp3);
		 if(strcmp(mne,"WORD")==0)
			loc=loc+3;
		else if(strcmp(mne,"RESW")==0)
			loc=3*atoi(op);
		else if(strcmp(mne,"RESB")==0)
			loc+=atoi(op);
		else if(strcmp(mne,"BYTE")==0)
		{
			if(op[0]=='X')
				loc=loc+1;
			else
			{
				len=strlen(op)-2;
				loc=loc+len;
			}
		}
		fscanf(fp1,"%s%s",lab,mne);
	}
	fprintf(fp4,"%x\t%s\t-",loc,mne);
	if(strcmp(mne,"END")==0)
	{	fp5=fopen("length.txt","w");
		fprintf(fp5,"length of program=%x",loc-sa);
	}


}
