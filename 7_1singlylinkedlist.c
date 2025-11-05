//  Write an algorithm and a program to implement singly linked list. The program should
//  implement following operations:
//  a)Create(k) - create a linked list with single node of value k
//  b)InsertFront(k) - insert node of value k at the front of the linked list
//  c)InsertEnd(k) - insert a node of value k at the end of the linked list
//  d)InsertAnywhere(p) - insert a node at specific position p
//  e)DeleteFront() - delete a node from the front of the linked list
//  f)DeleteEnd() - delete a node from the end of the linked list
//  g)DeleteAnywhere(p) - delete a node from a specific position p
//  h)Size() - find the size of the linked list
//  i) IsEmpty() - checks if the linked list is empty or not
//  j)FindMiddle() - finds the middle element of the linked list


#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Function to create a new node with given data
struct Node* Create(int k) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = k;
    newNode->next = NULL;
    return newNode;
}

void InsertFront(int k) {
    struct Node *newNode = Create(k);
    newNode->next = head;
    head = newNode;
}

void InsertEnd(int k) {
    struct Node *newNode = Create(k);

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void InsertAnywhere(int k, int pos) {
    if (pos < 1) {
        printf("Invalid position!\n");
        return;
    }

    if (pos == 1) {
        InsertFront(k);
        return;
    }

    struct Node *temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range!\n");
        return;
    }
    struct Node *newNode = Create(k);
    newNode->next = temp->next;
    temp->next = newNode;
}
void DeleteFront() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node *temp = head;
    head = head->next;
    free(temp);
}
void DeleteEnd() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    struct Node *temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
}

void DeleteAnywhere(int pos) {
    if (pos < 1 || head == NULL) {
        printf("Invalid position or empty list!\n");
        return;
    }

    if (pos == 1) {
        DeleteFront();
        return;
    }

    struct Node *temp = head;
    for (int i = 1; i < pos - 1 && temp->next != NULL; i++)
        temp = temp->next;

    if (temp->next == NULL) {
        printf("Position out of range!\n");
        return;
    }

    struct Node *delNode = temp->next;
    temp->next = delNode->next;
    free(delNode);
}

int Size() {
    int count = 0;
    struct Node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int IsEmpty() {
    return head == NULL;
}

void FindMiddle() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    printf("Middle element: %d\n", slow->data);
}

void Display() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node *temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, k, pos;

    while (1) {
        printf("\n--- Singly Linked List Operations ---\n");
        printf("1. InsertFront\n2. InsertEnd\n3. InsertAnywhere\n");
        printf("4. DeleteFront\n5. DeleteEnd\n6. DeleteAnywhere\n");
        printf("7. Size\n8. IsEmpty\n9. FindMiddle\n10. Display\n11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &k);
            InsertFront(k);
            break;
        case 2:
            printf("Enter value: ");
            scanf("%d", &k);
            InsertEnd(k);
            break;
        case 3:
            printf("Enter value and position: ");
            scanf("%d%d", &k, &pos);
            InsertAnywhere(k, pos);
            break;
        case 4:
            DeleteFront();
            break;
        case 5:
            DeleteEnd();
            break;
        case 6:
            printf("Enter position: ");
            scanf("%d", &pos);
            DeleteAnywhere(pos);
            break;
        case 7:
            printf("Size of list: %d\n", Size());
            break;
        case 8:
            if (IsEmpty())
                printf("List is empty\n");
            else
                printf("List is not empty\n");
            break;
        case 9:
            FindMiddle();
            break;
        case 10:
            Display();
            break;
        case 11:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}

