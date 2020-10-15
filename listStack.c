#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

void push(node** headPtr, int x) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = x;
    newNode->next = *headPtr;
    *headPtr = newNode;
    printf("Successfully pushed %d\n", x);
}

void pop(node** headPtr) {
    if (*headPtr == NULL) {
        printf("Stack is empty\n");
        return;
    }
    *headPtr = (*headPtr)->next;
}

void peek(node* head) {
    if (head == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Top element : %d\n", head->data);
}

int main() {
    node* head = (node*)malloc(sizeof(node));
    head = NULL;
    int i = 1, op = 0, x = 0;
    while (i) {
        printf("\nEnter operation : \n");
        printf("1. Push\n2. Pop\n3. Peek\n0. Exit\n");
        scanf("%d", &op);
        switch (op) {
            case 0:
                i = 0;
                break;
            case 1:
                printf("Enter element to push : ");
                scanf("%d", &x);
                push(&head, x);
                break;
            case 2:
                pop(&head);
                break;
            case 3:
                peek(head);
                break;
            default:
                printf("Incorrect option entered. Enter again\n");
        }
    }
}
