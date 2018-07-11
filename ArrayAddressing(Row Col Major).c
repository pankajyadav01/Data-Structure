#include<stdio.h>
int main()
{
	int B,w,lb1,lb2,ub1,ub2,J,K,ch;
	printf("Enter the base address");
	scanf("%d ",&B);
	printf("Enter data type size");
	scanf("%d ",&w);
	printf("Enter LB1");
	scanf("%d ",&lb1);
	printf("Enter LB2");
	scanf("%d ",&lb2);
	printf("Enter UB1");
	scanf("%d ",&ub1);
	printf("Enter UB2");
	scanf("%d ",&ub2);
	printf("Row subscript(address to be found)");
	scanf("%d ",&J);
	printf("Column subscript(address to be found)");
	scanf("%d ",&K);
	printf("\n\n1.Row Major\n2.Column Major\nENTER YOUR CHOICE");
	scanf("%d ",&ch);
	switch(ch)
	{
		case 1:
			printf("Address of LOC[%d][%d] is %d",J,K,(B+w*((ub2-lb2+1)*(J-lb1)+(K-lb2))));
			break;
		case 2:
			printf("Address of LOC[%d][%d] is %ld",J,K,(B+w*((J-lb1)+(ub1-lb1+1)*(K-lb2))));
			break;
		default:
			return;
	}
	return 0;
}

