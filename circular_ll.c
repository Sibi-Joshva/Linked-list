#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *nxt;
};

struct node *head;

void display(struct node *head)
{
	struct node *curr;
	curr = head;
	while(curr->nxt != head)
	{
		printf("%d --> ",curr->data);
		curr = curr->nxt;
	}
	printf("%d\n",curr->data);
}


struct node* build_cll(int a[], int size){
	int v,i;
	struct node *my_node;
	struct node *current, *temp;
	if (size>0)
	{
		v = a[0];
		my_node = (struct node *)malloc(sizeof(struct node));
		my_node->nxt = my_node;
		my_node->data = v;
		current = my_node;

		while(current->nxt != my_node)
		{
			current = current->nxt;
		}

		for (i=1; i<size; i++)
		{
			temp = (struct node *)malloc(sizeof(struct node));
			temp->data = a[i];
			temp->nxt = current->nxt;
			current->nxt = temp;
			current = temp;
		}
	}
	return my_node;
}


void main()
{
	head = NULL;
	int arr[] = {1,2,3,4,5,6,7,8};
	int size = sizeof(arr)/sizeof(arr[0]);
	head = build_cll(arr,size);

	display(head);
}