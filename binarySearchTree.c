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

void main(){
    node* root = NULL;
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 24);
    root = insert(root, 21);
    printf("%d", search(root, 24));
}