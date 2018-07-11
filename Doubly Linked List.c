#include<stdio.h>
#include<malloc.h>
struct node
{
	int info;
	struct node *next,*prev;
}*start=NULL;
void search(struct node *ptr, int el)
{	int c=0;
	while(ptr!=NULL && ptr->info!=el)
	{
		ptr=ptr->next;
		c++;
	}
	if(c>0)
		printf("The element is at %d position ",c);
	else
		printf("Element is not found in the list ");
}
void ins(int el)
{
	struct node *temp;
	temp =(struct node *)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->next = NULL;
    if (start == NULL)
    {
        temp->info = el;
        start = temp;
    }
    else
    {
    	temp->info = el;
        temp->next = start;
        start->prev = temp;
        start = temp;
    }
}
void del()
{
	struct node *temp; int el;
	if(start==NULL)
	printf("Stack Underflow NO NODE");
	else
	{
		if(start!=NULL)
		{
			temp=start;
			el=start->info;
			printf("The deleted element id %d\n",el);
			start=start->next;
			start->prev=NULL;
			free(temp);
		}
	}
}
void disp(struct node *ptr)
{
	if(start==NULL)
	printf("NO NODE");
	else
	{
		while(ptr!=NULL)
		{
			printf("%d",ptr->info);
			ptr=ptr->next;
		}
	}
}
void main()
{
	int new_el,el,ch;
	while(1)
	{
		printf("\t\t MENU\n ");
		printf("-------------------------------\n ");
		printf("1. Insert\n ");
		printf("2. Detete\n ");
		printf("3. Display\n");
		printf("4. Search\n");
		printf("-------------------------------\n ");
		scanf("%d:",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter an element");
				scanf("%d ",&el);
				ins(el);
				break;
			case 2:
				del();
				break;
			case 3:
				disp(start);
				break;
			case 4:
				printf("Enter an element");
				scanf("%d ",&el);
				search(start,el);
				break;
			default:
				return;
		}
	}
}

