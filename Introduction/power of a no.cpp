#include <bits/stdc++.h>
using namespace std;

int main() {
	// Write your code here
    long long x, n; cin>>x>>n;
    if(n==0){
        cout<<1; 
        return 0;
    }
    if(x==0){
        cout<<0;
        return 0;
    }
    long long ans = powl(x, n);
    cout << ans;
    return 0;
	
}
