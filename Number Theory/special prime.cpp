#include<bits/stdc++.h>
using namespace std;


void sieve(vector<bool>& is_prime, int n){
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
}
int main(){
    int n, ans=0;
    cin>>n;
    vector<bool> is_prime(n + 1, true);
    sieve(is_prime, n);
    vector<int> pr;
    for(int i=0; i<=n; ++i){
        if(is_prime[i])
            pr.push_back(i);
    }
    // for(int p: pr) cout<<p<<" ";
    for(int i=0; i<pr.size()-1; ++i){
        int x = pr[i]+pr[i+1]+1;
        if(x>n) break;
        if(is_prime[x]) ++ans;
    }
    cout<<ans<<'\n';
    return 0;
}
