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

struct node *del_at_center(struct node *head)
{
	int pos, i=1;
	printf("ENTER THE POSITION : ");
	scanf("%d",&pos);

	struct node *current, *follow;
	current = head;
	while(i < pos)
	{
		follow = current;
		current = current->p;
		i++;
	}
	printf("data in follow : ");
	printf("%d\n",follow->data);
	printf("POSITION = %d\n",current->data);

	follow->p = current->p;
	free(current);
	display(head);

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
	
	display(head);
	head = del_at_center(head);
}