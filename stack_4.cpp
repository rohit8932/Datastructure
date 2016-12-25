// reverse linked list using stack

#include<iostream>
#include<stdlib.h>
#include<stack>
using namespace std;

class node{
    public:
    int data;
    node*next;
};

node* head=NULL;
void insert(int num){
    node* temp=new node;
    temp->data=num;
    temp->next=NULL;

    if(head==NULL)
    {
        head=temp;
        return;
    }
    temp->next=head;
    head=temp;

}
void print(){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data;
        temp=temp->next;
    }
    cout<<"\n";
}
void reverse(){
    stack<class node*> s;
    node*temp=head;
    while(temp!=NULL)
    {
        s.push(temp);
        temp=temp->next;
    }

    temp=s.top();
    s.pop();
    head=temp;

    while(!s.empty()){
        temp->next=s.top();
        s.pop();
        temp=temp->next;

    }
    temp->next=NULL;
}
int main(){
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    print();
    reverse();
    print();
    return 0;
}
