// stack implementation using array

#include<stdio.h>
#define MAX 20
int arr[MAX];
int top=-1;
int isFull(){
    if(top==MAX-1)
        return 1;
    else
        return 0;
}
void push(int num){
    int x=isFull();
    if(x==0){
        top=top+1;
        arr[top]=num;
    }
    else{
        printf("stack is full\n");
    }
}

void pop(){
    if(top==-1){
        printf("Stack underflow\n");
        return;
    }
    top=top-1;
}
int topOfstack(){
    return arr[top];
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
    printf("Top:- %d\n",topOfstack());
    push(100);
    printf("Top:- %d\n",topOfstack());
    pop();
    printf("Top:- %d\n",topOfstack());
    return 0;
}
