// Preorder postorder inorder traversal
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

void preorder(bstNode* root){
    if(root==NULL)
        return;
    cout <<root->data<<" " ;
    preorder(root->left);
    preorder(root->right);
}

void postorder(bstNode* root){
     if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout <<root->data<<" " ;
}
void inorder(bstNode* root){
     if(root==NULL)
        return;
    inorder(root->left);
    cout <<root->data<<" " ;
    inorder(root->right);

}

int main(){
    bstNode* root = NULL;
    int num;
    root = insert(root,15);
    root = insert(root,10);
    root = insert(root,20);
    root = insert(root,25);
    root = insert(root,12);
    root = insert(root,13);
    preorder(root);cout <<"\n";
    postorder(root); cout <<"\n";
    inorder(root);

    return 0;
}
