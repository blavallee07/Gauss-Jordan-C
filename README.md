# Pivot-Point: A Gauss-Jordan Matrix Solver in C

A lightweight, robust implementation of the **Gauss-Jordan Elimination** method with **Partial Pivoting**. This command-line tool solves systems of linear equations of the form $Ax = b$ and transforms augmented matrices into **Reduced Row Echelon Form (RREF)**.

## Features

- Partial Pivoting for numerical stability
- Handles systems up to 1000×1000
- Interactive command-line interface
- Double-precision floating-point arithmetic
- Input validation and error handling

## The Algorithm

This implementation uses **Gauss-Jordan Elimination with Partial Pivoting**, which improves upon naive elimination in key ways:

1. **Pivot Selection**: Before processing each column, the algorithm searches for the row with the largest absolute value in that column (from the current row downward)
2. **Row Swapping**: The row with the best pivot is moved to the diagonal position
3. **Row Scaling**: The pivot row is divided by the pivot element to create a leading 1
4. **Column Elimination**: All other rows are reduced to create zeros in the current column

This approach:
- Prevents division by near-zero values
- Reduces floating-point rounding errors
- Ensures the algorithm doesn't fail on solvable systems

### Algorithm Steps (for each column $i$ from 0 to $n-1$):
```
1. find_pivot_row():  Locate largest |matrix[k][i]| where k ≥ i
2. swap_rows():       Move pivot row to position i (if needed)  
3. scale_pivot_row(): Divide row i by matrix[i][i] to get leading 1
4. elim_col():        Subtract multiples of row i from all other rows
```

## Complexity Analysis

- **Time Complexity:** $O(n^3)$  
  The algorithm uses three nested loops:
  - Outer loop: $n$ iterations (one per column)
  - Middle loop: $n$ iterations (eliminating each row)
  - Inner loop: $n$ iterations (updating each column in a row)

- **Space Complexity:** $O(n^2)$  
  Stores the augmented matrix as a 2D array of doubles. With `MAX_SIZE = 1000`, allocates approximately 8MB of memory.

## Getting Started

### Prerequisites

- A C compiler (`gcc` or `clang`)
- Standard C library with math support

### Compiling
```bash
gcc main.c -o solver -lm
```

**Flags explained:**
- `-o solver` : Names the output executable "solver"
- `-lm` : Links the math library (required for `fabs()`)

### Running
```bash
./solver
```

### Example Usage
```
Enter size of matrix: 3
Enter the augmented matrix [A|b] row by row:
(Each row should have 4 values)
2 1 -1 8
-3 -1 2 -11
-2 1 2 -3

x0 = 2.000000
x1 = 3.000000
x2 = -1.000000
```

This solves the system:
```
2x + y - z = 8
-3x - y + 2z = -11
-2x + y + 2z = -3
```

## Implementation Details

### Functions

| Function | Purpose |
|----------|---------|
| `find_pivot_row()` | Locates the row with maximum absolute value in current column |
| `swap_rows()` | Exchanges two rows in the matrix |
| `scale_pivot_row()` | Divides a row by its pivot to create a leading 1 |
| `elim_col()` | Eliminates all non-pivot entries in a column |

### Key Design Decisions

- **`MAX_SIZE = 1000`**: Maximum matrix dimension (adjustable)
- **Double precision**: Uses `double` type to minimize rounding errors
- **Pointer usage**: `find_pivot_row()` uses a pointer parameter to return the pivot row index
- **Augmented matrix format**: Stores $[A|b]$ as an $n \times (n+1)$ matrix

## Limitations

- Matrix size capped at `MAX_SIZE × MAX_SIZE` (default 1000)
- Assumes the system has a unique solution (no checking for singular matrices)
- No support for underdetermined or overdetermined systems
- Input must be entered manually (no file import)

## Potential Improvements

- Add singular matrix detection
- Implement file I/O for batch processing
- Add matrix visualization during solving
- Support for reading from `.csv` or `.txt` files
- Command-line arguments for non-interactive mode

## License

This project is open source and available for educational purposes.
