#include <vector>
long long int countDerangements(int n) {
    const int M=1e9+7;
    vector<long long> dp(n+1);
    dp[0]=1;

    for(int i=2; i<=n; ++i){
        dp[i]=(i-1LL)*(dp[i-1]+dp[i-2])%M;
    }
    return dp[n];
}
