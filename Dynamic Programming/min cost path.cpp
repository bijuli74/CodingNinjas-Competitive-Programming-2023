// m - number of rows
/// n - number of columns
#include <bits/stdc++.h>
using namespace std;

int minCostPath(int **g, int m, int n) {
    int dp[m+1][n+1] = {0};
    dp[m-1][n-1] = g[m-1][n-1];

    for(int i=m-2; ~i; --i)
        dp[i][n-1] = dp[i+1][n-1] + g[i][n-1];
    
    for(int j=n-2; ~j; --j)
        dp[m-1][j] = dp[m-1][j+1] + g[m-1][j];
    
    for(int i=m-2; ~i; --i)
        for(int j=n-2; ~j; --j)
            dp[i][j] = g[i][j] + min({dp[i+1][j], dp[i][j+1], dp[i+1][j+1]});

    return dp[0][0];
}
