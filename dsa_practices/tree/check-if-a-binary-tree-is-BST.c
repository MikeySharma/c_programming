//Check the given Binary tree is BST (Binary Search Tree) or Not.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int key){
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    if(node == NULL){
        printf("Memory Allocation Failed.\n");
        return NULL;
    }

    node->key = key;
    node->right = node->left = NULL;
    return node;
}

void inOrderTraversal(struct Node *root){
    if(root != NULL){
        inOrderTraversal(root->left);
        printf("%d ", root->key);
        inOrderTraversal(root->right);
    }
}

int isBSTUtil(struct Node *node, int min, int max){
    if(node == NULL) return 1;

    if(node->key <= min || node->key >= max){
        return 0;
    }

    return (isBSTUtil(node->left, min, node->key) && isBSTUtil(node->right, node->key, max));
}

int isBST(struct Node *root){
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main() {

    // //Example Of Non BST
    // struct Node *root = createNode(1);
    // root->left = createNode(2);
    // root->right = createNode(3);
    // root->left->left = createNode(4);
    // root->left->right = createNode(5);
    // root->right->left = createNode(6);
    // root->right->right = createNode(7);

    //Example of BST 
    struct Node* root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(5);
    root->left->left = createNode(1);
    root->left->right = createNode(3);

    printf("In Order Traversal are : \n");
    inOrderTraversal(root);
    printf("\n");

    if(isBST(root)){
        printf("The Given Binary Tree is A Binary Search Tree(BST).\n");
        
    }else{
        printf("The Given Binary Tree is Not A Binary Search Tree(BST).\n");
    }
    free(root);
    return 0;
}