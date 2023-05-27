#include <bits/stdc++.h>
void helper(vector<int> &A, int idx, int n, int X, vector<int> &tmp, vector<vector<int>>& ans) {
  if(X==0)
    ans.push_back(tmp);
    
  if (idx >= n || X - A[idx] < 0) {
    return;
  }
  tmp.push_back(A[idx]);

  helper(A, idx, n, X - A[idx], tmp, ans);
  tmp.pop_back();

  helper(A, idx + 1, n, X, tmp, ans);
}

vector<vector<int>> combSum(vector<int> &A, int X) {
  sort(A.begin(), A.end());
  int n = A.size();
  vector<int> tmp;
  vector<vector<int>> ans;

  helper(A, 0, n, X, tmp, ans);
  return ans;
}
