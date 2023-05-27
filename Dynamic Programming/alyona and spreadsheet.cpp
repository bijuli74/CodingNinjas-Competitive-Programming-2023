#include <bits/stdc++.h>
using namespace std;
#define pb push_back

vector<vector<int> > A, B;
int n, m;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;

    vector<int> dp(n);
    for(int i=0;i<n;i++){
        vector<int>v(m), v2(m, 0);
        for(int j=0;j<m;j++)cin>>v[j];
        A.pb(v);
        B.pb(v2);
    }
    for(int i=0;i<m;i++){
        B[0][i]=0;
        for(int j=1;j<n;j++){
            if(A[j][i]>=A[j-1][i])
                B[j][i]=B[j-1][i];
            else
                B[j][i]=j;
        }
    }
    for(int i=0;i<n;i++){
        dp[i]=i;
      for(int j=0;j<m;j++)
        dp[i]=min(dp[i], B[i][j]);
    //cout<<i<<" "<<dp[i]<<endl;
    }

    int q, l, r;
    cin>>q;
    while(q--){
        cin>>l>>r;
        l--;r--;
        if(dp[r]<=l) cout<<"Yes\n";
        else cout<<"No\n";
    }
}
// int main(){
//     ios::sync_with_stdio(0); cin.tie(0);
//     int n, m; cin>>n>>m;

//     vector<int> row1(m), row2(m);
//     for(int i=0; i<m; ++i) cin>>row1[i];
//     for(int i=0; i<m; ++i) cin>>row2[i];
    
//     vector<int> dp(m, 0);
//     vector<int> dp2(m);
//     for(int i=0; i<m; ++i)
//         if(row2[i]>=row1[i]) dp2[i]=0;
//         else dp2[i]=1;
    
//     vector<int> min_row_ele(n);
//     min_row_ele[0] = *min_element(begin(dp), end(dp));
//     min_row_ele[1] = *min_element(begin(dp2), end(dp2));
    
//     for(int i=2; i<n; ++i){
//         for(int i=0; i<m; ++i){
//             dp[i] = dp2[i];
//         }
//         for(int j=0; j<m; ++j){
//             row1[j] = row2[j];
//         }

//         for(int j=0; j<m; ++j)
//             cin>>row2[j];

//         for(int j=0; j<m; ++j){
//             if(row1[j]<=row2[j])
//                 dp2[j]=dp[j];
//             else
//                 dp2[j]=i;
//         }

//         min_row_ele[i] = *min_element(begin(dp2), end(dp2));
        
//     }

//     int k; cin>>k;
//     while(k--){
//         int l, r;
//         cin>>l>>r;

//         if(min_row_ele[r-1]< l )
//             cout<<"Yes"<<'\n';
//         else
//             cout<<"No"<<'\n';
//     }

//     return 0;
// }
