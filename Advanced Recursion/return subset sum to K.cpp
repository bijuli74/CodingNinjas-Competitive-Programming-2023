void subsets(vector<int>& a, int id, int n, int k, vector<vector<int>>& ans, vector<int>& tmp, int sum){
    if(id>=n){
        if(sum==k) ans.push_back(tmp);
        return;
    }
    tmp.push_back(a[id]); // Take
    sum+=a[id];
    subsets(a, id+1, n, k, ans, tmp, sum);

    tmp.pop_back(); // Dont take
    sum-=a[id];
    subsets(a, id+1, n, k, ans, tmp, sum);
    return;
}
vector<vector<int>> findSubsetsThatSumToK(vector<int> a, int n, int k){
    vector<vector<int>> ans;
    vector<int> tmp;
    int sum=0;
    subsets(a, 0, n, k, ans, tmp, sum);
    return ans;
}
// Bitmasking Solution
//  vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k){
//      vector<vector<int>> ans;
//      for (int i = 0; i < (1 << n); i++){
//          vector<int> temp;
//          long long int sum = 0;
//          for (int j = 0; j < n; j++){
//            if (i & (1 << j)) {
//              temp.push_back(arr[j]);
//              sum += arr[j];
//            }
//          }
//         if (sum == k) ans.push_back(temp);
//     }
//  return ans;
// }
