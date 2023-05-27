#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ii pair<int, int>
#define fast_io     ios::sync_with_stdio(0);  cin.tie(0);

const int mxN=1e6;
vector<int> a(mxN);
void sieve(){
    iota(a.begin(), a.end(), 0);
    for(int i=2; i*i<=mxN; ++i)
        for(int j=i*i; j<=mxN; j+=i)
            if(a[j]>i) a[j]=i;
}

int main(){
    fast_io
    int n, k=0; cin>>n;
    sieve();

    vector<int> ans(n);
    vector<bool> vis(n+1, 0);
    for(int i=n; i>=1; --i){
        if(!vis[i]){
            int lpf = a[i];
            int x=i;
            vector<int> v;
            vis[i]=1;
            v.push_back(i);
            while(x>1){
                for(int j=i-lpf; j>=1; j=j-lpf)
                    if(!vis[j]){
                        vis[j]=1;
                        v.push_back(j);
                    }
                while(x%lpf==0)
                    x /= lpf;

                lpf=a[x];
            }
            sort(begin(v), end(v), greater<int>());
            for(int i=0; i<v.size(); ++i){
                ans[k]=v[i];
                ++k;
            }
        }
    }
    ans[n-1]=1;
    for(auto& i: ans) cout<<i<<" ";
    cout<<'\n';

    return 0;
}
