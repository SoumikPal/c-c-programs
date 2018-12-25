#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};
void push(struct node** head, int val )
{
	struct node *ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data=val;
	ptr->next=NULL;
	ptr->next=(*head);
	(*head)=ptr;
}
struct node* newNode(int val)
{
	struct node *ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data=val;
	ptr->next=NULL;
	return ptr;

}
struct node* sort(struct node *head)
{
	if(head==NULL||head->next==NULL)
		return head;
	struct node* oned=newNode(0);
    struct node* twod=newNode(0);
    struct node* zerod=newNode(0);
    struct node* one=oned;
	struct node* two=twod;
	struct node* zero=zerod;
	struct node* ptr=head;
	while(ptr!=NULL)
	{
		if(ptr->data==0)
			{
				zero->next=ptr;
				zero=zero->next;
			}
		else if(ptr->data==1)
			{
				one->next=ptr;
				one=one->next;
			}
		else
			{
				two->next=ptr;
				two=two->next;
			}
		ptr=ptr->next;
	}
	if(oned->next)
	{
        zero->next=oned->next;
	}
	else
		zero->next=twod->next;
	one->next=twod->next;
	two->next=NULL;
	head=zerod->next;
	free(oned);
	free(zerod);
	free(twod);
	return head;


}
void print(struct node *head)
{
	struct node* ptr=head;
	while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
	printf("\n");
}
int main()
{
	struct node* head=NULL;
	push(&head,1);
	push(&head,1);
	push(&head,1);
	push(&head,1);
	push(&head,1);
	push(&head,1);
	push(&head,0);
	push(&head,0);
	push(&head,0);
	push(&head,2);
	push(&head,2);
	push(&head,2);
	push(&head,2);
	print(head);
	struct node* res=sort(head);
	print(res);


	

}
