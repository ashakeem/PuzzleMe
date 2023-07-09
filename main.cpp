#include <iostream>

const int N = 9;

// Function to print the Sudoku grid
void printGrid(int grid[N][N]) {
  for (int row = 0; row < N; row++) {
    for (int col = 0; col < N; col++) {
      std::cout << grid[row][col] << " ";
    }
    std::cout << std::endl;
  }
}

// Function to check if a number is valid in a specific position
bool isValid(int grid[N][N], int row, int col, int num) {
  // Check if the number is already present in the same row
  for (int c = 0; c < N; c++) {
    if (grid[row][c] == num) {
      return false;
    }
  }

  // Check if the number is already present in the same column
  for (int r = 0; r < N; r++) {
    if (grid[r][col] == num) {
      return false;
    }
  }

  // Check if the number is already present in the same 3x3 grid
  int startRow = row - row % 3;
  int startCol = col - col % 3;
  for (int r = 0; r < 3; r++) {
    for (int c = 0; c < 3; c++) {
      if (grid[r + startRow][c + startCol] == num) {
        return false;
      }
    }
  }

  return true;
}

// Function to find an empty cell
bool findEmptyCell(int grid[N][N], int &row, int &col) {
  for (row = 0; row < N; row++) {
    for (col = 0; col < N; col++) {
      if (grid[row][col] == 0) {
        return true;
      }
    }
  }
  return false;
}

// Main solving algorithm using backtracking
bool solveSudoku(int grid[N][N]) {
  int row, col;

  // If there are no empty cells, the puzzle is solved
  if (!findEmptyCell(grid, row, col)) {
    return true;
  }

  // Try placing numbers from 1 to 9
  for (int num = 1; num <= 9; num++) {
    if (isValid(grid, row, col, num)) {
      grid[row][col] = num;

      // Recursively call the solving function
      if (solveSudoku(grid)) {
        return true;
      }

      // If recursion returns false, remove the number and try the next one
      grid[row][col] = 0;
    }
  }

  return false;
}

int main() {
  int grid[N][N] = {{5, 3, 0, 0, 7, 0, 0, 0, 0}, {6, 0, 0, 1, 9, 5, 0, 0, 0},
                    {0, 9, 8, 0, 0, 0, 0, 6, 0}, {8, 0, 0, 0, 6, 0, 0, 0, 3},
                    {4, 0, 0, 8, 0, 3, 0, 0, 1}, {7, 0, 0, 0, 2, 0, 0, 0, 6},
                    {0, 6, 0, 0, 0, 0, 2, 8, 0}, {0, 0, 0, 4, 1, 9, 0, 0, 5},
                    {0, 0, 0, 0, 8, 0, 0, 7, 9}};

  if (solveSudoku(grid)) {
    std::cout << "Sudoku solved:\n\n";
    printGrid(grid);
  } else {
    std::cout << "No solution exists for the given Sudoku puzzle.\n";
  }

  std::cout << "\n****You can replace the puzzle by editing the grid code****";

  return 0;
}
