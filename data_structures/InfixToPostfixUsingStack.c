#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct Stack *ptr){
    if(ptr->top == -1)
        return 1;
    else 
        return 0;
}

int isOperator(char exp){
    if(exp == '+' || exp == '-' || exp == '*' || exp == '/')
        return 1;
    else
        return 0;
}

char stackTop(struct Stack *ptr){
    return ptr->arr[ptr->top];
}

int prec(char exp){
    if(exp == '/' || exp == '*'){
        return 3;
    }else if(exp == '+' || exp == '-'){
        return 2;
    }
    return 1;
}

void push(struct Stack *ptr, char exp){
    ptr->top++;
    ptr->arr[ptr->top] = exp;
}

char pop(struct Stack *ptr){
    if(isEmpty(ptr)){
        exit(0);
    }
    char topValue = stackTop(ptr);
    ptr->top--;
    return topValue;
}

char *infixToPostfix(char *infix){
    struct Stack *sp = (struct Stack *)malloc(sizeof(struct Stack));
    sp->size = strlen(infix) + 1;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char *postfix = (char *)malloc(sp->size * sizeof(char));
    int i = 0, j = 0;
    while (infix[i] != '\0')
    {
        if(!isOperator(infix[i])){
            postfix[j] = infix[i];
            j++;
        }else{
            while(!isEmpty(sp) && prec(stackTop(sp)) >= prec(infix[i])){
                postfix[j] = pop(sp);
                j++;
            }
            push(sp, infix[i]);
        }
        i++;
    }
    while(!isEmpty(sp)){
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    free(sp->arr);
    free(sp);
    return postfix;
    
}

int main() {
    char infix[] = "A * B + C * D";
    char *postfix = infixToPostfix(infix);
    printf("The prefix of infix %s is : %s.\n", infix, postfix);
    free(postfix);
    return 0;
}