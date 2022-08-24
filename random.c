#include <stdio.h>
#include <stdlib.h>
#define max 50

typedef struct arrlist{
    int a[max];
    int index;
}arrlist;

void init(arrlist *p){
    p->index = -1;
}

int append(arrlist *p, int data){
    if(p->index == max-1)
        return 0;
    p->index++;
    p->a[p->index] = data;
    return 1;
}

int dellist(arrlist *p){
    if(p->index==-1)
        return 0;
    int *ptrdata;
    *ptrdata = p->a[p->index];
    p->index--;
    return 1;
}

void display(arrlist *p){
    for(int i =0; i<=p->index; i++){
        printf("%d\n", p->a[i]);
    }
}

void main(){
    arrlist mylist;
    init(&mylist);
    int choice, res, ele;
    do{
        printf("1. Append, 2. Delete Last, 3. Display\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: printf("enter");
                scanf("%d", &ele);
                append(&mylist, ele);
                break;

        case 2: dellist(&mylist);
        break;
        
        case 3: display(&mylist);
                break;
        
        }
    }while(choice<4);
}