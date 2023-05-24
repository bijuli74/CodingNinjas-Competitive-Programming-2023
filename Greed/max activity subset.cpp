#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
    int n; cin>>n;
    vector<vector<int>> a(n, vector<int>(2));
    for(int i=0; i<n; ++i)
        cin>>a[i][1]>>a[i][0];
    
    sort(a.begin(), a.end());
    int ans=1, l=0;
    for(int i=1; i<n; ++i){
        if(a[i][1]>=a[l][0]){
            l=i;
            ++ans;
        }
    }
    cout<<ans<<'\n';
    return 0;
}
