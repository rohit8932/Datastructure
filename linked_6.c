// reverse the linked list using recursion
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* head=NULL;
void insert(int num){
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


}
void print(){
    struct node* temp=head;
    printf("list is: ");
    while(temp!=NULL){
        printf("%d",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void reverse(struct node* p){
    if(p->next==NULL){
        head=p;
        return;
    }
    reverse(p->next);
    struct node* q=p->next;
    q->next=p;
    p->next=NULL;
}

int main(){
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    print();
    reverse(head);
    print();
    return 0;
}
