// doubly linked list
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* prev;
    struct node* next;
};

struct node* head=NULL;
struct node* temp1=NULL;
void insertAthead(int num){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=num;
    temp->prev=NULL;
    temp->next=NULL;

    if(head==NULL){
        temp->prev=NULL;
        temp->next=NULL;
        head=temp;
        temp1=temp;
    }
    else
    {
        head->prev=temp;
        temp->next=head;
        head=temp;

    }


}
void insertAtlast(int num){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=num;
    temp->prev=NULL;
    temp->next=NULL;

    if(head==NULL){
        temp->prev=NULL;
        temp->next=NULL;
        head=temp;
        temp1=temp;

    }
    else
    {
        temp1->next=temp;
        temp->prev=temp1;
        temp1=temp;
    }
}
void print(){
    struct node* temp=head;
    while(temp!=NULL){
        printf("%d",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void reversePrint(){
    struct node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    while(temp!=NULL){
        printf("%d",temp->data);
        temp=temp->prev;
    }
    printf("\n");
}
int main(){
    insertAthead(1);
    insertAthead(2);
    insertAtlast(3);
    insertAtlast(4);
    print();
    reversePrint();
    return 0;
}
