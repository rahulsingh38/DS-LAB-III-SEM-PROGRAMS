// Design an algorithm and write a program to implement circular queue. Circular queue is a queue
//  in which last position of queue is connected with first position of queue to make a circle. The
//  program should implement following operations:
//  a) Create() - create a queue of specific size
//  b)EnQueue(k) - insert an element k into the queue
//  c) DeQueue() - delete an element from the queue
//  d)IsEmpty() - check if queue is empty or not
//  e) Front() - return front item from queue
//  f) Rear() - return rear item from queue

#include <stdio.h>
#include <stdlib.h>

struct CircularQueue {
    int front, rear, size, capacity;
    int *arr;
};

struct CircularQueue* createQueue(int capacity) {
    struct CircularQueue* q = (struct CircularQueue*) malloc(sizeof(struct CircularQueue));
    q->capacity = capacity;
    q->front = -1;
    q->rear = -1;
    q->size = 0;
    q->arr = (int*) malloc(q->capacity * sizeof(int));
    return q;
}

int isEmpty(struct CircularQueue* q) {
    return (q->size == 0);
}

int isFull(struct CircularQueue* q) {
    return (q->size == q->capacity);
}

void enQueue(struct CircularQueue* q, int value) {
    if (isFull(q)) {
        printf("Queue is Full! Cannot insert %d\n", value);
        return;
    }
    if (q->front == -1)  // first element
        q->front = 0;
    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear] = value;
    q->size++;
    printf("Inserted: %d\n", value);
}

void deQueue(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is Empty! Cannot delete.\n");
        return;
    }
    int deleted = q->arr[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    printf("Deleted: %d\n", deleted);
    if (q->size == 0) {  
        q->front = -1;
        q->rear = -1;
    }
}

void Front(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is Empty!\n");
        return;
    }
    printf("Front : %d\n", q->arr[q->front]);
}

void Rear(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is Empty!\n");
        return;
    }
    printf("Rear : %d\n", q->arr[q->rear]);
}

void display(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Circular Queue : Empty\n");
        return;
    }
    printf("Circular Queue : ");
    int i = q->front;
    for (int count = 0; count < q->size; count++) {
        printf("%d ", q->arr[i]);
        i = (i + 1) % q->capacity;
    }
    printf("\n");
}

int main() {
    int size, choice, value;
    printf("Enter size of circular queue : ");
    scanf("%d", &size);

    struct CircularQueue* q = createQueue(size);

    while (1) {
        printf("\nPress:\n");
        printf("1 to Enqueue\n");
        printf("2 to Dequeue\n");
        printf("3 to Find Front\n");
        printf("4 to Find Rear\n");
        printf("5 to Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enQueue(q, value);
                display(q);
                break;
            case 2:
                deQueue(q);
                display(q);
                break;
            case 3:
                Front(q);
                break;
            case 4:
                Rear(q);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
