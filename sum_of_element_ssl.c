#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int data;
	struct node *ptr;
};

struct node *head;

struct node *create(struct node *head,int arr[],int l)
{
	for(int i=0;i<l;i++)
	{
		struct node *new_node;
		struct node *curr;

		new_node = (struct node*)malloc(sizeof(struct node));
		new_node->data = arr[i];
		new_node->ptr = NULL;

		if(head == NULL)
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
		printf(" %d  --> ",current->data);
		current = current->ptr;
	}
	printf(" %d \n",current->data );
}

int add(struct node *head)//add function
{
	int sum = 0;
	struct node *curr;
	curr = head;
	while(curr->ptr != NULL)
	{
		sum += curr->data;
		curr = curr->ptr;
	}
	sum += curr->data;
	return sum;//it return the value to sum
}

void main()
{
	int arr[] = {12,23,34,4,5,56};
	int len = sizeof(arr)/sizeof(arr[0]);
	head = create(head,arr,len);

	display(head);
	printf(" sum of the list  : %d\n",add(head));
}