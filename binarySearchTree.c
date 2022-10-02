#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}node;

node* getNewNode(int data){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

node* insert(node* root, int data){
    if(root == NULL){
        root = getNewNode(data);
        return root;
    }
        else if(data <= root->data){
            root->left = insert(root->left, data);
        }
        else{
            root->right = insert(root->right, data);
        }
    return root;
}

int search(node* root, int data){
    if(root == NULL)
        return 0;
    else if(root->data == data) return 1;
    else if (root->data >= data) return search(root->left, data);
    else return search(root->right, data);
}
node* findmin(node* root)
{
	while(root->left != NULL) root = root->left;
	return root;
}

node* delete(node* root, int data){
    if(root==NULL) return root;
    else if(data<root->data) 
        root->left = delete(root->left, data);
    else if(data>root->data)
        root->right = delete(root->right, data);
    else{
        if(root->left == NULL&& root->right ==NULL){
            free(root);
            root = NULL;
        }
        else if(root->right == NULL){
            node* temp = root;
            root = root->left;
            free(temp);
        }
        else if(root->left == NULL){
            node* temp = root;
            root = root->right;
            free(temp);
        }
        else{
            node* temp= findmin(root->right);
            root->data  = temp->data;
            root->right = delete(root->left, temp->data);
        }
    }
    return root;

}   
void inorder(node* root){
	if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void main(){
    node* root = NULL;
    
    root = insert(root, 90);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 24);
    delete(root, 29);
    root = insert(root, 21);
    inorder(root);

}