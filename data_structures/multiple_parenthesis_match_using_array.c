#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Stack {
    int size;
    int top;
    char *arr;
};
int isFull(struct Stack *ptr){
    if(ptr->size == ptr->top + 1){
        return 1;
    }
    return 0;
}

int isEmpty(struct Stack *ptr){
    if(ptr->top == -1){
        return 1;
    }
    return 0;
}

int push(struct Stack *ptr, char exp){
    if(isFull(ptr)){
        return 0;
    }
    ptr->top++;
    ptr->arr[ptr->top] = exp;
}

int pop(struct Stack *ptr, char exp){
    if(isEmpty(ptr)){
        return 0;
    }
    if(ptr->arr[ptr->top] != exp){
        return 0;
    }
    ptr->top--;
    return 1;
}

int multipleParenthesisCheck (char *exp){
    struct Stack *ptr = (struct Stack *)malloc(sizeof(struct Stack));
    if(ptr == NULL){
        printf("Memory Allocation Failed!.\n");
        return 0;
    }
    ptr->size = strlen(exp);
    ptr->top = -1;
    ptr->arr = (char *)malloc(ptr->size * sizeof(char));

    if(ptr->arr == NULL){
        printf("Memory Allocation Failed!.\n");
        return 0;
    }

    for (int i = 0; i < ptr->size; i++)
    {
        if(exp[i] == '[' || exp[i] == '{' || exp[i] == '('){
            push(ptr, exp[i]);
        }else if(exp[i] == ']' || exp[i] == '}' || exp[i] == ')'){
            if(exp[i] == ']'){
                if(!pop(ptr, '[')){
                    free(ptr->arr);
                    free(ptr);
                    return 0;
                }
            }else if(exp[i] == '}'){
                if(!pop(ptr, '{')){
                    free(ptr->arr);
                    free(ptr);
                    return 0;
                }
            }else if(exp[i] == ')'){
                if(!pop(ptr, '(')){
                    free(ptr->arr);
                    free(ptr);
                    return 0;
                }
            }
        }
    }
    if(!isEmpty(ptr)){
        free(ptr->arr);
        free(ptr);
        return 0;
    }
    free(ptr->arr);
    free(ptr);
    return 1;
}

int main() {
    char *exp = "[39+{2-32*(2-2)}]";
    int isMatch = multipleParenthesisCheck(exp);
    if(isMatch){
        printf("Multiple Parenthesis Matched Successfully!\n");
    }else{
        printf("Multiple Parenthesis Failed To Match!\n");
    }
    return 0;
}