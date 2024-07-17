#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data){
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    if(node == NULL){
        printf("Memory Allocation Failed!");
        return NULL;
    }
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

int main() {
    struct Node *p = createNode(1);
    struct Node *p1 = createNode(4);
    struct Node *p2 = createNode(8);

    p->left = p1;
    p->right = p2;

    free(p);
    free(p1);
    free(p2);
    return 0;
}