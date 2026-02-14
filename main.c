#include <stdio.h>   // For printf and scanf (input/output)
#include <stdlib.h>  // For memory allocation
#include <math.h>    // For fabs() - CRITICAL for finding the pivot

#define MAX_SIZE 1000  // The MAXIMUM size allowed for a matrix

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
     matrix[row][k] /= pivot_value;
    }
}


void main(void) {

}
