//Check For balanced Parenthesis - Mikey Sharma
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int top;
    int *arr;
    int size;
} Stack;

int isEmpty(Stack *s){
    return (s->top == -1);
}

int isFull(Stack *s){
    return (s->top == s->size - 1);
}

void push(Stack *s, int key){
    if(isFull(s)){
        printf("Stack Overflow.\n");
        return;
    }
    s->arr[++s->top] = key;
}

int isOpenParenthesis(char paren){
    return (paren == '[' ||  paren == '{'  || paren == '(');
}

int isCloseParenthesis(char paren){
    return(paren == ']' || paren == '}' || paren == ')');
}

int isParenthesisMatched(char paren1, char paren2){
    if(paren1 == '[' && paren2 == ']'){
        return 1;
    }else if(paren1 == '{' && paren2 == '}'){
        return 1;
    }else if(paren1 == '('  && paren2 == ')'){
        return 1;
    }
    return 0;
}

int pop(Stack *s){
    if(isEmpty(s)){
        printf("Stack Underflow.\n");
        return -1;
    }
    int value = s->arr[s->top];
    s->top--;

    return value;
}

int isBalanced(char *str){
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int *)malloc(sizeof(int) * s->size);
    for(int i = 0; str[i] != '\0'; i++){
        if(isOpenParenthesis(str[i])){
            push(s, str[i]);
        }else if(isCloseParenthesis(str[i])){
            if(!isParenthesisMatched(pop(s), str[i])){
                return 0;
            }
        }
    }

    if(!isEmpty(s)){
        return 0;
    }

    return 1;
    
}

int main() {
    char str[] = "[2x+{(3y-4)/2}-2]";

    if(isBalanced(str)){
        printf("String \" %s \" Parenthesis is Balanced.\n", str);
    }else{
        printf("String \" %s \" Parenthesis is not Balanced.\n", str);
    }

    return 0;
}