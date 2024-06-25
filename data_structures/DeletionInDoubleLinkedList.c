#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *previous;
    struct Node *next;
};

void Traversal(struct Node *head){
    struct Node *p = head;
    while(p != NULL){
        printf("Address : %u, & Element : %d\n", p, p->data);
        p = p->next;
    }
}

struct Node *DeleteHeadNode(struct Node *head){
    head->next->previous = NULL;
    struct Node *newHead = head->next;
    free(head);
    return newHead;
}

void DeleteLastNode(struct Node *head){
    struct Node *p = head;
    while(p->next != NULL){
        p = p->next;
    }
    p->previous->next = NULL;
    free(p);
}

void DeleteNodeAtIndex(struct Node *head, int index){
    struct Node *p = head;
    for (int i = 0; i < index; i++)
    {
        p = p->next;
    }
    p->previous->next = p->next;
    p->next->previous = p->previous;
    free(p);
}

int main() {
    struct Node *head = (struct Node*)malloc(sizeof(struct Node));
    struct Node *second = (struct Node*)malloc(sizeof(struct Node));
    struct Node *third  = (struct Node*)malloc(sizeof(struct Node));
    struct Node *forth = (struct Node*)malloc(sizeof(struct Node));

    //LInked Head in Doubly LInked List in dynamically allocated memory or in Heap memory;
    head->previous = NULL;
    head->data = 43;
    head->next = second;

    second->previous = head;
    second->data = 45;
    second->next = third;

    third->previous = second;
    third->data = 46;
    third->next = forth;

    forth->previous = third;
    forth->data = 54;
    forth->next = NULL;

    Traversal(head);
    // printf("Elements After Deleting First Node.\n");
    // head = DeleteHeadNode(head);

    // printf("Elements After Deleting Last Node.\n");
    // DeleteLastNode(head);

    printf("Elements AFter Deleting Node At Index\n");
    DeleteNodeAtIndex(head, 2);
    Traversal(head);

    free(head);
    free(second);
    free(third);
    free(forth);
    return 0;
}