#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *p; 
};

struct node *head;//global pointer 

//function used to insert a value in beginning
void insert(int x)
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp -> data = x;//x address is stored here & value of x is also stored here
	temp -> p = head;
	head = temp;
}

//function used to print 
void print()
{
	struct node *temp = head;
	while(temp != NULL)
	{
		printf(" --> %d",temp->data);
		temp = temp ->p;
	}
}

//main funtion
int main()
{
	head = NULL;//in local I inizalise head pointer is NULL
	int n,i,x;
	printf("Enter the values wants to insert : ");
	scanf("%d",&n);

	for (i=0; i<n; i++)
	{
		printf("\n");
		printf("Enter the value : ");
		scanf("%d",&x);//value given by user
		insert(x);
		print();
		printf("\n");
	}

}