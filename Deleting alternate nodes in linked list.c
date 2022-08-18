

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};
int track = 0;
struct node* head=NULL;

void insert(int data){
    struct node* temp;
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    if(head==NULL){
        head = newnode;
        temp = head;
    }
    else{
        temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next=newnode;
    }
}

void create(int no){
    for(int i = 0; i<no; i++){
        insert(i);
        track++;
    }
}

void display(){
    struct node* temp;
    temp = head;
    while(temp!=NULL){
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

void del(){
int c=1;
head = head->next;
struct node* prev=head;

struct node* a=head->next;

while(a!=NULL){
    if(c==1){
        struct node* tmp=a;
        prev->next=a->next;
        c=0;
        a=prev->next;
    }
    else{
        c=1;
        prev=a;
        a=a->next;
    }
    }
}

void main(){

    int num;
    printf("enter no of nodes:");
    scanf("%d", &num);
    create(num);
    printf("------List before delete operation----------\n");
    display();
    printf("------List after delete operation----------\n");
    
    del();

    display();

    
}