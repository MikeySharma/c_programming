//Implement Queue using Array
#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int rear;
    int front;
    int size;
    int *arr;
};

int isFull(struct Queue *q){
    if(q->rear == q->size - 1){
        return 1;
    }
    return 0;
}

int isEmpty(struct Queue *q){
    if(q->rear == q->front){
        return 1;
    }
    return 0;
}

void enque(struct Queue *q, int key){
    if(isFull(q)){
        printf("Queue is full.\n");
    }else{
        if(q->front == -1){
            q->front++;
        }
        q->rear++;
        q->arr[q->rear] = key;
    }
}

int dequeue(struct Queue *q){
    int value = -1;
    if(isEmpty(q)){
        printf("Queue is Empty.\n");
    }else{
        value = q->arr[q->front];
        q->front++;
    }
    return value;
}

void queueTraversal(struct Queue *q){
    for (int i = q->front; i <= q->rear; i++)
    {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main() {
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->rear = q->front = -1;
    q->size = 10;
    q->arr = (int *)malloc(q->size * sizeof(int));


    enque(q, 2);
    enque(q, 4);
    enque(q, 6);
    enque(q, 8);
    enque(q, 10);

    printf("Original Queue\n");
    queueTraversal(q);

    dequeue(q);
    dequeue(q);

    printf("Queue After Deque.\n");
    queueTraversal(q);

    free(q->arr);
    free(q);

    return 0;
}