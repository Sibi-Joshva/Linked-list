#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *ptr;
};

struct node *head;

struct node *insert(int n[],int l,struct node *head)
{
	struct node *new_node , *temp;

	new_node = (struct node *)malloc(sizeof(struct node));
	new_node->data = n[0];
	new_node->ptr = head;

	temp = new_node;

	for(int i=1;i<l;i++)
	{
		struct node *next_node;

		next_node = (struct node *)malloc(sizeof(struct node));
		next_node->data = n[i];
		next_node->ptr  = new_node->ptr;
		new_node->ptr   = next_node;
		temp = next_node;
	}
	return head;

}

void display(struct node *head)
{
	struct node *current;
	current=head;
	while(current->ptr != head)
	{
		printf("%d --> ",current->data);
		current=current->ptr;
	}
	printf("%d\n",current->data);
}

void main()
{
	int arr[] = {10,20,30,40,50};
	int len = sizeof(arr)/sizeof(arr[0]);

	head = insert(arr,len,head);
	display(head);
}