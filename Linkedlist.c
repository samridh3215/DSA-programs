#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *address;
};

struct node *head;

void front_insert(int x){
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = x;
	temp->address = head;
	head = temp;
	printf("Inserted %d at the front\n", x);
}

void rear_insert(int x){
	struct node* newnode  = (struct node*)malloc(sizeof(struct node));
	struct node* temp;
	temp = head;
	newnode->data = x;
	newnode-> address  = NULL;
	while(temp->address!=NULL)
		temp = temp->address;
	temp->address = newnode;
	printf("Inserted %d at the rear\n", x);
}

void insert_here(int x, int  pos){
	int c = 0, i = 0;
	struct node* temp;
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	temp = head;
	while(temp->address != NULL){
		temp = temp->address;
		c++;
	}
	if(pos==0)
		front_insert(x);
	else if(pos==c)
		rear_insert(x);
	else if(pos>c)
		printf("higher than limit\n");
	else{
		temp = head;
		while(i!=pos){
			temp = temp->address;
            i++;
		}
		struct node* temp1 = temp->address; 
		newnode->data = x;
		temp->address = newnode;
		newnode->address = temp1;
		printf("Inserted %d at %d\n",x,pos);
	}
}

void pop(){
	struct node* temp =  head;
	struct node* temp1 = head;
	temp = temp->address;
	while(temp->address!=NULL){
		temp = temp->address;
	    temp1 = temp1->address;
	}
	int a = temp->data;
	free(temp);
	temp1->address = NULL;
	printf("popped %d\n", a);
}

int get_size(){
	int count=0;
	struct node* new  = head;
	while(new!=NULL){
		new = new->address;
		count++;
	}
	return count;
}

void display(){
	struct node* temp;
	temp = head;
	while (temp!= NULL){
		printf("%d\n", temp->data);
		temp = temp->address;
	}
}

void reverse(){
    printf("______REVERSED_______\n");
	struct node* next = NULL;
	struct node* prev = NULL;
	struct node* current = head;
	while(current!=NULL){
	    next = current->address; printf("%d   ", next->data);
	    current->address  = prev;
	    prev = current; printf("%d   ", prev->data);
	    current = next; printf("%d\n", current->data);
	}
	head = prev;
}

void sort(){
	struct node *current= head;
	struct node *next;
	int temp;
	int size = get_size();
	int k = size;
	for ( int i = 1; i < size; i++, k-- ) {
      current = head;
      next = head->address;
		
      for (int j = 1 ; j < size ; j++ ) {   

         if ( current->data > next->data ) {
            temp = current->data;
            current->data = next->data;
            next->data = temp;
         }
			
         current = current->address;
         next = next->address;
      }
   }   
}

void main(){
	head = NULL;
	front_insert(1);
	front_insert(2);
	front_insert(5);
	rear_insert(3);
	rear_insert(6);
	insert_here(4,2);
	display();
	reverse();
	display();
	printf("----\n");
	sort();
	display();

}