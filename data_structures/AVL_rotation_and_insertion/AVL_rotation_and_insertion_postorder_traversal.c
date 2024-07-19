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

struct Node
{
    int key;
    int height;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int key){
    struct Node *node  = (struct Node *)malloc(sizeof(struct Node));
    if(node == NULL){
        printf("Memory Allocation Failed!");
        return NULL;
    }
    node->key = key;
    node->right = node->left = NULL;
    node->height = 1;

    return node;
}

int height(struct Node *node){
    if(node == NULL) return 0;

    return node->height;
}

int getBalance(struct Node *node){
    if(node == NULL) return 0;

    return height(node->left) - height(node->right);
}

int max(int a, int b){
    return a > b ? a : b;
}

struct Node *rotateRight(struct Node *y){
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    //perform rotation
    x->right = y;
    y->left = T2;

    //update height
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    //return new root;
    return x;

}

struct Node *rotateLeft(struct Node *x){
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    //perform rotation
    y->left = x;
    x->right = T2;


    //update heigh
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    //return new root;
    return y;
}

struct Node *insert(struct Node *node, int key){
    //perform normal BST Insertion
    if(node == NULL) return createNode(key);
    
    if(key < node->key){
        node->left = insert(node->left, key);
    }else if(key > node->key){
        node->right  = insert(node->right, key);
    }else{
        printf("Duplicate Elements Not Allowed!\n");
        return node;
    }

    //update height
    node->height = max(height(node->left), height(node->right)) + 1;

    //get balance factor
    int balance = getBalance(node);

    //Check different cases if balance factor becomes unbalance
    //Left Left Case
    if(balance > 1 && key < node->left->key){
        return rotateRight(node);
    }
    //Right Right Case
    if(balance < -1 && key > node->right->key){
        return rotateLeft(node);
    }

    //Left Right Case
    if(balance > 1 && key > node->left->key){
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    //Right Left Case
    if(balance < -1 && key < node->right->key){
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    //return an unchanged node
    return node;
}

void postOrder(struct Node *node){
    if(node != NULL){
        postOrder(node->left);
        postOrder(node->right);
        printf("%d ", node->key);
    }
}

int main() {

    struct Node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 25);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 60);

    printf("PostOrder Traversal of AVL Trees: \n");
    postOrder(root);

    return 0;
}