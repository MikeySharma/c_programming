#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *previous;
    struct Node *next;
};

struct Node *InsertAtBegining(struct Node *head, int data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    head->previous = ptr;
    ptr->next = head;
    ptr->data = data;
    ptr->previous = NULL;

    return ptr;
}

void InsertAtEnd(struct Node *head, int data){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;
    while(p->next != NULL){
        p = p->next;
    }
    ptr->previous = p;
    p->next = ptr;
    ptr->next = NULL;
}

void InsertAtIndex(struct Node *head, int data, int index){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;
    for (int i = 0; i < index -1; i++)
    {
        p = p->next;
    }
    ptr->previous = p;
    ptr->next = p->next;
    p->next = ptr;    
}

void Traversal(struct Node *head){
    struct Node *p = head;
    while(p != NULL){
        printf("Address : %u & Element : %d\n", p, p->data);
        p = p->next;
    }
}

int main() {
    struct Node *head = (struct Node*)malloc(sizeof(struct Node));
    struct Node *second = (struct Node*)malloc(sizeof(struct Node));
    struct Node *third = (struct Node*)malloc(sizeof(struct Node));
    struct Node *forth = (struct Node*)malloc(sizeof(struct Node));

    //Doubly LInked List Head in dynamically Allocated Memory or in Heap memory;
    head->previous = NULL;
    head->data = 43;
    head->next = second;

    second->previous = head;
    second->data = 42;
    second->next = third;

    third->previous = second;
    third->data = 32;
    third->next = forth;

    forth->previous = third;
    forth->data = 23;
    forth->next = NULL;

    //INsert At begining of Double Linked List in dynamically Allocated Memory or in Heap Memory;
    Traversal(head);
    // printf("Elements After Insrtion At Index.\n");
    // head = InsertAtBegining(head, 2);

    // printf("Elements After Insertion At End.\n");
    // InsertAtEnd(head, 54);

    printf("Elements After Insertion At Index.\n");
    InsertAtIndex(head, 54, 2);
    Traversal(head);


    free(head);
    free(second);
    free(third);
    free(forth);

    return 0;
}