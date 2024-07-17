// Post-Order Binary Tree Traversal In C Program

/*
                1
              /   \
             7     9
           /  \   /
          2   6   5
             / \
            5   11  
*/


#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data){
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    if(node == NULL){
        printf("Memory Allocation Failed In Heap Memory!");
    }
    node->data = data;
    node->right = NULL;
    node->left = NULL;

    return node;
}

void postOrder(struct Node *root){
    if(root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d, ", root->data);
    }
}

int main() {

    struct Node *root = createNode(1);
    struct Node *child1 = createNode(7);
    struct Node *child2 = createNode(9);
    struct Node *child3 = createNode(2);
    struct Node *child4 = createNode(6);
    struct Node *child5 = createNode(5);
    struct Node *child6 = createNode(5);
    struct Node *child7 = createNode(11);


    root->left = child1;
    root->right = child2;

    child2->left = child5;

    child1->left = child3;
    child1->right = child4;


    child4->left = child6;
    child4->right = child7;

    postOrder(root);

    free(root);
    free(child1);
    free(child2);
    free(child3);
    free(child4);
    free(child5);
    free(child6);
    free(child7);

    return 0;
}