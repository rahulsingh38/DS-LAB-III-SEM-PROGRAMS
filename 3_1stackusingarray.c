// Design an algorithm and a program to implement stack using array. The program should
//  implement following stack operations:
//  a) Create() - create an empty stack 
//  b) Push(k) - push an element k into the stack
//  c) Pop() - pop an element from the stack snd return it
//  d) IsEmpty() - check if stack is empty or not
//  e) Size() - finds the size of the stack
//  f) Print() - prints the contents of stack
 
#include <stdio.h>
#include <stdlib.h>
struct stack {
    int *arr;
    int top;
    int capacity;
};
struct stack* create(int size) {
    struct stack* st = (struct stack*) malloc(sizeof(struct stack));
    st->top = -1;
    st->capacity = size;
    st->arr = (int*) malloc(size * sizeof(int));
    return st;
}
void print(struct stack *st) {
    if (st->top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements (top to bottom):\n");
    for (int i = st->top; i >= 0; i--) {
        printf("%d\n", st->arr[i]);
    } }
void push(struct stack *st) {
    int val;
    printf("Enter the number of values to add: ");
    scanf("%d", &val);
    if (st->top + val >= st->capacity) {
        printf("Stack overflow! Cannot push %d elements.\n", val);
        return;
    }
    printf("Enter the values to add:\n");
    for (int i = 0; i < val; i++) {
        int num;
        scanf("%d", &num);
        st->arr[++st->top] = num;
    }
    printf("After push:\n");
    print(st);
}
void pop(struct stack *st) {
    int v;
    printf("Enter the number of values to pop: ");
    scanf("%d", &v);
    if (v > st->top + 1) {
        printf("Stack underflow! Cannot pop %d elements. Stack has %d elements.\n", v, st->top + 1);
        return;
    }
    for (int i = 0; i < v; i++) {
        printf("Popped: %d\n", st->arr[st->top--]);
    }
    printf("After pop:\n");
    print(st);
}

void isempty(struct stack *st) {
    if (st->top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack is not empty.\n");
    }
}
void sizeofstack(struct stack *st) {
    int size = st->top + 1;
    printf("The size of the stack is %d\n", size);
}
int main() {
    int size;
    printf("Enter the size of the stack: ");
    scanf("%d", &size);

    struct stack *st = create(size);
    int choice;
    while (1) {
        printf("\nMenu:\n");
        printf("1 - Push\n");
        printf("2 - Pop\n");
        printf("3 - Check if empty\n");
        printf("4 - Get size\n");
        printf("5 - Print stack\n");
        printf("6 - Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                push(st);
                break;
            case 2:
                pop(st);
                break;
            case 3:
                isempty(st);
                break;
            case 4:
                sizeofstack(st);
                break;
            case 5:
                print(st);
                break;
            case 6:
                free(st->arr);
                free(st);
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Wrong choice! Try again.\n");
        }
    }

    return 0;
}
