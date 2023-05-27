#include<bits/stdc++.h>
using namespace std;

const int mxA=1000;

void solve(int n, vector<int>& a){
    vector<int> f(mxA+1, 0);
    vector<int> dp(mxA+1, 0); //dp[points]

    for(int i=0; i<n; ++i) f[a[i]]++;

    dp[1]=f[1];

    for(int i=2; i<=mxA; ++i)
        dp[i] = max(dp[i-1], dp[i-2]+i*f[i]);
    
    cout<< dp[mxA] << '\n';
    return;
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n; 
        vector<int> a(n);
        for(int i=0; i<n; ++i) cin>>a[i];
        solve(n, a);
    }
    
    return 0;
}
