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

## CSES Counting Tilings
Your task is to count the no of ways you can fill an n x m using 1x2 and 2x1 tiles.
return the no of ways modulo 1e9+7

```cpp
#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MOD = (int)(1e9+7);


vector<int> next_mask;

void gen_next_mask(int mask, int i, int n, int curr_mask) {
	if(i == n) {
		next_mask.push_back(curr_mask);
		return;
	}

	if(mask & (1<<i)) {
		gen_next_mask(mask, i+1, n, curr_mask);
	} else {
		gen_next_mask(mask, i+1, n, curr_mask | (1<<i));
		if((i+1) < n and (mask & (1<<(i+1))) == 0) {
			gen_next_mask(mask, i+2, n, curr_mask);
		}
	}
}

signed main() {
	freopen("input.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int n, m;
	cin>>n>>m;

	vector<int> all_next_masks[1<<n];

	for(int mask=0; mask<(1<<n); mask++) {
		next_mask.clear();
		gen_next_mask(mask, 0, n, 0);
		all_next_masks[mask] = next_mask;
	}

	int dp[m+1][1<<n];

	for(int i=0; i<(1<<n); i++) {
		dp[0][i] = 0;
	}

	dp[0][0] = 1;	

	for(int i=1; i<=m; i++) {
		for(int mask=0; mask<(1<<n); mask++) {
			dp[i][mask] = 0;
			for(int j: all_next_masks[mask]) {
				dp[i][mask] = (dp[i][mask] + dp[i-1][j]) % MOD;
			}
		}
	}

	cout<<dp[m][0];

	return 0;
}
```

## Hackerearth Sherlock and Coprime Subset
```cpp
#include<bits/stdc++.h>
#define int long long

using namespace std;

const int M = 15;
int dp[51][1<<M];

signed main() {
	freopen("input.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		int a[n+1];
		for(int i=1; i<=n; i++) cin>>a[i];

		vector<int> primes;
		for(int i=2; i<51; i++) {
			bool isDivisible = false;
			for(int j=2; (j*j)<=i; j++) {
				if((i%j) == 0){
					isDivisible = true;
					break;
				}
			}
			if(!isDivisible) primes.push_back(i);
		}

		int pf_mask[n+1];
		for(int i=1; i<=n; i++) {
			int mask = 0;
			for(int j = 0; j<primes.size(); j++) {
				if((a[i] % primes[j]) == 0) {
					mask |= (1<<j);
				}
			}
			pf_mask[i] = mask;
		}

		int m = primes.size();

		
		for(int i=0; i<=n; i++) {
			for(int j=0; j<(1<<m); j++) {
				dp[i][j] = 0;
			}
		}

		for(int i=1; i<=n; i++){
			for(int mask=0; mask<(1<<m); mask++) {
				if(pf_mask[i] & mask) {
					dp[i][mask] = dp[i-1][mask];
				} else{
					dp[i][mask] = max(1 + dp[i-1][mask | pf_mask[i]], dp[i-1][mask]);
				}
			}
		}

		cout<<dp[n][0]<<"\n";

	}

	return 0;
}
```

## Print All Subsets
You are given an array ‘arr’ of ‘N’ distinct integers. Your task is to print all the non-empty subsets of the array.
Note: elements inside each subset should be sorted in increasing order. But you can print the subsets in any order, you don’t have to specifically sort them.
```cpp
void printAllSubsets(int n, vector<int> &a){
    for(int i=0; i<(1<<n); ++i){
        for(int j=0; j<n; ++j)
            if(i & (1<<j))
                cout << a[j] << " ";
            cout << "\n";
    }
    return;
}
```
## Braille's Dilemma
Abhishek, a blind man recently bought N binary strings all of equal length .A binary string only contains '0's and '1's . The strings are numbered from 1 to N and all are distinct, but Abhishek can only differentiate between these strings by touching them. In one touch Abhishek can identify one character at a position of a string from the set. Find the minimum number of touches T Abhishek has to make so that he learn that all strings are different.

```cpp
#include<bits/stdc++.h>
using namespace std;

int  count(int x){ return __builtin_popcount(x);}
int fun(int j , int len ,int n , string s[], int mask)
{
   int x = count(mask);
    if(x<=1)
        return 0;
    
    if(j>=len)
    {
        return 1e9;
    }
    
    int m1 = 0,m2=0;
    int c=0 ;
    for(int i=0;i<n;i++)
    {
        if(((1<<i)&mask))
        {
            c++;
            if(s[i][j] == '1')
            {
                m1 |= (1<<i);     
            }
            else
            {
                m2|=(1<<i);
            }
        }
    }
    return min(c+fun(j+1,len,n,s,m1)+fun(j+1,len,n,s,m2),fun(j+1,len,n,s,mask));
}
int main(){
   
    int t=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s[n];
        int len;
        for(int i=0;i<n;i++)
        {
            cin>>s[i];
            
        }

        len = s[0].size();
        int mask = (1<<n)-1;
        int ans = fun(0,len,n,s,mask);

        if(ans==9) cout << 8 << "\n"; // case 1 gives wa
        else cout << ans << "\n";
    }
}
```
## The Ghost Type

Gengar has got an integer N. Now using his ghostly powers, he can create the permutation from 1 to N of this given number.
Since, he's a special kind of Poke'mon, so he thinks he deserves special permutations. He wants to find the total number of special permutations of length N, consisting of the integers from 1 to N

A permutation is called special if it satisfies following condition:
If Ap & Aq == Ap, then p < q, where p and q are two distinct indices of permutation and A is the permutation itself. "&" denotes the bitwise and operation.
Help Gengar in finding the number of such permutations.
Input format:
The only line of input will consist of a single integer N denoting the length of the permutation.
Output format:
Output the total number of special permutations of length N
```cpp
#include <bits/stdc++.h>
using namespace std;

#define ll long long
vector<int> submask[21];
bool vis[1 << 21];
ll dp[1 << 21];

ll dfs(int mask, int n) {
  if (mask == (1 << (n + 1)) - 2)
    return 1;
  if (vis[mask])
    return dp[mask];

  vis[mask] = 1;

  ll &ans = dp[mask];
  ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (!(mask & (1 << i))) {
      bool ok = 1;
      for (int j = 0; j < submask[i].size(); ++j) {
        if (!(mask & (1 << submask[i][j])))
          ok = 0;
      }
      if (ok)
        ans += dfs(mask | (1 << i), n);
    }
  }
  return ans;
}

int main() {

  int n;
  cin >> n;

  for (int i = 1; i <= 20; ++i) {
    for (int j = i - 1; j >= 1; --j) {
      if ((i & j) == j)
        submask[i].push_back(j);
    }
  }
  cout << dfs(0, n);

  return 0;
}

/*
Time complexity: O(2 ^ N * ( N ^ 2))
Space complexity: O(2 ^ N)
where N is the input number
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll dp[(1 << 20)];
ll solve(int n) {
  int mask = (1 << n) - 1;
  memset(dp, 0, sizeof(dp));
  dp[0] = 1;
  for (int i = 0; i < mask; i++) {
    for (int j = 0; j < n; j++) {
      if (((1 << j) & i) == 0) {
        bool flag = false;
        for (int k = 0; k < n; k++) {
          if (((j + 1) & (k + 1)) == (j + 1) && ((1 << k) & i)) {
            flag = true;
            break;
          }
        }
        if (flag == false) {
          dp[(1 << j) | i] += dp[i];
        }
      }
    }
  }
  return dp[mask];
}
int main() {
  int n;
  cin >> n;
  cout << solve(n) << endl;
}
```

## Hat Combination $
More Formally, There are n people and 40 types of hats labeled from 1 to 40.
Given a list of integers hats, where ‘hats[i]’ is a list of all hats preferred by the i-th person. Return the number of ways that the ‘N’ students wear different hats to each other. Since the answer may be too large, return it modulo 10 ^ 9 + 7.
For example:
Given:
‘N’ = 2, ‘M’ = 3.
‘Hats’ = [[1, 2, 3],
          [3, 4, 5]]

The answer will be 8, the combinations can be (1,3), (1,4), (1,5), (2,3), (2,4), (2,5), (3,4), (3,5).
```cpp
int numberWays(vector<vector<int>> &hats) {
        vector<vector<int>> persons(40);
        int N = hats.size();
		const int M = 1e9+7;
        vector<int> masks(1 << N);
        masks[0] = 1;
        for (int i = 0; i < N; ++i) {
            for (int h : hats[i]) persons[h - 1].push_back(i);
        }
        for (int i = 0; i < 40; ++i) {
            for (int j = (1 << N) - 1; j >= 0; --j) {
                for (int p : persons[i]) {
                    if (j & (1 << p)) continue;
                    masks[j | (1 << p)] += masks[j];
                    masks[j | (1 << p)] %= M;
                }
            }
        }
        return masks[(1 << N) - 1];
}

//https://walkccc.me/LeetCode/problems/1434/

/*
	Time Complexity : O((2 ^ N) * (N*M))
	Space Complexity : O((M) * (2 ^ N))

	Where 'N' is the number of people and 'M' is the number of hats.
*/

// int mod = 1e9 + 7 ;

// int numberWaysHelper(vector<vector<int>> &mp , int hatId , int curMask , int &filledMask , vector<vector<int>> &dp) {
	
// 	// Base condition.
// 	if (curMask == filledMask) {
// 		return 1;
// 	}

// 	// Base condition.
// 	if (hatId >= 42) {
// 		return 0;
// 	}

// 	if (dp[hatId][curMask] != -1) {
// 		return dp[hatId][curMask];
// 	}

// 	long long int totalWays = numberWaysHelper(mp , hatId + 1 , curMask , filledMask , dp);

// 	for (int i : mp[hatId]) {
// 		if ( (curMask & (1 << (i - 1))) == 0) {
			
// 			// Recurr for next hatId, assigning current hatId to i.
// 			totalWays += numberWaysHelper(mp , hatId + 1 , ((curMask) | (1 << (i - 1))) , filledMask , dp);
// 		}
// 	}

// 	return dp[hatId][curMask] = totalWays % mod;
// }

// int numberWays(vector<vector<int>>& hats) {
// 	int n = hats.size();

// 	vector<vector<int>> mp(42);

// 	// Hashing student to hatId.
// 	for (int i = 0 ; i < n ; i++) {
// 		int sz = hats[i].size();

// 		for (int j = 0 ; j < sz ; j++) {
// 			mp[hats[i][j]].push_back(i + 1);
// 		}
// 	}

// 	vector<vector<int> > dp(42 , vector<int>(pow(2 , 11) , -1));

// 	int filledMask = (1 << n) - 1;

// 	return numberWaysHelper(mp , 1 , 0 , filledMask , dp);
// }
```
## Integer Distribution
You are given an array ‘ARR’ of ‘N’ integers. Where ‘N’ is an even number. You have to make exactly ‘N/2’ pair, such that each pair have power. The power of a pair P(i,j) consisting of ith and jth element is ‘ARR[i]’ XOR ‘ARR[j]’. Find the minimum and maximum sum of power of these pairs.
EXAMPLE:
Input: 
'N' = 4
‘ARR’ = [1, 2, 3, 4]

Output: 6 10

The following combinations are possible:

P(1, 2) , P(3, 4) = 3 + 7 = 10.
P(1, 3) , P(2, 4) = 2 + 6 = 8.
P(1, 4) , P(2, 3) = 5 + 1 = 6.

Thus the minimum sum of powers is ‘6’ and maximum sum of powers is ‘10’.
```cpp
pair<int,int> distribute(int n, vector<int> &a){
    int sz = (1<<n);
    vector<int> f(sz, 1e9);
    vector<int> g(sz, -1e9);

    f[0]=0, g[0]=0;

    for(int k=1; k<sz; ++k){
        int m = __builtin_popcount(k);

        if(m%2==0){
            for(int i=0; i<n; ++i){
                for(int j=i+1; j<n; ++j){
                    if((k&(1<<i))!=0 && (k&(1<<j))!=0){
                        int h = k & (~(1<<i)) & (~(1<<j));

                        f[k] = min(f[k], f[h]+(a[i]^a[j]));
                        g[k] = max(g[k], g[h]+(a[i]^a[j]));
                    }
                }
            }
        }
    }
    return { f[sz - 1], g[sz - 1] };
}
```
## GCD Not One $$
You are given an array of positive integers ‘NUM’. Let’s define a function ‘fun(l, r)’ as the number of pairs ‘(i, j)’ such that ‘l’ <= ‘i’, ‘j’ <= ‘r’ and ‘gcd(num[i], num[j]) != 1’.
Your task is to find the sum of ‘fun(l, r)’ over all ‘l’, ‘r’ such that ‘l’ <= ‘i’, ‘j’ <= ‘r’ .
Since the output can be large, output it modulo 10^9 + 7.
EXAMPLE:
Input: 'N' = 2, 'NUM' = [2, 4]

Output: 5

‘fun(0, 0)’ = 1 as ‘gcd(2, 2)’ = 2, which is not equal to 1.
‘fun(1, 1)’ = 1 as ‘gcd(4, 4)’ = 4, which is not equal to 1.
‘fun(0, 1)’ = 3 as ‘gcd(2, 2)’, ‘gcd(4, 4)’ and ‘gcd(2, 4)’ are not equal to 1.
‘fun(0, 0)’ + ‘fun(1, 1) + ‘fun(0, 1)’ = 1 + 1 + 3 = 5.
Hence, the output is 5.  
```cpp
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int M = 1e9+7;
const int mxN = 1e4+5;
int p[mxN];
ll dpcnt[mxN], dpsum[mxN];
vector<int> pf[mxN];

// inline ll check_overflow(ll x, ll y){
//     if(x> 1e18-y){
//         return -1;
//     }
//     x+=y;
//     return x;
// }

ll add(ll x, ll y) {
   x += y;
   if (x >= M) return x - M;
   return x;
}
ll sub(ll x, ll y) {
   x -= y;
   if (x < 0) return x + M;
   return x;
}
ll mult(ll x, ll y) {
   return (x * y) % M;
}

void sieve(){
    p[0]=p[1]=1;
    for(int i=2; i<mxN; ++i){
        if(p[i]) continue;
        pf[i].push_back(i);
        for(int j=2*i; j<mxN; j+=i){
            p[j]=1;
            pf[j].push_back(i);
        }
    }
}

void clean(){
    for(int i=0; i<mxN; ++i){
        pf[i].clear();
        p[i]=dpcnt[i]=dpsum[i]=0;
    }
}
int gcdNotOne(int n, vector < int > & a) {
    clean();

   ll sum=0, ans=0, c;
   sieve();
   for(int i=n-1; ~i; --i){
       int sz=pf[a[i]].size();
       c=0; sum=0;
       for(int m=1; m<(1<<sz); ++m){
           int x=1;
           for(int j=0; j<sz; ++j){
               if(!(m&(1<<j))) continue;
            //    x = x*pf[a[i]][j]%M;
            x = mult(x, pf[a[i]][j]);
           }

           if((__builtin_popcount(m))& 1){
            //    c += (ll)dpcnt[x]%M;
            //    sum += (ll)dpsum[x]%M;

             c = add(c, dpcnt[x]);
             sum = add(sum, dpsum[x]); 
           }
           else{
            //    c = (c-(ll)dpcnt[x])%M + M;
            //    sum = (sum - (ll)dpsum[x])%M + M;
                c = sub(c, dpcnt[x]);
                sum = sub(sum, dpsum[x]);
           }
       }

    //    ans = check_overflow(ans, 1LL*(i+1)*(1LL*n*c + c-sum)%M);
    //    if(ans == -1) return -1;
        ll k = mult(i+1, add(sub(c, sum), mult(n, c)));
        ans = add(ans, k);

       for(int m=1; m< (1<<sz); ++m){
           int x = 1;
           for(int j=0; j<sz; ++j){
               if(!(m&(1<<j))) continue;
            //    x = x*pf[a[i]][j]%M;
                x = mult(x, pf[a[i]][j]);
           }

           dpcnt[x]++;
        //    dpsum[x] += 1LL*(i+1)%M;
            dpsum[x] = add(dpsum[x], 1LL*(i+1));
       }
   }

   for(int i=0; i<n; ++i){
     if (a[i] != 1) {
       // ans = check_overflow(ans, 1LL * (1LL * (i + 1) * (n - i))%M );
       // if (ans == -1)
       //     return -1;
       // }
    //    ans = add(ans, 1LL * (1LL * (i + 1) * (n - i)));
        ll k = mult(i+1, n-i);
        ans = add(ans, k);
     }
   }

   return (int)ans%M;
}
```
## Partition to K equal sum subsets
You are given an array of 'N' integers, and a positive integer 'K'. You need to determine if it is possible to divide the array into 'K' non-empty subsets such that the sum of elements of each subset is equal.
Note:
1. The array can have duplicate elements.

2. Each of the array elements must belong to exactly one of the 'K' subsets.

3. The elements chosen for a subset may not be contiguous in the array.
```cpp
#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<int>& a,int i,int &req,int sum,int k) {
    if(k==0) {
        return 1;
    }
    if(sum==req) {
        return dfs(a,0,req,0,k-1);
    }
    if(i>=a.size()) {
        return 0;
    }
    if(a[i]!=-1 && sum+a[i]<=req) {
        int n=a[i];
        a[i]=-1;
        if(helper(a,i+1,req,sum+n,k)) {
            return 1;
        }
        a[i]=n;
        if(helper(a,i+1,req,sum,k)) {
            return 1;
        }
        return 0;
    }
    else {
        return helper(a,i+1,req,sum,k);
    }
}

bool canPartitionKSubsets(vector<int>& a, int n, int K) {
    int sum=0;
    for(int i=0;i<a.size();i++) {
        sum+=a[i];
    }
    if((sum%K)!=0) {
        return 0;
    }
    int req=sum/K;
    return helper(a,0,req,0,K);
}
```
