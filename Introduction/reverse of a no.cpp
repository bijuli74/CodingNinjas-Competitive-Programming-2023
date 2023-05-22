#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    bool ok=0;
    if(n==0) { cout<<0;  return 0;}
    while(n>0){
        int r=n%10;
        if(r!=0) ok=1;
        
        if(ok) cout<<r;
        
        n/=10;
    }
    
}
