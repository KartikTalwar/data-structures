#include <stdio.h>
#include <stdlib.h>

#define STACK_MAX 10


struct Stack
{
    int data[STACK_MAX];
    int length;
};


typedef struct Stack Stack;

void init(Stack *);
void push(Stack *, int value);
int  pop(Stack *);
int  peek(Stack *);
int  empty(Stack *);


void push(Stack *S, int value)
{
    if(S->length < STACK_MAX)
    {
        S->data[S->length++] = value;
    }
}

int pop(Stack *S)
{
    if(S->length > 0)
    {
        return S->data[--S->length];
    }
    return -1;
}

int peek(Stack *S)
{
    if(S->length > 0)
    {
        return S->data[S->length - 1];
    }
    return -1;
}

int empty(Stack *S)
{
    return S->length <= 0;
}

void init(Stack *S)
{
    S->length = 0;
}


main()
{
    Stack *stk = malloc(1 * sizeof(Stack));

    init(stk);
    push(stk, 1);
    push(stk, 2);
    push(stk, 3);

    printf("Pop: %d\n", pop(stk));
    printf("Peek: %d\n", peek(stk));
    printf("Empty: %d\n", empty(stk));
}

