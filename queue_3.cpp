// implementation of queue using linked list

#include<iostream>
#include<stdlib.h>
using namespace std;
class node{
public:
    int data;
    node* next;

};

node* front=NULL;
node* rear=NULL;

void enqueue(int x){
    node* temp = new node;
    temp->data=x;
    temp->next=NULL;

    if(front==NULL)
    {
        front = temp;
        rear  = temp;
    }
    else
    {
        rear->next=temp;
        rear=temp;
    }

}

void dequeue(){
    if(front==NULL)
    {
        cout <<"queue is empty ";
        return;
    }
    if(front == rear)
    {
        front = rear = NULL;
    }
    node* temp =front;
    front=front->next;
    delete temp;
}

int frnt(){
    if(front == NULL)
    {
        cout <<"queue is empty";
        return NULL;
    }
    return front->data;
}

void print(){
    node* temp=front;
    while(temp!=NULL){
        cout <<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"\n";
}

int main(){
    enqueue(1); print();
    enqueue(2); print();
    enqueue(3); print();
    enqueue(4); print();
    enqueue(5); print();
    cout<<"front is at: "<<frnt()<<endl;
    dequeue(); print();
    dequeue(); print();
    cout<<"front is at: "<<frnt();

    return 0;
}
