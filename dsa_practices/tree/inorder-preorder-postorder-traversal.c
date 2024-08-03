//Implement Inorder PreOrder and PostOrder Traversal in a tree

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
        printf("Memory Allocation Failed.\n");
        return NULL;
    }
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void preOrderTraversal(struct Node *root){
    if(root != NULL){
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void inOrderTraversal(struct Node *root){
    if(root != NULL){
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

void postOrderTraversal(struct Node *root){
    if(root != NULL){
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Pre Order Traversal Of Given Tree Is: \n");
    preOrderTraversal(root);

    printf("\nIn Order Traversal of Given Tree is: \n");
    inOrderTraversal(root);


    printf("\nPost Order Traversal Of Given Tree is: \n");
    postOrderTraversal(root);

    return 0;
}