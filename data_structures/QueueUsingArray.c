#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int r;
    int f;
    int *arr;
};

int isFull(struct Queue *q){
    if(q->r == q->size-1){
        return 1;
    }
    return 0;
}
int isEmpty(struct Queue *q){
    if(q->r == q->f){
        return 1;
    }
    return 0;
}

void enque(struct Queue *q, int value){
    if(isFull(q)){
        printf("The Queue is Full.\n");
    }else{
        q->r++;
        q->arr[q->r] = value;
    }
}

int deque(struct Queue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("Queue is Empty.\n");
    }else{
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

int main() {
    struct Queue q;
    q.size = 10;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));


    enque(&q, 32);
    enque(&q, 23);
    printf("Element %d is Dequed.\n", deque(&q));
    // printf("Element %d is Dequed.\n", deque(&q));
    if(isEmpty(&q)){
        printf("Queue is Empty.\n");
    }
    if(isFull(&q)){
        printf("Queue is Full.\n");
    }
    free(q.arr);
    return 0;
}