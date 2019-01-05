#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
void push(struct node** head,int data)
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=(*head);
    *head=ptr;
}
void print(struct node *head)
{
    struct node *ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");

}
void modmiddle(struct node **head)
{
    struct node *fptr=*head;
    struct node *sptr=*head;
    struct node *prev=NULL;
    while(fptr!=NULL&&fptr->next!=NULL)
    {
        fptr=fptr->next->next;
        prev=sptr;
        sptr=sptr->next;
    }
    prev->next=sptr->next;
    sptr->next=(*head);
    *head=sptr;
    
}
int main()
{
    struct node *head=NULL;
    push(&head,5);
    push(&head,4);
    push(&head,3);
    push(&head,2);
    //push(&head,1);
    print(head);
    modmiddle(&head);
    print(head);
}
