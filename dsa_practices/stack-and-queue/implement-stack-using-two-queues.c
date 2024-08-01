//Implement Stack using Two Queues

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int arr[MAX];
    int front, rear, size;
} Queue;

void initQueue(Queue *q){
    q->front = q->rear = q->size = 0;
}

int isEmpty(Queue *q){
    return (q->size == 0);
}

int isFull(Queue *q){
    return (q->size == MAX);
}

void enque(Queue *q, int value){
    if(isFull(q)){
        printf("Queue is Full.\n");
        return;
    }
    q->arr[q->rear] = value;
    q->rear++;
    q->size++;
}

int dequeu(Queue *q){
    int value = -1;
    if(isEmpty(q)){
        printf("Queue is Empty.\n");
        return value;
    }
    value = q->arr[q->front];
    q->front++;
    q->size--;

    return value;
}

typedef struct {
    Queue q1, q2;
} Stack;

void initStack(Stack *s){
    initQueue(&s->q1);
    initQueue(&s->q2);
}

void push(Stack *s, int value){
    enque(&s->q1, value);
}

int pop(Stack *s){
    if(isEmpty(&s->q1)){
        printf("Stack Underflow.\n");
        return -1;
    }

    while (s->q1.size > 1)
    {
        enque(&s->q2, dequeu(&s->q1));
    }
    int poppedValue = dequeu(&s->q1);

    //Swap the names of queue
    Queue temp = s->q1;
    s->q1 = s->q2;
    s->q2 = temp;

    return poppedValue;
}

int main() {
    Stack s;
    initStack(&s);

     push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Popped: %d\n", pop(&s));  // Should print 30
    printf("Popped: %d\n", pop(&s));  // Should print 20

    push(&s, 40);

    printf("Popped: %d\n", pop(&s));  // Should print 40
    printf("Popped: %d\n", pop(&s));  // Should print 10

    return 0;
}