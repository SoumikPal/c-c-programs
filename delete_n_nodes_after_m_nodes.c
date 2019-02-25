#include<stdio.h>
#include<stdlib.h>
int n=6;
int m=3;
struct node
{
    int data;
    struct node *next;
};
struct node* getNode(int data)
{
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=NULL;
    return ptr;
}
void push(struct node **head,int data)
{
    struct node* np=getNode(data);
    np->next=*head;
    *head=np;
}
struct node* del(struct node* head)
{
    struct node *ptr=head,*ptr1,*ptr2,*prv;
    
    while(ptr){
        int c=0;
    while(c<m&&ptr!=NULL)
    {
        prv=ptr;
        ptr=ptr->next;
        c++;
    }
    int d=0;
    ptr2=ptr;
    while(d<n&&ptr2!=NULL)
    {
        ptr1=ptr2->next;
        free(ptr2);
        ptr2=ptr1;
        d++;
    }
    prv->next=ptr2;
    ptr=ptr2;
    }
    return head;
    
}
    
void print(struct node *root)
{
    while(root!=NULL)
    {
        printf("%d ",root->data);
        root=root->next;
    }
    printf("\n");
}
int main()
{
    struct node *head=NULL;
     push(&head, 10); 
    push(&head, 9); 
    push(&head, 8); 
    push(&head, 7); 
    push(&head, 6); 
    push(&head, 5); 
    push(&head, 4); 
    push(&head, 3); 
    push(&head, 2); 
    push(&head, 1);
    print(head);
    print(del(head));
    

}
