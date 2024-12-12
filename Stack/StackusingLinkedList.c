#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* initializeStack() {
    return NULL;
}

int isEmpty(struct Node* top) {
    return top == NULL;
}

void push(struct Node** top, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
    printf("%d pushed onto the stack.\n", value);
}

int pop(struct Node** top) {
    if (isEmpty(*top)) {
        printf("Stack Underflow! Cannot pop.\n");
        return -1;
    }
    struct Node* temp = *top;
    int poppedValue = temp->data;
    *top = temp->next;
    free(temp);
    return poppedValue;
}

int peek(struct Node* top) {
    if (isEmpty(top)) {
        printf("Stack is empty.\n");
        return -1;
    }
    return top->data;
}

void display(struct Node* top) {
    if (isEmpty(top)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    struct Node* temp = top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* stack = initializeStack();

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    push(&stack, 50);

    display(stack);

    printf("%d popped from the stack.\n", pop(&stack));

    printf("Top element is %d.\n", peek(stack));

    display(stack);

    pop(&stack);
    pop(&stack);
    pop(&stack);
    pop(&stack);

    pop(&stack);

    return 0;
}
