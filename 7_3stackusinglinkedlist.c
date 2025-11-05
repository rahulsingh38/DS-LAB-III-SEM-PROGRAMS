//  Write an algorithm and a program to implement stack using linked list. he program should
//  implement following queue operations:
//  a) Create()
//  b)  Push()
//  c)  Pop()
//  d)  IsEmpty()
//  e)  IsFull()
//  f)  Size()
 

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;

struct Node* Create(int k) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = k;
    newNode->next = NULL;
    return newNode;
}

void Push(int k) {
    struct Node *newNode = Create(k);
    newNode->next = top;
    top = newNode;
    printf("%d pushed onto stack.\n", k);
}

void Pop() {
    if (top == NULL) {
        printf("Stack is empty!\n");
        return;
    }

    struct Node *temp = top;
    printf("%d popped from stack.\n", top->data);
    top = top->next;
    free(temp);
}

int IsEmpty() {
    return top == NULL;
}

int IsFull() {
    
    return 0; 
}

int Size() {
    int count = 0;
    struct Node *temp = top;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void Display() {
    if (top == NULL) {
        printf("Stack is empty!\n");
        return;
    }

    struct Node *temp = top;
    printf("Stack elements (top to bottom): ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, k;

    while (1) {
        printf("\n--- Stack Using Linked List ---\n");
        printf("1. Push\n2. Pop\n3. IsEmpty\n4. IsFull\n5. Size\n6. Display\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &k);
            Push(k);
            break;
        case 2:
            Pop();
            break;
        case 3:
            if (IsEmpty())
                printf("Stack is empty.\n");
            else
                printf("Stack is not empty.\n");
            break;
        case 4:
            if (IsFull())
                printf("Stack is full.\n");
            else
                printf("Stack is not full.\n");
            break;
        case 5:
            printf("Size of stack: %d\n", Size());
            break;
        case 6:
            Display();
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}

