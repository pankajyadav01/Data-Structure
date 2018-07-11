#include<stdio.h>
#include<malloc.h>
struct node
{
	int info;
	struct node *link;
}*start=NULL;
void DispOrder(struct node *ptr)
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
void DispRev(struct node *ptr)
{
	if(ptr->link!=NULL)
	DispRev(ptr->link);
	printf("%d\n",ptr->info);
}
struct node *search(struct node *ptr, int el)
{
	while(ptr!=NULL && ptr->info!=el)
	ptr=ptr->link;
	return(ptr);
}
void InsBeg(int el)
{
	struct node *str;
	str=(struct node*)malloc(sizeof(struct node*));
	str->info=el;
	str->link=start;
	start=str;
}
void InsEnd(struct node *ptr, int el)
{
	struct node *temp;
	while(ptr->link!=NULL)
	{
		ptr=ptr->link;
	}
	temp=(struct node*)malloc(sizeof(struct node*));
	temp->info=el;
	temp->link=NULL;
	ptr->link=temp;
}
void InsAGN(int new_el , int el)
{
	struct node *temp,*loc;
	temp=(struct node*)malloc(sizeof(struct node*));
	loc=search(start,el);
	if(loc==NULL)
	printf("Element no found");
	else
	{
		temp->info=new_el;
		temp->link=loc->link;
		loc->link=temp;
	}
}
void DelBeg()
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
void DelEnd()
{
	struct node *pt1,*pt2;
	if(start==NULL)
	printf("NO NODE");
	else if(start->link == NULL)
	free(start);
	else
	{
		pt1=NULL;
		pt2=start;
		pt1->link=start;
		while(pt2->link!=NULL)
		{
			pt1=pt2;
			pt2=pt2->link;
		}
		free(pt2);
		pt1->link=NULL;
	}
}
void DelAGN(int el)
{
	struct node *temp,*loc;
	if(start==NULL)
	printf("NO NODE");
	else
	{
		loc=search(start,el);
		if(loc==NULL)
		printf("elemrnt not found");
		else if (loc->link==NULL)
		printf("No Node After The Given Node");
		else
		{
			temp=loc->link;
			loc->link=temp->link;
			printf("%d",temp->info);
			free(temp);
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
		printf("1. INSERT (AT BEG )\n ");
		printf("2. INSERT (AT END )\n ");
		printf("3. INSERT (AFTER A GIVEN NODE ) \n");
		printf("-------------------------------\n ");
		printf("4. DELETE (AT BEG )\n ");
		printf("5. DELETE (AT END )\n ");
		printf("6. DELETE (AFTER A GIVEN NODE ) \n");
		printf("-------------------------------\n ");
		printf("7. DISPLAY (IN ORDER )\n ");
		printf("8. DISPLAY (REVERSE ORDER )\n ");
		printf("-------------------------------\n ");
		scanf("%d:",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter an element");
				scanf("%d ",&el);
				InsBeg(el);
				break;
			case 2:
				printf("Enter an element");
				scanf("%d ",&el);
				InsEnd(start,el);
				break;
			case 3:
				printf("Enter a NEW element");
				scanf("%d ",&el);
				printf("Enter an element aftr which you want to insert");
				scanf("%d ",&new_el);
				InsAGN(new_el,el);
				break;
			case 4:
				DelBeg();
				break;
			case 5:
				DelEnd();
				break;
			case 6:
				printf("Enter an element aftr which you want to DELETE");
				scanf("%d ",&el);
				DelAGN(el);
				break;
			case 7:
				DispOrder(start);
				break;
			case 8:
				DispRev(start);
				break;
			default:
				return;
		}
	}
}

