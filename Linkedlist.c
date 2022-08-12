#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* address;
};

struct node* head;

//
void front_insert(){
	int x;
	scanf("%d", &x);
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = x;
	temp->address = head;
	head = temp;
	printf("Inserted %d at the front\n", x);
}

void rear_insert(){
	int x;
	scanf("%d", &x);
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

void insert_here(){
	int x;
	scanf("%d", &x);
	int pos;
	scanf("%d", &pos);
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

void delete_this(){
	int x;
	scanf("%d", &x);
	struct node* curr = head;
	struct node* prev = NULL;
	
	while(curr!=NULL){
	
		if(head->data == x){
		prev = head;
		head = head->address;
		free(prev);
		break;
	}
		if(curr->data == x){
			prev->address = curr->address;
			free(curr);
			break;
		}
		prev = curr;
		curr = curr->address;
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
	for (int i = 1; i < size; i++, k--){
      current = head;
      next = head->address;
		
      for (int j = 1 ; j < size ; j++ ) {   

         if (current->data > next->data){
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
	int choice;
	
	do{
		printf("Enter your choice\n1.Front insert\n2.Rear insert\n3.Insert at a position\n4.Pop\n5.Delete an element\n6.Display\n7.Sort");
		scanf("%d", &choice);
		switch (choice)
	{
	case 1:
		front_insert();
		break;
	case 2:
		rear_insert();
		break;
	case 3:
		insert_here();
		break;
	case 4:
		pop();
		break;
	case 5:
		delete_this();
		break;
	case 6:
		display();
		break;
	case 7:
		sort();
		break;
	
	} 

}while(choice>=1 && choice<8);



}