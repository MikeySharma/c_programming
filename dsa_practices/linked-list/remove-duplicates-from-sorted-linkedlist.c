//Remove Duplicates from sorted linkedlist

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
    node->data = data;
    node->next = NULL;

    return node;
}

void linkedlistTraversal(struct Node *head){
    struct Node *current = head;
    while(current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void removeDuplicates(struct Node *head){
    struct Node *prev = head;
    struct Node *current = head->next;

    while (current != NULL)
    {
        if(prev->data == current->data){
            current = current->next;
            free(prev->next);
            prev->next = current;
        }else{
            current= current->next;
            prev = prev->next;
        }
    }
    
}

int main() {
    struct Node *head = createNode(2);
    head->next = createNode(2);
    head->next->next = createNode(4);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(6);
    head->next->next->next->next->next = createNode(8);

    printf("Original LinkedList: \n");
    linkedlistTraversal(head);

    removeDuplicates(head);
    
    printf("Removed Duplicates From LinkedList: \n");
    linkedlistTraversal(head);
    free(head);
    return 0;
}