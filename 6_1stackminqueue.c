//  Design an algorithm and write a program to implement stack operations using minimum number
//  of queues.

#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct {
    int arr[SIZE];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = q->rear = -1;
}

int isEmpty(Queue *q) {
    return q->front == -1;
}

int isFull(Queue *q) {
    return q->rear == SIZE - 1;
}

void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear++;
    }
    q->arr[q->rear] = value;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    int val = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return val;
}

int getSize(Queue *q) {
    if (isEmpty(q)) return 0;
    return q->rear - q->front + 1;
}

void push(Queue *q, int value) {
    enqueue(q, value);
    int size = getSize(q);
    for (int i = 0; i < size - 1; i++) {
        int temp = dequeue(q);
        enqueue(q, temp);
    }
}

void pop(Queue *q) {
    if (isEmpty(q)) {
        printf("Stack is empty\n");
        return;
    }
    int popped = dequeue(q);
    printf("Element popped from stack : %d\n", popped);
}

void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack - ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}
int main() {
    Queue q;
    initQueue(&q);
    int choice, value;
    while (1) {
        printf("\nPress:\n1 to push\n2 to pop\n3 to exit\n");
        scanf("%d", &choice);

        if (choice == 1) {
            scanf("%d", &value);
            push(&q, value);
            display(&q);
        } else if (choice == 2) {
            pop(&q);
            printf("Stack after pop operation :");
            display(&q);
        } else if (choice == 3) {
            break;
        } else {
            printf("Invalid choice\n");
        }
    }

    return 0;}
