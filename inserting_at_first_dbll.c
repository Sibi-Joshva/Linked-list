#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *prev;
	struct node *nxt;
};

struct node *head;

struct node *insert(struct node *head,int n[],int l)
{
	for(int i=0;i<l;i++)
	{
		struct node *new_node;
		struct node *curr;

		new_node = (struct node *)malloc(sizeof(struct node));
		
		new_node->prev = NULL;
		new_node->data = n[i];
		new_node->nxt  = NULL;
		if(head == NULL)
		{
			head = new_node;
		}
		else
		{
			curr = head;
			while(curr->nxt != NULL)
			{
				curr = curr->nxt;
			}
			curr->nxt = new_node;
		}
	}
	return head;
}

void display(struct node *head)
{
	struct node *current;
	current = head;
	while(current->nxt != NULL)
	{
		printf("%d --> ",current->data);
		current = current->nxt;
	}
	printf("%d\n",current->data);
}

struct node *insert_first(struct node *head,int num[],int l)
{
	for(int i=0;i<l;i++)
	{
		struct node *new_node;
		new_node = (struct node *)malloc(sizeof(struct node));
		
		new_node->data = num[i];
		new_node->nxt  = head;
		new_node->prev = NULL;
		head->prev = new_node;
		head = new_node;										
		display(head);
	}
	return head;
}

void main()
{
	head = NULL;
	int val[] = {12,23,34,45,56,67,78};
	int len = sizeof(val)/sizeof(val[0]);

	int val2[] = {21,32,43,54,65,76};
	int len2 = sizeof(val2)/sizeof(val[0]);

	head = insert(head,val,len);
	display(head);
	head = insert_first(head,val2,len2);

}