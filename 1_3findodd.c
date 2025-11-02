// Given an array of nonnegative integers, where all numbers occur even number of times except
//  one number which occurs odd number of times. Write an algorithm and a program to find this
//  number. (Time complexity = O(n))

#include <stdio.h>

// Function to find the number occurring odd number of times
int findOddOccurrence(int arr[], int n) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        result = result ^ arr[i];  // XOR logic
    }
    return result;
}

int main() {
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d nonnegative integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int oddNum = findOddOccurrence(arr, n);
    printf("The number occurring odd number of times is: %d\n", oddNum);

    return 0;
}

