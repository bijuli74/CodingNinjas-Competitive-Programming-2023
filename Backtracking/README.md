## N-Queens
You are given an integer 'N'. For a given 'N' x 'N' chessboard, find a way to place 'N' queens such that no queen can attack any other queen on the chessboard.
A queen can be killed when it lies in the same row, or same column, or the same diagonal of any of the other queens. You have to print all such configurations.

## Paths in a Maze
You are given a 2-D matrix consisting of 0’s and 1’s with ‘N’ rows and ‘N’ columns, you are supposed to find all paths from the cell (0,0) (top-left cell) to the cell (N-1, N-1)(bottom-right cell). All cells with value 0 are blocked and cannot be travelled through while all cells with value 1 are open.
If you are currently at cell (x,y) then you can move to (x+1,y)(denoted by ‘D’), (x-1,y)(denoted by ‘U’), (x,y+1)(denoted by ‘R’), (x,y-1)(denoted by ‘L’) in one move. You cannot move out of the grid.

## Reach the destination
Given a source point (sx, sy) and a destination point (dx, dy), the task is to check if it is possible to reach the destination point using the following valid moves:
(a, b) -> (a + b, b)
(a, b) -> (a, a + b)
Your task is to find if it is possible to reach the destination point using only the desired moves or not.

## Crossword $
Send Feedback
CodingNinjas has provided a crossword of 10*10 grid. The grid contains '+' or '-' as its cell values. Now, you are also provided with a word list that needs to placed accurately in the grid. Cells marked with '-' are to be filled with word list.
For example, The following is an example for the input crossword grid and the word list.
```
+-++++++++
+-++-+++++
+-------++
+-++-+++++
+-++-+++++
+-++-+++++
++++-+++++
++++-+++++
++++++++++
----------
CALIFORNIA;NIGERIA;CANADA;TELAVIV
Output for the given input should be:
+C++++++++
+A++T+++++
+NIGERIA++
+A++L+++++
+D++A+++++
+A++V+++++
++++I+++++
++++V+++++
++++++++++
CALIFORNIA
```

## Subset Sum
You are given an array of integers and a target K. You have to find the count of subsets of the given array that sum up to K.
Note:
1. Subset can have duplicate values.
2. Empty subset is a valid subset and has sum equal to zero.

## Valid Sudoku
You have been given a 9 X 9 2D matrix 'MATRIX' with some cells filled with digits(1 - 9), and some empty cells (denoted by 0).
You need to find whether there exists a way to fill all the empty cells with some digit(1 - 9) such that the final matrix is a valid Sudoku solution.
A Sudoku solution must satisfy all the following conditions-
1. Each of the digits 1 - 9 must occur exactly once in each row.
2. Each of the digits 1 - 9 must occur exactly once in each column.
3. Each of the digits 1 - 9 must occur exactly once in each of the 9, 3 x 3 sub-matrices of the matrix.

## Construct the Lexicographically Largest Valid Sequence
You are given a positive integer N. Your task is to create the lexicographically largest sequence of length 2*N - 1 containing integers between 1 to N such that:
1. 1 occurs in the sequence exactly once.
2. Each integer between 2 to N(inclusive) occurs in the sequence exactly twice.
3. For each integer i between 2 to N, the distance between the two occurrences of i should be exactly i.
