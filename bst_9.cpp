// Inorder predecessor in bst

#include<iostream>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
};
node* getNewnode(int data){
    node * temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
node* insert(node* root, int data){
    if(root == NULL)
    {
        root = getNewnode(data);
        return root;
    }

    if(data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
}

void preorder(node* root){
    if(root==NULL)
        return;
    cout << root->data<<" " ;
    preorder(root->left);
    preorder(root->right);

}
node* findMax(node* root){
    while(root->right!=NULL){
        root = root->right;
    }
    return root;
}
node* find(node* root, int data){
    while(root->data != data){
        if(data < root->data)
        root = root->left;

        else
            root = root->right;
    }
    return root ;

}
struct node* getPredecessor(struct node* root,int data){
    struct node* current = find(root,data);
    if(current==NULL)
        return NULL;

    // case : 1 when there is left node, go to next left of the
    // subtree
    if(current -> left!= NULL)
            return findMax(current->left);
    // case : 2 when there is no left subtree. just predecessor will
    // be the predecessor
    node* predecessor = NULL;
    while(root!= current){
        if(data < root ->data)
            root = root ->left;
        else{
            predecessor = root;
            root = root ->right;
        }
    }


    return predecessor;



};
int main(){
    node* root = NULL;
    root = insert(root,15);
    root = insert(root,8);
    root = insert(root,7);
    root = insert(root,10);
    root = insert(root,9);
    root = insert(root,20);
    root = insert(root,25);
    preorder(root);
    node* temp = getPredecessor(root,20);
    cout << "\n"<<temp->data;
    return 0;
}
