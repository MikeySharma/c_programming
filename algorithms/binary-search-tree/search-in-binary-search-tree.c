//Check the given binary tree is binary search tree or not.

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
        printf("Memory Allocation Failed.");
    }

    node->data = data;
    node->right = NULL;
    node->left = NULL;

    return node;
}

struct Node *search(struct Node *root, int key){
    if(root == NULL){
        return NULL;
    }
    if(root->data == key){
        return root;
    }else if(key < root->data){
        return search(root->left, key);
    }else{
        return search(root->right, key);
    }
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

    struct Node *n = search(root, 8);
    if(n != NULL){
        printf("Element Found : %d", n->data);
    }else{
        printf("Element Not Found!");
    }
    free(root);
    free(child1);
    free(child2);
    free(child3);
    free(child4);
    free(child5);
    free(child6);
    return 0;
}