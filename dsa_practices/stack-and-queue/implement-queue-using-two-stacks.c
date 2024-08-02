//Implement Queue Using Two Stacks

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int arr[MAX];
    int top;
} Stack;

int isFull(Stack *s){
    return (s->top == MAX - 1);
}

int isEmpty(Stack *s){
    return (s->top == -1);
}

void initStack(Stack *s){
    s->top = -1;
}

void push(Stack *s, int key){
    if(isFull(s)){
        printf("Stack Overflow.\n");
        return;
    }
    s->top++;
    s->arr[s->top] = key;
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

typedef struct {
    Stack s1, s2;
}Queue;

void initQueue(Queue *q){
    initStack(&q->s1);
    initStack(&q->s2);
}

void enqueue(Queue *q, int key){
    push(&q->s1, key);
}

int dequeue(Queue *q){
    if(isEmpty(&q->s1) && isEmpty(&q->s2)){
        printf("Queue is Empty.\n");
        return -1;
    }
    if(isEmpty(&q->s2)){
        while (!isEmpty(&q->s1))
        {
            push(&q->s2, pop(&q->s1));
        }
    }

    return (pop(&q->s2));
    
}

void stackTraversal(Stack *s){
    Stack tempS = *s;
    while (tempS.top >= 0)
    {
        printf("%d ", tempS.arr[tempS.top--]);
    }
    printf("\n");
    
}

int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);


    printf("Dequeued: %d\n", dequeue(&q));  // Should print 10
    printf("Dequeued: %d\n", dequeue(&q));  // Should print 20

    enqueue(&q, 40);

    printf("Dequeued: %d\n", dequeue(&q));  // Should print 30
    printf("Dequeued: %d\n", dequeue(&q));  // Should print 40

    return 0;
}