#include<stdio.h>
#include<malloc.h>
struct node
{
	int info;
	struct node *link;
}*start=NULL;
void push(int el)
{
	struct node *str;
	str=(struct node*)malloc(sizeof(struct node*));
	str->info=el;
	str->link=start;
	start=str;
}
void pop()
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
			start=start->link;
			free(temp);
		}
	}
}
void Disp(struct node *ptr)
{
	if(start==NULL)
	printf("NO NODE");
	else
	{
		while(ptr!=NULL)
		{
			printf("%d",ptr->info);
			ptr=ptr->link;
		}
	}
}
int main()
{
	int el,ch;
	while(1)
	{
		printf("\t\t MENU\n ");
		printf("----------------------\n ");
		printf("1. INSERT \n ");
		printf("2. DELETE \n ");
		printf("3. DISPLAY \n");
		printf("----------------------\n ");
		scanf("%d:",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter an element");
				scanf("%d ",&el);
				push(el);
				break;
			case 2:
				pop();
				break;
			case 3:
				Disp(start);
				break;
			default:
				return 0;
		}
	}
}

