#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *p;
};

struct node *head;

struct node * insert_at_last(struct node *head,int n)
{
	struct node *new_node;
	struct node *curr;
	new_node = (struct node *)malloc(sizeof(struct node));
	
	new_node->data = n;
	new_node->p=NULL;

	if (head==NULL)
	{
		head = new_node;
		
	}
	else
	{
		
		curr = head;
		while(curr -> p!=NULL)
		{
			curr = curr->p; 
			
		}
		curr -> p = new_node;

	}
	return head;
	
}

void display(struct node *head)
{
	struct node *current;
	current = head;
	while (current->p!=NULL)
	{
		printf("%d--> ",current->data);
		current = current -> p;
	}
	printf("%d",current->data);
}


void main()
{
	head = NULL;
	head = insert_at_last(head,10);
	head = insert_at_last(head,20);
	head = insert_at_last(head,30);
	head = insert_at_last(head,40);
	
	display(head);
}
