//Merge Two Sorted Linked List

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

void linkedlistTraversal(struct Node *head){
    struct Node *current = head;
    while(current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

struct Node *mergeLinkedList(struct Node *head1, struct Node *head2){
    struct Node dummy;
    struct Node *tail = &dummy;
    dummy.next = NULL;

    while(head1 != NULL && head2 != NULL){
        if(head1->data <= head2->data){
            tail->next = head1;
            head1= head1->next;
        }else{
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }
    if(head1 != NULL){
        tail->next = head1;
    }else{
        tail->next = head2;
    }

    return dummy.next;
}

int main() {
    struct Node *head1 = createNode(2);
    head1->next = createNode(3);
    head1->next->next = createNode(4);
    head1->next->next->next = createNode(5);

    struct Node *head2 = createNode(1);
    head2->next = createNode(6);
    head2->next->next = createNode(7);
    head2->next->next->next = createNode(9);

    printf("LinkedList 1: \n");
    linkedlistTraversal(head1);

    printf("LinkedList 2: \n");
    linkedlistTraversal(head2);

    struct Node *head = mergeLinkedList(head1, head2);

    printf("Merged LinkedList: \n");
    linkedlistTraversal(head);


    free(head1);
    free(head2);
    return 0;
}