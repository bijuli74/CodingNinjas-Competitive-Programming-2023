#include<bits/stdc++.h>
using namespace std;
#define vit vector<int>::iterator
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        for(int i=0; i<n; ++i) cin>>a[i];
        int ans=INT_MAX;
        sort(begin(a), end(a));
        for(int i=0; i<n-1; ++i){
            ans = min(ans, abs(a[i]-a[i+1]));
        }

        cout<<ans<<"\n";
    }
    return 0;
}
