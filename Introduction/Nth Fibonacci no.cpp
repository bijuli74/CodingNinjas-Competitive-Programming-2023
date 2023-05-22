#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll n, f0=0, f1=1;
    cin>>n;
    if(n<2){
        if(n==0)cout<<0;
        else cout<<1;
        return 0;
    }
    
    ll memo[n+1];
    memo[0]=f0, memo[1]=f1;
    for(ll i=2; i<n+1; ++i)
        memo[i]=memo[i-1]+memo[i-2];
    
    cout<<memo[n]<<'\n';
    return 0;
