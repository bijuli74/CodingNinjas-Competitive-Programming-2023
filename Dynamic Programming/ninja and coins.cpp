#include <vector>
const int M=1e9+7;
int ninjaAndCoins(int n, int k, vector<int> &a)
{
    vector<vector<long long>> dp(n+1, vector<long long>(k+1));
    for(int i=0; i<=n; ++i) dp[i][0]=1;
    for(int i=1; i<=k; ++i) dp[0][i]=0;

    for(int i=1; i<=n; ++i){
      for(int j=1; j<=k; ++j){
        if(a[i-1]>j) dp[i][j]=dp[i-1][j]%M;
        else dp[i][j] = (dp[i-1][j] + dp[i-1][j-a[i-1]])%M;
      }
    }

    return dp[n][k]%M;
}
