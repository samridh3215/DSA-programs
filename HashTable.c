#include <stdio.h>
#include <stdlib.h>
#define size 10

struct set{
	int key;
	int data;
	struct set *address;
};
	
struct set arr[size];
int count= 0;

void initialise(){
	for(int i = 0; i<size; i++){
		arr[i].key = -1;
		arr[i].data = -1;
		arr[i].address = NULL;
	}
}

int hash_function(int key){
	return key%size;
}

void handle_collision(int key, int index, int data){
	struct set* head = (struct set*)malloc(sizeof(struct set));
	head = &arr[index];
	if(arr[index].address == NULL){
	    struct set newset;
	    arr[index].address = &newset;
	    newset.data = data;
	    newset.key = key;
	    newset.address = NULL;
	}
	else{
	    struct set *anotherset;
	    anotherset = head;
	    while (anotherset->address!=NULL)
	    	anotherset = anotherset->address;
	    anotherset->data= data;
	    anotherset->key = key;
	    anotherset->address = NULL;
    }
}
void insert(int key, int data){
	int index = hash_function(key);
	if(arr[index].data == -1){
		arr[index].key	= key;
		arr[index].data = data;
		count++;
		printf("inserted!\n");
	}
	else{
		printf("collision\n");
		handle_collision(key, index, data);
	}
}

void delete(int key){
	int index = hash_function(key);
	if (arr[index].data == -1)
		printf("It does not exist\n");
	else{   													//complete this 
		arr[index].key = -1;
		arr[index].data = -1;
		count--;
		printf("removed\n");
	}
}

void print_table(){
	for(int i = 0; i<size; i++){
		if(arr[i].data == -1)
			printf("arr[%d] ->  empty\n", i);
		else{
			if(arr[i].address ==NULL)
			    printf("arr[%d]: %d\n", i, arr[i].data);	
			else{
			    struct set* temp = &arr[i];
			    while(temp!=NULL){
			        printf("arr[%d]: %d -->", i, temp->data);
			        temp = temp->address;
			    }
			    printf("\n");
			}
			    
		}
	}
}



void main(){
	initialise();
	insert(1, 1);
	insert(2, 5);
	insert(7, 4);
	insert(1, 3);
	print_table();
}
