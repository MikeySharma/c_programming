#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void circularLinkedListTraversal (struct Node *head){
    struct Node *ptr = head;
    do
    {
        printf("Element is %d.\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    
}

struct Node *InsertAtFirst(struct Node *head, int data){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head->next;

    while(p->next != head){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;

    return head;

}

int main() {
    struct Node *head = (struct Node*)malloc(sizeof(struct Node));
    struct Node *second = (struct Node*)malloc(sizeof(struct Node));
    struct Node *third = (struct Node*)malloc(sizeof(struct Node));
    struct Node *forth = (struct Node*)malloc(sizeof(struct Node));

    //link first and second node in dynamically allocated memory or Heap Memory;
    head->data = 4;
    head->next = second;

    //link second and third node;
    second->data = 3;
    second->next = third;

    //link third and forth node;
    third->data = 6;
    third->next = forth;

    //link forth and head node;
    forth->data = 1;
    forth->next = head;

    //circularLinkedList Traversal
    circularLinkedListTraversal(head);
    printf("Elements After Insertion in Circular Linked List\n");
    head = InsertAtFirst(head, 54);
    head = InsertAtFirst(head, 58);
    circularLinkedListTraversal(head);
    
    free(head);
    free(second);
    free(third);
    free(forth);

    return 0;
}