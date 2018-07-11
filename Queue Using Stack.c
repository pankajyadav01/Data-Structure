#include<stdio.h>
#include<stdlib.h>
#define n 5
 int queue[n];
 int f=-1,r=-1;

void insert_queue()
{ int element;
	

	if((f==0 && r==n-1) || (f==r+1))
		printf("Queue overflow");
 	
	
	else 

	{
	if(f==-1)
	 {
	 f=0;
	 r=0;
	 }
	else if(r==n-1)
 		r=0;
	else
		r++;
	}
 printf("enter element");
 scanf("%d",&element);
 queue[r]=element;
}

void delete_queue()
{ int element;
	if (f==-1)
	{
	printf("queue underflow");
	}
 else
	{
 	element=queue[f];
 	printf("Deleted elem %d",element);

	if(f==r)
	{
	 f=-1;
	 r=-1;
	}	
	else if(f==n-1)
	 f=0;
	else
	 f=f+1;
	}
}
void display()
{	
        int i;
	if (f==-1)
	printf("Queue underflow");
	else
	{
		if(f<=r)
		{
			for (i=f;i<=r;i++)
			printf("%d",queue[i]);
		}
		else if(f>r)
		{
		  for(i=f;i<=(n-1);i++)
		  printf("%d",queue[i]);
		  for(i=0;i<=r;i++)
	          printf("%d",queue[i]);
		}
	}
}
void main()
{
	int ch;
	printf("1.Add element in queue \n 2.Delete element from queue \n 3.Display Queue \n 4.Exit");
	while(1)
	{
	printf("enter choice");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
		insert_queue();
		break;

		case 2:
		delete_queue();
		break;

		case 3:
		display();
		break;

		case 4:
		exit(0);
	}
}
}

