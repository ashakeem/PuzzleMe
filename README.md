# PuzzleMe (Sudoku Solver)

This code provides a solution to solve a Sudoku puzzle using the backtracking algorithm. It is written in C++ and can be used to solve Sudoku puzzles of size 9x9.

## How it works

1. The `printGrid` function is responsible for printing the Sudoku grid in a human-readable format.
2. The `isValid` function checks if a number is valid to be placed in a specific position on the Sudoku grid. It checks if the number is already present in the same row, column, or the 3x3 grid.
3. The `findEmptyCell` function finds an empty cell (represented by 0) in the grid. It updates the `row` and `col` variables with the coordinates of the empty cell if found.
4. The `solveSudoku` function is the main solving algorithm. It first calls `findEmptyCell` to find an empty cell. If no empty cell is found, it means the puzzle is solved, and the function returns true.
5. The function then tries placing numbers from 1 to 9 in the empty cell. It checks if the number is valid using `isValid`. If valid, it places the number in the grid and recursively calls itself.
6. If the recursive call returns true, it means the puzzle is solved, and the function returns true. If the recursive call returns false, it means the current placement of the number is not correct, so the number is removed from the grid, and the next number is tried.
7. If all numbers have been tried and no solution is found, the function returns false.
8. In the `main` function, a Sudoku grid is initialized with some initial values. The `solveSudoku` function is called to solve the puzzle. If a solution is found, it is printed using `printGrid`. If no solution exists, a message is displayed.
9. You can replace the initial puzzle by editing the `grid` code in the `main` function.

## How it was inspired

This code was inspired by the struggles I faced while learning Data Structures and Algorithms. Solving a Sudoku puzzle using backtracking is a common algorithmic problem that can be used to help reinforce concepts like recursion and constraint satisfaction. Through this project I was able to improve my problem-solving skills and understand the efficiency of algorithms by providing myself with a practical example of backtracking and its application in solving puzzles.
