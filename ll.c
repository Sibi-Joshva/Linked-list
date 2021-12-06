#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *nxt;
};

struct node *head;

struct node *insert(struct node *head, int arr[], int l)
{
    for(int i=0;i<l;i++)
    {
        struct node *new_node;
        struct node *curr;
        
        new_node = (struct node *)malloc(sizeof(struct node));
        
        new_node->data = arr[i];
        new_node->nxt = NULL;
              
        if(head == NULL)
        {
            head = new_node;
        }
        else
        {
            curr = head;
            while(curr->nxt != NULL)
            {
                curr = curr->nxt;
            }
            curr->nxt = new_node;
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
        printf("%d--->",curr->data);
        curr = curr->nxt;
    }
    printf("%d\n",curr->data);
}


struct node *insert_first(struct node *head,int data)
{
    struct node *new_node;

    new_node = (struct node *)malloc(sizeof(struct node));

    new_node->data = data;
    new_node->nxt = head;

    return new_node;
}

void main()
{
    head = NULL;
    int arr[] = {10,20,30,40,50,60,70};
    int len = sizeof(arr)/sizeof(arr[0]);
    
    head = insert(head,arr,len);
    display(head);

    int data;
    printf("enter the value you want to insert at first : ");
    scanf("%d",&data);

    head = insert_first(head,data);
    display(head);
    
    
}