#include<bits/stdc++.h>
using namespace std;

vector<char> segmentedSieveNoPreGen(long long L, long long R) {
    vector<char> isPrime(R - L + 1, true);
    long long lim = sqrt(R);
    for (long long i = 2; i <= lim; ++i)
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;
    return isPrime;
}

int main(){
    
    int t; cin>>t;
    int L, R;
   
    while(t--){
        vector<char> ans;
        cin>>L>>R;
        ans = segmentedSieveNoPreGen(L, R);
        for(int i=0; i<ans.size(); ++i)
            if(ans[i]) cout<<i+L<<" ";
        cout<<'\n';
    }
    return 0;
}
