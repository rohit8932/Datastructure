//check if binary tree is binary search tree (BST) or not
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

bool isBstutil(bstNode* root, int min,int max){
    if(root==NULL)
        return true;
    if(root->data > min && root->data < max
       && isBstutil(root->left,min,root->data)
       && isBstutil(root->right,root->data,max))
        return true;

    else
        return false;


}

bool isBst(bstNode* root){
    return isBstutil(root,INT_MIN,INT_MAX);
}

int main(){
    bstNode* root = NULL;
    int num;
    root = insert(root,15);
    root = insert(root,10);
    root = insert(root,20);
    root = insert(root,25);
    root = insert(root,12);
    bool ret = isBst(root);
    if(ret== true)
        cout <<"binary tree is BST ";
    else
        cout <<"not a BST " ;
    return 0;
}

