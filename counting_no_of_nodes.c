#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *p;
};

struct node *head;

struct node *insert(struct node *head, int a[], int l)
{
	int i;
	for (i=0; i<l; i++)
	{
		struct node *new_node;
		struct node *current;
		new_node = (struct node *)malloc(sizeof(struct node));

		new_node->data = a[i];
		new_node->p    = NULL;
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
	}
	return head;

}

int count(struct node *head)
{
	int count = 0;
	struct node *temp;
	temp = head;
	while(temp != NULL)
	{
		count++;
		temp = temp->p;
	}
	return count;
}

void display(struct node * head)
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

void main()
{
	head = NULL;
	
	int n[] = {10,20,30,40,50,60,70,80,90,100}; 
	int len = sizeof(n)/sizeof(n[0]);
	
	head = insert(head,n,len);
	
	display(head);

	printf("No of node in my linked list : ");
	int c = count(head);
	printf("%d\n",c);



}