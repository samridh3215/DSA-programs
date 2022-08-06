#include <stdio.h>
#define max 10

int queue[max];
int front, rear;

void create_queue(int arr[]){
	for(int i = 0; i<max; i++)
		arr[i] = -1;
	front = 0;rear = -1;
	printf("[front:%d, rear: %d]\n", front, rear);
}
void in_front(int arr[], int item){
	if(front == -1)
		printf("full from front\n");
	else{
		front--;
		arr[front] = item;
		printf("Inserted from front %d", item);
	printf("[front:%d, rear: %d]\n", front, rear);
	}
}
void in_rear(int arr[], int item){
	if (rear ==max -1)
		printf("full from rear\n");
	else if (rear ==-1){
		rear=0;
		arr[rear] = item;
		printf("Inserted from rear %d", item);
	}
	else{
	    rear++;
	    arr[rear]=item;
	    printf("Inserted from rear %d", item);
	}
	printf("[front:%d, rear: %d]\n", front, rear);
}
int del_front(int arr[]){
	int item;
	if(front == max-1)
		printf("cannot delete using front\n");
	else{
		item = arr[front];
		arr[front] = -1;
		front++;
		printf("deleted %d from front", item);
	}
	printf("[front:%d, rear: %d]\n", front, rear);
}
int del_rear(int arr[]){
	int item;
	if(rear == -1)
		printf("Cannot delete using rear\n");
	else{
		item = arr[rear];
		arr[rear] = -1;
		rear--;
		printf("deleted %d from rear", item);
	}
	printf("[front:%d, rear: %d]\n", front, rear);
}
void display(int arr[]){
		printf("Front: ");
		for(int i =0; arr[i]!='\0'; i++)
			printf("%d, ", arr[i]);
		printf(" : Rear\n");
}

int main(){
		create_queue(queue);
		in_rear(queue, 1);
		in_rear(queue, 2);
		in_rear(queue, 3);
		in_rear(queue, 4);
		in_rear(queue, 5);
		del_front(queue);
		del_rear(queue);
		display(queue);
		in_front(queue, 6);
		display(queue);
		return 0;
}
