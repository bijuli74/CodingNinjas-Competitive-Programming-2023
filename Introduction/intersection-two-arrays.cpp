#include <bits/stdc++.h>
void intersection(int *a, int *b, int n, int m)
{
    vector<int> ans;
    unordered_map<int, int> mp;
    for(int i=0; i<m; ++i)
        mp[b[i]]++;
    for(int i=0; i<n; ++i){
        if(mp[a[i]]>0){
            mp[a[i]]--;
            ans.push_back(a[i]);
        }
    }
    
    for(int x: ans) cout << x <<" ";
    cout<<"\n";
        
}
