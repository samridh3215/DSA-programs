#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct node{
	int value;
	struct node* left;
	struct node* right;
}treenode;

treenode* head;


void swap(treenode* a, treenode*b){
	int temp = a->value;
	a->value= b->value;
	b->value = temp;
}

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
int findheight(treenode* root){
	if(root == NULL)
		return 0;
	int left = findheight(root->left);
	int right = findheight(root->right);
	if(left>right)
		return left+1;
	else
		return right+1;
}

void printCurrentLevel(treenode* root, int level){
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->value);
    else if (level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

void printLevelOrder(treenode* root){
    int h = findheight(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}



void display(int a[], int size){
	for(int i =0; i<size; i++){
		printf("%d\n", a[i]);
	}
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
	insertleft(root->left, 5);
	inorder(root);
	printf("\n");
	printLevelOrder(root);
	printf("\n");
	preorder(root);
	printf("\n");
	postorder(root);
	return 0;
}
