//Find The Starting Point of the loop in linkedlist

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
    node->data = data;
    node->next = NULL;

    return node;
}

void linkedListTraversal(struct Node *head){
    struct Node *current = head;
    while(current != NULL){
        printf("%d ",current->data);
        current = current->next;
    }
    printf("\n");
}

struct Node *detectHeadOfLoop(struct Node *head){
    struct Node *slow = head;
    struct Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            struct Node *start = head;
            while (start != slow)
            {
                start = start->next;
                slow = slow->next;
            }

            return start;
        }
    }
    return NULL;
}
int main() {
    // Creating a sample linked list: 1 -> 2 -> 3 -> 4 -> NULL
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);

    // Creating a loop for testing: 4 -> 2
    head->next->next->next->next = head->next;

    struct Node *loopHead = detectHeadOfLoop(head);

    if(loopHead){
        printf("Loop Start From %d.\n", loopHead->data);
    }else{
        printf("No Loop Detected in the linked list.\n");
        printf("Original Linked List: \n");
        linkedListTraversal(head);
    }
    free(head);
    return 0;
}