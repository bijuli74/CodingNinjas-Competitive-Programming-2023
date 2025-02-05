## Nth Fibonacci Number

Nth term of Fibonacci series F(n), where F(n) is a function, is calculated using the following formula -
F(n) = F(n-1) + F(n-2),
Where, F(1) = 1,
F(2) = 1
Provided N you have to find out the Nth Fibonacci Number.
```cpp
#include<bits/stdc++.h>
using namespace std;

int main()
{
      int n; cin>>n;
      int dp[n+1];
      dp[0]=0, dp[1]=1;
      for(int i=2; i<=n; ++i){
              dp[i]=dp[i-1]+dp[i-2];
      }
      cout<<dp[n]<<'\n';
      return 0;
}
```

## Staircase

A child is running up a staircase with n steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child can run up to the stairs. You need to return all possible number of ways.
Time complexity of your code should be O(n).
Since the answer can be pretty large print the answer % mod(10^9 +7)
```cpp
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
const int M = 1e9+7;
long long dp[N+1];

int main(){
    
    int t; cin>>t;

    dp[0]=1, dp[1]=1, dp[2]=2;
    for(int i=3; i<=N; ++i){
        dp[i]=(dp[i-1]+dp[i-2]+dp[i-3])%M;
    }

    while(t--){
        int n; cin>>n;
        cout<<dp[n]%M<<'\n';
    }
    return 0;
}
```

## Digits Decoding

A few days back, Ninja encountered a string containing characters from ‘A’ to ‘Z’ which indicated a secret message. For security purposes he encoded each character of the string to its numeric value, that is, A = 1, B = 2, C = 3, till Z = 26 and combined them as a single sequence (SEQ) of digits of length N. Let's say the message was "LA", Ninja encoded it as 121 for L=12 and A=1.
Today, when he read the encoded secret message, he realised that he was not able to decode the original string. So, the Ninja is wondering in how many ways he can decode the numeric sequence to some valid string.
A valid string is a string with characters from A to Z and no other characters.

```cpp
#include <vector>
const int M=1e9+7;

 bool isValid(char c) {
    return c != '0';
  }

  bool isValid(char c1, char c2) {
    return c1 == '1' || c1 == '2' && c2 < '7';
  }

int decodingDigits(string s)
{   
    int n = s.length();
    vector<long long> dp(n+1);
    dp[n]=1; //empty string
    dp[n-1]=isValid(s[n-1]);

    for(int i=n-2; ~i; --i){
        if(isValid(s[i]))
            dp[i]= (dp[i]+dp[i+1])%M;
        if(isValid(s[i], s[i+1]))
            dp[i] = (dp[i]+dp[i+2])%M;
    }
    return dp[0]%M;

}
 ```
 
## Coin Change (Infinite Supply)

You are given an infinite supply supply of coins of each of denominations D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total number of ways W, in which you can make change for Value V using coins of denominations D
```cpp
#include <vector>
const int M = 1e9+7;
int countWaysToMakeChange(int a[], int n, int x){
  vector<long long> dp(x+1);
  dp[0]=1;
  for(int i=0; i<n; ++i){
    for(int j=a[i]; j<=x; ++j)
      dp[j]+=dp[j-a[i]]%M;
  }
  return dp[x]%M;
}
```


## Coin Change(Finite Supply)

Send Feedback
You are given an array of integers ‘coins’ denoting the denomination of coins and another array of integers ‘freq’ denoting the number of coins of each denomination.
You have to find the number of ways to make the sum ‘V’ by selecting some(or all) coins from the array.
The answer can be very large. So, return the answer modulo 1000000007.
```cpp
const int M=1e9+7;
#define vt vector

int coinChange(int n, vector<int> &coins, vector<int> &freq, int v) {
    int mxf=1;
   mxf = *max_element(freq.begin(), freq.end());
   
   vt<vt<vt<int>>> dp(n, vt<vt<int>>(v+1, vt<int>(mxf+1, 0)));

   for(int i=0; i<n; ++i)
        for(int j=0; j<=freq[i]; ++j)
            dp[i][0][j]=1;
    
    for(int i=0; i<n; ++i){
        for(int j=1; j<=v; ++j){
            for(int k=0; k<=freq[i]; ++k){
                if(j-coins[i]>=0 && k>0)                             // Check if we can take the current coin or not
                    dp[i][j][k] = dp[i][j-coins[i]][k-1]%M;

                if (i > 0)                                                   // Go to the previous coin.
                  dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][freq[i - 1]]) % M;
            }
        }
    }
    
    return dp[n-1][v][freq[n-1]];

}
```


## Ninja and Coins

Ninja is at a shop and wants to buy a gift whose value is ‘K’. Ninja has N coins, each having a different denomination. While paying the shopkeeper, he found that he could pay the price of the gift using other ways. Ninja wants to know what is the number of different combinations in which Ninja can pay the price. Can you help the ninja to find the number of ways to make the value of ‘K’ using these ‘N’ coins?
You are given an array ‘COINS’ having ‘N’ integers corresponding to the value of each denomination and an integer ‘K’ denoting the value of the gift. Your task is to find the number of different ways in which the value ‘K’ can be made using these ‘N’ coins. The answer can be very large.Return answer % (10^9 +7).
```cpp
#include <vector>
const int M=1e9+7;
int ninjaAndCoins(int n, int k, vector<int> &a)
{
    vector<vector<long long>> dp(n+1, vector<long long>(k+1));
    for(int i=0; i<=n; ++i) dp[i][0]=1;
    for(int i=1; i<=k; ++i) dp[0][i]=0;

    for(int i=1; i<=n; ++i){
      for(int j=1; j<=k; ++j){
        if(a[i-1]>j) dp[i][j]=dp[i-1][j]%M;
        else dp[i][j] = (dp[i-1][j] + dp[i-1][j-a[i-1]])%M;
      }
    }

    return dp[n][k]%M;
}
```


## Maze obstacles

Given a ‘N’ \* ’M’ maze with obstacles, count and return the number of unique paths to reach the right-bottom cell from the top-left cell. A cell in the given maze has a value '-1' if it is a blockage or dead-end, else 0. From a given cell, we are allowed to move to cells (i+1, j) and (i, j+1) only. Since the answer can be large, print it modulo 10^9 + 7.
For Example :
Consider the maze below :
0 0 0
0 -1 0
0 0 0

There are two ways to reach the bottom left corner -

(1, 1) -> (1, 2) -> (1, 3) -> (2, 3) -> (3, 3)
(1, 1) -> (2, 1) -> (3, 1) -> (3, 2) -> (3, 3)

Hence the answer for the above test case is 2.

```cpp
const int M = 1e9+7;
int mazeObstacles(int n, int m, vector< vector< int> > &g) {
    if(g[0][0]==-1) return 0;

    for(int i=0; i<n; ++i){
        if(g[i][0]==0) g[i][0]=1;
        else break;
    }
    for(int i=1; i<m; ++i){  //not i=1 not 0 init topmost  row
        if(g[0][i]==0) g[0][i]=1;
        else break;
    }

    for(int i=1; i<n; ++i){
        for(int j=1; j<m; ++j){
            if(g[i][j]==-1) continue;
            if(g[i-1][j]>0)
                g[i][j] = (g[i][j] + g[i-1][j])%M;
            if(g[i][j-1]>0)
                g[i][j] = (g[i][j] + g[i][j-1])%M;
        }
    }
    return (g[n-1][m-1]>0) ? g[n-1][m-1] : 0;
}
```

## Min Cost Path

Given an integer matrix of size m\*n, you need to find out the value of minimum cost to reach from the cell (0, 0) to (m-1, n-1).
From a cell (i, j), you can move in three directions : (i+1, j), (i, j+1) and (i+1, j+1).
Cost of a path is defined as the sum of values of each cell through which path passes.

```cpp
// m - number of rows
/// n - number of columns
#include <bits/stdc++.h>
using namespace std;

int minCostPath(int **g, int m, int n) {
    int dp[m+1][n+1] = {0};
    dp[m-1][n-1] = g[m-1][n-1];

    for(int i=m-2; ~i; --i)
        dp[i][n-1] = dp[i+1][n-1] + g[i][n-1];
    
    for(int j=n-2; ~j; --j)
        dp[m-1][j] = dp[m-1][j+1] + g[m-1][j];
    
    for(int i=m-2; ~i; --i)
        for(int j=n-2; ~j; --j)
            dp[i][j] = g[i][j] + min({dp[i+1][j], dp[i][j+1], dp[i+1][j+1]});

    return dp[0][0];
}
```

## Boredom

Gary is bored and wants to play an interesting but tough game . So he figured out a new board game called "destroy the neighbours" . In this game there are N integers on a board. In one move, he can pick any integer x from the board and then all the integers with value x+1 or x-1 gets destroyed .This move will give him x points.
He plays the game until the board becomes empty . But as he want show this game to his friend Steven, he wants to learn techniques to maximise the points to show off . Can you help Gary in finding out the maximum points he receive grab from the game ?

```cpp
#include<bits/stdc++.h>
using namespace std;

const int mxA=1000;

void solve(int n, vector<int>& a){
    vector<int> f(mxA+1, 0);
    vector<int> dp(mxA+1, 0); //dp[points]

    for(int i=0; i<n; ++i) f[a[i]]++;

    dp[1]=f[1];

    for(int i=2; i<=mxA; ++i)
        dp[i] = max(dp[i-1], dp[i-2]+i*f[i]);
    
    cout<< dp[mxA] << '\n';
    return;
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n; 
        vector<int> a(n);
        for(int i=0; i<n; ++i) cin>>a[i];
        solve(n, a);
    }
    
    return 0;
}
```

## Minimum Number of Chocolates

Miss. Noor Rashid is a teacher. She wants to give some chocolates to the students in her class. All the students sit in a line, and each of them has a score according to performance. Noor wants to give at least one chocolate to each student. She distributes chocolates to them such that If two students sit next to each other, then the one with the higher score must get more chocolates. Miss. Noor wants to save money, so she wants to minimize the total number of chocolates.

```cpp
#include <vector>
int getMin(int *a, int n)
{
  int ans = 0;
  if (n == 1)
    return 1;
  vector<int> v(n, 1);
  for (int i = 0; i < n - 1; ++i) {
    if (a[i + 1] > a[i])
      v[i + 1] = v[i] + 1;
  }
  for (int i = n - 2; ~i; --i) {
    if (a[i] > a[i + 1] && v[i] <= v[i + 1]) {
      v[i] = v[i + 1] + 1;
    }
    ans += v[i];
  }
  ans += v[n - 1];
  return ans;
}
```

## Minimum Count

Given an integer N, find and return the count of minimum numbers required to represent N as a sum of squares.
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. The output will be 1, as 1 is the minimum count of numbers required to represent N as sum of squares.

```cpp
int minCount(int n)
{
	vector<int> dp(n+1, n);
	dp[0]=0;
	dp[1]=1;
	for(int i=2; i<=n; ++i)
		for(int j=1; j*j<=i; ++j)
			dp[i] = min(dp[i], dp[i-j*j]+1);
	return dp[n];
}
```

## Vanya and GCD

Vanya has been studying all day long about sequences and other Complex Mathematical Terms. She thinks she has now become really good at it. So, her friend Vasya decides to test her knowledge and keeps the following challenge it front of her:
Vanya has been given an integer array A of size N. Now, she needs to find the number of increasing sub-sequences of this array with length ≥1 and GCD=1. A sub-sequence of an array is obtained by deleting some (or none) elements and maintaining the relative order of the rest of the elements. As the answer may be large, print it Modulo 109+7

```cpp
#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mxA=100;
const int M = 1e9+7;
int main(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin>>a[i];
    
    vector<vector<ll>> dp(n, vector<ll>(mxA+1));

    dp[0][a[0]]=1;
    ll ans=dp[0][1];
    
    for(int i=1; i<n; ++i){
        for(int k=i-1; ~k; --k){
            if(a[i]>a[k]){
              for (int g = 1; g <= mxA; ++g) {
                int cur_gcd = __gcd(g, a[i]);
                dp[i][cur_gcd] = (dp[i][cur_gcd] + dp[k][g]) %M;
              }
            }
        }
        dp[i][a[i]]++;
        ans = (ans+ dp[i][1]) % M;
    }

    cout<<ans<<'\n';
}
```

## Alyona and Spreadsheet

During the lesson small girl Alyona works with one famous spreadsheet computer program and learns how to edit tables.
Now she has a table filled with integers. The table consists of n rows and m columns. By ai, j we will denote the integer located at the i-th row and the j-th column. We say that the table is sorted in non-decreasing order in the column j if ai, j ≤ ai + 1, j for all i from 1 to n - 1.
Teacher gave Alyona k tasks. For each of the tasks two integers l and r are given and Alyona has to answer the following question: if one keeps the rows from l to r inclusive and deletes all others, will the table be sorted in non-decreasing order in at least one column? Formally, does there exist such j that ai, j ≤ ai + 1, j for all i from l to r - 1 inclusive.

```cpp
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
```

## Angry Children

Bill Gates is on one of his philanthropic journeys to a village in Utopia. He has N packets of candies and would like to distribute one packet to each of the K children in the village (each packet may contain different number of candies). To avoid a fight between the children, he would like to pick K out of N packets such that the unfairness is minimized.
Suppose the K packets have (x1, x2, x3,....xk) candies in them, where xi denotes the number of candies in the ith packet, then we define unfairness as

```cpp
unfairness=0;
for(i=0;i<n;i++)
    for(j=i;j<n;j++)
        unfairness+=abs(xi-xj)
```

## 0 1 Knapsack

A thief is robbing a store and can carry a maximum weight of ‘W’ into his knapsack. There are 'N' items available in the store and the weight and value of each item is known to the thief. Considering the constraints of the maximum weight that a knapsack can carry, you have to find the maximum profit that a thief can generate by stealing items.
Note: The thief is not allowed to break the items.
For example, N = 4, W = 10 and the weights and values of items are weights = [6, 1, 5, 3] and values = [3, 6, 1, 4]. Then the best way to fill the knapsack is to choose items with weight 6, 1 and 3. The total value of knapsack = 3 + 6 + 4 = 13.

```cpp
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w) {
  vector<int> dp(w + 1);

  for (int i = 0; i < n; ++i)
    for (int j = w; j >= weights[i]; --j)
      dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);

  return dp[w];
}
```

## Loot Houses

A thief wants to loot houses. He knows the amount of money in each house. He cannot loot two consecutive houses. Find the maximum amount of money he can loot.
```cpp 
#include <bits/stdc++.h>
using namespace std;

int maxMoneyLooted(int *arr, int n)
{
	if(n==0) return 0;
	if(n==1) return arr[0];

	vector<int> dp(n);

	dp[0] = arr[0];
	dp[1] = max(arr[0], arr[1]);

	for(int i=2; i<n; ++i)
		dp[i] = max(dp[i-1], dp[i-2] + arr[i]);

	return dp[n-1];

}
```

## One Away

You are given two strings, string A and string B. Your task is to determine whether string A can be transformed into string B by performing only one of the following operations at most one (or maybe zero) time.

1. You can delete a character from any position.
2. You can replace a character with any other character.
3. You can insert a character at any position.
   Note :
4. The strings are non-empty.
5. The strings only contain lowercase English letters.

```cpp
// int editDistance(string &s, string &t) {
//         if (s.size() < t.size()) swap(s, t);
//         int M = s.size(), N = t.size();
//         vector<int> dp(N + 1, 0);
//         for (int i = 1; i <= N; ++i) dp[i] = i;
//         for (int i = 1; i <= M; ++i) {
//             int pre = dp[0];
//             dp[0] = i;
//             for (int j = 1; j <= N; ++j) {
//                 int tmp = dp[j];
//                 if (s[i - 1] == t[j - 1]) dp[j] = pre;
//                 else dp[j] = min(pre, min(dp[j - 1], dp[j])) + 1;
//                 pre = tmp;
//             }
//         }
//         return dp[N];
//     }

bool isOneAway(string a, string b) {
    // Edit distance variation One Edit Distance

    int n=a.length(), m=b.length();
    if(a==b) return 1;
    if(n>m) return isOneAway(b, a);

    for(int i=0; i<n; ++i){
        if(a[i] != b[i]){
            if(n==m){
                return a.substr(i+1)==b.substr(i+1);
            }
            return a.substr(i) == b.substr(i+1);
        }
    }
    return n+1 == m;

    // return editDistance(a, b) == 1;
}
```
