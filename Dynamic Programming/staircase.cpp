#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
const int M = 1e9+7;
long long dp[N+1];

int main(){
    
    int t; cin>>t;

    dp[0]=1, dp[1]=1, dp[2]=2;
    for(int i=3; i<=N; ++i){
        dp[i]=(dp[i-1]+dp[i-2]+dp[i-3])%M;
    }

    while(t--){
        int n; cin>>n;
        cout<<dp[n]%M<<'\n';
    }
    return 0;
}
