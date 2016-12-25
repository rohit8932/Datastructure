// Level order traversal (BREADTH FIRST TRAVERSAL)
#include<iostream>
#include<stdlib.h>
#include<queue>
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

void levelOrder(bstNode* root){
    if(root==NULL)
        return;
    queue <bstNode*> q;
    q.push(root);
    while(!q.empty()){
        bstNode* curr = q.front();
        cout <<curr->data<<" ";
        if(curr->left!=NULL)
            q.push(curr->left);
        if(curr->right!=NULL)
            q.push(curr->right);

        q.pop();

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
    levelOrder(root);

    return 0;
}

