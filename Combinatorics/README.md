## CF 1433 E Two Round Dance
```cpp
#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll fact[21];

ll solve(int n){
	ll res = (fact[n] / fact[n/2]) / fact[n/2];
	res = res / 2;

	res = res * fact[n/2-1] * fact[n/2-1];

	return res;
}


int main(){
	int n;
	cin>>n;

	fact[0] = 1;
	for(int i=1;i<=20;i++) fact[i] = fact[i-1] * i;

	cout<<solve(n);
}
```

## Infinite Workout
Ninja has gained weight in lockdown and has decided to shed this extra weight by joining the famous Infinite Gym. His gym is actually an infinite grid, where he works out according to the instructions of his trainer.
Each day, his trainer gives him two integers n, m. Ninja begins from cell (0,0) and has to reach cell (n,m).
Also, when Ninja is standing at cell (i, j), he can move to (i, j+1) and (i+1, j) only (right and bottom cells). Calculate the total number of ways he can do so.
```cpp
#include<bits/stdc++.h>
using namespace std;

#define ll long long

// const int mxA=40;
// const int M = 1e9+7;
// ll iv[mxA], f1[mxA], f2[mxA];
int main(){
    int t; cin>>t;
    // iv[1]=1;
    // for(int i=2; i<=mxA; ++i)
    //     iv[i]=M-M/i*iv[M%i]%M;
    // f1[0]=f2[0]=1;
    // for(int i=1; i<=mxA; ++i){
    //     f1[i]=f1[i-1]*i%M;
    //     f2[i]=f2[i-1]*iv[i]%M;
    // }
    while(t--){
        int n, m;
        cin>>n>>m;
        // cout << f1[n+m] * f2[n]%M * f2[m]%M << '\n';
        int N = m+n;
        int R = m;
        ll ans=1;
        for(int i=1; i<=R; ++i){
            ans = ans*(N-R+i)/i;
        }
        cout<<ans<<'\n';
    }
    
    return 0;
}
```

## Arrangement
You are given a number 'N'. Your goal is to find the number of permutations of the list 'A' = [1, 2, ......, N], satisfying either of the following conditions:
A[i] is divisible by i or i is divisible by A[i], for every 'i' from 1 to 'N'.
```cpp
void dfs(int n, int pos, vector<bool>& vis, int& ans){
    if(pos>n) ++ans;
    for(int i=1; i<=n; ++i){
        if(!vis[i] && (pos%i==0 || i%pos==0)){
            vis[i]=1;
            dfs(n, pos+1, vis, ans);
            vis[i]=0;
        }
    }
}
int countArrangement(int n) {
    int ans=0;
    vector<bool> vis(n+1, false);
    dfs(n, 1, vis, ans);
    return ans;
}
```

## Number of rectangles in a grid
You are given an arbitrary grid with M rows and N columns. You have to print the total number of rectangles which can be formed using the rows and columns of this grid. In simple words, print the number of unique rectangles in the grid.
For example:
Consider the grid shown below. The dark black boundary encloses a grid of dimension 3x4.
alt text

The green colour represents rectangles of dimension 1x1. 
The brown colour represents the rectangles of dimension 1x2.
The blue colour represents the rectangles of dimension 2x2.
The red colour represents the rectangles of dimension 3x3.
The yellow colour represents the rectangles of dimension 3x1.
There can be many different other possibilities as well. You need to print the total number of all such rectangles. 
Note:
Two rectangles are said to be unique if atleast one of their 4 sides is non-overlapping.

```cpp
long long countRectangles(int m, int n){
	long long M = m, N=n;
	long long ans = (N*M)*(N+1)*(M+1); //(n+1)C2 *()
	return ans/4;
}
```

## STRING KA KHEL
Ninja started a gaming shop and for that shop, he is planning to make a new game ‘String Ka Khel’. In that game user is provided with ‘N’ number of strings and he has to find out the maximum length of strings he can form by joining these ‘N’ strings. For joining two strings there is a condition that two strings will only join if the last character of the first string is same as the last character of the second string. If the user will find out the correct answer he will be given Coding Ninja goodies by the Ninja.
So your task is to find the maximum length of string which can be formed by joining strings according to the given condition. If no such combination exists return ‘0’. Strings only contain the letter ‘B’ and ‘R’.
Example:
The string is ‘RR’, ‘RB’ so we can combine ‘RR’ and ‘RB’ as the last character of ‘RR’ i.e ‘R’ matches with the first character of ‘RB’. But we cant combine ‘RB’ and ‘RR’ as the last character of ‘RB’ i.e ‘B’ doesn't matches with the first character of ‘RR’ i.e ‘R’ so our answer is '4'.

```cpp
int stringKhel(vector<string>& a, int n)
{
	int rr=0, bb=0, rb=0, br=0;
	int len = a[0].size();
	for(int i=0; i<n; ++i){
		char first = a[i][0], last = a[i][len-1];
		if(first=='R' && last=='R') rr++;
		if(first=='B' && last=='B') bb++;
		if(first=='B' && last=='R') br++;
		if(first=='R' && last=='B') rb++;
	}
	int ans;
	if(rb==0 && br==0){
		ans = max(rr, bb);
	}else{
		if(br==rb)
			ans = rr+bb+2*min(rb, br);
		else
			ans = rr+bb+2*min(br, rb)+1;
	}

	if(ans==1) return 0;
	else return ans*len;
}


/*
    Time complexity: O(N!)
    Space complexity: O(N) 

    Where N represents the size of the array 'ARR'.
*/

// int stringkhelHelper(vector<string> &arr, int idx, int n)
// {
//     if (idx == n)
//     {
//         int c = 0;
//         for (int i = 1; i < n; i++)
//         {
//             if (arr[i - 1][arr[0].size() - 1] == arr[i][0])
//             {
//                 c += 1;
//             }
//             else
//             {
//                 break;
//             }
//         }

//         if (c > 0)
//         {
//             c += 1;
//         }

//         return c;
//     }

//     int ans = 0;
//     for (int i = idx; i < n; i++)
//     {
//         swap(arr[idx], arr[i]);
//         ans = max(ans, stringkhelHelper(arr, idx + 1, n));
//         swap(arr[idx], arr[i]);
//     }

//     return ans;
// }

// int stringKhel(vector<string> &arr, int n)
// {
//     int ans = 0;
//     ans = stringkhelHelper(arr, 0, n);

//     return ans * (arr[0].size());
// }
```

## The Mentalist and Arrays - II
Patrick Jane is ready to pick up another challenge, and his friend Teresa is up to the task. She has created an elaborate puzzle for him to solve.
She gives Patrick two integers n and m. Using those integers Patrick needs to find the number of pairs of arrays (a,b) by following some rules. Teresa lists the rules as:
1. The length of both arrays should be equal to m.
2. Elements inside both the arrays should be an integer in the range 1 to n (both inclusive).
3. Arrays a and b should be created such that, ai ≤ bi for any index i from 1 to m.
4. Array a should be sorted in non-descending order.
5. Array b should be sorted in non-ascending order.

```cpp
#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int mxA = 1e6, M = 1e9 + 7;
ll iv[mxA + 1], f1[mxA + 1], f2[mxA + 1];

int main() {
    iv[1]=1;                         //Calculating mod inverse of all nos 2 to mxA
	for(int i=2; i<=mxA; ++i)
		iv[i]=M-M/i*iv[M%i]%M;
		
	f1[0]=f2[0]=1;
	for(int i=1; i<=mxA; ++i){
		f1[i]=i*f1[i-1]%M;
		f2[i]=f2[i-1]*iv[i]%M;
	}

    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
        while (t--) {
          // inclusion exclusion stars and bars
          ll n, m;
          cin >> n >> m;
          ll ans = f1[n + 2 * m - 1] * f2[2 * m] % M * f2[n - 1] % M;
          cout << ans << endl;
    }
    return 0;
}
```
