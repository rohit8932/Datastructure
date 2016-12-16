//reverse the linked node
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};

struct node* insert(struct node* head,int num){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=num;
    temp->next=NULL;

    if(head==NULL)
        head=temp;
    else
    {
        temp->next=head;
        head=temp;
    }
    return head;
}

void print(struct node* head){
    struct node* temp=head;
    while(temp!=NULL){
        printf("%d",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
struct node* reverse(struct node* head){
    struct node* prev=NULL;
    struct node* next=head;
    struct node* curr=head;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;

    }
    head=prev;
    return head;
}
int main(){
    struct node* head=NULL;
    head=insert(head,1);
    head=insert(head,2);
    head=insert(head,3);
    head=insert(head,4);
    print(head);
    head=reverse(head);
    print(head);

return 0;
}
