#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int num;
    int xp;
    int yp;
    struct node* next;    
}node;

int count = 0;
node *head = NULL;


node* search(int xp, int yp){
    node* temp = head;
    while(temp!=NULL){
        if(temp->xp ==xp && temp->yp == yp)
            return temp;
        temp = temp->next;
    }    
    return NULL;
}
void insert(){
    node* temp;
    node* newnode = (node*)malloc(sizeof(node));
    int num, xp, yp;
    printf("Enter num, x power and y power: ");
    scanf("%d %d %d", &num, &xp, &yp);
    node* address = search(xp, yp);
    if (head==NULL){
        newnode->num= num;
        newnode->xp = xp;
        newnode->yp = yp;
        newnode->next = NULL;
        head = newnode;
        temp = head;
        }

    else{
    if (address==NULL){
        newnode->num= num;
        newnode->xp = xp;
        newnode->yp = yp;
        newnode->next = NULL;
        

        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newnode;
    }
    else{
        address->num = address->num+num;
    }
}
}

void create(int no){
    for(int i =0; i<no; i++){
        insert();
        count++;
    }
}

void display(){
    node* temp = head;
    while(temp!= NULL){
        printf("%d*x^%d*y^%d +", temp->num, temp->xp, temp->yp);
        temp = temp->next;
    }
}


void main(){
    int num;
    printf("enter no of nodes:");
    scanf("%d", &num);
    create(num);
    display();

}
