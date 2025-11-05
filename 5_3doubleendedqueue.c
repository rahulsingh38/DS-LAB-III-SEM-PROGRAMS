// Design an algorithm and write a program to implement Deque i.e. double ended queue. Double
//  ended queue is a queue in which insertion and deletion can be done from both ends of the queue.
//  The program should implement following operations:
//  a) insertFront() - insert an element at the front of Deque
//  b)insertEnd() - insert an element at the end of Deque
//  c) deleteFront() - delete an element from the front of Deque
//  d)deleteEnd() - delete an element from the end of Deque
//  e) isEmpty() - checks whether Deque is empty or not
//  f)isFull() - checks whether Deque is full or not
//  g)printFront() - print Deque from front
//  h)printEnd() - print Deque from end



#include <stdio.h>
#define SIZE 5

struct Deque {
    int arr[SIZE];
    int front, rear;
};

void initDeque(struct Deque *dq) {
    dq->front = -1;
    dq->rear = -1;
}

int isFull(struct Deque *dq) {
    return ((dq->front == 0 && dq->rear == SIZE - 1) || (dq->front == dq->rear + 1));
}

int isEmpty(struct Deque *dq) {
    return (dq->front == -1);
}

void insertFront(struct Deque *dq, int value) {
    if (isFull(dq)) {
        printf("Deque is full\n");
        return;
    }

    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else if (dq->front == 0) {
        dq->front = SIZE - 1;
    } else {
        dq->front--;
    }

    dq->arr[dq->front] = value;
}

void insertRear(struct Deque *dq, int value) {
    if (isFull(dq)) {
        printf("Deque is full\n");
        return; }
  if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else if (dq->rear == SIZE - 1) {
        dq->rear = 0;
    } else {
        dq->rear++;
    }

    dq->arr[dq->rear] = value;
}

void deleteFront(struct Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return;
    }

    printf("Deleted from front: %d\n", dq->arr[dq->front]);

    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else if (dq->front == SIZE - 1) {
        dq->front = 0;
    } else {
        dq->front++;
    }
}
void deleteRear(struct Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return;  }

    printf("Deleted from rear: %d\n", dq->arr[dq->rear]);
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else if (dq->rear == 0) {
        dq->rear = SIZE - 1;
    } else {
        dq->rear--;
    }
}
void display(struct Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return;
    }

    printf("Deque elements: ");
    int i = dq->front;
    while (1) {
        printf("%d ", dq->arr[i]);
        if (i == dq->rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}
int main() {
    struct Deque dq;
    initDeque(&dq);
    int choice, value;

    while (1) {
        printf("\n1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertFront(&dq, value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertRear(&dq, value);
                break;
            case 3:
                deleteFront(&dq);
                break;
            case 4:
                deleteRear(&dq);
                break;
            case 5:
                display(&dq);
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }  }
