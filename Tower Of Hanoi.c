#include<stdio.h>
void TOH(int n,char S,char E,char A)
{
	if(n==1)
	{
		printf("Move disc %d from %c to %c",n,S,E);
		return;
	}
	TOH(n-1, S , A, E);
	printf("\nMove disc %d from %c to %c\n",n,S,E);
	TOH(n-1,A,E,S);
}

main()
{
	int n;
	printf("Enter the number of Discs:\n");
	scanf("%d",&n);
	TOH(n,'A','C','B');
}

