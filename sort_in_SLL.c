#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int data;
	struct node *ptr;
};

struct node *head;

struct node *insert(struct node *head,int n[],int l)
{
	for(int i=0;i<l;i++)
	{
		struct node *new_node;
		struct node *curr;

		new_node = (struct node *)malloc(sizeof(struct node));

		new_node->data = n[i];
		new_node->ptr  = NULL;
	
		if(head==NULL)
		{
			head = new_node;
		}
		else
		{
			curr = head;
			while(curr->ptr != NULL)
			{
				curr = curr->ptr;
			}
			curr->ptr = new_node;
		}
	}
	return head;
}

void display(struct node *head)
{
	struct node *current;
	current = head;
	while(current->ptr != NULL)
	{
		printf("%d --> ",current->data);
		current = current->ptr;
	}
	printf("%d\n",current->data);
}

 void bubble_sort(struct node *h, int n)
{
	int i,j;
	struct node *curr, *follow;
	curr = h;
	follow = NULL;

	for(i=0;i<n;i++)
	{
		curr = h;
		follow = NULL;
		for(j=0;j<n;j++)
		{
			if(curr!=NULL && follow!=NULL && curr->data <follow->data)
			{
				//printf("%d-%d\n",curr->data,follow->data);
				int temp = curr->data;
				curr->data = follow->data;
				follow->data = temp;
				//changes 1
				//changes 2
			}	
			follow = curr;
			curr = curr->ptr;
		}
	}	
	printf("		AFTER SORTING		\n");
	display(head);
}





void main()
{
	head = NULL;
	int val[] = {12,34,10,7,5,89,98};
	int len = sizeof(val)/sizeof(val[0]);
	head = insert(head,val,len);
	printf("		BEFORE SORTING		\n");
	display(head);

	bubble_sort(head,len);

}