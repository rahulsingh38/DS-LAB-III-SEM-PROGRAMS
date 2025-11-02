// Given a boolean matrix (contains only 0 and 1) of size m X n where each row is sorted, write an
//  algorithm and a program to find which row has maximum number of 1's. (Linear time
//  complexity)

#include <stdio.h>

// Function to find the row with maximum number of 1s
int rowWithMax1s(int m, int n, int mat[m][n]) {
    int index = -1;           // initialize index
    int row = 0, col = n - 1; // start from top-right corner

    while (row < m && col >= 0) {
        if (mat[row][col] == 1) {
            index = row; // update row index
            col--;       // move left
        } else {
            row++;       // move down
        }
    }
    return index;
}

int main() {
    int m, n;
    printf("Enter number of rows (m): ");
    scanf("%d", &m);
    printf("Enter number of columns (n): ");
    scanf("%d", &n);

    int mat[m][n];
    printf("Enter the elements of the matrix (only 0 or 1):\n");    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    int result = rowWithMax1s(m, n, mat);
    if (result != -1)
        printf("Row with maximum 1s is: %d\n", result);
    else
        printf("No 1s found in the matrix.\n");

    return 0;
}

