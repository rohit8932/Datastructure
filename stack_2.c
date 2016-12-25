// stack using inked list
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* top=NULL;
void push(int num){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=num;
    temp->next=NULL; //----------------------------------------------

    if(top==NULL)
    {
        top=temp;
    }
    else
    {
        temp->next=top;
        top=temp;
    }//-------------------------------------------------------------
   // temp->next=top; //instead of writing if else we can write what written in comment
   // top=temp;
}
void pop(){
    if(top==NULL)
    {
        printf("UnderFlow!!\n");
        return;
    }
    struct node* temp=top;
    top=top->next;
    free(temp);
}

void tops(){
    printf("Top Of Stack: %d",top->data);

}

int main(){
    pop();
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    pop();
    pop();
    tops();
    return 0;
}
