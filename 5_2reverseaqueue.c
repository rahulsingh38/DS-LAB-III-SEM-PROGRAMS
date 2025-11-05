//  Design an algorithm and write a program to reverse a queue.

#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

// Queue structure
struct Queue {
    int items[SIZE];
    int front, rear;
};

// Stack structure
struct Stack {
    int items[SIZE];
    int top;
};

// Queue operations
void initQueue(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isEmptyQueue(struct Queue *q) {
    return q->front == -1;
}

int isFullQueue(struct Queue *q) {
    return q->rear == SIZE - 1;
}

void enqueue(struct Queue *q, int value) {
    if (isFullQueue(q)) {
        printf("Queue is full!\n");
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->items[++q->rear] = value;
}

int dequeue(struct Queue *q) {
    if (isEmptyQueue(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int value = q->items[q->front++];
    if (q->front > q->rear)
        q->front = q->rear = -1;
    return value;
}
void initStack(struct Stack *s) {
    s->top = -1;
}

int isEmptyStack(struct Stack *s) {
    return s->top == -1;
}
int isFullStack(struct Stack *s) {
    return s->top == SIZE - 1;
}
void push(struct Stack *s, int value) {
    if (isFullStack(s)) {
        printf("Stack is full!\n");
        return;
    }
    s->items[++s->top] = value;
}

int pop(struct Stack *s) {
    if (isEmptyStack(s)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return s->items[s->top--];
}
void reverseQueue(struct Queue *q) {
    struct Stack s;
    initStack(&s);

 
    while (!isEmptyQueue(q)) {
        push(&s, dequeue(q));
    }

  
    while (!isEmptyStack(&s)) {
        enqueue(q, pop(&s));
    }
}
// Function to display queue
void display(struct Queue *q) {
    if (isEmptyQueue(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++)
        printf("%d ", q->items[i]);
    printf("\n");
}


int main() {
    struct Queue q;
    initQueue(&q);

    int n, val;
    printf("Enter number of elements in queue: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(&q, val);
    }

    printf("\nOriginal Queue:\n");
    display(&q);

    reverseQueue(&q);

    printf("\nReversed Queue:\n");
    display(&q);

    return 0;
}
