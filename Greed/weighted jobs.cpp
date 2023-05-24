#include<bits/stdc++.h>
using namespace std;
int firstGreaterEqual(const vector<int> &A, int startFrom, int target) {
  return lower_bound(begin(A) + startFrom, end(A), target) - begin(A);
}
int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
    int n; cin>>n;
    vector<vector<int>> a(n, vector<int>(3));
    for(int i=0; i<n; ++i) cin>>a[i][0]>>a[i][1]>>a[i][2];
    vector<int> dp(n+1);
    sort(begin(a), end(a));
    vector<int> start(n);
    for(int i=0; i<n; ++i)
        start[i] = a[i][0];
    for(int i=n-1; ~i; --i){
        const int j = firstGreaterEqual(start, i+1, a[i][1]);
        const int choose = a[i][2]+dp[j];
        const int skip = dp[i+1];
        dp[i] = max(choose, skip);
    }

    cout << dp[0]<<'\n';
    return 0;
}

