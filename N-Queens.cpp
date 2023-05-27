void addSol(vector<vector<int>> &board, int n, vector<vector<int>> &ans) {
  vector<int> state;
  for (auto i : board) 
    for (auto j : i)
      state.push_back(j);
  

  ans.push_back(state);
  return;
}

bool isValid(vector<vector<int>> & board, int row, int col) {
  // check this row on the left
  for (int i = 0; i < col; ++i) {
    if (board[row][i] == 1)
      return false;
  }
  // check upper left diagonal
  for (int i = row, j = col; i >= 0 && j >= 0; --i, --j)
    if (board[i][j] == 1)
      return false;

  // check lower left diagonal
  for (int i = row, j = col; i < board.size() && j >= 0; ++i, --j)
    if (board[i][j] == 1)
      return false;
  // if its safe to place the queen
  return true;
}

void dfs(vector<vector<int>> &board, int col, int n, vector<vector<int>> &ans) {
  // base case
  if (col >= n) {
    addSol(board, n, ans);
    return;
  }
  // iterate over all the rows
  for (int row = 0; row < n; row++) {
    if (isValid(board, row, col)) {
      // mark this state with queen
      board[row][col] = 1;

      // recursive all the helper function
      dfs(board, col + 1, n, ans);

      // backtrack to the prev state
      board[row][col] = 0;
    }
  }
  return;
}

 vector<vector<int>> solveNQueens(int n) {
  vector<vector<int>> ans;
  vector<vector<int>> board(n, vector<int>(n, 0));
  dfs(board, 0, n, ans);
  return ans;
}
