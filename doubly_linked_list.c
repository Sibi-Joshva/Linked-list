#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *prev;
	struct node *nxt;
};

struct node *head;

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

void main()
{
	struct node *new_node1, *new_node2, *new_node3, *new_node4;

	new_node1 = (struct node *)malloc(sizeof(struct node));
	new_node2 = (struct node *)malloc(sizeof(struct node));
	new_node3 = (struct node *)malloc(sizeof(struct node));
	new_node4 = (struct node *)malloc(sizeof(struct node));

	new_node1->prev = NULL;
	new_node1->data = 10;
	new_node1->nxt  = new_node2;
	
	new_node2->prev = head;
	new_node2->data = 20;
	new_node2->nxt  = new_node3;

	new_node3->prev = new_node2;
	new_node3->data = 30;
	new_node3->nxt  = new_node4;

	new_node4->prev = new_node3;
	new_node4->data = 40;
	new_node4->nxt  = NULL;

	printf("%d --> %d --> %d --> %d --> NULL\n", new_node1->data, new_node2->data, new_node3->data, new_node4->data);

	display(new_node1);//new_node is assied to head ptr

}