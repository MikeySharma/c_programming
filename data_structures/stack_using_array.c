#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int size;
    int top;
    int *arr;
};

int isEmpty(struct Stack *ptr){
    if(ptr->top == -1){
        return 1;
    }
    return 0;
}

int isFull(struct Stack *ptr){
    if(ptr->top == (ptr->size - 1)){
        return 1;
    }
    return 0;
}

int push(struct Stack *ptr, int value){
    if(isFull(ptr)){
        printf("Stack Overflow. Can't push %d Value in stack.\n", value);
        return -1;
    }else{
        ptr->top ++;
        ptr->arr[ptr->top] = value;
        return ptr->top;
    }
}

int pop(struct Stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow.\n");
        return -1;
    }else{
        int value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}

int peek(struct Stack *ptr, int i){
    if((ptr->top - i + i ) <= 0){
        printf("Not a valid position in the Stack.\n");
        return -1;
    }
    return ptr->arr[ptr->top - i + 1];

}

void displayArray(struct Stack *arr){
    for (int i = 0; i <= arr->top; i++)
    {
        printf("%d \n",arr->arr[i]);
    }
}

int stackTop(struct Stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow!");
        return -1;
    }
    return ptr->arr[ptr->top];
}

int stackBottom(struct Stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow!");
        return -1;
    }
    return ptr->arr[0];
}

int main() {
    struct Stack *s = (struct Stack*)malloc(sizeof(struct Stack));
    s->size = 10;                 
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    push(s, 34);
    push(s, 54);
    push(s, 54);
    push(s, 54);
    push(s, 65);
    push(s, 64);
    push(s, 65);
    // printf("Elements of Stack Are:\n");
    // displayArray(s);
    // int popValue = pop(s);
    // if(popValue >= 0){
    //     printf("The value %d is poped from Stack.\n", popValue);
    // }
    printf("Elements of Stack After pop function.\n");
    for (int i = 1; i <= s->top + 1; i++)
    {
        printf("The element of position %d is %d.\n", i, peek(s, i));
    }

    printf("The top Element of The stack is: %d\n", stackTop(s));
    printf("The Bottom element of the stack is: %d\n", stackBottom(s));
    
    // displayArray(s);
    free(s);
    free(s->arr);
    return 0;
}