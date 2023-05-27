const int M=1e9+7;
#define vt vector

int coinChange(int n, vector<int> &coins, vector<int> &freq, int v) {
    int mxf=1;
   mxf = *max_element(freq.begin(), freq.end());
   
   vt<vt<vt<int>>> dp(n, vt<vt<int>>(v+1, vt<int>(mxf+1, 0)));

   for(int i=0; i<n; ++i)
        for(int j=0; j<=freq[i]; ++j)
            dp[i][0][j]=1;
    
    for(int i=0; i<n; ++i){
        for(int j=1; j<=v; ++j){
            for(int k=0; k<=freq[i]; ++k){
                if(j-coins[i]>=0 && k>0)                             // Check if we can take the current coin or not
                    dp[i][j][k] = dp[i][j-coins[i]][k-1]%M;

                if (i > 0)                                                   // Go to the previous coin.
                  dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][freq[i - 1]]) % M;
            }
        }
    }
    
    return dp[n-1][v][freq[n-1]];

}
