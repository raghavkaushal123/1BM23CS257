#include <stdio.h>
#define N 3

int queue[N];
int front = -1, rear = -1;

int isFull() {
    return (front == (rear + 1) % N);
}

int isEmpty() {
    return (front == -1);
}

void enqueue(int value) {
    if (isFull()) {
        printf("\nQueue is full\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % N;
        queue[rear] = value;
    }
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        printf("Dequeued: %d\n", queue[front]);
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % N;
        }
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        int i = front;
        while (1) {
            printf("%d ", queue[i]);
            if (i == rear) break;
            i = (i + 1) % N;
        }
        printf("\n");
    }
}

int main() {
    int choice = 0, x;
    printf("1. Enqueue\n 2. Dequeue\n 3. Display\n 4. Exit\n");

    while (choice != 4) {
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to be inserted:\n");
                scanf("%d", &x);
                enqueue(x);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
