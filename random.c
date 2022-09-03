#include<stdlib.h>
#include<stdio.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;

}NODE;

typedef struct list
{   
    struct node *head;
    struct node *last;
}LIST;

NODE* createnode()
{
    NODE *newnode;
    newnode=(NODE*)malloc(sizeof(NODE));
    return newnode;
}

void ins(LIST* p){

    if(p->head ==NULL){
        p->head = createnode();
        int no;
        printf("enter number for first node\n");
        scanf("%d", &no);
        p->head->data = no;
        p->last = p->head;
        p->head->next = NULL;
        
    }
    else{
        NODE* newnode = createnode();
        int no;
        printf("enter number for next node \n");
        scanf("%d", &no);
        newnode->data = no;
        NODE* temp = p->head;

        if(no<=p->head->data){
            newnode->prev=NULL;
            newnode->next = p->head;
            p->head->prev = newnode;
            p->head = newnode;
        }

        else if(no>=p->last->data){
            newnode->prev = p->last;
            newnode->next = NULL;
            p->last->next = newnode;
            p->last = newnode;
        }

        else{
            while (temp->data<=no && temp!=NULL){
                temp = temp->next;
            }              
            newnode->next = temp;
            newnode->prev = temp->prev;
            temp->prev->next = newnode;
            temp->prev = newnode;
        }
    }
}

void display(LIST *p){
    NODE* temp;
    temp = p->head;
    if (p->head==NULL){
    	printf("\n the list is empty\n");
    }
    else{
	    while(temp!=NULL){
	    	printf("%d->",temp->data);
            temp= temp->next;
	        }
        printf("NULL\n");
    }
}

void freelist(LIST* q){
    NODE* qtemp = q->head;
    while(q->head!=NULL){
        q->head = q->head->next;
        qtemp->next =NULL;
        qtemp->prev=NULL;
        free(qtemp);
        qtemp = q->head;
    }
}

void merge(LIST *p, LIST *q){
    NODE* qtemp = q->head;
    int no;
    while(qtemp!=NULL){
    no = qtemp->data;

    if(p->head ==NULL){
        p->head = createnode();
        p->head->data = no;
        p->last = p->head;
        p->head->next = NULL;
        
    }
    else{
        NODE* newnode = createnode();
        newnode->data = no;
        NODE* temp = p->head;

        if(no<=p->head->data){
            newnode->prev=NULL;
            newnode->next = p->head;
            p->head->prev = newnode;
            p->head = newnode;
        }

        else if(no>=p->last->data){
            newnode->prev = p->last;
            newnode->next = NULL;
            p->last->next = newnode;
            p->last = newnode;
        }

        else{
            while (temp->data<=no && temp!=NULL){
                temp = temp->next;
            }              
            newnode->next = temp;
            newnode->prev = temp->prev;
            temp->prev->next = newnode;
            temp->prev = newnode;
            }
        }
    qtemp = qtemp->next;
    }
    freelist(q);
}

void create_list(LIST *p){
    int x;
    printf("enter no of elements to enter\n");
    scanf("%d", &x);
    printf("creating a list of size %d\n", x);
    p->head =NULL;
    p->last=NULL;
    printf("initialised list\n");
    
    for(int i =0; i<x; i++){
        ins(p);
    }
}

int main(){

    LIST list1, list2;
    create_list(&list1);
    printf("done creating list\n\n");
    create_list(&list2);
    printf("---before merging---\n");
    display(&list1);
    display(&list2);
    merge(&list1, &list2);
    printf("---after merging---\n");
    display(&list1);
    display(&list2);

    return 0;
}