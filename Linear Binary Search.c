#include<stdio.h>
void linear(int a[],int el,int n)
{
	int x=0,i;
	for(i=0;i<n;i++)
	{
		if(a[i]==el)
		{
			printf("the element is found on position %d ",i+1);
			x++;
		}
	}
	if(x==0)
	printf("ELEMENT NOT FOUND");
}
void binary(int a[],int el,int n)
{
	int B,E,M,x=1;
	B=0;E=n-1;
	M=(B+E)/2;
	while(B<=E && el!=a[M])
	{
		if(a[M]>el)
			E=M-1;
		else 
			B=M+1;
		M=(B+E)/2;
	}
	if(a[M]==el)
		printf("the index of element %d is %d",el,M);
	else
		printf("ELEMENT NOT FOUND");
}
main()
{
	int a[100],n,el,i,ch;
	printf("Enter length of the array");
	scanf("%d",&n);
	printf("Enter a 10 element array");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter a element to be searched");
	scanf("%d",&el);
	printf("\n\n1.linear search\n2.binary search\nchoice=");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			linear(a,el,n);
			break;
		case 2:
			binary(a,el,n);
			break;
		default:
			return;
	}	
	
}

