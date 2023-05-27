#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        if(n==0) cout<<0<<'\n';
        if(n%4==0) cout<<n<<'\n';
        if(n%4==1) cout<<1<<'\n';
        if(n%4==2) cout<<n+1<<'\n';
        if(n%4==3) cout<<0<<'\n';

    }
    return 0;
}
