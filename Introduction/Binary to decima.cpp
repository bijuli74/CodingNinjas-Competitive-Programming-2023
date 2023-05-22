#include <bits/stdc++.h>
using namespace std;

int main() {
	string n; cin>>n;
    int ans=0;
    for(int i=(int)n.size()-1, j=0; ~i; --i, ++j){
        ans+=pow(2, j)*(n[i]-'0');
    }
    cout<<ans;
	
}
