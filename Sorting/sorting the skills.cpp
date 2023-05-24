#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin>>a[i];
    bool ok=1;
    int i=0, j=1;
    while(i<n&&j<n){
        if(a[i]==a[j]+1){
            swap(a[i], a[j]);
            while(i>0 && a[i]==a[i-1]-1){
                swap(a[i], a[i-1]);
                i--;
            }
        i=j;
        j=i+1;
        }else{
            i++;
            j++;
        }
    }
    for(int i=1; i<n; ++i){
        if(a[i-1]>a[i]){
            ok=0;
            break;
        }
    }

    if(ok) cout<<"Yes"<<'\n';
    else cout<<"No"<<'\n';
    return;


}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
    
