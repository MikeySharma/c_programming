//DEQueue means Double Ended Queue
//Array

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int size;
    int *arr;
};

struct Queue
{
    int front;
    int rear;
};

int isEmpty(struct Queue *queue){
    if(queue->front == -1 || queue->front > queue->rear){
        return 1;
    }
    return 0;
}

int isFull(struct Node *ptr, struct Queue *queue){
    if(queue->rear == ptr->size - 1){
        return 1;
    }
    return 0;
}

void enqueR(struct Node *ptr, struct Queue *queue, int value){
    if(isFull(ptr, queue)){
        printf("Queue is Full. Failed enqeuef %d\n", value);
    }else{
        if(queue->front == -1){
            queue->front++;
        }
        queue->rear++;
        ptr->arr[queue->rear] = value;
    }
}

void enqueF(struct Node *node, struct Queue *queue, int value){
    if(isFull(node, queue)){
        printf("Queue is Full. Failed EnqueF of %d\n", value);
    }else{
        if(isEmpty(queue)){
            queue->front++;
            queue->rear++;
        }else{
            int lastPos = queue->rear;
            while (lastPos != queue->front - 1)
            {
                node->arr[lastPos + 1] = node->arr[lastPos];
                lastPos--;
            }
            queue->rear++;
        }
            node->arr[queue->front] = value;
    }
}

int dequeuF(struct Node *node, struct Queue *queue){
    int value = -1;
    if(isEmpty(queue)){
        printf("Queue is Empty. Failed Execution of DequeuR.\n");
    }else{
        value = node->arr[queue->front];
        queue->front++;
        if(queue->front > queue->rear){
            queue->front = queue->rear = -1;
        }
    }
    return value;
}

int dequeuR(struct Node *node, struct Queue *queue){
    int value = -1;
    if(isEmpty(queue)){
        printf("Queue is Empty. Failed Execution of dequeuR.\n");
        return value;
    }
    value = node->arr[queue->rear];
    queue->rear--;
    if(queue->front > queue->rear){
        queue->front = queue->rear = -1;
    }

    return value;
}

void transverseArray(struct Node *ptr, struct Queue *queue){
    if(isEmpty(queue)){
        printf("Queue is Empty. Can't Execute Transverse Function.\n");
        exit(-1);
    }
    printf("Printing Elements of Queue.\n");
    for (int i = queue->front; i <= queue->rear; i++)
    {
        printf("Elements : %d.\n", ptr->arr[i]);
    }
    
}

int main() {
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    if(q == NULL || node == NULL){
        printf("Memory Allocation Failed.\n");
    }
    q->front = q->rear = -1;
    node->size = 10;
    node->arr = (int *)malloc(sizeof(int) * node->size);
    if(node->arr == NULL){
        printf("Memory Allocation Failed.\n");
    }

    if(isEmpty(q)){
        printf("Queue is Empty.\n");
    }

    enqueR(node, q, 12);
    enqueR(node, q, 22);
    enqueR(node, q, 32);
    enqueR(node, q, 42);
    transverseArray(node, q);
    printf("DqueuedF of element %d.\n", dequeuF(node, q));
    printf("DqueuedR of element %d.\n", dequeuR(node, q));
    enqueF(node, q, 67);
    transverseArray(node, q);


    //free dynamically allocated memory.
    free(node->arr);
    free(node);
    free(q);

    return 0;
}