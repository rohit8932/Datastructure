
//delete from anywhere

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
struct node* head=NULL;
struct node* temp1=NULL;
void insert(int num){

    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=num;
    temp->next=NULL;

    if(head==NULL)
    {
        head=temp;
        temp1=temp;
    }
    else
    {
        temp1->next=temp;
        temp1=temp;
    }
}
void print(){
    struct node* temp=head;
    printf("List is :");
    while(temp!=NULL){
        printf("%d",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void del(int num){
    struct node* temp=head;
    struct node* temp1=head;
    int i;
    if(num==1){
        temp=head;
        head=head->next;
        free(temp);
        return;
    }
    for(i=0;i<num-2;i++){
        temp=temp->next;


    }
    temp1=temp->next;
    temp->next=temp->next->next;
    free(temp1);

}
int main(){
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    print();
    del(3);
    print();


return 0;
}
