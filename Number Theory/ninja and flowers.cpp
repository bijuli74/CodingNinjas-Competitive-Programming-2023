#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    if(n==1){
        cout<<1<<'\n';
        cout<<1<<'\n';
        return 0;
    }
    if(n==2){
        cout<<1<<'\n';
        cout<<2<<'\n';
    }

    vector<int> lpf(n+2);
    vector<int> pfs;
    for(int i=2; i<=n+1; ++i){
        if(!lpf[i]){
            pfs.push_back(i);
            lpf[i]=i;
        }
        for(int j=0; j<pfs.size()&& pfs[j]<=lpf[i]&& i*pfs[j]<=n+1; ++j)
            lpf[i*pfs[j]] = pfs[j];
    }

    int p = pfs.size();
    cout<<2<<'\n';
    cout<<min(p, n-p)<<" "<<max(p, n-p)<<'\n';
    return 0;
}
