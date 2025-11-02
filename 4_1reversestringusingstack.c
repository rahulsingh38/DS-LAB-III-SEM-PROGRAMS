//  Given an empty stack, design an algorithm and a program to reverse a string using this stack
//  (with and without recursion).

// Without recursion :

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct stack {
    int size, top;
    char *arr;
} s;
s* create(int val) {
    s*st = (s*)malloc(sizeof(s));
    st->top = -1;
    st->size = val;
    st->arr = (char*)malloc(val * sizeof(char));
    return st;
}
void push(s *st, char a[], int cap) {
    for (int i = 0; i < cap; i++) {
        char ch = a[i];
        st->arr[++st->top] = ch;
    }
    st->arr[cap] = '\0'; 
    printf("Input string is:\n%s\n", st->arr);
}
void reverse(s *st) {
    char temp;
    int i = 0, j = strlen(st->arr) - 1;
    
while (i < j) {
        temp = st->arr[i];
        st->arr[i] = st->arr[j];
        st->arr[j] = temp;
        i++;
        j--;
    }
    printf("\nReversed string is:\n%s\n", st->arr);
}


int main() {
    int n;
    printf("Enter the size:\n");
    scanf("%d", &n);
    char arr[n];
    printf("Enter the stack:\n");
    scanf("%s", arr);
    s *st = create(n);
    push(st, arr, strlen(arr));
    reverse(st);
    free(st->arr);
    free(st);
    return 0;
}


//  With recursion:

// #include <stdio.h>
// #include <string.h>
// void reverseRecursive(char arr[], int start, int end) {
//     if (start >= end) 
//         return;
//     char temp = arr[start];
//     arr[start] = arr[end];
//     arr[end] = temp;
//     reverseRecursive(arr, start + 1, end - 1); 
// }
// int main() {
//     char arr[100];
//     printf("Enter a string:\n")
//     scanf("%s", arr);
//     printf("Original string: %s\n", arr);
//     reverseRecursive(arr, 0, strlen(arr) - 1);
//     printf("Reversed string: %s\n", arr);
//     return 0;
// }
