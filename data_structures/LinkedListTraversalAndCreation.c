#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr);

int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *forth;
    struct Node *fifth;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    forth = (struct Node*)malloc(sizeof(struct Node));
    fifth = (struct Node*)malloc(sizeof(struct Node));

    //Linked First and Second node in dynamically allocated memory;
    head->data = 3;
    head->next = second;

    //linked second and third node
    second->data = 6;
    second->next = third;

    //linked third and forth node
    third->data = 8;
    third->next = forth;

    //linked forth and fifth node
    forth->data = 12;
    forth->next = fifth;

    //terminated linked list;
    fifth->data = 43;
    fifth->next = NULL;

    linkedListTraversal(head);

    free(head);
    free(second);
    free(third);
    free(forth);
    free(fifth);
    return 0;
}

void linkedListTraversal(struct Node *ptr){
    while(ptr != NULL){
        printf("Element : %d\nPointer Address: %u \n", ptr->data, ptr->next);
        ptr = ptr->next;
    }
}