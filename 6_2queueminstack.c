//  Design an algorithm and write a program to implement queue operations using minimum number
//  of stacks.

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
    int arr[MAX];
    int top;
} stack;

void push(stack *s, int val) {
    if (s->top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    s->arr[++(s->top)] = val;
}

int pop(stack *s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
        return -1;  
    }
    return s->arr[(s->top)--];
}

int isEmpty(stack *s) {
    return s->top == -1;
}

void enqueue(stack *s1, int val) {
    push(s1, val);
}

int dequeue(stack *s1, stack *s2) {
    if (isEmpty(s2)) {
        while (!isEmpty(s1)) {
            int val = pop(s1);
            push(s2, val);
        }
    }
    if (isEmpty(s2)) {
        printf("Queue underflow\n");
        return -1;
    }
    return pop(s2);
}

int main() {
    stack s1, s2;
    s1.top = -1;
    s2.top = -1;

    int choice, val, dq;

    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                enqueue(&s1, val);
                printf("%d enqueued.\n", val);
                break;

            case 2:
                 dq = dequeue(&s1, &s2);
                if (dq != -1) {
                    printf("Dequeued: %d\n", dq);
                }
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (1);

    return 0;}
