#include<stdlib.h>
#include<stdio.h>

//Double Circ LL

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;

}NODE;

typedef struct list
{   
    int cnt;
    struct node *head;
    struct node *last;
}DCLL;

NODE *newnode,*t1,*t2;

DCLL* p;

void init(DCLL *p)
{
    p->cnt =0;
    p->head =NULL;
    p->last=NULL;


}

NODE* createnode(int no)
{
    newnode=(NODE*)malloc(sizeof(NODE));
    newnode->data = no;
    return newnode;
    
}

void ins_beg(DCLL *p,int no)
{
    newnode = createnode(no);
    if(p->head==NULL)
    {
        //newnode->next=newnode; can be done
        //newnode->prev = newnode;can be done
        p->head = newnode;
        p->last = newnode;
        p->head->prev = p->last;
        p->last->next = p->head;
        p->cnt++;
    }
    else{
        p->head->prev=newnode;
        newnode->next = p->head;
        p->head = newnode;
        p->head->prev = p->last;//change from Linear DLL
        p->last->next = p->head;//change from Linear DLL
        p->cnt++;

    }


}

void ins_end(DCLL *p, int no)
{

    newnode = createnode(no);
    if(p->head==NULL)
    {
        //newnode->next=newnode; can be done
        //newnode->prev = newnode;can be done
        p->head = newnode;
        p->last = newnode;
        p->head->prev = p->last;
        p->last->next = p->head;
        p->cnt++;
    }
    else{
        newnode = createnode(no);
        p->last->next=newnode;
        newnode->prev=p->last;
        p->last = newnode;
        p->head->prev = p->last;//change from Linear DLL
        p->last->next = p->head;//change from Linear DLL
        p->cnt++;
    }

}

void del_beg(DCLL *p)
{
    if(p->head==NULL)//empty list condition!
    {
        printf("Deletion cant be performed!!\n");

    }
    else if(p->head->next==p->head){
        t1=p->head;
        free(t1);
        p->head=NULL;
        p->last = NULL;
        p->cnt=0;


    }
    else{

        t1 =p->head;
        p->head = p->head->next;
        p->head->prev = p->last;
        p->last->next = p->head;//change from Linear DLL
        p->cnt--;
        t1->next = t1->prev = NULL;
        free(t1);
    }
}

void del_end(DCLL *p)
{
    if(p->head==NULL)//empty list condition!
    {
        printf("Deletion cant be performed!!\n");

    }
    else if(p->head->next==p->head){
        t1=p->head;
        free(t1);
        p->head=NULL;
        p->last = NULL;
        p->cnt=0;


    }
    else{
        t1=p->head;
        p->last = p->last->prev;
        p->last->next=p->head;//change from Linear DLL
        p->head->prev = p->last;//change from Lin DLL
        p->cnt--;
        t1->next = t1->prev = NULL;
        free(t1);
    }
}

void display(DCLL *p)
{
if (p->head==NULL)
{
	printf("\n the list is empty\n");
}
else
{
	t2 = p->head;
	printf("\n%d->",t2->data);
	while(t2->next !=p->head)
	{
		t2 = t2->next;
		printf("%d->",t2->data);
	}
	printf("NULL\n");
}

}
int main(){
    DCLL*mylist;
    mylist = (DCLL*)malloc(sizeof(DCLL));
    init(mylist);
    ins_beg(mylist,5);
    display(mylist);
    ins_end(mylist,10);
    display(mylist);
    del_beg(mylist);
    display(mylist);
    del_end(mylist);
    display(mylist);
    return 0;
}