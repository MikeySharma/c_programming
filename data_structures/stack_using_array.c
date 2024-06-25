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

int main() {
    struct Stack *s = (struct Stack*)malloc(sizeof(struct Stack));
    s->size = 30;                 
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    
    if(isEmpty(s)){
        printf("Array Is Empty.\n");
    }else {
        printf("Array isn't Empty.\n");
    }

    if(isFull(s)){
        printf("Array is Full.\n");
    }else{
        printf("Array is not full.\n");
    }

    free(s);
    free(s->arr);
    return 0;
}