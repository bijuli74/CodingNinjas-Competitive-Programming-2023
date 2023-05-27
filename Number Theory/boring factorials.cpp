#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll power(ll b, ll p, ll m){      //modular Binary Exponentiation Function a^b 
	b%=m;
	ll r=1;
	while(p>0){
		if(p&1)
			r=(r*b)%m;
		b=(b*b)%m;
		p >>=1;  //p /=2
	}
	
	return r;
}
void solve(){
    ll n, p; cin>>n>>p;
    ll ans=0;
    if(n>=p){
        cout<<ans<<'\n';
    }
    else{
        ans=p-1;
        for(int i=p-1; i>=n+1; --i){
            ans= ans*power(i, p-2, p)%p;  //modinv(i) = i^(p-2) % p from Fermat Little Theoram
        }
        cout<<ans<<'\n';
    }
    return;

}
int main(){
    
    int t; cin>>t;

    while(t--){
        solve();
    }
    return 0;
}
