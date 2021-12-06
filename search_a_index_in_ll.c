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
	for (int i=0; i<l; i++)
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

void display(struct node *head)
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

struct node *insert_first(struct node *head, int data){
	struct node *new_node;
	new_node = (struct node *)malloc(sizeof(struct node));
	
	new_node->data = data;
	new_node->p    =head;
	return new_node;

}

struct node *insert_mid(struct node *head, int data, int index)
{

	if (index==0)
	{
		return insert_first(head, data);
	}
	int n = index;	
	int i = 0;
	struct node *new_node, *current, *follow;
	new_node = (struct node *)malloc(sizeof(struct node));
	
	new_node->data = data;
	new_node->p    =NULL;

	current = head;
	while(current!=NULL)
	{
		follow = current;
		current = current->p;
		if (i==n-1)
		{
			break;
		}
		i++;

	}

	if (i==n-1)
	{
		new_node->p = current;
		follow->p = new_node;
		return head;
	}
	else
	{
		printf("Index Out of range (1-%d)\n",i+1);
		return head;
	}


	display(head);
}



int searching_index2(struct node *head)
{
	int count = 1;
	int search;
	printf("Which element index wants to find : ");
	scanf("%d",&search);

	struct node *temp;
	temp = head;

 	while(temp!=NULL)
 	{
		if (search == temp->data)
		{
			return count;
		}
		count++;
		temp = temp->p;
	}
	return -1;
}



void searching_index(struct node *head)
{
	int count = 1;
	int search, flag=0;
	printf("Which element index wants to find : ");
	scanf("%d",&search);

	struct node *temp;
	temp = head;


 	while(temp!=NULL)
 	{
		if (search == temp->data)
		{
			flag = 1;
			break;
		}
		count++;
		temp = temp->p;
	}
	if (flag==1)
	{
		printf("Element located at index %d\n", count);
	} 
	else 
	{
		printf("Element Not found\n");
	}
}

void main()
{
	head =NULL;
	int pos, value;
	int n[] = {10,20,30,40,50,60,70,80,90};
	int lenth = sizeof(n)/sizeof(n[0]);

	head = insert(head,n,lenth);

	display(head);
	searching_index(head);

	printf("which position : ");
	scanf("%d",&pos);
	printf("which value wants to insert : ");
	scanf("%d",&value);
	head = insert_mid(head,value,pos);

	display(head);
}