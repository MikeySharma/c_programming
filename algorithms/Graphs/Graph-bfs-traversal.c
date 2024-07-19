#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int f;
    int r;
    int size;
    int *arr;
};

int isEmpty(struct Queue *ptr){
    if(ptr->f == ptr->r){
        return 1;
    }
    return 0;
}

int isFull(struct Queue *ptr){
    if(ptr->r >= ptr->size -1){
        return 1;
    }
    return 0;
}

void enque(struct Queue *q, int key){
    if(isFull(q)){
        printf("Queue is Full! Operation Failed.\n");
        exit(-1);
    }
    
    q->r++;
    q->arr[q->r] = key;
}

int dequeu(struct Queue *q){
    int value = -1;
    if(isEmpty(q)){
        printf("Queue is Empty! Operation Failed.\n");
    }
    q->f++;
    value = q->arr[q->f];
    return value;
}

void printQueue(struct Queue *q){
    for (int i = q->f; i <= q->r; i++)
    {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
    
}

int main() {
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->f = q->r = -1;
    q->size = 20;
    q->arr = (int *)malloc(q->size * sizeof(int));


    //BFS Implementation
    int node;  //node of the graphs
    int i = 2;
    int visited[8] = {0, 0, 0, 0, 0, 0, 0, 0};

    int adj[8][8] = {
        {0, 1, 1, 0, 0, 0, 0, 0},
        {1, 0, 1, 1, 0, 0, 0, 0},
        {1, 1, 0, 0, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 0, 0, 1},
        {0, 0, 0, 1, 0, 1, 1, 1},
        {0, 0, 1, 0, 1, 0, 1, 0},
        {0, 0, 0, 0, 1, 1, 0, 1},
        {0, 0, 0, 1, 1, 0, 1, 0}
    };
    enque(q, i);
    printf("%d ", i);
    visited[i] = 1;
    while(!isEmpty(q)){
        node = dequeu(q);
        for (int j = 0; j < 8; j++)
        {
            if(adj[node][j] == 1 && visited[j] == 0){
                printf("%d ", j);
                visited[j] = 1;
                enque(q, j);
            }
        }
        
    }
    //free memory location
    free(q->arr);
    free(q);

    return 0;
}