#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void Traversal(struct Node *head){
    struct Node *p = head;
    do{
        printf("Element : %d and Address : %u\n",p->data, p );
        p = p->next;
    }while(p != head);

}

struct Node *DeleteHeadNode(struct Node *head){
    struct Node *p = head;
    while(p->next != head){
        p = p->next;
    }
    p->next = head->next;
    free(head);
    return p->next;
}

void DeleteLastNode(struct Node *head){
    struct Node *delNode = head->next;
    struct Node *prev = head;
    while(delNode->next != head){
        delNode = delNode->next;
        prev = prev->next;
    }
    prev->next = delNode->next;
    free(delNode);
}

void DeleteNodeAtIndex(struct Node *head, int index){
    struct Node *prevNode = head;
    struct Node *delNode = head->next;
    for (int i = 0; i < index -1; i++)
    {
        prevNode = prevNode->next;
        delNode = delNode->next;
    }
    prevNode->next = delNode->next;
    free(delNode);
}

int main() {
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *forth = (struct Node *)malloc(sizeof(struct Node));

    //Added Head data on Dynamically allocated memory;
    head->data = 43;
    head->next = second;

    second->data = 34;
    second->next = third;

    third->data = 45;
    third->next = forth;

    forth->data = 65;
    forth->next = head;

    //Traversal In Circular Linked List;
    // Traversal(head);
    // printf("Elements After Deleting Head Element\n");
    // head = DeleteHeadNode(head);
    // Traversal(head);

    //Delete Element At End;
    // Traversal(head);
    // printf("Elements After Deleting Last Element\n");
    // DeleteLastNode(head);
    // Traversal(head);

    //Delete Node At Index;
    Traversal(head);
    printf("Elements After Deleting Node At Index\n");
    DeleteNodeAtIndex(head, 2);
    Traversal(head);

    free(head);
    free(second);
    free(third);
    free(forth);

    return 0;
}