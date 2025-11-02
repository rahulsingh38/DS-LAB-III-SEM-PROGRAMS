// .Given a string of opening and closing paranthesis, design an algorithm and a program to find the
//  length of the longest valid paranthesis substring. Valid paranthesis substring is a string which
//  contains balanced paranthesis.

#include <stdio.h>
#include <stdlib.h>
void push(int s[], int t, int *top, int len) {
    if (*top == len - 1) {
        printf("Stack overflow\n");
        return;
    } else {
        *top = *top + 1;
        s[*top] = t;
    }
}
void pop(int *top) {
    if (*top == -1) {
        printf("Stack underflow\n");
    } else {
        *top = *top - 1;
    }
}

int main() {
    int n, i, max = 0, top = -1, len;
    printf("Enter the size of the stack (length of string): ");
    scanf("%d", &n);
    char arr[n + 1]; 
    int s[n];
printf("Enter the parentheses string: ");
    scanf("%s", arr);
    
    push(s, -1, &top, n);
    for (i = 0; arr[i] != '\0'; i++) {
        char c = arr[i];
        if (c == '(') {
            push(s, i, &top, n);
        } else if (c == ')') {
            pop(&top);
            if (top == -1) {
                
                push(s, i, &top, n);
            } else {
                len = i - s[top];
                if (max < len) {
                    max = len;
                }
            }
        }
    }
    printf("Longest valid parentheses length: %d\n", max);
    return 0;
}
 
