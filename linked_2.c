// insert at anywhere

#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node* head=NULL;
void insert(int num,int pos){

        struct node* temp=(struct node*)malloc(sizeof(struct node));
        temp->data=num;
        temp->next=NULL;

        if(pos==1)
        {
            temp->next=head;
            head=temp;
        }
        else
        {   struct node*temp1=head;
            int i;
            for(i=0;i<pos-2;i++){
                temp1=temp1->next;

            }
            temp->next=temp1->next;
            temp1->next=temp;
        }


    }

    void print(){
        struct node* temp=head;
        printf("The list is: ");
        while(temp!=NULL){
            printf("%d",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
int main(){
    insert(1,1);
    insert(2,2);
    insert(3,3);
    insert(4,4);
    insert(5,1);
    print();

return 0;}
