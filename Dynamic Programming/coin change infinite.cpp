#include <vector>
const int M = 1e9+7;
int countWaysToMakeChange(int a[], int n, int x){
  vector<long long> dp(x+1);
  dp[0]=1;
  for(int i=0; i<n; ++i){
    for(int j=a[i]; j<=x; ++j)
      dp[j]+=dp[j-a[i]]%M;
  }
  return dp[x]%M;
}
