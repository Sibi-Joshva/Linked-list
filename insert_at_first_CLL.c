#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *ptr;
};

struct node *head;

void display(struct node *head)
{
	struct node *curr;
	curr = head;
	while(curr->ptr != head)
	{
		printf("%d --> ",curr->data);
		curr = curr->ptr;
	}
	printf("%d\n",curr->data);

}

struct node *insert_first(int n[], int l)
{
	struct node *new_node, *curr, *temp;

	if(l>0)
	{
		int val  = n[0];
		new_node = (struct node*)malloc(sizeof(struct node));
		
		new_node->data = val;
		new_node->ptr  = new_node;

		curr = new_node;

		while(curr->ptr != new_node)
		{
			curr = curr->ptr;
		}
 
	}
	return new_node;
}

void main()
{
	head = NULL;
	int arr[] = {1,2,3,4,5,6,7,8};
	int len = sizeof(arr)/sizeof(arr[0]);

	head = insert_first(arr,len);
	display(head);

}