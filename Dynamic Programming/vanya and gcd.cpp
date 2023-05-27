#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mxA=100;
const int M = 1e9+7;
int main(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin>>a[i];
    
    vector<vector<ll>> dp(n, vector<ll>(mxA+1));

    dp[0][a[0]]=1;
    ll ans=dp[0][1];
    
    for(int i=1; i<n; ++i){
        for(int k=i-1; ~k; --k){
            if(a[i]>a[k]){
              for (int g = 1; g <= mxA; ++g) {
                int cur_gcd = __gcd(g, a[i]);
                dp[i][cur_gcd] = (dp[i][cur_gcd] + dp[k][g]) %M;
              }
            }
        }
        dp[i][a[i]]++;
        ans = (ans+ dp[i][1]) % M;
    }

    cout<<ans<<'\n';
}
