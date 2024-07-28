//Write A Program to reverse a Linked List
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
        printf("Memory Allocation Failed!\n");
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

struct Node *reverseLinkedList(struct Node *head){
    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
    return head;
    
}

int main() {
    struct Node *head = createNode(2);
    struct Node *p1 = createNode(4);
    struct Node *p2 = createNode(6);
    struct Node *p3 = createNode(8);
    struct Node *p4 = createNode(10);

    head->next = p1;
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    printf("Original LinkedList: \n");
    linkedListTraversal(head);

    head = reverseLinkedList(head);

    printf("Reversed LinkedList: \n");
    linkedListTraversal(head);

    free(head);
    free(p1);
    free(p2);
    free(p3);
    free(p4);
    return 0;
}