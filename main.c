#include <stdio.h>   // For printf and scanf (input/output)
#include <stdlib.h>  // For memory allocation
#include <math.h>    // For fabs() - CRITICAL for finding the pivot

#define MAX_SIZE 1000  // The MAXIMUM size allowed for a matrix (ammount of memory c will allocate for this program)

void find_pivot_row(double matrix[][MAX_SIZE + 1], int n, int col, int *pivot_row) {
    *pivot_row = col;
    double max_val = fabs(matrix[col][col]);

    for (int k = col + 1; k < n; k++) {
        if (fabs(matrix[k][col]) > max_val) {
        max_val = fabs(matrix[k][col]);
        *pivot_row = k;
        }
    }
}

void swap_rows(double matrix[][MAX_SIZE + 1], int row1, int row2, int n) {
    double temp; // temp variable for swapping rows
    for (int k = 0; k <= n; k++) {
        temp = matrix[row1][k];
        matrix[row1][k] = matrix[row2][k];
        matrix[row2][k] = temp;
    }
}

void scale_pivot_row(double matrix[][MAX_SIZE + 1], int row, double pivot_value, int num_cols) {
    for (int k = 0; k <= num_cols; k++) {
        matrix[row][k] /= pivot_value; // scaling the pivot row by exact double multiple to garner a 1
    }
}

void elim_col(double matrix[][MAX_SIZE + 1], int col, int pivot_row, int num_cols, int num_rows) {
    for (int k = 0; k < num_rows; k++) {
        if (k == pivot_row) {
           continue; // skip this row
        }
        // do the elimination for row k
        double factor = matrix[k][col];
        for (int j = 0; j < num_cols; j++) {
            matrix[k][j] = matrix[k][j] - factor * matrix[pivot_row][j];
        }

    }
}

int main(void) {
    // Steps for the program:
    double matrix[MAX_SIZE][MAX_SIZE + 1];
    int n;
    
    // Step 1: take input
    printf("Enter size of matrix: ");
    scanf("%d", &n);
    printf("Enter the augmented matrix [A|b] row by row:\n");
    printf("(Each row should have %d values)\n", n + 1);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }
    
    // Step 2: process input through algorithm
    for (int i = 0; i < n; i++) {
        int pivot;
        find_pivot_row(matrix, n, i, &pivot);
        
        if (pivot != i) {
            swap_rows(matrix, pivot, i, n);
        }
        
        scale_pivot_row(matrix, i, matrix[i][i], n);
        elim_col(matrix, i, i, n, n);
    }
    
    // Step 3: output
    for (int i = 0; i < n; i++) {
        printf("x%d = %f\n", i, matrix[i][n]);
    }
    
    return 0;
}