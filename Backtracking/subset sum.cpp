#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n, k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin>>a[i];

    int ans=0;
    for(int i=0; i<(1<<n); ++i){
        long long sum = 0;
        for(int j=0; j<n; ++j){
            if(i & (1<<j))
                sum +=a[j];
        }
        if(sum==k) ans++;
    }
    cout<<ans<<'\n';

}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t=1; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
