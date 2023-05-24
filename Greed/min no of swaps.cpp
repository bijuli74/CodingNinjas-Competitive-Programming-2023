int minSwap (int n, int m, int k, string& s, vector<char> &a)
{
    vector<vector<int>> dp(k, vector<int>(26, 0));
    vector<int> fa(26, 0);
    for(int i=0; i<m; ++i) fa[a[i]-'a']=1;
    int ans = 0;
    for(int i=0; i<n; ++i) dp[i%k][s[i]-'a']++;

    for(int i=0; i<k; ++i){
        int maxi=0, sum=0;
        for(int j=0; j<26; ++j){
            sum+=dp[i][j];
            if(dp[i][j]>maxi && fa[j]==1)
                maxi = dp[i][j];
        }
        ans += (sum-maxi);

    }
    return ans;
