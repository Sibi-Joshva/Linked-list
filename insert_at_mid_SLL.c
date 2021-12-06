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
	while(curr->p != NULL)
	{
		printf("%d --> ",curr->data);
		curr = curr->p;
	}
	printf("%d\n",curr->data);
}

struct node *insert(struct node *head, int n)
{
	struct node *new_node;
	struct node *current;

	new_node = (struct node *)malloc(sizeof(struct node));
	new_node->data = n;
	new_node->p = NULL;
	if(head == NULL)
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

struct node *insert_at_mid(struct node *head)
{
	int n, i=0;
	struct node *new_node;
	struct node *current;

	new_node = (struct node *)malloc(sizeof(struct node));
	
	new_node->data = 30;
	new_node->p = NULL;

	printf("ENTER THE POSITION : ");
	scanf("%d",&n);
	current = head;
	struct node *f;
	while(i<n-1)
	{
		f = current;
		current = current->p;
		i++;	
	}
	printf("current-->data = %d\n\n",current->data);
	printf("follow-->data = %d\n\n",f->data);
	new_node->p = f->p;
	f->p = new_node;

	display(head);
}

void main()
{
	head = NULL;
	head = insert(head,10);
	head = insert(head,20);
	head = insert(head,40);
	head = insert(head,50);
	head = insert(head,60);

	display(head);

	insert_at_mid(head);

}