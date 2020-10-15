#include <stdio.h>
#define max 10

int stack[max];
int top = -1;

void push(int x);
void pop();
void peek();

int main() {
    int i = 1, op = 0, x = 0;
    while (i) {
        printf("Enter operation : \n");
        printf("1. Push\n2. Pop\n3. Peek\n0. Exit\n");
        scanf("%d", &op);
        if (op == 0) {
            break;
        }
        else if (op == 1) {
            printf("Enter element to push : ");
            scanf("%d", &x);
            push(x);
        }
        else if (op == 2) {
            pop();
        }
        else if (op == 3) {
            peek();
        }
        else {
            printf("Enter a valid choice.\n");
        }
    }
}

void push(int x) {
    if (top == max - 1) {
        printf("Stack is full, cannot push %d\n", x);
        return;
    }
    top++;
    stack[top] = x;
    printf("Insertion Successful\n");
}

void pop() {
    if (top == -1) {
        printf("Stack is empty, cannot pop\n");
        return;
    }
    printf("%d popped successfully\n",stack[top]);
    top--;
}

void peek() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Element at top : %d\n", stack[top]);

}
