#include <stdlib.h>
#include <stdio.h>

typedef struct node{
	int value;
	struct node* left;
	struct node* right;
}treenode;

treenode* head;

treenode *createnode(int value){
	treenode* ptr = (treenode*)malloc(sizeof(treenode));
	ptr->value = value;
	ptr->left = NULL;
	ptr->right = NULL;
	return ptr;
}

void insertleft(treenode* node, int value){
	node->left = createnode(value);
}

void insertright(treenode* node, int value){
	node->right = createnode(value);
}

void inorder(treenode* root){
	if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->value);
    inorder(root->right);
}

void postorder(treenode* root){
	if(root==NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	printf("%d ",root->value);
}

void preorder(treenode* root){
	if(root==NULL)
		return;
	printf("%d ",root->value);
	preorder(root->left);
	preorder(root->right);
	
}

int main(){
	
	treenode* root =createnode(1);
	insertleft(root,2);
	insertright(root, 3);
	insertleft(root->left, 4);
	insertright(root->right, 5);
	inorder(root);
	printf("\n");
	preorder(root);
	printf("\n");
	postorder(root);
	
	return 0;
}
