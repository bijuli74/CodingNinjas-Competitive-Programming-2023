#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int mxA = 1e6;
void sieve(vector<int>& is_prime){
    for(int i=2; i<=mxA; ++i){
        if(!is_prime[i])
            for(int j=1; i*j<=mxA; ++j)
                is_prime[i*j] += 1;
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;

    vector<int> is_prime(mxA+1, 0);
    vector<vector<int>> dp(11, vector<int>(mxA+1));

    sieve(is_prime);
    for(int i=0; i<=10; i++){
        dp[i][0]=0;
        dp[i][1]=0;
        for(int j=2; j<=mxA; ++j)
            dp[i][j] = i==is_prime[j] ? dp[i][j-1]+1 : dp[i][j-1];
    }

    while(t--){
        int a, b, n;
        cin>>a>>b>>n;
        if(a==1 && n==0){
            cout<<1<<'\n';
            continue;
        }
        cout<< dp[n][b] - dp[n][a-1] << '\n';
    }

return 0;
}
