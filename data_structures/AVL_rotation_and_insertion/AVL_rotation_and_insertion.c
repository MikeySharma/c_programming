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

struct Node{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

int getHeight(struct Node *node){
    if(node == NULL) return 0;
    return node->height;
}

struct Node *createNode(int key){
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    if(node == NULL){
        printf("Memory Allocation Failed.");
        return NULL;
    }
    node->key = key;
    node->right = node->left = NULL;
    node->height = 1;

    return node;
}

int max(int a, int b){
    return a > b ? a : b;
}

struct Node *rotateRight(struct Node *y){
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    //perform rotations
    x->right = y;
    y->left =  T2;

    //update Heights;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    //return new root;
    return x;

}

struct Node *rotateLeft(struct Node *x){
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    //perform roatitions;
    y->left = x;
    x->right = T2;

    //update Heights;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
}

int getBalance(struct Node *node){
    if(node == NULL) return 0;

    return (getHeight(node->left) - getHeight(node->right));
}

struct Node *insert(struct Node *node, int key){
    //Normal BST Insertion 
    if(node == NULL) return createNode(key);
    
    if(key < node->key){
        node->left = insert(node->left, key);
    }else if(key > node->key){
        node->right = insert(node->right, key);
    }else{
        printf("Duplocate elements not Allowed in BST!");
        return node;
    }

    //update Height
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

    //get the balance factor of the node
    int balance = getBalance(node);

    //If BF becomes unbalanced then it becomes four cases
    
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

    //return the unchanged node
    return node;

}

void preOrder(struct Node *root){
    if(root != NULL){
        printf("%d, ", root->key);
        preOrder(root->left);
        preOrder(root->right);
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

    printf("PreOrder Traversal of AVL Tree :\n");
    preOrder(root);

    return 0;
}