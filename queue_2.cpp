// implementation of circular queue using array

#include<iostream>

using namespace std;
#define MAX 5
int arr[MAX];
int front=-1,rear=-1;
bool isEmpty(){
    if (front ==-1 && rear ==  -1)
        return true;
    return false;

}

void enqueue(int x){
    if(isEmpty())
    {
        front++; rear++;
        arr[rear]=x;
        return;

    }
    if((rear+1)%MAX==front)
    {
        cout <<"Queue is Full \n";
        return;
    }

    rear = (rear+1)%MAX;
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
    enqueue(5);
    cout <<"FronT: "<<frnt();
    dequeue();
    dequeue();
    cout <<"Front: "<<frnt()<<endl;
    for(int i=front;i<=rear;i++)
        cout <<arr[i]<<" ";

    enqueue(6);
    enqueue(7);
    enqueue(8);
    cout<<endl;
    cout <<"rear is at "<<arr[rear];

    return 0;
}
