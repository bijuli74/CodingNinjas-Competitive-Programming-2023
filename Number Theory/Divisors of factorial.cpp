#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int mxA = 5e4;
const int M = 1e9+7;
vector<ll> lpf(mxA + 1);
vector<ll> pfs;

void preprocess() {

  for (ll i = 2; i <= mxA; ++i) {
    if (!lpf[i]) {
      pfs.push_back(i);
      lpf[i] = i;
    }
    for (ll j = 0;
         j < (int)pfs.size() && pfs[j] <= lpf[i] && i * pfs[j] <= mxA; ++j)
      lpf[i * pfs[j]] = pfs[j];
  }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    preprocess();
    while(t--){
        ll n; cin>>n;
        ll ans=1;
        for(ll& p: pfs){
            if(p>n) break;
            ll num=n;
            ll k=0;
            while(num>0){
                k=(k+num/p)%M;
                num /=p;
            }
            ans = (ans*(k+1)%M)%M;
        }
        cout<<ans<<endl;
    }
    return 0;
}
