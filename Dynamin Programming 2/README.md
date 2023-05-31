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
