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

struct Node *createNode(int data){
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    if(node == NULL){
        printf("Memory Allocation Failed.\n");
    }
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void inOrderTraversal(struct Node *root){
    if(root != NULL){
        inOrderTraversal(root->left);
        printf("%d, ", root->data);
        inOrderTraversal(root->right);
    }
}

void deletion(struct Node *root, int key){
    struct Node *prev = NULL;
   while (root != NULL && root->data != key)
   {
        prev = root;
        if(key < root->data){
            root = root->left;
        }else{
            root = root->right;
        }
   }

   if(root == NULL){
    printf("\nKey %d Not Found in BST.\n", key);
    exit(-1);
   }
   if(key < prev->data){
    prev->left = NULL;
   }else{
    prev->right = NULL;
   }
   free(root);
}

int main() {
    struct Node *root = createNode(10);
    struct Node *child1 = createNode(4);
    struct Node *child2 = createNode(11);
    struct Node *child3 = createNode(2);
    struct Node *child4 = createNode(6);
    struct Node *child5 = createNode(5);
    struct Node *child6 = createNode(8);

    root->left = child1;
    root->right = child2;

    child1->left = child3;
    child1->right = child4;
    
    child4->left = child5;
    child4->right = child6;

    printf("Original Binary Search Tree: \n");
    inOrderTraversal(root);

    deletion(root, 11);
    deletion(root, 6);

    printf("\nBinary Search Tree After Deletion: \n");
    inOrderTraversal(root);

    free(root);
    free(child1);
    free(child2);
    free(child3);
    free(child4);
    free(child5);
    free(child6);
    return 0;
}