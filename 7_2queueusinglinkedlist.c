//  Write an algorithm and a program to implement queue using linked list. The program should
//  implement following stack operations:
//  a) Create()
//  b) EnQueue()
//  c) DeQueue()
//  d) IsEmpty()
//  e) Size()


#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

struct Node* Create(int k) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = k;
    newNode->next = NULL;
    return newNode;
}

void EnQueue(int k) {
    struct Node *newNode = Create(k);
    if (front == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d enqueued successfully.\n", k);
}

void DeQueue() {
    if (front == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    struct Node *temp = front;
    printf("%d dequeued successfully.\n", front->data);
    front = front->next;
    free(temp);

    if (front == NULL)
        rear = NULL;
}

int IsEmpty() {
    return front == NULL;
}

int Size() {
    int count = 0;
    struct Node *temp = front;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void Display() {
    if (front == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    struct Node *temp = front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    int choice, k;
    while (1) {
        printf("\n--- Queue Using Linked List ---\n");
        printf("1. EnQueue\n2. DeQueue\n3. IsEmpty\n4. Size\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &k);
            EnQueue(k);
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
            printf("Size of queue: %d\n", Size());
            break;
        case 5:
            Display();
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0; }
