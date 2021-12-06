#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *p;
};

struct node *head;
struct node *insert_at_first(struct node *head,int n[],int l)
{
	for(int i=0;i<l;i++)
	{
		struct node *new_node;
		new_node = (struct node *)malloc(sizeof(struct node));
		new_node->data = n[i];
		new_node->p = head;
		
		head = new_node;
		printf("%d --> ",new_node->data);
	}
}
struct node *insert(struct node *head, int n)
{
	struct node *new_node;
	struct node *current;
	new_node = (struct node *)malloc(sizeof(struct node));

	new_node->data = n;
	new_node->p    = NULL;

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
void display(struct node *head)
{
	struct node *curr;
	curr = head;
	while(curr->p != 0)
	{
		printf("%d --> ",curr->data);
		curr = curr->p;
	}
	printf("%d\n",curr->data);
}

void main()
{
	head = NULL;
	head = insert(head,20);
	head = insert(head,30);
	head = insert(head,40);
	head = insert(head,50);

	int values[] = {-50,-40,-30,-20,-10,0,10};
	int length = sizeof(values)/sizeof(values[0]);
	//printf("%d\n",length);

	insert_at_first(head,values,length);

	display(head);
}