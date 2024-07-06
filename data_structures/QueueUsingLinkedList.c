#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int data;
    struct Queue *next;
};


struct Queue *f = NULL;
struct Queue *r = NULL;

int isFull(struct Queue *ptr){
    if(ptr == NULL){
        return 1;
    }
    return 0;
}

int isEmpty(){
    if(f == r){
        return 1;
    }
    return 0;
}

void TransverseQueue(struct Queue *head){
    struct Queue *ptr = head;
    printf("Printing Elements: \n");
    while (ptr != NULL)
    {
        printf("Element : %d \n", ptr->data);
        ptr = ptr->next;
    }
    
}

void enque(int value){
    struct Queue *n = (struct Queue *)malloc(sizeof(struct Queue));
    if(isFull(n)){
        printf("Queue Full.\n");
    }else{
        n->data = value;
        n->next = NULL;
        if(f == NULL){
            f = r = n;
        }else{
            r->next = n;
            r = n;
        }
    }
}

int deque(){
    int value = -1;
    struct Queue *ptr = f;
    if(isEmpty()){
        printf("Queue Is Empty.\n");
    }else{
        f = f->next;
        value = f->data;
        free(ptr);
    }
    return value;
}

int peek(int value){
    int position = 0;
    if(isEmpty()){
        printf("Queue is Empty.\n");
        return -1;
    }
    struct Queue *ptr = f;
    while(ptr->data != value && ptr->next != NULL){
        position++;
        ptr = ptr->next;
    }
    if(ptr->next == NULL){
        if(ptr->data == value){
            position++;
            return position;
        }else{
            return -1;
        }
    }
    position++;
    return position;

}

int main() {
    enque(12);
    enque(14);
    enque(16);
    enque(126);
    enque(163);
    TransverseQueue(f);
    printf("The position of %d is %d.\n", 16, peek(16));
    deque();
    deque();
    TransverseQueue(f);
    free(f);
    free(r);
    return 0;
}