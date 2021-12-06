#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node *prev;
	int data;
	struct node *nxt;
};

struct node *head;

struct node *create(struct node *head,int arr[],int l)
{
	for(int i=0;i<l;i++)
	{
		struct node *new_node;
		struct node *current;
		new_node = (struct node *)malloc(sizeof(struct node));
		new_node->prev = NULL;
		new_node->data = arr[i];
		new_node->nxt  = NULL;

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
		printf(" %d --> ",curr->data);
		curr = curr->nxt;
	}
	printf(" %d \n",curr->data);
}

int add(struct node *head)
{
	int sum = 0;
	struct node *curr;
	curr = head;
	while(curr->nxt != NULL)
	{
		sum = sum + curr->data;
		curr = curr->nxt;
	}
	sum = sum+curr->data;
	return sum;
}

void main()
{
	head = NULL;
	int arr[] = {12,23,34,45,56,67};
	int len = sizeof(arr)/sizeof(arr[0]);

	head = create(head,arr,len);
	display(head);

	printf("sum of data in doubly linked list  : %d \n",add(head));
}