void dfs(vector<vector<bool>> &arr, vector<string> &paths, string path,
          int row, int col) {
  int n = arr.size();

  if (row == -1 || row == n || col == -1 || col == n)
    return;

  if (row == n - 1 && col == n - 1 && arr[row][col] == 1) {
    paths.push_back(path);
    return;
  }

  if (arr[row][col] == 1) {
    arr[row][col] = 0;

    dfs(arr, paths, path + "U", row - 1, col); //    up
    dfs(arr, paths, path + "R", row, col + 1); //    right
    dfs(arr, paths, path + "D", row + 1, col); //    down
    dfs(arr, paths, path + "L", row, col - 1); //    left

    arr[row][col] = 1;
  }
}

vector<string> findAllPaths(vector<vector<bool>> &arr) {
  //    Write your code here.
  vector<string> paths;
  dfs(arr, paths, "", 0, 0);
  return paths;
}

