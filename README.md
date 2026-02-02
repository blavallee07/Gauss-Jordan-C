# Pivot-Point: A Gauss-Jordan Matrix Solver in C

A lightweight, robust implementation of the **Gauss-Jordan Elimination** method with **Partial Pivoting**. This tool solves systems of linear equations of the form $Ax = B$ and transforms matrices into Reduced Row Echelon Form (RREF).

## 🚀 The Algorithm
Unlike a basic "naive" elimination, this solver uses **Partial Pivoting** to ensure numerical stability. Before each elimination step, the program scans the current column for the largest absolute value and swaps rows. This prevents division-by-zero errors and reduces floating-point "drift."



## 📊 Complexity Analysis
- **Time Complexity:** $O(n^3)$  
  For an $n \times n$ matrix, the algorithm uses a triple-nested loop structure to perform row reductions.
- **Space Complexity:** $O(n^2)$  
  The matrix is stored and manipulated in a 2D array (using `double` for precision).

## 🛠️ Getting Started

### Prerequisites
You'll need a C compiler like `gcc` or `clang`.

### Compiling
```bash
gcc main.c -o solver -lm
