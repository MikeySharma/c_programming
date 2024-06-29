#include <stdio.h>
#include <stdlib.h>

struct CircularQueue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct CircularQueue *q){
    if((q->r + 1) % q->size == q->f){
        return 1;
    }
    return 0;
}

int isEmpty(struct CircularQueue *q){
    if(q->r == -1 && q->f == -1){
        return 1;
    }
    return 0;
}

void enque(struct CircularQueue *q, int value){
    if(isFull(q)){
        printf("Queue is full.\n");
    }else{
        if(isEmpty(q)){
            q->r = q->f = 0;
        }else{
            q->r = (q->r + 1) % q->size;
        }
        q->arr[q->r] = value;
    }
}

int deque(struct CircularQueue *q){
    int dequeuedValue = -1;
    if(isEmpty(q)){
        printf("Queue is Empty.\n");
    }else{
        dequeuedValue = q->arr[q->f];
        if(q->r == q->f){
            //if the last element is dqueued, then reset the elements.
            q->r = q->f = -1;
        }else{
            q->f = (q->f + 1) % q->size;
        }

    }
    return dequeuedValue;
}

int peek(struct CircularQueue *queue, int value){
    int position = -1;
    if(!isEmpty(queue)){
        int i = queue->f;
        int count = 1;
        while (i != queue->r)
        {
            if(queue->arr[i] == value){
                position = count;
                break;
            }
            i = (i + 1) % queue->size;
            count++;
        }
        if(queue->arr[i] == value){
            position = count;
        }
        
    }
    return position;
}

int main() {
    struct CircularQueue q;
    q.size = 10;
    q.f = q.r = -1;
    q.arr = (int *)malloc(sizeof(int) * q.size);

    enque(&q, 23);
    enque(&q, 43);
    enque(&q, 24);

    printf("Element %d is dequeued From Queue.\n", deque(&q));
    printf("Element %d is dequeued From Queue.\n", deque(&q));

    enque(&q, 54);
    enque(&q, 65);

    printf("The position of element %d is %d.\n",54, peek(&q, 54));

    if(isEmpty(&q)){
        printf("Queue is Empty\n");
    }
    if(isFull(&q)){
        printf("Queue is Full.\n");
    }

    free(q.arr);
    return 0;
}