## Return Subsets Sum to K

Given an integer array 'ARR' of size 'N' and an integer 'K', return all the subsets of 'ARR' which sum to 'K'.
Subset of an array 'ARR' is a tuple that can be obtained from 'ARR' by removing some (possibly all) elements of 'ARR'.
Note :
The order of subsets is not important. 
The order of elements in a particular subset should be in increasing order of the index.
```cpp
vector<vector<int>> findSubsetsThatSumToK(vector<int> a, int n, int k)
{
    vector<vector<int>> ans;
    for(int i=0; i<(1<<n); ++i){
        vector<int> temp;
        long long sum = 0;
        for(int j=0; j<n; ++j){
            if(i & (1<<j)){
                temp.push_back(a[j]);
                sum += a[j];
            }
        }
        if(sum==k) ans.push_back(temp);
    }
    return ans;
}
```
## CANDY $
Gary is a teacher at XYZ school. To reward his N students he bought a packet of N candies all with different flavours. But the problem is some students like certain flavour while some doesn't. Now Gary wants to know the number of ways he can distribute these N candies to his N students such that every student gets exactly one candy he likes.
```cpp
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int like[20][20];
int dp[(1<<16)+2];
int countWays(int mask){
    int temp=mask;
    int k=0;
    while(temp>0){
        k+=(temp&1);
        temp=temp>>1;
    }
    if(k==n) return 1;
    if(dp[mask]!=-1) return dp[mask];
    int ans=0;
    for(int j=0;j<n;j++){
        if(!(mask&(1<<j)) && like[k][j]){
            ans+=countWays(mask|(1<<j));
        }
    }
    dp[mask]=ans;
    return ans;
}
signed main(){
   int t; cin>>t; 
   while(t--){
       memset(dp,-1,sizeof(dp));
       cin>>n; for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>like[i][j];
       cout<<countWays(0)<<endl;
   }
}
```
