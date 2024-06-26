#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
    int size;
    int top;
    char *arr;
};

int isEmpty(struct Stack *ptr){
    if(ptr->top == -1){
        return 1;
    }
    return 0;
}

int isFull(struct Stack *ptr){
    if(ptr->top + 1 == ptr->size){
        return 1;
    }
    return 0;
}

int push(struct Stack *sp, char exp){
    if(isFull(sp)){
        return -1;
    }
    sp->top ++;
    sp->arr[sp->top] = exp;
}

int pull(struct Stack *ptr){
    if(isEmpty(ptr)){
        return 0;
    }
    ptr->top--;
    return 1;
}

int parenthesisMatch(char *exp){
    struct Stack *sp = (struct Stack *)malloc(sizeof(struct Stack));
    sp->size = strlen(exp);
    sp->top = -1;
    sp->arr = (char *)malloc(sizeof(char) * sp->size);
    for (int i = 0; i < sp->size; i++)
    {
        if(exp[i] == '('){
            push(sp, exp[i]);
        }else if(exp[i] == ')'){
            if(!pull(sp)){
                return 0;
            }
        }
    }
    if(isEmpty(sp)){
        free(sp->arr);
        free(sp);
        return 1;
    }else{
        free(sp->arr);
        free(sp);
        return 0;
    }

}

int main() {
    char *exp = "(3*2+(2/2))";
    int isMatched =  parenthesisMatch(exp);
    if(isMatched){
     printf("Parenthesis Matched Successfully!\n");
    }else{
     printf("Parenthesis Matched Failed!\n");
    }
    return 0;
}