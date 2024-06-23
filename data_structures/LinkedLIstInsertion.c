#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr){
    while (ptr != NULL)
    {
        printf("Element %d. \n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node * insertAtStart(struct Node*head, int value){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = value;
    ptr->next = head;

    return ptr;
}

struct Node *insertAtIndex(struct Node *head, int value, int index){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;

    while(i != (index -1)){
        p = p->next;
        i++;
    }
    ptr->data = value;
    ptr->next = p->next;
    p->next = ptr;

    return head;
}

struct Node *insertAtEnd(struct Node *head, int data){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;

    while(p->next != NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;

    return head;
}

struct Node *insertAfterNode(struct Node *prevNode, int data){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;

}

int main() {
    struct Node *head = (struct Node*)malloc(sizeof(struct Node));
    struct Node *second = (struct Node*)malloc(sizeof(struct Node));
    struct Node *third = (struct Node*)malloc(sizeof(struct Node));
    struct Node *forth = (struct Node*)malloc(sizeof(struct Node));

    //initialize head in dynamically located memory;
    head->data = 32;
    head->next = second;

    //link second and third linked list;
    second->data = 34;
    second->next = third;

    //link third and forth linked list;
    third->data = 36;
    third->next = forth;

    //terminate linked list;
    forth->data = 54;
    forth->next = NULL;

    //display linked list;
    // linkedListTraversal(head);
    // printf("Linked List After Insertion At Head.\n");

    //insert At Index 0 or Head;
    // head = insertAtStart(head, 89);

    //display linked list after adding element at Head;
    // linkedListTraversal(head);
    // head = insertAtIndex(head, 80, 3);
    // linkedListTraversal(head);

    //display linked list after adding element at End;
    // head = insertAtEnd(head, 79);
    // linkedListTraversal(head);

    //display linked list after node ;
    insertAfterNode(third, 67);
    linkedListTraversal(head);
    //free allocated memory in heap memory;
    free(head);
    free(second);
    free(third);
    free(forth);

    return 0;
}