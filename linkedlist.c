#include<stdio.h>
#include<stdlib.h>

struct node//creating node
{
	int data;
	struct node *ptr;
};

void main()
{
	int v1, v2, v3, v4, v5;
	scanf("%d%d%d%d%d", &v1, &v2, &v3, &v4, &v5);

	struct node *head, *head2, *head3, *head4, *head5, *current;
	head = (struct node *) malloc(sizeof(struct node));//type caste first ,then create memory using malloc funct 
	head2 = (struct node *) malloc(sizeof(struct node));
	head3 = (struct node *) malloc(sizeof(struct node));
	head4 = (struct node *) malloc(sizeof(struct node));
	head5 = (struct node *) malloc(sizeof(struct node));

	//storing values in node 
	head -> data = v1;
	head -> ptr = head2;//point the address value 2
	
	head2 -> data = v2;
	head2-> ptr = head3;
	
	head3 -> data =v3;
	head3 -> ptr = head4;
	
	head4 -> data = v4;
	head4 -> ptr = head5;
	
	head5 -> data = v5;
	head5 -> ptr = 0;

	printf("-----------------------------------------------------\n");
	printf("%d\n",head->data);
	printf("%d\n",head2->data);
	printf("%d\n",head3->data);
	printf("%d\n",head4->data);
	printf("%d\n",head5->data);

	printf("-----------------------------------------------------\n");

	//linked list
	current = head;
	while(current->ptr != NULL)
	{
		printf("%d-->",current->data);
		current = current->ptr;
	}
	printf("%d\n",current->data);
}
