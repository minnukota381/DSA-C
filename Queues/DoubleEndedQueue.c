#include <stdio.h>

#define MAX 5  

int deque[MAX];
int front = -1;
int rear = -1;

int isEmpty() {
    return front == -1;
}

int isFull() {
    return (front == 0 && rear == MAX - 1) || (front == rear + 1);
}

void insertFront(int value) {
    if (isFull()) {
        printf("Deque Overflow! Cannot insert %d at the front.\n", value);
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else if (front == 0) {
        front = MAX - 1;
    } else {
        front--;
    }
    deque[front] = value;
    printf("%d inserted at the front.\n", value);
}

void insertRear(int value) {
    if (isFull()) {
        printf("Deque Overflow! Cannot insert %d at the rear.\n", value);
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }
    deque[rear] = value;
    printf("%d inserted at the rear.\n", value);
}

int deleteFront() {
    if (isEmpty()) {
        printf("Deque Underflow! Cannot delete from the front.\n");
        return -1;
    }
    int deletedValue = deque[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
    return deletedValue;
}

int deleteRear() {
    if (isEmpty()) {
        printf("Deque Underflow! Cannot delete from the rear.\n");
        return -1;
    }
    int deletedValue = deque[rear];
    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = MAX - 1;
    } else {
        rear--;
    }
    return deletedValue;
}

void display() {
    if (isEmpty()) {
        printf("Deque is empty.\n");
        return;
    }
    printf("Deque elements: ");
    int i = front;
    while (i != rear) {
        printf("%d ", deque[i]);
        i = (i + 1) % MAX;
    }
    printf("%d ", deque[rear]);
    printf("\n");
}

int main() {
    insertRear(10);
    insertRear(20);
    insertFront(30);
    insertFront(40);

    display();

    printf("%d deleted from the front.\n", deleteFront());
    printf("%d deleted from the rear.\n", deleteRear());

    display();

    return 0;
}
