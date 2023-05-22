#include <bits/stdc++.h>
int maxLengthChain(vector<pair<int, int>> &p, int n) {
    sort(p.begin(), p.end(), [](const pair<int, int>& a, const pair<int, int>& b){ return a.second < b.second; });
    int prev=p[0].second;
    int ans=1;
    for(int i=1; i<n; ++i){
        if(p[i].first>prev){
            ans++;
            prev=p[i].second;
        }
    }
    return ans;
}
