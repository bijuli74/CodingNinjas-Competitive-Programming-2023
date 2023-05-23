#include <bits/stdc++.h> 
int kDiffPairs(vector < int > & arr, int n, int k) {
    
    sort(arr.begin(),arr.end(),greater<int>());
    int ans = 0;
    set<int> seen;
    set<pair<int,int>> s;
    
    for(int i=0;i<n;i++){
      if (seen.count(arr[i] + k) > 0) {
        s.insert(make_pair(arr[i], arr[i] + k));
      }
      seen.insert(arr[i]);
    }
    return s.size();
}

// #include <bits/stdc++.h> 
// int kDiffPairs(vector < int > & arr, int n, int k) {
    
 // Fails one edges case !!!
    
//     map<int,int> m;
//     int ans = 0;
//     for(int i=0;i<n;i++){
//         m[arr[i]]++;
//     }
    
//     for(auto i : m){
//         if(m.count(i.first+k)>0){
//             ans++;
//         }
//     }
//     return ans;
    
// }
