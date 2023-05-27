#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;


void solve(){
    // take input of the segments & left-right points
    int n;
    cin>>n;
    vector<pair<int,int>>seg(n);
    vector<int>l(n),r(n);
    for(int i=0;i<n;i++){
        cin>>seg[i].first>>seg[i].second;
        l[i]=seg[i].first;
        r[i]=seg[i].second;
    }


    // sort the left & right points vector
    sort(l.begin(),l.end());
    sort(r.begin(),r.end());
    
    // initalize the maximum ans
    int ans =n-1;


    // binary search for each segment and minimize the ans
    for(int i=0;i<n;i++){
        int right_half = lower_bound(l.begin(),l.end(),seg[i].second+1)-l.begin();
        int left_half = lower_bound(r.begin(),r.end(),seg[i].first)-r.begin();
        ans = min(ans,n-right_half + left_half);
    }
    cout<<ans<<"\n";
}
                
int main(){
    ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            cout<<fixed;
            cout<<setprecision(10);
    //        freopen("timber_input.txt", "r", stdin);
    //        freopen("timber_output.txt", "w", stdout);
            int t=1;
            cin>>t;
            for(int i=1;i<=t;i++){
            //    cout<<"Case #"<<i<<": ";  
                solve();
    }
    return 0;
}
