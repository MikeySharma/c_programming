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

struct Node *minValueNode(struct Node *root){
    struct Node *current = root;
    while(current && current->left != NULL){
        current = current->left;
    }
    return current;
}

struct Node *deleteNode(struct Node *root, int value){
    if(root == NULL){
        return NULL;
    }
    //recur down the tree
    if(value < root->data){
        root->left = deleteNode(root->left, value);
    }else if(value > root->data){
        root->right = deleteNode(root->right, value);
    }else{
        //Node With only one child or no child
        if(root->left == NULL){
            struct Node *temp = root->right;
            free(root);
            return temp;
        }else if(root->right == NULL){
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        struct Node *temp = minValueNode(root->right);
        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }

    return root;
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

    deleteNode(root, 10);

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