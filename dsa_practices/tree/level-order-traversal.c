//Level Order Traversal In Tree

#include <stdio.h>
#include <stdlib.h>

struct Node {
    char key;
    struct Node *left;
    struct Node *right;
};

struct Queue {
    struct Node **arr;
    int front;
    int rear;
    int size;
};

int isEmpty(struct Queue *q){
    return (q->rear == -1);
}

int isFull(struct Queue *q){
    return (q->rear == q->size);
}

struct Queue *initQueue(int size){
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->size = size;
    q->rear = -1;
    q->front = 0;
    q->arr = (struct Node **)malloc(sizeof(struct Node *) * q->size);

    return q;
}

void enqueue(struct Queue *q, struct Node  *node){
    if(isFull(q)){
        printf("Can't enqueue %c! Queue is Full.\n", node->key);
        return;
    }
    q->arr[++q->rear] = node;
}

struct Node *dequeue(struct Queue *q){
    if(isEmpty(q)){
        printf("Can't Dequeue! Queue is Empty.\n");
        return NULL;
    }
    return q->arr[q->front++];
}


struct Node *createNode(char key){
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    if(node == NULL){
        printf("Memory Allocation failed.\n");
        return NULL;
    }

    node->key = key;
    node->right = NULL;
    node->left = NULL;

    return node;
}

void inOrderTraversal(struct Node *root){
    if(root != NULL){
        inOrderTraversal(root->left);
        printf("%c ", root->key);
        inOrderTraversal(root->right);
    }
}

void levelOrderTraversal(struct Node *root){
    if(root == NULL) return;
    struct Queue *q = initQueue(15);

    enqueue(q, root);

    while (!isEmpty(q))
    {
        struct Node *node = dequeue(q);
        printf("%c ", node->key);
        if(node->left != NULL){
            enqueue(q, node->left);
        }
        if(node->right != NULL){
            enqueue(q, node->right);
        }

    }
    free(q->arr);
    free(q);
}
int main() {
    struct Node *root = createNode('F');
    root->left = createNode('D');
    root->right = createNode('J');
    root->left->left = createNode('B');
    root->left->right = createNode('E');
    root->left->left->left = createNode('A');
    root->left->left->right = createNode('C');
    root->right->left = createNode('G');
    root->right->right = createNode('K');
    root->right->left->right = createNode('I');
    root->right->left->right->left = createNode('H');



    printf("InOrder Traversal Are : \n");
    inOrderTraversal(root);

    printf("\nLevel Order Traversal Are: \n");
    levelOrderTraversal(root);

    free(root);
    return 0;
}