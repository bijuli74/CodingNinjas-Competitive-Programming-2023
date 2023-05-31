## LCA - Lowest Common Ancestor
The lowest common ancestor (LCA) is a concept in graph theory and computer science.
Let ‘T’ be a rooted tree with ‘N’ nodes. The lowest common ancestor is defined between two nodes, ‘u’ and ‘v’, as the lowest node in ‘T’ that has both ‘u’ and ‘v’ as descendants (where we allow a node to be a descendant of itself). - Wikipedia
For the given tree, The LCA of nodes 5 and 8 will be node 2, as node 2 is the first node that lies in the path from node 5 to root node 1 and from node 8 to root node 1.
Path from node 5 to root node looks like 5 → 2 → 1.
Path from node 8 to root node looks like 8 → 6 → 2 → 1.
Since 2 is the first node that lies in both paths. Hence LCA will be 2.
Given any two nodes ‘u’ and ‘v’, find the LCA for the two nodes in the given Tree ‘T’.
Note: For each test case, the tree is rooted at node 1.
```cpp
const int mxN = 1e5;
vector<int> adj[mxN+1];

int d[mxN], anc[mxN][17];

void dfs(int u=0, int p=-1){
	anc[u][0]=p;
	for(int i=1; i<17; ++i)
		anc[u][i] = ~anc[u][i-1] ? anc[ anc[u][i-1] ][i-1] : -1;
	
	for(int v: adj[u]){
		if(v==p)
			continue;
		d[v] = d[u]+1;
		dfs(v, u);
	}
}

int lca(int u, int v){
	if(d[u]<d[v])
		swap(u, v);
	for(int i=16; ~i; --i)
		if(d[u]-(1<<i) >= d[v])
			u = anc[u][i];
		if(u==v)
			return u;
		for(int i=16; ~i; --i)
			if(anc[u][i]^anc[v][i])
				u = anc[u][i], v=anc[v][i];
		
		return anc[u][0];
}

vector<int> lca(int n, vector<vector<int>> edges, vector<vector<int>> query){

	for(int i=0; i<=mxN; ++i){
		adj[i].clear();
		d[i]=0;
	}
	
	for(int i=0; i<edges.size(); ++i){
		int u=edges[i][0], v=edges[i][1];
		--u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs();

	vector<int> ans;

	for(int i=0; i<query.size(); ++i){
		int x = query[i][0], y = query[i][1];
		--x, --y;
		int res = lca(x, y) + 1;
		ans.push_back(res);
	}

	return ans;

}
```
## Maximize Profit
You are given a tree having ‘N’ nodes, where each node has some coins ‘C[i]’, attached to it.
You are allowed to collect the coins from any node. Your task is to maximize the sum of chosen coins given that you cannot choose coins from adjacent nodes(i.e., nodes which are directly connected by an edge).
```cpp
const int mxN = 1e5;
vector<int> adj[mxN+1];

int d[mxN], anc[mxN][17];

void dfs(int u=0, int p=-1){
	anc[u][0]=p;
	for(int i=1; i<17; ++i)
		anc[u][i] = ~anc[u][i-1] ? anc[ anc[u][i-1] ][i-1] : -1;
	
	for(int v: adj[u]){
		if(v==p)
			continue;
		d[v] = d[u]+1;
		dfs(v, u);
	}
}

int lca(int u, int v){
	if(d[u]<d[v])
		swap(u, v);
	for(int i=16; ~i; --i)
		if(d[u]-(1<<i) >= d[v])
			u = anc[u][i];
		if(u==v)
			return u;
		for(int i=16; ~i; --i)
			if(anc[u][i]^anc[v][i])
				u = anc[u][i], v=anc[v][i];
		
		return anc[u][0];
}

vector<int> lca(int n, vector<vector<int>> edges, vector<vector<int>> query){

	for(int i=0; i<=mxN; ++i){
		adj[i].clear();
		d[i]=0;
	}
	
	for(int i=0; i<edges.size(); ++i){
		int u=edges[i][0], v=edges[i][1];
		--u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs();

	vector<int> ans;

	for(int i=0; i<query.size(); ++i){
		int x = query[i][0], y = query[i][1];
		--x, --y;
		int res = lca(x, y) + 1;
		ans.push_back(res);
	}

	return ans;

}
```
## Ninja And Numbers
Ninja is learning tree data structures. His friend is helping him learn by giving him problems to solve. He gives him a tree with N nodes numbered from 0 to N - 1 in the form of a parent array parent where parent[i] is the parent of the ith node. The root of the tree is node 0. Now Ninja has to find the kth ancestor of a given node. The kth ancestor of a tree node is the kth node in the path from that node to the root node.
```cpp
const int mxN = 1e5;
int n, d[mxN], anc[mxN][17];
vector<int> adj[mxN];

void dfs(int u=0, int p=-1){
    anc[u][0]=p;
    for(int i=1; i<16; ++i)
        anc[u][i]= ~anc[u][i-1] ? anc[anc[u][i-1]][i-1] : -1;
    for(int v: adj[u]){
        if(v==p)
            continue;
        d[v]=d[u]+1;
        dfs(v, u);
    }
}
int kthAncestor(int n, vector<int> & parent, int node, int k)
{
    for(int i=0; i<mxN; ++i)
        adj[i].clear();

    for(int i=0; i<n; ++i)
        adj[parent[i]].push_back(i);
    
    dfs();
    if(d[node]<k)
        return -1;
    else{
        for(int i=16; ~i; --i)
            if(k>>i&1) //kth bit is set
                node = anc[node][i];
            return node;
    }

}
```
## Ninja Star
Ninjas use stars to attack their enemies. A star is an asterisk character ‘*’ in the center of the figure and four rays ( to the left, right, top, bottom ) of the same positive length. The size of a star must be a positive number (i.e. rays of length 0 are not allowed).
Let's consider empty cells are denoted by '.', then the following figures are stars :
Ninja Stars

Here the leftmost figure is a star of length 1 and the rightmost figure is a star of length 2.
Ninja enters a rectangular grid ‘A’ of size ‘N x M’ consisting only of asterisks '*' and periods (dots) '.'
Rows are numbered from 1 to ‘N’ and columns are numbered from 1 to ‘M’. Ninja wants to draw this grid using any number of stars or find out that it is impossible. Stars can intersect, overlap or even coincide with each other. The number of stars in the output can't exceed ‘N*M’. Each star should be completely inside the grid. You can use stars of the same and arbitrary sizes.
If it is impossible to construct the grid, output -1. Otherwise in the first line print one integer ‘k’, the number of stars needed to draw the grid. The next ‘k’ lines should contain three integers each ‘x’ , ‘y’ and ‘s’ , where ‘x’ is the row index of the central star character, ‘y’ is the column index of the central star character and ‘s’ is the size of the star.
```
Example :
A = [ . * .  ]
    [ * * *  ]
    [ . * .  ]

Explanation : 
There is only 1 star with length 1 with its center at ( 2, 2).
There is no other star possible and no other asterisk character available.
So, it was possible to construct the grid with stars.
Hence, we output : 2 2 1.

https://codeforces.com/contest/1015/problem/E2
```
```cpp
//https://codeforces.com/contest/1015/problem/E2

vector<vector<char>> draw(vector<vector<int>>& r, int n, int m){
    vector<vector<char>> f(n, vector<char>(m, '.'));
    vector<vector<int>> h(n, vector<int>(m));
    vector<vector<int>> v(n, vector<int>(m));
    for(auto it: r){
        int x = it[0];
        int y = it[1];
        int len = it[2];
        ++v[x-len][y];
        if(x+len <n-1)
            --v[x+len+1][y];

        ++h[x][y-len];
        if(y+len<m-1)
            --h[x][y+len+1];
    }

    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(i>0) v[i][j] += v[i-1][j];
            if(j>0) h[i][j] += h[i][j-1];
            if(v[i][j]>0 || h[i][j]>0)
                f[i][j] = '*';
        }
    }
    return f;
}

vector<vector<int> > ninjaStar(vector<vector<char>> &s, int n, int m) {
    
    vector<vector<int>> l(n, vector<int>(m));
	vector<vector<int>> r(n, vector<int>(m));
	vector<vector<int>> u(n, vector<int>(m));
	vector<vector<int>> d(n, vector<int>(m));
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (i > 0) {
				if (s[i][j] != '.')
					u[i][j] = u[i - 1][j] + 1;
			} else {
				u[i][j] = s[i][j] != '.';
			}
			if (j > 0) {
				if (s[i][j] != '.')
					l[i][j] = l[i][j - 1] + 1;
			} else {
				l[i][j] = s[i][j] != '.';
			}
		}
	}


	for (int i = n - 1; i >= 0; --i) {
		for (int j = m - 1; j >= 0; --j) {
			if (i < n - 1) {
				if (s[i][j] != '.')
					d[i][j] = d[i + 1][j] + 1;
			} else {
				d[i][j] = s[i][j] != '.';
			}
			if (j < m - 1) {
				if (s[i][j] != '.')
					r[i][j] = r[i][j + 1] + 1;
			} else {
				r[i][j] = s[i][j] != '.';
			}
		}
	}

    vector<vector<int>> ans;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(s[i][j]=='*'){
              int len = min({u[i][j], l[i][j], d[i][j], r[i][j]})-1;
              if( len != 0)
                ans.push_back({i, j, len});
            }
        }
    }

    vector<vector<int>> res;
    if(draw(ans, n, m) != s)
      res.push_back({-1});
    
    else{
        int sz = ans.size();
        res.push_back({sz});
        for(auto it: ans){
            res.push_back({it[0], it[1], it[2]});
        }
    }

    return res;
}
```
## Count Of N-Digit Numbers $
You are given a positive integer ‘N’. You have to count all the ‘N’-digit numbers that have at least one digit repeating.
If there are no numbers possible, print 0.
Answers can be very large, so you have to print ‘answer’ modulo 1000000007.
For Example :
‘N’ = 2

For the given example, the number of two digit numbers having repeating digits are 11, 22, 33, 44, 55, 66, 77, 88, 99. Hence the answer is 9.
```cpp
#include <bits/stdc++.h>

#define ll long long

ll dp[20][2024][2];
const int M = 1e9+7;

ll power(ll b, ll p){
    ll r=1;
    b%=M;
    while(p>0){
        if(p&1){
            r = r*b%M;
        }
        b = b*b%M;
        p>>=1;
    }
    return r;
}

ll dfs(ll dig, ll mask, bool repeated, ll n){
    if(dig==n+1){
        if(repeated) return 1;
        return 0;
    }
    if(repeated){
        return power(10, n-dig+1);
    }

    ll& val = dp[dig][mask][repeated];

    if(val!=-1)
        return val%M; 
    
    val = 0;

    if(dig == 1){
        for(int i=(n==1 ? 0 : 1); i<=9; ++i){
            if(mask & (1<<i)){
                val += dfs(dig+1, mask | (1<<i), 1, n)%M;
            }
            else{
                val += dfs(dig+1, mask | (1<<i), 0, n)%M;
            }
        }
    }

    else{
        for(int i=0; i<=9; ++i){
            if(mask & (1<<i)){
                val += dfs(dig+1, mask | (1<<i), 1, n)%M;
            }
            else{
                val += dfs(dig+1, mask | (1<<i), 0, n)%M;
            }
        }
    }

    return val%M;
}

int countNumbers(int n) {
    memset(dp, -1, sizeof(dp));

    int ans = (int) dfs(1, 0, 0, n)%M ;
    return ans;
}




// int dp[50][2024][2];

// // Function to calculate the count of all N-digit numbers with at least one digit repeated.
// int recursiveFunction(int num, int d, int m,
//                       bool r)
// {
//     // Base condition to terminate the recursive function.
//     if (d == num + 1)
//     {
//         if (not r)
//             return 0;
//         return 1;
//     }
    
//     // if the number is repeated.
//     if (r)
//         return pow(10, num - d + 1);

//     // if dp[d][m][r] is already computed.
//     if (dp[d][m][r] != -1)
//     {
//         return dp[d][m][r];
//     }
//     dp[d][m][r] = 0;

//     // only for 1 digit
//     if (d == 1)
//     {
//         int i;
//         if (num == 1)
//             i = 0;
//         else
//             i = 1;
//         for (i; i < 10; i++)
//         {
//             if (m & (1 << i))
//             {
//                 dp[d][m][r] += recursiveFunction(num, d + 1, m | (1 << i), 1);
//             }
//             else
//             {
//                 dp[d][m][r] += recursiveFunction(num, d + 1, m | (1 << i), 0);
//             }
//         }
//     }
//     else
//     {
//         for (int i = 0; i < 10; i++)
//         {
//             if (m & (1 << i))
//             {
//                 dp[d][m][r] += recursiveFunction(num, d + 1, m | (1 << i), 1);
//             }
//             else
//             {
//                 dp[d][m][r] += recursiveFunction(num, d + 1, m | (1 << i), 0);
//             }
//         }
//     }
//     return dp[d][m][r];
// }

// int main()
// {
//     // input number of digits.
//     int n;
//     cin >> n;

//     // initialize all values of dp to -1;
//     memset(dp, -1, sizeof(dp));
//     cout << recursiveFunction(n, 1, 0, 0);
//     return 0;
// }
```

## Magical Numbers
You are given three integers ‘A’, ‘B’ and ’K’. Your task is to find the number of Magical Numbers between ‘A’ and ‘B’(inclusive). A number ‘N’ is said to be a magical number if the sum of its digits is prime and the number ‘N’ is divisible by ‘K’.
For example:
Forgiven A = 10, B = 15 and K = 2.
12 and 14 are magical numbers because the sum of digits of 12 and 14 is a prime number, also 12 and 14 both are divisible by 2.  
```cpp
#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll k, n;

string a, b;

ll dp[30][2][300][101];

bool isPrime(ll x)

{

  if (x <= 1) {

    return false;
  }

  for (ll i = 2; i * i <= x; i++) {

    if (x % i == 0)
      return false;
  }

  return true;
}

ll fun(ll ind, ll strict, ll sum, ll rem)

{

  if (ind == n) {

    if (isPrime(sum) && rem % k == 0) {
      return 1;
    }

    return 0;
  }

  ll ans = 0;

  if (dp[ind][strict][sum][rem] != -1) {

    return dp[ind][strict][sum][rem];
  }

  if (strict == 0) {

    for (ll i = 0; i < 10; i++)

    {

      ans += fun(ind + 1, 0, sum + i, (rem * 10 + i) % k);
    }

    return dp[ind][strict][sum][rem] = ans;

  }

  else {

    ll i;

    for (i = 0; i < a[ind] - '0'; i++)

    {

      ans += fun(ind + 1, 0, sum + i, (rem * 10 + i) % k);
    }

    ans += fun(ind + 1, 1, sum + i, (rem * 10 + i) % k);

    return dp[ind][strict][sum][rem] = ans;
  }
}

ll countMagicalNumbers(ll A, ll B, ll K)

{


  k = K;

  A--;

  a = to_string(A);

  n = a.size();

  memset(dp, -1, sizeof(dp));

  ll ans1 = fun(0, 1, 0, 0);

  memset(dp, -1, sizeof(dp));

  a = to_string(B);

  n = a.size();

  ll ans2 = fun(0, 1, 0, 0);

  return ans2 - ans1;
}
```
## Numbers with product K 44
Ninja Ankush likes to brag that he is the Ultimate Ninja among his peers. Therefore his fellow Ninja Nikhil gave him a riddle to check if Ankush is really the Ultimate Ninja. Nikhil gave Ankush a range and a number ‘K’, and asked how many numbers exist in the range such that the product of the digits of the number is equal to ‘K’. Help Ninja Ankush to prove to Ninja Nikhil that he, in fact, is the Ultimate Ninja.
More Formally, Given three positive integers ‘L’, ‘R’ and ‘K’, the task is to count the numbers in the range ‘L’ and ‘R’ inclusive, whose product of digits is equal to ‘K’.
For example
Given:
‘L’ = 1, ‘R’ = 23, ‘K’ = 6.

The answer will be 3 since there are three numbers between 1 and 23 whose product of digits is 6, and those are 6, 16, and 23.
```cpp

int dp[10005][30][2][2];  //dp(N, K, st, tight):
// prod K: Represents sum of digits. 
// tight: Check if sum of digits exceed K or not. 
// end: Stores the maximum possible value of ith digit of a number. 
// st: Check if a number contains leading 0 or not. 

int dfs(string s, int i, int prod, int k, int st, int tight){
	if(i>=s.size() || prod>k) return prod==k;

	if(dp[prod][i][tight][st] != -1) return dp[prod][i][tight][st];

	int res=0;
	int end = tight ? s[i]-'0' : 9;

	for(int j=0; j<=end; ++j){
		if(j==0 && !st){
			res += dfs(s, i+1, prod, k, false, (tight & (j==end)));
		}else{
			res += dfs(s, i+1, prod*j, k, true, (tight & (j==end)));
		}
	}

	return dp[prod][i][tight][st] = res;
}
int numsWithProductK(int l, int r, int k) {
	string s = to_string(r);
	memset(dp, -1, sizeof(dp));
	int cntR = dfs(s, 0, 1, k, false, true);

	s = to_string(l-1);
	memset(dp, -1, sizeof(dp));
	int cntL = dfs(s, 0, 1, k, false, true);

	return (cntR - cntL);
}

//https://www.geeksforgeeks.org/count-numbers-from-a-given-range-whose-product-of-digits-is-k/
```
## Odd Partitions
Axel loves to play with large numbers in his free time. He has come up with yet another interesting task for you.
You are given a large integer number represented by a string ‘S’, you need to partition it into multiple odd numbers. But to make the task more interesting each of the odd numbers after partitioning should lie in the range [0, 109]. You need to determine the minimum odd numbers you should partition into. Print -1 if it’s impossible to complete the task.
Follow Up :
Can you solve this in linear time and constant space?
For Example :
If S = 99299999999

Then, there can be multiple ways to partition the given number into two odd numbers that are less than 10^9. One such partition is { 9929, 9999999 }, therefore the answer is 2. Note that: 99299999999 is itself an odd number but is greater than 10^9, so the answer is not equal to 1.
```cpp
int oddPartitions(string s) {
    int n = s.size();
    vector<int> dp(n, 1e9);
    for(int i=0; i<min(n, 9); ++i){
        if((s[i]-'0')%2 != 0)
            dp[i]=1;
    }
    for(int i=0; i<n; ++i){
        if((s[i]-'0')%2 != 0 && dp[i] != 1e9){
            for(int j=i+1; j<=min(n-1, i+9); ++j){
                if((s[j]-'0')%2 != 0)
                    dp[j] = min(dp[j], dp[i]+1);
            }

        }
    }

    if(dp[n-1]== 1e9) return -1;

    return dp[n-1];
}
```

