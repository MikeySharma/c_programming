//Detect A Loop In LinkedList using Floyd's Cycle Finding Algorithm (Hare and Tortoise Algorithm) 

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data){
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    if(node == NULL){
        printf("Memory Allocation Failed.\n");
        return NULL;
    }

    node->next = NULL;
    node->data = data;

    return node;
}

void linkedListTraversal(struct Node *head){
    struct Node *ptr = head;
    
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
int detectLoop(struct Node *head){
    struct Node *tortoise = head;
    struct Node *hare = head;

    while(hare != NULL && hare->next != NULL){
        tortoise = tortoise->next;
        hare = hare->next->next;

        if(tortoise == hare){
            return 1;
        }
    }

    return 0;
}

int main() {
    // Creating a sample linked list: 1 -> 2 -> 3 -> 4 -> NULL
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);

    // Creating a loop for testing: 4 -> 2
    // head->next->next->next->next = head->next;

    

    if(detectLoop(head)){
        printf("Loop Detected in the linkedlist.\n");
    }else{
        printf("Loop Not Detected in the linkedlist.\n");
        printf("Original LinkedList: \n");
        linkedListTraversal(head);
    }

    free(head);

    return 0;
}