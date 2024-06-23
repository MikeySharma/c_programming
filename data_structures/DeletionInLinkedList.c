#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void NodeTraversal(struct Node *ptr){
    while(ptr != NULL){
        printf("Node Element : %d, Node Address : %u \n", ptr->data, &ptr);
        ptr = ptr->next;
    }

}

struct Node *DeleteAtFirst(struct Node *head){
    struct Node *p = head;
    struct Node *q = head->next;
    free(p);
    return q;
}

struct Node *DeleteAtIndex(struct Node *head, int index){
    struct Node *p = head;
    struct Node *q = head->next;

    for (int i = 0; i < index; i++)
    {
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    free(q);
    return head;
}

struct Node *DeleteLastNode(struct Node *head){
    struct Node *p = head;
    struct Node *q = head->next;
    while(q->next != NULL){
        q = q->next;
        p = p->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

struct Node *DeleteNodeByValue(struct Node *head, int value){
    struct Node *p = head;
    struct Node *q = head->next;

    while(q->data != value){
        q = q->next;
        p = p->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

int main() {
    struct Node *head = (struct Node*)malloc(sizeof(struct Node));
    struct Node *second = (struct Node*)malloc(sizeof(struct Node));
    struct Node *third = (struct Node*)malloc(sizeof(struct Node));
    struct Node *forth = (struct Node*)malloc(sizeof(struct Node));

    //initialize Head in dynamically allocated memory or Heap Memory;
    head->data = 32;
    head->next = second;

    second->data = 34;
    second->next = third;

    third->data = 46;
    third->next = forth;

    forth->data = 354;
    forth->next = NULL;

    // head = DeleteAtFirst(head);
    // head = DeleteAtIndex(head, 1);
    // head = DeleteLastNode(head);
    head = DeleteNodeByValue(head, 34);
    NodeTraversal(head);

    return 0;
}