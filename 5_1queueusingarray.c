// Design an algorithm and a program to implement queue using array. The program should
// implement following queue operations:
//  a) Create() - create a queue
//  b) EnQueue(k) - insert an element k into the queue
//  c) DeQueue() - delete an element from the queue
//  d) IsEmpty() - check if queue is empty or not
//  e) Size() - finds the size of the queue
 
#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void EnQueue(int k);
void DeQueue();
int IsEmpty();
int Size();
void Display();

void EnQueue(int k) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) front = 0;
    rear++;
    queue[rear] = k;
    printf("Inserted %d into queue\n", k);
    Display();
}

void DeQueue() {
    if (IsEmpty()) {
        printf("Queue Underflow\n");
        return;
    }
    printf("Deleted %d from queue\n", queue[front]);
    front++;
    Display();
}

int IsEmpty() {
    return (front == -1 || front > rear);
}

int Size() {
    if (IsEmpty()) return 0;
    return rear - front + 1;
}

void Display() {
    if (IsEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue contents: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\nChoose operation:\n");
        printf("1. Insert (EnQueue)\n");
        printf("2. Delete (DeQueue)\n");
        printf("3. Check if Empty\n");
        printf("4. Find Size\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                EnQueue(value);
                break;
            case 2:
                DeQueue();
                break;
            case 3:
                if (IsEmpty())
                    printf("Queue is empty\n");
                else
                    printf("Queue is not empty\n");
                break;
            case 4:
                printf("Queue size: %d\n", Size());
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. \n");
        }
    }
}



