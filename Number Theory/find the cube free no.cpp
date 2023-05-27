#include<bits/stdc++.h>
using namespace std;

const int mxN=1e6;
vector<int> a(mxN+1, 0);

void sieve(){
    a[1]=1;
    for(int i=2; i<=100; ++i){
        int x = i*i*i;
        for(int j=1; x*j<=mxN; ++j)
            a[x*j]=-1;      //mark cubic nos as -1
    }
    int k=1;
    for(int i=1; i<=mxN; ++i)
        if(a[i]!=-1){
            a[i]=k;
            ++k;
        }
}
int main(){
    int t; cin>>t;
    
    sieve();

    while(t--){
        int n; cin>>n;
        if(a[n]==-1) cout<<"Not Cube Free"<<'\n';
        else cout<<a[n]<<'\n';
    }

    return 0;
}
