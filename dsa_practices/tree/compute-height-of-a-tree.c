//Compute Height of a Tree.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int key){
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    if(!node){
        printf("Memory Allocation Failed.\n");
        return NULL;
    }

    node->key = key;
    node->left = node->right = NULL;

    return node;
}

void preOrderTraversal(struct Node *root){
    if(root != NULL){
        printf("%d ", root->key);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

int height(struct Node *root){
    if(root == NULL) return -1;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if(leftHeight > rightHeight){
        return (leftHeight + 1);
    }else{
        return (rightHeight + 1);
    }
}

int main() {
    struct Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Pre-Order Traversal Are: \n");
    preOrderTraversal(root);

    printf("\nThe Height Of Tree is: %d.\n", height(root));

    free(root);
    return 0;
}