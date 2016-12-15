

//Insert at the beginning

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

int main(){
    int n,i,num;
    printf("how many record u want\n");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter the number\n");
        scanf("%d",&num);
        insert(num);
        print();
    }
    struct node* tempfree;
    while(head!=NULL){
        tempfree=head;
        head=head->next;
        free(tempfree);
    }
return 0;
}
