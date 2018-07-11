#include<stdio.h>
struct node
{
	struct node * left;
	int info;
	struct node * right;
}root=NULL;

void ins(struct node * root ,int el)
{
	if(root==NULL)
	{
		root->info=el;
	return;
	}
	else
	{
		if(el==root->info)
		{
			printf("\n\nINVALID INPUT\n\n");
			return;
		}
		else if(el<root->info)
			return(ins(root->left,el));
		else
			return(ins(root->right,el));
	}
}

void in(struct node * tree)
{
	printf("\n\nIN ORDER\t");
	if(tree!=NULL)
	{
		in(tree->left);
		printf("\t%d",root->info);
		in(tree->right);
	}
}
void pre(struct node * tree)
{
	printf("\n\nPRE ORDER\t");
	if(tree!=NULL)
	{
		printf("\t%d",root->info);
		pre(tree->left);
		pre(tree->right);
	}
}
void post(struct node * tree)
{
	printf("\n\nPOST ORDER\t");
	if(tree!=NULL)
	{
		post(tree->left);
		post(tree->right);
		printf("\t%d",root->info);
	}
}
void disp(struct node * root)
{
	in(root);
	pre(root);
	post(root);

}

void main()
{
	int ch,el;
	while(1)
	{
		printf("\tMENU\n1.INSERT\n2.DISPLAY\nENTER CHOICE:  ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("ENTER AN ELEMENT  ");
				scanf("%d",&el);
				ins(root,el);
				break;
			case 2:
				disp(root);
				break;
			default:
				return;
		}
	}
}
