// implementation of queue(normal) using array

#include<iostream>

using namespace std;
#define MAX 20
int arr[MAX];
int front=-1,rear=-1;
bool isEmpty(){
    if (front ==-1 && rear ==  -1)
        return true;
    return false;

}

void enqueue(int x){
    if(rear==MAX-1)
    {
        cout <<"Queue is Full \n";
        return;
    }
    if(isEmpty)
    {
        front++; rear++;
        arr[rear]=x;
        return;

    }
    rear = rear+1;
    arr[rear]=x;
}

void dequeue(){
    if(isEmpty())
    {
        cout <<"Queue is empty \n";
        return;

    }
    if(front == rear){
        front--; rear--;
    }

    front = front+1;

}
int frnt(){
    return arr[front];
}
int main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);

    dequeue();
    dequeue();

    cout <<"Front: "<<frnt();

    enqueue(5);
    enqueue(6);
    return 0;
}
