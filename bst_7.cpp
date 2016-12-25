// delete a node from tree from any where

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

bstNode* getsmall(bstNode* root){
    if(root==NULL)
        return root;

    else
        root = getsmall(root->left);

        return root;
}
bstNode* del(bstNode* root , int data){
    if(root == NULL)
        return root;

    else if(data < root->data)
        root->left = del(root->left,data);

    else if(data > root->data )
        root->right = del(root->right,data);

    else // node which is to be deleted is found
    {
        if(root->left == NULL && root->right == NULL)  // both left and right child is null
            {
                delete(root);
                root = NULL;
                return root;
            }
            else if(root->left == NULL)     // one child (right)
            {
                bstNode* temp = root;
                temp = temp->right;
                delete(root);
                return temp;

            }
            else if(root->right == NULL)       // one child(left)
            {
                bstNode* temp = root;
                temp = temp->left;
                delete (root);
                return temp;
            }
            else                            // both child is present
            {
                bstNode* temp = root->right;
                root->right = getsmall(temp);
                root->data = temp->data;
                del(temp,temp->data);
            }
            return root;
    }

}
int main(){
    bstNode* root = NULL;
    int num;
    root = insert(root,15);
    root = insert(root,10);
    root = insert(root,20);
    root = insert(root,25);
    root = insert(root,12);
    preorder(root);
    root = del(root,15);
    cout <<"\n";
    preorder(root);
    return 0;
}

