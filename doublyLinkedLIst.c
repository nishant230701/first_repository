#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* prev;
    struct node* next;
} node;

void printList(node* head);
void pushFront(node** headPtr, int data);
void append(node** headPtr, int data);
void insertAfter(node* head, int data, int key);
void insertBefore(node* head, int data, int key);

int main() {
    node* head = (node*)malloc(sizeof(node));
    head = NULL;
    printList(head);
    pushFront(&head, 1);
    append(&head, 2);
    insertAfter(head, 3, 2);
    insertAfter(head, 4, 3);
    printList(head);

    return 0;
}

void printList(node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void pushFront(node** headPtr, int data) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = *headPtr;
    *headPtr = newNode;
}

void append(node** headPtr, int data) {
    node* newNode = (node*)malloc(sizeof(node));
    node* p = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    if (*headPtr == NULL) {
        *headPtr = newNode;
        return;
    }
    p = *headPtr;
    while (p->next != NULL)
        p = p->next;
    p->next = newNode;
    newNode->prev = p;
}

void insertAfter(node* head, int data, int key) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    while (head != NULL && head->data != key)
        head = head->next;
    if (head == NULL) {
        printf("%d is not found in the list\n", key);
        return;
    }
    newNode->next = head->next;
    newNode->prev = head;
    head->next = newNode;
    if (newNode->next != NULL)
        newNode ->next->prev = newNode;

}
