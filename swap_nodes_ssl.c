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
    struct node *current;
    current = head;
    while(current->nxt != NULL)
    {
        printf("%d --> ",current->data);
        current = current->nxt;
    }
    printf("%d\n",current->data);
}

struct node *create(struct node *head, int n[], int len)
{
    for(int i=0;i<len;i++)
    {
        struct node *new_node;
        struct node *curr;

        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = n[i];
        new_node->nxt  = NULL;

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

struct node *swap(struct node *head, int a[],int len)
{
    struct node *curr, *temp;
    temp = head;
    for(int i=0;i<len;i++)
    {
        if(head==NULL)
        {
            return NULL;
        }
        if(head->nxt == NULL)
        {
            return head;
            temp = head->nxt;
            head->nxt =(temp->nxt);
            temp->nxt = head;
        }

        }
        display(head);
    }

void main()
{
    head = NULL;
    int arr[] = {1,2,3,4};
    int len = sizeof(arr)/sizeof(arr[0]);

    head = create(head,arr,len);
    display(head);
    printf("========= swapping node =========\n");
    head = swap(head,arr,len);
}