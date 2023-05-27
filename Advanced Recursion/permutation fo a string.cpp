 #include <algorithm>
void permute(string &str, int idx, vector<string>& ans, int n) {
  if (idx >= n) {
    ans.push_back(str);
    return;
  }
  for (int i = idx; i < n; ++i) {
    swap(str[idx], str[i]);

    permute(str, idx + 1, ans, n);

    swap(str[idx], str[i]); // come back to original state
  }
}

vector<string> generatePermutations(string &str)
{
    int n=str.size();
    sort(str.begin(), str.end());

    vector<string> ans;
    permute(str, 0, ans, n);
    
    // sort(ans.begin(), ans.end());
    return ans;
}
