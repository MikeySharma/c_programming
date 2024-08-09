//Finding LCA In C (Lowest Common Ancestor); - Mikey Sharma
#include <stdio.h>
#include <stdlib.h>

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
    node->right = NULL;
    node->left = NULL;

    return node;
}

void inOrderTraversal(struct Node *root){
    if(root != NULL){
        inOrderTraversal(root->left);
        printf("%d ", root->key);
        inOrderTraversal(root->right);
    }
}

struct Node *lowestCommonAncestor(struct Node *root, struct Node *p, struct Node *q){
    // Base case: if the root is NULL or matches one of the nodes (p or q), return root.
    if(root == NULL || root == p || root == q){
        return root;
    }

    // Recur for the left and right subtrees.
    struct Node *left = lowestCommonAncestor(root->left, p, q);
    struct Node *right = lowestCommonAncestor(root->right, p, q);

    // If both left and right are non-NULL, this root is the LCA.
    if(left != NULL && right != NULL){
        return root;
    }

     // Otherwise, return the non-NULL value from left or right.
     return left != NULL ? left : right;
}

int main() {

    // Example usage:
    struct Node* root = createNode(3);
    root->left = createNode(5);
    root->right = createNode(1);
    root->left->left = createNode(6);
    root->left->right = createNode(2);
    root->right->left = createNode(0);
    root->right->right = createNode(8);
    root->left->right->left = createNode(7);
    root->left->right->right = createNode(4);

    printf("In Order Traversal are: \n");
    inOrderTraversal(root);
    printf("\n");

    struct Node *p = root->left;
    struct Node *q = root->right;

    struct Node *lca = lowestCommonAncestor(root, p, q);

    if(lca != NULL){
        printf("Lowest Common Ancestor of %d and %d is %d.\n", p->key, q->key, lca->key);
    }else{
        printf("Lowest Common Ancestor Not Found.\n");
    }

    free(root);
    return 0;
}