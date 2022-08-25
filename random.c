#include <stdio.h>
#include <stdlib.h>
#define max 50

typedef struct vararr{
    int *a;
    int index;
    int size;
}VARLIST;

void init(VARLIST *p){
    p->index = -1;
    p->size = 0;
}

void array_alloc(VARLIST *p){
    if(p->size == 0){
        p->a = (int *)malloc(max*sizeof(int));
        p->size = max;
    }
    else if(p->index ==p->size-1){
        p->a = (int *)realloc(p->a, 2*(p->size)*sizeof(int));
        p->size = 2*(p->size);
    }
}

int append(VARLIST *p, int data){
    array_alloc(p);
    if(p->index == p->size-1)
        return 0;
    p->index++;
    p->a[p->index] = data;
    return 1;
}

int delete(VARLIST *p, int *pdata){
    if(p->index == -1)
        return 0;
    *pdata = p->a[p->index];
    p->index--;
    return 1;
}

void display(VARLIST *p){
    if(p->index == -1)
        printf("list is empty");
    else{
        for(int i = 0; i<p->index;  i++){
            printf("%d\n", p->a[i]);
        }
    }
}

void main(){
    VARLIST mylist;
    init(&mylist);
    int choice, res, ele, *a;
    do{
        printf("1. Append, 2. Delete Last, 3. Display\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: printf("enter");
                scanf("%d", &ele);
                append(&mylist, ele);
                break;

        case 2: delete(&mylist, a);
        break;
        
        case 3: display(&mylist);
                break;
        
        }
    }while(choice<4);
}