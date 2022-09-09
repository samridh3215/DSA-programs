#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Stack {
	int top;
	int capacity;
	int* array;
};

struct Stack* createStack(int capacity)
{
	struct Stack* stack
		= (struct Stack*)malloc(sizeof(struct Stack));

	if (!stack)
		return NULL;

	stack->top = -1;
	stack->capacity = capacity;

	stack->array
		= (int*)malloc(stack->capacity * sizeof(int));

	return stack;
}

int isEmpty(struct Stack* stack)
{
	return (stack->top == -1);
}

char peek(struct Stack* stack)
{
	return (stack->array[stack->top]);
}

char pop(struct Stack* stack)
{
	if (!isEmpty(stack))
		return stack->array[stack->top--];
	return '%';
}

void push(struct Stack* stack, char op)
{
	stack->array[++stack->top] = op;
}

int isOperand(char ch)
{
	return (ch >= 'a' && ch <= 'z')|| (ch >= 'A' && ch <= 'Z')||(ch>='0' && ch<='9');
}

int Prec(char ch)
{
	switch (ch) {
	case '+':
	case '-':
		return 1;

	case '*':
	case '/':
		return 2;

	case '^':
		return 3;
	}
	return -1;
}

int infixToPostfix(char* exp)
{
	int i, k;

	struct Stack* stack = createStack(strlen(exp));
	if (!stack)
		return -1;

	for (i = 0, k = -1; exp[i]; ++i) {


		if (isOperand(exp[i]))
			exp[++k] = exp[i];

		else if (exp[i] == '(')
			push(stack, exp[i]);

		else if (exp[i] == ')') {
			while (!isEmpty(stack) && peek(stack) != '(')
				exp[++k] = pop(stack);
			if (!isEmpty(stack) && peek(stack) != '(')
				return -1; // invalid expression
			else
				pop(stack);
		}

		else 
		{
			while (!isEmpty(stack)
				&& Prec(exp[i]) <= Prec(peek(stack)))
				exp[++k] = pop(stack);
			push(stack, exp[i]);
		}
	}

	
	while (!isEmpty(stack))
		exp[++k] = pop(stack);

	exp[++k] = '\0';
	printf("%s", exp);
}

int infixToPrefix(char* exp){
    int i = 0;
    int k = -1;
    struct Stack* stack = createStack(strlen(exp));
    exp = strrev(exp);
    for(;exp[i];++i){
        if(isOperand(exp[i])) exp[++k] = exp[i];
        else if(exp[i] == ')') push(stack, exp[i]);
        else if(exp[i]=='('){
            while(!isEmpty(stack)&&peek(stack)!=')') exp[++k] = pop(stack);
            if(!isEmpty && peek(stack)!=')') return -1;
            else pop(stack);
        }
        else{
            while (!isEmpty(stack) && Prec(exp[i])<=Prec(peek(stack)))  exp[++k] = pop(stack);
            push(stack, exp[i]);
        }
    }
    while (!isEmpty(stack)) exp[++k] = pop(stack);
	exp[++k] = '\0';
	printf("%s", strrev(exp));
}

char evaluatePostfix(char *exp){
	struct Stack* stack = createStack(strlen(exp));
	int i = 0;
	for (;i<strlen(exp); ++i){
		if(isdigit(exp[i]))
			push(stack, exp[i]-'0');
		else{
			int val1 = pop(stack);
            int val2 = pop(stack);
            switch (exp[i]){
            case '+': push(stack, val2 + val1); break;
            case '-': push(stack, val2 - val1); break;
            case '*': push(stack, val2 * val1); break;
            case '/': push(stack, val2/val1); break;
		}
	}
	return pop(stack);
	}
}

int main(){

	char exp[] = "(6+8-1)";
	infixToPostfix(exp);
	
	printf("\n%d", evaluatePostfix(exp));
	
	return 0;

}
