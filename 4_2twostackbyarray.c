//  Design an algorithm and a program to implement two stacks by using only one array i.e. both the
// stacks should use the same array for push and pop operation. Array should be divided in such a
//  manner that space should be efficiently used if one stack contains very large number of elements
//  and other one contains only few elements.

#include <stdio.h>
#include <stdlib.h>
struct TwoStacks {
    int size;
    int *arr;
    int top1;
    int top2;
};
void create(struct TwoStacks *ts, int size) {
    ts->size = size;
    ts->arr = (int *)malloc(size * sizeof(int));
    ts->top1 = -1;
    ts->top2 = size;
}
void push1(struct TwoStacks *ts, int x) {
    if (ts->top1 < ts->top2 - 1) {
        ts->arr[++ts->top1] = x;
        printf("%d pushed into Stack 1\n", x);
    } else {
        printf("Stack Overflow! Cannot push %d into Stack 1\n", x);
    }
}

void push2(struct TwoStacks *ts, int x) {
    if (ts->top1 < ts->top2 - 1) {
        ts->arr[--ts->top2] = x;
printf("%d pushed into Stack 2\n", x);
    } else {
        printf("Stack Overflow! Cannot push %d into Stack 2\n", x);
    }
}
int pop1(struct TwoStacks *ts) {
    if (ts->top1 >= 0) {
        int val = ts->arr[ts->top1--];
        printf("%d popped from Stack 1\n", val);
        return val;
    } else {
        printf("Stack Underflow! Stack 1 is empty\n");
        return -1;
    }
}
int pop2(struct TwoStacks *ts) {
    if (ts->top2 < ts->size) {
        int val = ts->arr[ts->top2++];
        printf("%d popped from Stack 2\n", val);
        return val;
    } else {
        printf("Stack Underflow! Stack 2 is empty\n");
        return -1;
    }
}

void display1(struct TwoStacks ts) {
    printf("Stack 1 elements: ");
    for (int i = ts.top1; i >= 0; i--) {
        printf("%d ", ts.arr[i]);
    }
    printf("\n");  }
void display2(struct TwoStacks ts) {
    printf("Stack 2 elements: ");
    for (int i = ts.top2; i < ts.size; i++) {
        printf("%d ", ts.arr[i]);
    }
    printf("\n");
}

int main() {
    struct TwoStacks ts;
    int size;
    printf("Enter size of array for two stacks: ");
    scanf("%d", &size);
    create(&ts, size);

    int choice, value, stackNo;
    do {
        printf("\nPress:\n1 to push\n2 to pop\n3 to display\n4 to exit\n");
        scanf("%d", &choice);
        switch (choice) {
            
case 1:
                printf("Enter stack number (1 or 2): ");
                scanf("%d", &stackNo);
                printf("Enter value to push: ");
                scanf("%d", &value);
                if (stackNo == 1) push1(&ts, value);
                else if (stackNo == 2) push2(&ts, value);
                else printf("Invalid stack number\n");
                break;

            case 2:
                printf("Enter stack number (1 or 2): ");
                scanf("%d", &stackNo);
                if (stackNo == 1) pop1(&ts);
                else if (stackNo == 2) pop2(&ts);
                else printf("Invalid stack number\n");
                break;
            case 3:
                display1(ts);
                display2(ts);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    free(ts.arr);  // Free allocated memory
    return 0;
