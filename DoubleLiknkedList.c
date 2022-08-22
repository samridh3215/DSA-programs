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

int get_size(){
	int count=0;
	node* temp= head;
	while(temp!=NULL){
		count++;
		temp = temp->next;
	}
	return count;
}

void insert_here(){
	int data, pos;
	printf("enter position and data separated by a space");
	scanf("%d %d", &pos, &data);
	node* temp = head;
	if(head==NULL){
		printf("empty");
	}
	else if(pos>get_size()){
		printf("overflow");
	}
	else{
		node* newnode = (node*)malloc(sizeof(node));
		for(int i = 1;i<pos; i++){
			temp = temp ->next;
		}
		newnode->data = data;
		newnode->next = temp->next;
		temp->next->prev = newnode;
		temp->next = newnode;
		newnode->prev = temp;
	}
	printf("inserted %d at %d\n", data, pos);

}

void delete_front(){
	head = head->next;
	node* temp = head->prev;
	head->prev = NULL;
	temp->next =NULL;
	free(temp);
}

void delete_rear(){
	tail = tail->prev;
	node* temp = tail->next;
	temp->prev=NULL;
	tail->next=NULL;
	free(temp);
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
	delete_front();
	front_insert();
	insert_here();
	display();
}