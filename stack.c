#include <stdlib.h>
#include <stdio.h>
#define max 10
#include <stdbool.h>
int count = 0;
typedef struct Stack{
    int topa;
    int items[max];
}s;
/*Functions of stack
Create
isEmpty
isFull
Push
Pop
PrintStack
Seek*/

void create(s* pt){
    pt->top = -1; //top is element and pt is the pointer pointing at it
    printf("stack created");
}

int isfull(s* pt){
    if (pt->top == max-1){
        printf("full");
        return true;
        }
    else
        return false;
}

int isempty(s* pt){
    if (pt->top == -1){
        printf("empty");
        return true;
    }
    else
        return false;
                    }

void push(s* pt,int a){
    if (isfull(pt))
        printf("stack is full");
    else{
    pt->top++;
    pt->items[pt->top] = a;

        }
        count++;
                        }

void pop(s* pt){
    if (isempty(pt))
        printf("stack is empty");
    else{
        pt->top--;
        count--;
        printf("popped!");
    }

                        }
int seek(s* pt){
     if (isempty(pt))
        printf("stack is empty");
    else{
        printf("%d", pt->items[pt->top]);
}
}
void printstack(s* st){
    for(int i = 0; i<count; i++){
            printf("%d\n", st->items[i]);
}
}
int main(){
    s* mystack = (s*)malloc(sizeof(s));

    create(mystack);
    printf("\n");
    isempty(mystack);
    push(mystack, 232);
    printf("\n");
    push(mystack, 324);
    printf("\n");
    push(mystack, 23);
    printf("\n");
    push(mystack, 69);
    printf("\n");
    seek(mystack);
    printf("\n");
    pop(mystack);
    printf("\n");
    printstack(mystack);


    return 0;
}