// create a binary search tree and search.
#include<iostream>
#include<stdlib.h>
using namespace std;

struct bstNode{
    int data;
    bstNode* left;
    bstNode* right;
};
bstNode* getNewnode(bstNode* root,int data){
    root=new bstNode;
    root->data=data;
    root->left=NULL;
    root->right=NULL;
    return root;
}
bstNode* insert (bstNode* root,int data){
    if(root==NULL){
        root = getNewnode(root,data);
    }
    else if(data<=root->data){
        root->left = insert(root->left,data);
    }
    else{
        root->right = insert(root->right,data);
    }
    return root;
}

bool search(bstNode* root,int data){
    if(root==NULL)
        return false;
    else if(root->data==data)
        return true ;
    else if(data<root->data)
        return search(root->left,data);
    else if(data>root->data)
        return search(root->right,data);

}

int main(){
    bstNode* root = NULL;
    int num;
    root = insert(root,15);
    root = insert(root,10);
    root = insert(root,20);
    root = insert(root,25);
    root = insert(root,12);
    cout <<"Enter the no. you want search \n";
    cin>>num;
    bool ret = search(root,num);
    if(ret==true)
        cout <<"Found\n";
    else
        cout<<"Not found\n";

    return 0;
}
