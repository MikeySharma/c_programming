//Implement Stack Using Array

#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int top;
    int size;
    int *arr;
};

int isEmpty(struct Stack *stack){
    if(stack->top == -1){
        return 1;
    }
    return 0;
}
int isFull(struct Stack *stack){
    if(stack->top == stack->size - 1){
        return 1;
    }
    return 0;
}

void push(struct Stack *stack, int key){
    if(isFull(stack)){
        printf("Stack Is Full. Cannot push %d.\n", key);
    }else{
    stack->top++;
    stack->arr[stack->top] = key;
    }
}

int pop(struct Stack *stack){
    int value = -1;
    if(isEmpty(stack)){
        printf("Stack is Empty.\n");
    }else{
        value = stack->arr[stack->top];
        stack->top--;
    }
    return value;
}

void stackTraversal(struct Stack *stack){
    struct Stack tempStack = *stack;
    while(tempStack.top != -1){
        printf("%d ", tempStack.arr[tempStack.top]);
        tempStack.top--;
    }
    printf("\n");
}
int main() {
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->size = 10;
    stack->top = -1;
    stack->arr = (int *)malloc(stack->size * sizeof(int));

    push(stack, 2);
    push(stack, 4);
    push(stack, 6);
    push(stack, 8);
    push(stack, 10);
    
    printf("Stack Before Pop: \n");
    stackTraversal(stack);
    
    printf("Poped %d from stack.\n", pop(stack));

    printf("Stack After Pop: \n");
    stackTraversal(stack);

    free(stack);
    free(stack->arr);
    return 0;
}