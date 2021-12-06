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
		struct node *current;

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
		printf("%d -->",curr->data);
		curr = curr->nxt;
	}
	printf("%d\n",curr->data);
}

struct node *insert_at_mid(struct node *head,int value,int position)
{
	struct node *new_node, *curr, *follow;
	
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node->prev = NULL;
	new_node->data = value;
	new_node->nxt  = NULL;

	curr = head;
	if(curr != NULL)
	{
		for(int i=0;i<position-1;i++)
		{
			curr = curr->nxt;
			if(curr->nxt != NULL)
			{
				curr->nxt->prev = new_node;
				break;
			}
			curr->nxt = new_node;
		}
		new_node->nxt = curr->nxt;
		new_node->prev = curr;
		curr->nxt = new_node;	
	}
	else
	{
		printf("invalid");
	}	
	display(head);

}

void main()
{
	head = NULL;
	//inserting a value in linked list
	int val[] = {10,20,30,40,50,60};
	int len = sizeof(val)/sizeof(val[0]);
	head = insert(head,val,len);
	display(head);

	//insert_at_mid  
	int center_value, pos ;
	printf("Which value wants to insert : ");
	scanf("%d",&center_value);
	printf("Which position do you want to insert : ");
	scanf("%d",&pos);

	head = insert_at_mid(head,center_value,pos);

}