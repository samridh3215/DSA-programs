#include <stdlib.h>
#include <stdio.h>
#define max 10
int count = 0;
typedef struct Stack{
    int top;
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

s* create(s* pt){
    pt= (s*)malloc(sizeof(s));
    pt->top = -1; //top is element and pt is the pointer pointing at it
    printf("stack created\n");
    return pt;
    
}

int isfull(s* pt){
    if (pt->top == max-1){
        return 1;
        }
    else
        return 0;
}

int isempty(s* pt){
    if (pt->top == -1){
        printf("empty");
        return 1;
    }
    else
        return 0;
                    }

void push(s* pt){
    
    
    if (isfull(pt))
        printf("\nstack is full");
    else{
        int a;
        printf("enter number: ");
        scanf("%d", &a);
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

void peek(s* pt){
     if (isempty(pt))
        printf("\nstack is empty");
    else{
        printf("%d\n", pt->items[pt->top]);
}
}

void printstack(s* st){
    for(int i = 0; i<count; i++){
            printf("%d\n", st->items[i]);
}
}
int main(){
    s mystack;
    s* s_pointer;
    
    s_pointer = create(&mystack);
    int response;
    do{

        printf("0 to exit\n1. To push\n2. To pop\n3. To peek\n4. Print stack");
        scanf("%d", &response);
        switch (response)
        {
        case 0:
            break;
        
        case 1:
            push(s_pointer);
            break;
        case 2:
            pop(s_pointer);
            break;
        
        case 3:
            peek(s_pointer);
            break;
        case 4:
            printstack(s_pointer);
            break;
        }

    }while(response);
    return 0;
}