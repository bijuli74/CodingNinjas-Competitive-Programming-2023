int maxProfit(vector<int> &values, vector<int> &weights, int n, int w) {
  vector<int> dp(w + 1);

  for (int i = 0; i < n; ++i)
    for (int j = w; j >= weights[i]; --j)
      dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);

  return dp[w];
}
