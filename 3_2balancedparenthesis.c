//  Given an expression string consisting of opening and closing brackets “{“,”}”,”(“,”)”,”[“,”]”,
//  design an algorithm and a program to check whether this expression has balanced paranthesis or
//  not.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char arr[100];
int top = -1;
int isempty() {
    return top == -1;
}
int match(char o, char c) {
    return (o == '(' && c == ')') ||
           (o == '{' && c == '}') ||
           (o == '[' && c == ']');
}
void topush(char a) {
    arr[++top] = a;
}
char topop() {
    return arr[top--];
}
int main() {
    char ch[100];
    int t;
    printf("Enter the number of cases: ");
    scanf("%d", &t);
    getchar(); 
    while (t--) {
        top = -1;
        int balanced = 1;
        int i;
        printf("Enter the brackets string:\n");
        fgets(ch, 100, stdin);
        for (i = 0; ch[i] != '\0'; i++) {
            char c = ch[i];
            if (c == '{' || c == '[' || c == '(') {
                topush(c);
            }
            else if (c == '}' || c == ']' || c == ')') {
                if (isempty() || !match(arr[top], c)) {
                    balanced = 0;
                    break;
                }
                topop();
            }
        }

        if (balanced && isempty()) {
            printf("Balanced\n");
        }
        else {
            printf("Unbalanced\n");
        }
    }
    return 0;
}
