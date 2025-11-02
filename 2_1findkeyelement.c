//  Given a matrix of size n X n, where every row and every column is sorted in increasing order.
//  Write an algorithm and a program to find whether the given key element is present in the matrix
//  or not. (Linear time complexity)

#include <stdio.h>
#include <stdbool.h>

// Function to search for a key in an N x N sorted matrix
bool searchMatrix(int n, int matrix[n][n], int key) {
    int row = 0, col = n - 1;  // start from top-right corner

    while (row < n && col >= 0) {
        if (matrix[row][col] == key) {
            return true;  // found
        } else if (matrix[row][col] > key) {
            col--;  // move left
        } else {
            row++;  // move down
        }
    }
    return false;  // not found
}

int main() {
    int n, key;

    printf("Enter size of square matrix: ");
    scanf("%d", &n);

    int matrix[n][n];

    printf("Enter elements of %d x %d matrix:\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Enter the key to search: ");
    scanf("%d", &key);

    if (searchMatrix(n, matrix, key))
        printf("Element %d found in matrix.\n", key);
    else
        printf("Element %d not found in matrix.\n", key);

    return 0;
}
