/*
                10
              /   \
             4     11
           /  \  
          2   6  
             / \
            5   8
*/


#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int value){
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = value;
    node->right = node->left = NULL;
    
    return node;
}

struct Node *inOrderSuccess(struct Node *root){
    struct Node *current = root;

    while(current && current->left != NULL){
        current  = current->left;
    }

    return current;
}

int main() {
    struct Node *root;
    root = createNode(10);
    root->left = createNode(4);
    root->right = createNode(11);
    root->left->left = createNode(2);
    root->left->right = createNode(6);
    root->left->right->left = createNode(5);
    root->left->right->right = createNode(8);


    struct Node *inOrder = inOrderSuccess(root);

    if(inOrder){
        printf("The value of Inorder Sucess is : %d\n", inOrder->data);
    }

    
    return 0;
}