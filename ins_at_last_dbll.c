#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *prev;
	struct node *nxt;
};

struct node *head;

struct node *insert(struct node *head,int n[], int l)
{
	for(int i=0;i<l;i++)
	{
		struct node *new_node;
		struct node *current;

		new_node = (struct node *)malloc(sizeof(struct node));

		new_node->prev = NULL;
		new_node->data = n[i];
		new_node->nxt = NULL;
		if(head == NULL)
		{
			head = new_node;
		}
		else
		{
			current = head;
			while(current->nxt != NULL)
			{
				current = current->nxt;
			}
			current->nxt = new_node;
		}
	}
	return head;
}

void display(struct node *head)
{
	struct node *curr;
	curr = head;
	while(curr->nxt != NULL)
	{
		printf("%d --> ",curr->data);
		curr = curr->nxt;
	}
	printf("%d\n",curr->data);
}

void main()
{
	head = NULL;
	int values[] = {10,20,30,40,50,60};
	int length = sizeof(values)/sizeof(values[0]);

	head = insert(head,values,length);
	display(head);
}