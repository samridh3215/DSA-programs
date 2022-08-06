#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 5

int front = -1;	
int rear = -1;	
int array[SIZE];



void insert(int data){
	if ((rear == SIZE-1 && front == 0)||(front == rear+1))
		printf("Queue is full!!");
	else{
		if (front ==-1)
			front = 0;
		rear = (rear+1)%SIZE;
		array[rear] = data;
		printf("inserted %d		[rear : %d   front : %d]\n", data, rear, front);
	}
}

void pop(){
	if(front == -1)
		printf("Queue is Empty");
	else{
		int p = array[front];
		if (front == rear){
			front = -1;
			rear = -1;
		}
		
		array[front] = -1;
		front = (front+1)%SIZE;
		printf("popped %d		[rear : %d   front : %d]\n", p, rear, front);
	}
}

void main(){
	
	for(int i = 0; i< SIZE; i++)
		array[i] = -1;    

	insert(1);
	insert(2);
	insert(3);
	insert(4);
	insert(5);
	pop();
	pop();
	insert(6);
	insert(7);
	insert(8);
}
