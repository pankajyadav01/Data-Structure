#include<stdio.h>
#include<malloc.h>
struct node
{
	int info;
	struct node *link;
}*f=NULL,*r=NULL;
void ins()
{ 
	int n;
	struct node *temp;
	scanf("%d",&n);
	temp=(struct node*)malloc(sizeof (struct node));
	temp->info=n;
	if(f==NULL)
	{
		f=temp;
		r=temp;
	}
	else
	{
		r->link=temp;
		temp->link=NULL;
		r=temp;
	}
}
void del()
{ 
	struct node *temp;
	if(f==NULL)
    printf("Underflow");
	else if (f->link=NULL)
	{
    	temp=f;
    	printf("Deleted elem %d",temp->info);
    	f=r=NULL;
    	free(temp);
	}
	else
	{
		temp=f;
		printf("Deleted elem %d",temp->info);
		f=temp->link;
		free(temp); 
   	}
}
void disp()
{	
	struct node *temp=f;
   	while(temp!=NULL)
	{
    	printf("%d",temp->info);
		temp=temp->link;
	}
}
void main()
{
	int ch;
	while(1)
	{
		printf(" \t MENU");
		printf(" 1.INSERT \n 2.Delete \n 3.Display \n 4.Exit\n\n");
		printf("enter choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				ins();
				break;
			case 2:
				del();
				break;
			case 3:
				disp();
				break;
			default:
				exit(0);
		}
	}
}

