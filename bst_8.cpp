// Inorder successor in bst

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
node* findMin(node* root){
    while(root->left!=NULL){
        root = root->left;
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
struct node* getSuccessor(struct node* root,int data){
    struct node* current = find(root,data);
    if(current==NULL)
        return NULL;
    if(current->right!= NULL)
        // case 1 : Node has right subtree
        return findMin(current->right);
    // case 2 : no right subtree
    else{
        node* successor = NULL;
        node* anchestor = root;
        while(anchestor!=current)
        {
            if(data < anchestor->data){
                successor = anchestor;
                anchestor = anchestor->left;
            }
            else
                anchestor = anchestor->right;

        }
        return successor;

    }



};
int main(){
    node* root = NULL;
    root = insert(root,2);
    root = insert(root,1);
    root = insert(root,3);
    root = insert(root,0);
    preorder(root);
    node* temp = getSuccessor(root,0);
    cout << "\n"<<temp->data;
    return 0;
}
