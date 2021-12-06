#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *p;
};

struct node *head;

void display(struct node *head)
{
	struct node *curr;
	curr = head;
	while (curr->p != 0)
	{
		printf("%d --> ",curr->data);
		curr = curr->p;
	}
	printf("%d\n",curr->data);
}

struct node *insert(struct node *head,int n)
{
	struct node *new_node;
	struct node *current;
	new_node = (struct node *)malloc(sizeof(struct node));

	new_node->data = n;
	new_node->p = NULL;

	if(head==NULL)
	{
		head = new_node;
	}
	else
	{
		current = head;
		while(current->p != NULL)
		{
			current = current->p;
		}
		current->p = new_node;
	}
	return head;
}


struct node *delete_at_last(struct node *head)
{
	struct node *c1 ,*c2;
	c1 = head;
	while(c1->p != NULL)
	{
		c2 = c1;
		c1 = c1->p; 
	}
	c2->p = NULL;
	return head;
}

void main()
{
	head = NULL;
	head = insert(head,10);
	head = insert(head,20);
	head = insert(head,30);
	head = insert(head,40);
	head = insert(head,50);
	head = insert(head,60); 

	display(head);

	head = delete_at_last(head);
	display(head);
}