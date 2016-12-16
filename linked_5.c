// recursion print and reverse print
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

void print(struct node* p){
    if(p==NULL){

        return;
    }
    printf("%d",p->data);
    print(p->next);


};
void reverseprint(struct node* p){
    if(p==NULL)
        return;

    reverseprint(p->next);
    printf("%d",p->data);

}
int main(){
    struct node* head=NULL;
    head=insert(head,1);
    head=insert(head,2);
    head=insert(head,3);
    head=insert(head,4);
    print(head);
    printf("\n");
    reverseprint(head);
}
