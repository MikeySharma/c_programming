/* The constructed AVL Tree would be
              30
             /   \
            /     \
          20      50
         /  \    /  \
       10  25   40    60
    */


#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    int height;
    struct Node *left;
    struct Node *right;
};

int max(int a, int b){
    return a > b ? a : b;
}

int getHeight(struct Node *node){
    if(node == NULL) return 0;
    return node->height;
}

int getBalance(struct Node *node){
    if(node == NULL) return 0;

    return (getHeight(node->left) - getHeight(node->right));
}

struct Node *createNode(int key){
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    if(node == NULL){
        printf("Memory Allocation Failed!");
        return NULL;
    }
    node->key = key;
    node->right = node->left = NULL;
    node->height = 1;

    return node;
}

struct Node *rightRotate(struct Node *y){
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    //perform rotation
    x->right = y;
    y->left = T2;

    //update Height
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    //return new root;
    return x;
}

struct Node *leftRotate(struct Node *x){
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    //perform rotation
    y->left = x;
    x->right = T2;

    ///update Height
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    //return new root;

    return y;
}

struct Node *insert(struct Node *node, int key){
    //perform normal BST Insertion
    if(node == NULL) return createNode(key);

    if(key < node->key){
        node->left = insert(node->left, key);
    }else if(key > node->key){
        node->right = insert(node ->right, key);
    }else{
        printf("Duplicate Elements Not Allowed In BST!");
        return node;
    }

    //update Height
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

    //check for balance factor
    int balance = getBalance(node);

    //check for different cases if balance is not stable

    //Left Left Case
    if(balance > 1 && key < node->left->key){
        return rightRotate(node);
    }
    //Right Right Case
    if(balance < -1 && key > node->right->key){
        return leftRotate(node);
    }
    //Left Right Case
    if(balance > 1 && key > node->left->key){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    //Right Left Case
    if(balance < -1 && key < node->right->key){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    //Return an unchanged node
    return node;
}

void inOrder(struct Node *root){
    if(root != NULL){
        inOrder(root->left);
        printf("%d, ", root->key);
        inOrder(root->right);
    }
}

int main() {
    struct Node *root = NULL;
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 10);
    root = insert(root, 25);
    root = insert(root, 50);
    root = insert(root, 60);

    printf("Inorder Traversal of AVL Tree : \n");
    inOrder(root);

    return 0;
}