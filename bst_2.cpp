// find min and max in binary search tree using recursion
#include<iostream>
using namespace std;
struct bstNode{
    int data;
    bstNode* left;
    bstNode* right;
};
bstNode* getNewnode(bstNode* root , int data){
    root = new bstNode;
    root->data=data;
    root->left=NULL;
    root->right=NULL;
    return root;
}

bstNode* insert(bstNode* root, int data){
    if(root==NULL)
    {
        root = getNewnode(root,data);
    }
    else if(data<=root->data)
    {
        root->left = insert(root->left,data);
    }
    else
    {
        root->right = insert(root->right,data);
    }
    return root;

}
int findMin(bstNode* root){
    if(root==NULL)
        return -1;
    else if(root->left==NULL)
        return root->data;
    else
    {
        return findMin(root->left);
    }
}

int findMax(bstNode* root){
    if(root==NULL)
        return -1;
    else if(root->right==NULL)
        return root->data;
    else
    {
        return findMin(root->right);
    }
}

int main()
{
    bstNode* root = NULL;
    root = insert(root,15);
    root = insert(root,20);
    root = insert(root,25);
    root = insert(root,12);
    int min = findMin(root);
    cout <<"Min: "<<min<<endl;
    int max = findMax(root);
    cout <<"Max: "<<max<<endl;
    return 0;
}
