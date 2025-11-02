//  Given an expression in the form of postfix representation, design an algorithm and a program to
//  find result of this expression. 

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  

// Stack structure
struct stack {
    int size;
    int *s;
    int top;
};

// Function to create stack
void create(struct stack *st, int size) {
    st->size = size;
    st->top = -1;
    st->s = (int *)malloc(st->size * sizeof(int));
}

// Push function
void push(struct stack *st, int x) {
    if (st->top == st->size - 1) {
        printf("Stack overflow\n");
    } else {
        st->s[++st->top] = x;
    }
}

// Pop function
int pop(struct stack *st) {
    if (st->top == -1) {
        printf("Stack underflow\n");
        return -1;
    } else {
        return st->s[st->top--];
    }
}

// Function to evaluate postfix expression
int evaluatePostfix(char *exp) {
    struct stack st;
    create(&st, 100);  // create stack with max size 100

    for (int i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];

        // skip spaces
        if (ch == ' ')
            continue;

        // if digit, read full number (multi-digit support)
        if (isdigit(ch)) {
            int num = 0;
            while (isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            i--;  // step back after reading number
            push(&st, num);
        } else {  // operator
            int val2 = pop(&st);
            int val1 = pop(&st);

            switch (ch) {
                case '+': push(&st, val1 + val2); break;
                case '-': push(&st, val1 - val2); break;
                case '*': push(&st, val1 * val2); break;
                case '/': push(&st, val1 / val2); break;
                default:
                    printf("Invalid operator: %c\n", ch);
                    free(st.s);
                    return -1;
            }
        }
    }

    int result = pop(&st);
    free(st.s);
    return result;
}

int main() {
    char exp[200];

    printf("Enter a postfix expression (operands can be multi-digit, separated by spaces): ");
    fgets(exp, sizeof(exp), stdin); 

    int result = evaluatePostfix(exp);
    printf("Result of postfix evaluation: %d\n", result);

    return 0;
}
