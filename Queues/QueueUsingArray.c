#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

int isEmpty() {
    return front == -1;
}

int isFull() {
    return rear == MAX - 1;
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow! Cannot enqueue %d\n", value);
        return;
    }
    if (front == -1) {
        front = 0;
    }
    queue[++rear] = value; 
    printf("%d enqueued to the queue.\n", value);
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! Cannot dequeue.\n");
        return -1;
    }
    int dequeuedValue = queue[front];
    if (front == rear) {
        front = rear = -1; 
    } else {
        front++;  
    }
    return dequeuedValue;
}

int peek() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return -1;
    }
    return queue[front];  
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    display();

    enqueue(60);

    printf("%d dequeued from the queue.\n", dequeue());

    printf("Front element is %d.\n", peek());

    display();

    dequeue();
    dequeue();
    dequeue();
    dequeue();

    dequeue();

    return 0;
}
