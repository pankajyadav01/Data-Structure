#include <stdio.h>
#define MAX 5
struct stack
{ 
	int stack[MAX];
	int top;
}s;
void push ()
{
	int num;
	if (s.top == (MAX - 1))
	{
		printf ("Stack is Full\n");
		return;
	}
	else
	{
		printf ("Enter the element to be pushed\n");
		scanf ("%d", &num);
		s.top = s.top + 1;
		s.stack[s.top] = num;
	}
	return;
}
int pop ()
{
	int num;
	if (s.top == - 1)
	{
		printf ("Stack is Empty\n");
		return (s.top);
	}
	else
	{
		num = s.stack[s.top];
		printf ("poped element is = %d\n", s.stack[s.top]);
		s.top = s.top - 1;
	}
	return(num);
}
void disp ()
{
	int i;
	if (s.top == -1)
	{
		printf ("Stack is empty\n");
		return;
	}
	else
	{
		printf ("\nThe status of the stack is\n");
		for (i = s.top; i >= 0; i--)
		{
			printf ("%d\n", s.stack[i]);
		}
	}
	printf ("\n");
}
void main ()
{
	int ch;
	int op = 1;
	s.top = -1;
	printf ("STACK OPERATION\n");
	while (op)
	{
		printf ("-------------------------\n");
		printf (" 1 --> PUSH \n");
		printf (" 2 --> POP \n");
		printf (" 3 --> DISPLAY \n");
		printf (" 4 --> EXIT \n");
		printf ("Enter your ch\n");
		scanf ("%d", &ch);
		switch (ch)
		{
			case 1: push();
			break;
			case 2: pop();
			break;
			case 3: disp();
			break;
			default: return;
		}
		printf ("Do you want to continue(Type 0 or 1)?\n");
		scanf ("%d", &op);
	}
}

