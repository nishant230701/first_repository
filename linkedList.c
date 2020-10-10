#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

void printList(node* head);
void pushFront(node** headPtr, int data);
void append(node** headPtr, int data);
void insertAfter(node* head, int data, int key);
void insertBefore(node* head, int data, int key);
void isEmpty(node* head);

int main() {
    node* head = (node*)malloc(sizeof(node));
    head = NULL;
    pushFront(&head, 1);
    pushFront(&head, 2);
    append(&head, 3);
    printList(head);
    insertAfter(head, 4, 3);
    insertBefore(head, 6, 1);
    printList(head);

}

void printList(node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    node* p = (node*)malloc(sizeof(node));
    p = head;
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
}

void insertAfter(node* head, int data, int key) {
    node* p = (node*)malloc(sizeof(node));
    node* newNode = (node*)malloc(sizeof(node));
    p = head;
    while (p != NULL && p->data != key)
        p = p->next;
    if (p == NULL) {
        printf("The element %d was not found in the list\n", key);
        return;
    }
    newNode->data = data;
    newNode->next = p->next;
    p->next = newNode;
}

void insertBefore(node* head, int data, int key) {
    node* p = (node*)malloc(sizeof(node));
    node* newNode = (node*)malloc(sizeof(node));
    p = head;
    while (p->next->data != key && p != NULL)
        p = p->next;
    newNode->data = data;
    newNode->next = p->next;
    p->next = newNode;
}

void isEmpty(node* head) {
    if (head == NULL) {
        printf("The list is empty\n");
        return;
    }
    printf("The list is not empty\n");
}
