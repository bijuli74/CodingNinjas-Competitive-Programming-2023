#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll power(ll b, ll p, ll M){
    ll r = 1;
    b %=M;
    while(p>0){
        if(p&1)
            r = r*b%M;
        b = b*b%M;
        p>>=1;
    }
    return r;
}
int main(){
    int t; cin>>t;
    while(t--){
        ll a, M; 
        string b; 
        cin>>a>>b>>M;
        ll ans=1;
        ll y=0;
        ll x=0;
        for(ll i= b.size()-1; ~i; --i){
            // x = ( x+ (b[i]-'0') * power(3, p, M));
            // ll c = b[i]-'0';
            // x = x+c*(ll)pow(3, y);
            // ++y;

             if(b[i]=='2') ans = (((ans*a)%M) * a)%M;
            else if(b[i]=='1'){
                ans = (ans*a)%M;
            }

            a = (((a*a)%M) * a)%M;
        }
        ans = power(a, x, M);

        cout<<ans<<'\n';
    }
    return 0;
}
