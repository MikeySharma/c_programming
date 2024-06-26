#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
int isEmpty(struct Node *top){
    if(top == NULL){
        printf("Stack Underflow!\n");
        return 1;
    }
    return 0;
}

int isFull(){
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if(n == NULL){
        printf("Stack Overflow!\n");
        free(n);
        return 1;
    }
    free(n);
    return 0;
}
struct Node *push(struct Node *top, int data){
    if(isFull()){
        printf("Can't Push %d value.\n", data);
    }else{
        struct Node *n = (struct Node *)malloc(sizeof(struct Node));
        n->next = top;
        n->data = data;
        top = n;
        return top;
    }
}

struct Node *pop(struct Node *top){
    if(isEmpty(top)){
        printf("Can't pop Element.\n");
    }else{
        struct Node *n = top;
        int value = top->data;
        top = top->next;
        free(n);
        printf("Element %d is poped from Stack!\n", value);
        return top;

    }
}

void linkedListTraversal(struct Node *ptr){
    struct Node *n = ptr;
    while(n != NULL){
        printf("Element : %d \n", n->data);
        n = n->next;
    }
}

int linkedListPeek(struct Node *ptr, int position){
    struct Node *n = ptr;
    for (int i = 0; i < (position - 1) && ptr != NULL; i++)
    {
        ptr = ptr->next;
    }
    if(ptr == NULL){
        return -1;
    }
    return ptr->data;

}

int stackTop(struct Node *top){
    if(isEmpty(top)){
        return -1;
    }else{
        return top->data;
    }
}

int stackBottom(struct Node *top){
    if(isEmpty(top)){
        return -1;
    }
    struct Node *ptr = top;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    return ptr->data;
}

int main() {
    struct Node *top = NULL;
    top = push(top, 54);
    top = push(top, 34);
    top = push(top, 89);
    top = push(top, 23);
    printf("Elements of Stack before pop function.\n");
    linkedListTraversal(top);

    // top = pop(top);
    // top = pop(top);

    //display data of linked list stack
    printf("Elements of Stack After pop function.\n");
    linkedListTraversal(top);

    printf("Peek function of Stack.\n");
    printf("Element of position 2 is %d\n", linkedListPeek(top, 2));

    printf("Element of Stack Top is %d\n", stackTop(top));

    printf("Element of Stack Bottom is %d\n", stackBottom(top));

    free(top);
    free(top->next);
    free(top->next->next);
    return 0;
}