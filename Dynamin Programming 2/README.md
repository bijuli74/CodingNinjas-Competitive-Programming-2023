## Longest Common Subsequence
Given two strings, 'S' and 'T' with lengths 'M' and 'N', find the length of the 'Longest Common Subsequence'.
For a string 'str'(per se) of length K, the subsequences are the strings containing characters in the same relative order as they are present in 'str,' but not necessarily contiguous. Subsequences contain all the strings of length varying from 0 to K.
Example :
Subsequences of string "abc" are:  ""(empty string), a, b, c, ab, bc, ac, abc.
```cpp
#include <bits/stdc++.h>
using namespace std;

int lcs(string s, string t)
{
	int n = s.size(), m=t.size();
	vector<vector<int>> dp(n+1, vector<int>(m+1));

	for(int i=0; i<n; ++i)
		for(int j=0; j<m; ++j)
			dp[i+1][j+1] = (s[i]==t[j]) ? dp[i][j]+1 : max(dp[i][j+1], dp[i+1][j]);
	
	return dp[n][m];
}
```
## Longest Increasing Subsequence
For a given array with N elements, you need to find the length of the longest subsequence from the array such that all the elements of the subsequence are sorted in strictly increasing order.
Strictly Increasing Sequence is when each term in the sequence is larger than the preceding term.
For example:
[1, 2, 3, 4] is a strictly increasing array, while [2, 1, 4, 3] is not.

```cpp
#include <bits/stdc++.h>

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> v;
    for(int i=0; i<n; ++i){
        int a = arr[i];
        int p = lower_bound(v.begin(), v.end(), a)-v.begin();
        if(p<v.size())
            v[p]=a;
        else
            v.push_back(a);
    }
    return v.size();
}
```
## Matrix Chain Multiplication
Given a chain of matrices A1, A2, A3,.....An, you have to figure out the most efficient way to multiply these matrices. In other words, determine where to place parentheses to minimize the number of multiplications.
You will be given an array p[] of size n + 1. Dimension of matrix Ai is p[i - 1]*p[i]. You need to find minimum number of multiplications needed to multiply the chain.
```cpp
#include <bits/stdc++.h>
int matrixChainMultiplication(int* a, int n) {
    vector<vector<int>> dp(n, vector<int>(n));

    for(int i=n-2; ~i; --i){
        for(int j=i+1; j<n; ++j){
            dp[i][j] = INT_MAX;
            for(int k=i; k<j; ++k)
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]+ a[i]*a[k+1]*a[j+1]);
        }
    }
    return dp[0][n-1];
}
```

## Distinct Subsequences
Given a string, count the number of distinct subsequences of it ( including empty subsequence ). For the uninformed, A subsequence of a string is a new string which is formed from the original string by deleting some of the characters without disturbing the relative positions of the remaining characters.
For example, "AGH" is a subsequence of "ABCDEFGH" while "AHG" is not.
```cpp
#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int M = 1e9+7;

void solve(){
    string s; cin >> s;
    vector<ll> dp(26);

    for(char c: s)
        dp[c-'A'] = accumulate(begin(dp), end(dp), 1LL)%M;
        
    cout << accumulate(begin(dp), end(dp), 1LL)%M << '\n';
}
int main()
{
    int t; cin>>t;
    while(t--){
        solve();
    }
}
```
## Miser Man $
Jack is a wise and miser man. Always tries to save his money.
One day, he wants to go from city A to city B. Between A and B, there are N number of cities(including B and excluding A) and in each city there are M buses numbered from 1 to M. And the fare of each bus is different. Means for all N*M busses, fare (K) may be different or same. Now Jack has to go from city A to city B following these conditions:
1. At every city, he has to change the bus.
2. And he can switch to only those buses which have number either equal or 1 less or 1 greater to the previous.
You are to help Jack to go from A to B by spending the minimum amount of money.
N, M, K <= 100.
```
The first loop initializes the dp array for the first city (city A). For each bus in the city, the cost of using that bus is stored as the initial value in dp.

The second loop iterates over all the remaining cities (from the second city to the last city). For each city, it iterates over all the buses in that city and computes the minimum cost of traveling to that city using any of the buses. It uses the values in the dp array of the previous city to compute the minimum cost.

To compute the minimum cost, the code considers the cost of using the current bus in the current city (given by g[i][j]) and the cost of using the three possible buses in the previous city that satisfy the given constraints. The three possible buses are the previous bus (k), the bus with one number less than the previous bus (l), and the bus with one number greater than the previous bus (r).
```

```cpp
#include <bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(0); cin.tie(0);

int g[105][105];

int main(){
    fast_io
    int n, m; cin>>n>>m;
    for(int i=0; i<n; ++i)
        for(int j=0; j<m; ++j)
            cin>>g[i][j];
    
    int dp[n][m];
    for(int i=0; i<m; ++i)
        dp[0][i]=g[0][i];

    for(int i=1; i<n; ++i){
        for(int j=0; j<m; ++j){
            int l, r, k;
            l = (j>0) ? dp[i-1][j-1] : INT_MAX;
            k = dp[i-1][j];
            r = (j<m-1) ? dp[i-1][j+1] : INT_MAX;
            dp[i][j] = g[i][j] + min(k, min(l, r));
        }
    }
    int ans = INT_MAX;
    for(int i=0; i<m; ++i)
        if(ans > dp[n-1][i] )
            ans = dp[n-1][i];
    
    cout << ans << "\n";
    return 0;
}
```
## Trader Profit
Mike is a stock trader and makes a profit by buying and selling stocks. He buys a stock at a lower price and sells it at a higher price to book a profit. He has come to know the stock prices of a particular stock for n upcoming days in future and wants to calculate the maximum profit by doing the right transactions (single transaction = buying + selling). Can you help him maximize his profit?
Note: A transaction starts after the previous transaction has ended. Two transactions can't overlap or run in parallel.
The stock prices are given in the form of an array A for n days.
Given the stock prices and a positive integer k, find and print the maximum profit Mike can make in at most k transactions.
```cpp
#include<bits/stdc++.h>
using namespace std;


int maxProfit(int k, vector<int>& price) {
    
    vector<int> dp(2*k+1, INT_MIN);
    dp[0] = 0;
    
    for(int j = 0; j < price.size(); j++) {
        
        for(int i = 0; i+2 <= 2*k; i += 2){
            
            dp[i+1] = max(dp[i+1], dp[i]-price[j]);
            dp[i+2] = max(dp[i+2], dp[i+1]+price[j]);
        }
    }
    return *max_element(dp.begin(), dp.end());
}

int main(){
    
    int t; cin>>t;
    while(t--){
        int n, k;
        cin >> k >> n;
        vector<int> a(n);
        for(int i=0; i<n; ++i) cin>>a[i];

        cout << maxProfit(k, a) << "\n";
    }
    return 0;
}
```
## Charlie and Pilots
Charlie acquired airline transport company and to stay in business he needs to lower the expenses by any means possible. There are N pilots working for his company (N is even) and N/2 plane crews needs to be made. A plane crew consists of two pilots - a captain and his assistant. A captain must be older than his assistant. Each pilot has a contract granting him two possible salaries - one as a captain and the other as an assistant. A captain's salary is larger than assistant's for the same pilot. However, it is possible that an assistant has larger salary than his captain. Write a program that will compute the minimal amount of money Charlie needs to give for the pilots' salaries if he decides to spend some time to make the optimal (i.e. the cheapest) arrangement of pilots in crews.
```cpp
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin>>n;
    vector<array<int, 2>> pilots(n);

    for(int i=0; i<n; ++i)
        cin>> pilots[i][0] >>pilots[i][1];

    int m = n/2;
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

    for(int i=n; ~i; --i){
        for(int j=0; j<=n-i; ++j){
            if(i==n) dp[i][j]=0;

            else if(dp[i][j]==-1){
                int ans;
                if(j==0){
                    ans = pilots[i][1] + dp[i+1][1];
                }
                else if(j==n-i){
                    ans = pilots[i][0] + dp[i+1][j-1];
                }
                else{
                    int op1 = pilots[i][1] + dp[i+1][j+1];
                    int op2 = pilots[i][0] + dp[i+1][j-1];
                    ans = min(op1, op2);
                }
                dp[i][j] = ans;
            }
        }
    }

    cout << dp[0][0] << "\n";
}
int main(){
    
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
```
## Square Brackets $
You are given:
a positive integer n,
an integer k, 1<=k<=n,
an increasing sequence of k integers 0 < s1 < s2 < ... < sk <= 2n.
What is the number of proper bracket expressions of length 2n with opening brackets appearing in positions s1, s2,...,sk?
Illustration
```
Several proper bracket expressions:
[[]][[[]][]] 
[[[][]]][][[]]
An improper bracket expression:
[[[][]]][]][[]]
```
```cpp
#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll M = 1e9+7;

ll dfs(vector<bool>& ok, ll n, ll open, ll closed, vector<vector<ll>>& dp){
    if(ok[0]) return 0;
    if(dp[open][closed] >= 0) return dp[open][closed];
    if(closed>n || open>n) return 0;
    if(closed==n && open==n) return 1;
    
    ll ans;
    if(open==closed || ok[closed+open+1])
        ans = dfs(ok, n, open+1, closed, dp);
    else if(open==n)
        ans = dfs(ok, n, open, closed+1, dp);
    else{
        ll op1 = dfs(ok, n, open+1, closed, dp);
        ll op2 = dfs(ok, n, open, closed+1, dp);
        ans = op1+op2;
    }
    dp[open][closed] = ans;
    return ans%M;
}

int main(){
    ll t; cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        vector<bool> ok(2*n+1, false);
        for(ll i=0; i<k; ++i){
            ll x; cin >> x;
            ok[x] = true;
        }

        vector<vector<ll>> dp(105, vector<ll>(105, -1));

        cout << dfs(ok, n, 0, 0, dp)%M << "\n";
    }
}


#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll M = 1e9+7;

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n, k;
         cin >> n >> k;
        vector<bool> v(2*n+1, false);
        for(ll i=0; i<k; ++i){
            ll x; cin >> x;
            v[x] = true;
        }

        vector<vector<ll>> dp(n+1, vector<ll>(n+1, -1));
        dp[0][0] = 1;
        for(ll open=0; open<=n; open++){
            for(ll closed=0; closed<=n; closed++){
                if(closed > open || closed > n || open > n || open < 0 || closed < 0)
                    dp[open][closed] = 0;
                else if(dp[open][closed] < 0){
                    if(closed == n && open == n)
                        dp[open][closed] = 1;
                    else{
                        if(open == closed || v[closed+open+1])
                            dp[open][closed] = dp[open+1][closed];
                        else if(open == n)
                            dp[open][closed] = dp[open][closed+1];
                        else
                            dp[open][closed] = (dp[open+1][closed] + dp[open][closed+1]) % M;
                    }
                }
            }
        }
        cout << dp[0][0] << "\n";
    }
}




// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long
// const int M = 1e9+7;

// ll f(ll m, vector<ll>& ok){
//     ll n = 2*m;
//     vector<vector<ll>> dp(n+1,  vector<ll>(n+1));
//     vector<bool> k(n+1);

//     for(ll i=0; i<ok.size(); ++i){
//         k[ok[i]] = true;
//     }
//     dp[0][0]=0, dp[1][1]=1;

//     for(ll j=2; j<=n; ++j)
//         dp[1][j]=0;
    
//     for(ll i=2; i<=n; ++i){
//         for(ll j=0; j<n; ++j){
//           if (j == 0) {
//             if (k[i])
//               dp[i][j] = 0;
//             else
//               dp[i][j] = dp[i - 1][1];
//             } 
            
//             else{
//                 if(k[i]) dp[i][j] = dp[i-1][j-1];
//                 else dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];

//             }
            
//         }
//     }

//     return dp[n][0]%M;
// }

// int main(){
//     ll t; cin>>t;
//     while(t--){
//         ll n, k;
//         cin >> n >> k;
//         vector<ll> ok(k);
//         for(ll i=0; i<k; ++i){
//             cin >> ok[i];
//         }
//         cout << f(n, ok) << "\n";
//     }
// }
```
## Balika Vadhu- Problem $$
Anandi and Jagya were getting married again when they have achieved proper age. Dadi Sa invited Alok Nath to do the kanyadaan and give blessings. Alok Nath has 2 blessings. Each bessing is in the form of a string consisting of lowercase charaters(a-z) only. But he can give only one blessing of K length because some priest told him to do so. Thus he decides to generate a blessing using the other two blessings. While doing this he wants to ensure that happiness brought into their life by his blessing is maximum.
The generated blessing is a common subsequence of length K of the two blessings he has. Happiness of the blessing he generates is calculated by the sum of ASCII values of characters in the blessing and he wants the happiness to be maximum. If he is not able to generate a common subsequence of length K then the happiness is 0 (zero). Alok Nath comes to you and asks you to find the maximum happiness that can be generated by the two blessings he has
```cpp

//BVAAN - Balika Vadhu and Alok Nath
#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll dp[105][105][105];
string s1,s2;
ll K;
vector<char> v;
ll N,M;
ll dfs(ll i,ll j,ll remain)
{
	if(i==N || j==M)
	{
		if(remain>0) return -1e18;
		else return 0;
	}
	if(dp[i][j][remain]!=-1)
	return dp[i][j][remain];
	if(s1[i]==s2[j])
	{
		if(remain>0)
			return dp[i][j][remain]=max(s1[i]+dfs(i+1,j+1,remain-1), max(dfs(i+1,j,remain), dfs(i,j+1,remain)));
		else
			return 0;
	}
	return dp[i][j][remain]=max(dfs(i+1,j,remain), dfs(i,j+1,remain));
}
int main()
{
	ll T;
	cin >> T;
	while(T--)
	{
		v.clear();
		memset(dp, -1, sizeof dp);
		cin >> s1 >> s2;
		N=s1.size();
		M=s2.size();
		
		cin >> K;
		cout << max(0LL, dfs(0, 0, K)) <<"\n";
	}
	return 0;
}
```
## LCS of 3 Strings
Given three strings A, B and C, the task is to find the length of the longest common subsequence in all the three strings A, B and C.
A subsequence of a string is a new string generated from the original string with some characters(possibly 0) deleted without changing the relative order of the remaining characters. (For eg, "cde" is a subsequence of "code" while "cdo" is not). A common subsequence of two or more strings is a subsequence that is common to all the strings.
```cpp
#include <bits/stdc++.h>

int LCS(string a, string b, string c)
{
  int n=a.size(), m=b.size(), o=c.size();
  int dp[n+1][m+1][o+1];
  // memset(dp, 0, sizeof dp);

  for(int i=0; i<=n; ++i){
    for(int j=0; j<=m; ++j){
      for(int k=0; k<=o; ++k){
        if(i==0 || j==0 || k==0) dp[i][j][k]=0;

        else if(a[i-1]==b[j-1] && a[i-1]==c[k-1])
          dp[i][j][k] = dp[i-1][j-1][k-1]+1;

        else
          dp[i][j][k] = max({dp[i-1][j][k], dp[i][j-1][k],  dp[i][j][k-1]});
      }
    }
  }

  return dp[n][m][o];
}
```
## Smallest Super-Sequence
Given two strings S and T with lengths M and N. Find and return the length of their shortest 'Super Sequence'.
The shortest 'Super Sequence' of two strings is defined as the smallest string possible that will have both the given strings as its subsequences.
```cpp
int smallestSuperSequence(string s1, string s2)
{
	int n=s1.size(), m=s2.size();
	vector<vector<int>> dp(n+1, vector<int>(m+1));

	int c=0;
	for(int i=m; ~i; --i) dp[n][i]=c++;

	c=0;
	for(int i=n; ~i; --i) dp[i][m] = c++;

	for(int i=n-1; ~i; --i){
		for(int j=m-1; ~j; --j){
			dp[i][j] = (s1[i]==s2[j]) ? dp[i+1][j+1]+1 : min(dp[i+1][j], dp[i][j+1]) +1;
		}
	}

	return dp[0][0];
}
```
## Atcoder E-Knapsack 2
There are N items, numbered 1,2,…,N. For each i (1≤i≤N), Item i has a weight of wiand a value of vi
Taro has decided to choose some of the N items and carry them home in a knapsack. The capacity of the knapsack is W, which means that the sum of the weights of items taken must be at most W.
Find the maximum possible sum of the values of items that Taro takes home.
```cpp
#include<bits/stdc++.h>

using namespace std;

int main(){
	// freopen("input.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);

	int n, W;
	cin>>n>>W;
	int w[n+1], v[n+1];
	for(int i=1; i<=n; i++){
		cin>>w[i]>>v[i];
	}

	//F(n, v) = MIN(F(n-1, v-V[n]) + W[n], F(n-1, v))
	//F(n, 0) = 0; F(0, v) = MAX

	const long long MAX = (long long)(1e9+7);
	int V = 0;
	for(int i=1; i<=n; i++) V += v[i];
	V++;
	long long dp[n+1][V];

	for(int i=0; i<=n; i++) dp[i][0] = 0;
	for(int i=1; i<V; i++) dp[0][i] = MAX;

	for(int i=1; i<=n; i++){
		for(int j=1; j<V; j++){
			if(v[i] <= j){
				dp[i][j] = min(dp[i-1][j], dp[i-1][j-v[i]] + w[i]);
			} else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	int maxV = 0;
	for(int i=V-1; i>=0; i--){
		if(dp[n][i] <= W){
			maxV = i;
			break;
		}
	}

	cout<<maxV<<"\n";

}
```
## CF Alyona and Strings
```cpp
#include<bits/stdc++.h>

using namespace std;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	/*
		F(n, m, k, 0):
			if s[n] = t[m] max(F(n-1, m-1, k, 1) + 1, F(n-1, m, k, 0), F(n, m-1, k, 0))
			else max(F(n-1, m, k, 0), F(n, m-1, k, 0))

		F(n, m, k, 1):
			if s[n] = t[m] max(F(n-1, m-1, k, 1) + 1, F(n, m, k-1, 0))
			else F(n, m, k-1, 0)

		Base cases:
		F(n, m, 0, flag) = 0, F(0, m, 1, 1) = F(n, 0, 1, 1) = 0
		Initialize: F(n, m, k, flag) = INT_MIN
	*/

	int n,m,K;
	cin>>n>>m>>K;

	string s, t;
	cin>>s;
	cin>>t;

	s = "#" + s;
	t = "@" + t;

	int dp[n+1][m+1][K+1][2];

	for(int i=0; i<=n; i++){
		for(int j=0; j<=m; j++){
			for(int k=0; k<=K; k++){
				for(int flag=0; flag<2; flag++){
					dp[i][j][k][flag] = INT_MIN;

					if(k == 0) dp[i][j][k][flag] = 0;

					if(i == 0 or j == 0){
						if(k == 1 and flag == 1) dp[i][j][k][flag] = 0;
					}
				}
			}
		}
	}

	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			for(int k=1; k<=K; k++){
				if(s[i] == t[j]){
					dp[i][j][k][0] = max(dp[i-1][j-1][k][1] + 1, max(dp[i-1][j][k][0], dp[i][j-1][k][0]));
					dp[i][j][k][1] = max(dp[i-1][j-1][k][1] + 1, dp[i][j][k-1][0]);
				} else{
					dp[i][j][k][0] = max(dp[i-1][j][k][0], dp[i][j-1][k][0]);
					dp[i][j][k][1] = dp[i][j][k-1][0];
				}				
			}
		}
	}

	cout<<max(dp[n][m][K][0], dp[n][m][K][1]);
	

	return 0;
}
```
## CF Caesers Legion $
https://codeforces.com/problemset/problem/118/D
```cpp
#include<bits/stdc++.h>

using namespace std;

int k1, k2;

const int mod = (int)(1e8);

long long dp[102][102][11][11];

long long f(int n1, int n2, int p1, int p2){
	if(p1 == -1 or p2 == -1) return 0;
	if(n1 == 0 and n2 == 0) return 1;

	if(dp[n1][n2][p1][p2] > -1) return dp[n1][n2][p1][p2];

	else{
		dp[n1][n2][p1][p2] = 0;
		if(n1 > 0) dp[n1][n2][p1][p2] = f(n1-1, n2, p1-1, k2);
		if(n2 > 0) dp[n1][n2][p1][p2] += f(n1, n2-1, k1, p2-1);

		dp[n1][n2][p1][p2] %= mod;
	}

	return dp[n1][n2][p1][p2];

}


int main(){
	
		int n1, n2;
		cin>>n1>>n2>>k1>>k2;

		for(int i=0; i<=n1; i++){
			for(int j=0; j<=n2; j++){
				for(int p1=0; p1<=k1; p1++){
					for(int p2=0; p2<=k2; p2++){
						dp[i][j][p1][p2] = -1;
					}
				}
			}
		}

		cout<<f(n1, n2, k1, k2)<<"\n";
	
	return 0;
}
```

## Expensive Subsequence
You are given two strings, ‘STR1’ and ‘STR2’, and an integer array ‘COST’, which contains the cost of each lowercase English letter. Your task is to find the cost of the most expensive common subsequence.
For example:
You are given ‘STR1’ = “abcd” and ‘STR2’ = “abed” and ‘COST’ = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
The answer will be 3. The most expensive common subsequence will be “abd”, where the cost of each letter is 1. Hence the final answer is 3.
```cpp
int findCost(vector<int> &cost, string s1, string s2)
{
    int n = s1.size(), m = s2.size();
    int mx = max(n, m);
    vector<int> c(2025);
    vector<vector<int>> dp(2025, vector<int>(2025, 0));

    for(int i='a', j=0; i<='z', j<=25; ++i, ++j)
        c[i] = cost[j];
    
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1] + c[s1[i-1]];
            }
            else{
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }

    return dp[n][m];
}
```
## Maximum Students
The Ultimate Ninja Ankush, has prepared a test for all of his fellow Ninja students, but since he is the Ultimate Ninja, he does not like cheating, and since his students are also ninjas, they broke some chairs in the dojo while practicing their moves.
The class consists of ‘M’ * ‘N’ seats, represented in a matrix ‘SEATS’. Among the seats, some of the seats are broken. If a seat is broken, it is denoted by '#' character otherwise it is denoted by a '.' character, denoting that the seat can be occupied. A Ninja can’t sit in a broken seat.
Ankush wants to avoid cheating at any cost. According to his observations, a student can see the answers of four neighboring students sitting next to the left, right, upper left, and upper right, but they cannot see the answers of the student sitting directly in front or behind him. Ankush is very busy so he wants to use the dojo to the fullest. More formally he wants to know the maximum number of ninja students that can be placed in the dojo.
```
For example
Given:
‘M’ = 3, ‘N’ = 3.
‘SEATS’ = {
   {‘.’, ‘.’, ‘.’},
   {‘#’,’#’, ‘#’},
   {‘.’,’.’,’.’} 
   }
The answer will be 4, since 4 students can be placed at the four corners, i.e. (0,0), (2,2), (2,0), and (0,2) such that no cheating is possible.
```
```cpp
#include <bits/stdc++.h>
using namespace std;

#define vvi vector<vector<int>>
#define vvc vector<vector<char>>

int maxStudents(vector<vector<char>>& seats)
{
    int n = seats.size();
    int m = seats[0].size();
    vector<int> validity;

    for (int i = 0; i < n; ++i)
    {
        int cur = 0;
        for (int j = 0; j < m; ++j)
        {
            if (seats[i][j] == '.')
            {
                cur = cur ^ (1 << j);
            }
        }
        validity.push_back(cur);
    }

    vvi dp(n + 1, vector<int>(1 << m, -1));

    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        int valid = validity[i - 1];
        for (int j = 0; j < (1 << m); ++j)
        {
            if ((j & valid) == j && !(j & (j >> 1)))
            {
                for (int k = 0; k < (1 << m); ++k)
                {
                    if (!(j & (k >> 1)) && !((j >> 1) & k) && dp[i - 1][k] != -1)
                    {
                        dp[i][j] = max(dp[i][j], dp[i - 1][k] + __builtin_popcount(j));
                    }
                }
            }
        }
    }

    return *max_element(dp[n].begin(), dp[n].end());
}

```
