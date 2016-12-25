// Find the height of tree
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


int maxHeight(bstNode* node)
{
   if (node==NULL)
       return 0;
   else
   {
       /* compute the height of each subtree */
       int lheight = maxHeight(node->left);
       int rheight = maxHeight(node->right);

       /* use the larger one */
       if (lheight > rheight)
           return(lheight+1);
       else return(rheight+1);
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

    cout <<"height of the tree is "<<maxHeight(root);

    return 0;
}
