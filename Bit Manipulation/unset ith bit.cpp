#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int n, i; cin>>n>>i;
        n &= ~(1 << i);
        cout<<n<<'\n';
    }
    return 0;
}
