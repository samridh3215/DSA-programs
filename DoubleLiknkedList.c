#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* next;
    struct node* prev;

}node;

node* head=NULL;
node* tail = NULL;


void front_insert(){
	int data;
	printf("Enter element to insert at front");
	scanf("%d", &data);
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data= data;
	newnode->prev = NULL;
	if (head ==NULL){
		newnode->next = NULL;
		head = newnode;
		tail = newnode;
	}
	else{
		head->prev = newnode;
		newnode->next = head;
		head = newnode;
	}
	printf("inserted %d at front\n", data);
	
}

void rear_insert(){
	int data;
	printf("Enter element to insert at rear");
	scanf("%d", &data);
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data= data;
	newnode->next = NULL;
	if(head == NULL){
		newnode->prev = NULL;
		head = newnode;
		tail = newnode;
	}
	else{
		tail->next= newnode;
		newnode->prev = tail;
		tail = newnode;
	}
	printf("inserted %d at rear\n", data);
}

void display(){
	if(head == NULL)
		printf("empty\n");
	else{
		node* temp = head;
		while(temp!=NULL){
			printf("%d\n", temp->data);
			temp = temp->next;
		}
	}
}


void main(){
	front_insert();
    front_insert();
    rear_insert();
    rear_insert();
    display();
}