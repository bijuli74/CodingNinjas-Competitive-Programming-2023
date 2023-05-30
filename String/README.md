## Rabin carp
You are given a string ‘str’ of length 'N' and a string ‘pat’ of length 'M'. Your task is to find the starting index of all the occurrences of ‘pat’ in str.
You need to return a list of integers that denote the indices from which ‘pat’ is present in ‘str’(consider 0 based indexing).
For example,
Let str= “AABAACAADAABAABA”
And pat= “AABA”
We will return the array/list [0,9,12] as we can clearly see that from indices 0 9 and 12 we have the same pattern ‘pat’ in ‘str’

```cpp
//kmp
vector<int> stringMatch(string &s, string &p) {
    int n = s.size(), m = p.size();
    vector<int> lps(m, 0);
    int i=1, j=0;
    while(i<m){
        if(p[i]==p[j]) lps[i++]= ++j;
        else if(j) j = lps[j-1];
        else i++;
    }

    vector<int> ans;
    int cnt = 0;
    i=0, j=0;

    while (i < n) {
      if (j == m) {
        ans.push_back(i-j);
        j = lps[j - 1];
      } else if (s[i] == p[j]) {
        i++;
        j++;
      } else if (j) {
        j = lps[j - 1];
      } else {
        i++;
      }
    }
    if(j==m){
        ans.push_back(i-j);
    }
    
    return ans;
}
```
## Z-algorithm
You’re given a string S of length N and a string P of length M. Your task is to find the number of occurrences of P in S in linear time.
```cpp
int zAlgorithm(string s, string p, int n, int m)
{ 
  s = p + "#" + s;
	vector<int> z(s.size());
	int l=0, r=1;
	for(int i=1; i<s.size(); ++i){
		z[i] = i>r ? 0 : min(r-i, z[i-l]);
		while(i + z[i] < s.size() && s[z[i]] == s[z[i]+i])
			++z[i];
		if(z[i]+i > r){
			l = i;
			r = z[i] + i;
		}
	}

  int ans=0;
  for(int i=0; i<s.size(); ++i){ 
    if(z[i] == p.size()) 
		++ans;
  }

  return ans;
}
```

## Longest Common Prefix After Rotation
You are given two strings 'A' and 'B' where string 'A' is fixed. But you can perform left shift operations on string B any number of times.
Your task is to find out the minimum number of left-shift operations required in order to obtain the longest common prefix of string 'A' and 'B'.
```cpp
int minimumRequiredShifts(string a, string b){
  //Modified KMP
  b+=b;
  int n = b.size(), m = a.size();

  int lps[m] = {0};
  int i = 1, j = 0;
  while (i < m) {
    if (a[i] == a[j])
      lps[i++] = ++j;
    else if (j)
      j = lps[j - 1];
    else
      i++;
  }

  int ans = 0, mx=0;
  i = 0, j = 0;

  while (i < n) {
    
    if (b[i] == a[j]) {
      i++;
      j++;
    } else if (j) {
      j = lps[j - 1];
    } else {
      i++;
    }

    if (j > mx) {
      mx = j;
      ans = i - j;
    }
  }
  return ans;
}

//BRUTE FORCE
// int getL(string a, string b, int id){
// 	int c = 0;
// 	for(int i=0; i<a.size(); ++i){
// 		if(a[i] == b[id%b.size()]){
// 			id++;
// 			c++;
// 		}else{
// 			return c;
// 		}
// 	}
// 	return c;
// }
// int minimumRequiredShifts(string a, string b){
// 	int ans = 0, s = 0, n = b.size();
// 	for(int i=0; i<n; ++i){
// 		int s1 = getL(a, b, i);
// 		if(s1 > s){
// 			s = s1;
// 			ans = i;
// 		}
// 	}
// 	return ans;
// }
```

## Word Search - ll
You are given a two-dimensional grid having 'N' rows and 'M' columns, consisting of upper case characters. You are also given a word 'WORD'. You have to find the number of occurrences of that word in the grid.
Starting from a given cell, a word can be formed by moving in all eight directions: horizontally left, horizontally right, vertically up, vertically down, and four diagonal directions.
```cpp
#include <bits/stdc++.h>
using namespace std;

int kmp(string s, string word, vector<int>& lps){
    int n = s.size(), m = word.size();
    int cnt=0;

    int i = 0, j = 0;
    while (i < n) {
        if (j == m) {
            cnt++;
            j = lps[j - 1];
        } else if (s[i] == word[j]) {
            i++;
            j++;
        } else if (j) {
            j = lps[j - 1];
        } else {
            i++;
        }
    }
    if (j == m)
        cnt++;
    
    return cnt;
}
int wordSearch(string g[], int n, int m, string word){
    int len = word.size();
    //compute lps array
    vector<int> lps(len, 0);
    int i=1, j=0;
    while(i<len){
        if(word[i]==word[j]) lps[i++] = ++j;
        else if(j) j = lps[j-1];
        else i++;
    }
    int ans = 0;
    //rows
    for(int i=0; i<n; ++i){
        ans += kmp(g[i], word, lps);
        ans += kmp(string(g[i].rbegin(), g[i].rend()), word, lps);
    }
    //cols
    for(int j=0; j<m; ++j){
        string s;
        for(int i=0; i<n; ++i)
            s.push_back(g[i][j]);
        ans += kmp(s, word, lps);
        ans += kmp(string(s.rbegin(), s.rend()), word, lps);
    }
    //upper diag
    for(int i=0; i<n; ++i){
        string s;
        for(int j=0; i+j<n && j<m; ++j)
            s.push_back(g[i+j][j]);
        ans += kmp(s, word, lps);
        ans += kmp(string(s.rbegin(), s.rend()), word, lps);
    }
    for(int j=1; j<m; ++j){
        string s;
        for(int i=0; i<n && j+i<m; ++i)
            s.push_back(g[i][j+i]);
        ans += kmp(s, word, lps);
        ans += kmp(string(s.rbegin(), s.rend()), word, lps);
    }

    //lower diag
    for(int i=0; i<n; ++i){
        string s;
        for(int j=0; i-j>=0 && j<m; ++j)
            s.push_back(g[i-j][j]);
        ans += kmp(s, word, lps);
        ans += kmp(string(s.rbegin(), s.rend()), word, lps);
    }

    for(int j=1; j<m; ++j){
        string s;
        for(int i=n-1; ~i && j+(n-1)-i<m; --i){
            s.push_back(g[i][j+(n-1)-i]);
        }
        ans += kmp(s, word, lps);
        ans += kmp(string(s.rbegin(), s.rend()), word, lps);
    }
    return ans;
}

//BRUTE FORCE TLE 2 CASES
// int N, M;
// string W;

// vector<pair<int, int>> d8 = {{1, 0},  {0, 1},  {-1, 0}, {0, -1},
//                              {-1, 1}, {1, -1}, {1, 1},  {-1, -1}};

// int dfs(string g[], int x, int y) {
//   int cnt = 0;
//   if (g[x][y] != W[0])
//     return 0;
 
//     for (int i = 0; i < 8; ++i) {
//       int nx = x + d8[i].first;
//       int ny = y + d8[i].second;
//       int ok = 1;
//       for (int k = 1; k < W.size(); ++k) {
//         if (nx < 0 || nx >= N || ny < 0 || ny >= M || W[k] != g[nx][ny]) {
//           ok = 0;
//           break;
//         }
//         nx = nx + d8[i].first;
//         ny = ny + d8[i].second;
//       }
//       cnt += ok;
//   }
//   return cnt;
// }
// int wordSearch(string g[], int n, int m, string word) {
//     N = n, M = m;
//     int ans = 0;
//     W = word;
//     for(int i=0; i<N; ++i)
//         for(int j=0; j<M; ++j)
//             ans += dfs(g, i, j);
    
//     return ans;
// }
```

## Minimum Characters For Palindrome
Given a string STR of length N. The task is to return the count of minimum characters to be added at front to make the string a palindrome.
For example, for the given string “deed”, the string is already a palindrome, thus, minimum characters needed are 0.
Similarly, for the given string “aabaaca”, the minimum characters needed are 2 i.e. ‘a’ and ‘c’ which makes the string “acaabaaca” palindrome.
```cpp
#include <algorithm>
int minCharsforPalindrome(string s) {
	string rev=s; 
	reverse(rev.begin(), rev.end());
	string ns = s+"#"+rev;
	int m = ns.size();

        int lps[m] = { 0 };
		int i=1, j=0;
		while(i<m){
			if(ns[i]==ns[j]) lps[i++] = ++j;
			else if(j) j = lps[j-1];
			else i++;
		}

		return s.size() - lps[m-1];

}
```
## Justify Text
Given a sentence(in the form of an array of words), and an integer ‘L’, return an array of strings i.e a paragraph such that each line has exactly ‘L’ characters, and is left and right justified.
Justification of text means that space is added between words so that both edges of each line are aligned with both margins. The last line in the paragraph is aligned left.
One needs to add the maximum number of words in a line such that the number of lines is minimised.
We can add whitespaces in a line so that each line has exactly the same number of characters i.e L.
If the number of spaces on a line does not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
For the last line of text, it should be left justified and no extra space is inserted between words.
For example:
Let the given sentence be: [ “what”, “must”, “be”, “shall”, “be.”]
And L=12.

The justified output will be :

[ “what must be”
“Shall be.”       ]

Note that the last line is only left justified.
```cpp
string join(const vector<string> &v, const string &c) {
  string s;
  for (auto p = begin(v); p != end(v); ++p) {
    s += *p;
    if (p != end(v) - 1)
      s += c;
  }
  return s;
}

string ljust(string s, int width) {
  for (int i = 0; i < s.length() - width; ++i)
    s += " ";
  return s;
}

vector<string> fullJustify(vector<string> &words, int maxWidth) {
  vector<string> ans;
  vector<string> row;
  int rowLetters = 0;

  for (const string &word : words) {
    // If we put the word in this row, it'll exceed the maxWidth,
    // So we cannot put the word to this row and have to pad spaces to
    // Each word in this row
    if (rowLetters + row.size() + word.length() > maxWidth) {
      const int spaces = maxWidth - rowLetters;
      if (row.size() == 1) {
        // Pad all spaces after row[0]
        for (int i = 0; i < spaces; ++i)
          row[0] += " ";
      } else {
        // Evenly pad spaces to each word (expect the last one) in this row
        for (int i = 0; i < spaces; ++i)
          row[i % (row.size() - 1)] += " ";
      }
      ans.push_back(join(row, ""));
      row.clear();
      rowLetters = 0;
    }
    row.push_back(word);
    rowLetters += word.length();
  }
  ans.push_back(ljust(join(row, " "), maxWidth));

  return ans;
}
```
## First Repeated Character
You are given a string 'STR' of lowercase English alphabets. You need to find the repeated character present first in the string.
Example:
If the string is: “abccba”, then the first repeated character is ‘c’, but the repeated character that is present first in the string is ‘a’. You need to print ‘a’.
Note:
Keep in mind that you need to print the repeated character that is present first in the string and not the first repeating character.

```cpp
#include <bits/stdc++.h>
char repeatedCharacter(string &s){
  int f[26] = { 0 } ;
  for (char &c : s) f[c - 'a']++;
  for (char &c : s) {
    if (f[c - 'a'] > 1)
      return c;
	}
	return '%';
}
```
## Matching Prefix $$
You are given an integer ’N’ denoting the length of the array ‘Arr’ of strings made up of lower case English alphabets. The cost of this array is equal to the sum of length of each string in the array.
You can select a new string ‘S’ of length ‘N’, you are now allowed to delete the prefix from the strings in the array (This leads to lowering the cost of the array), the deleted prefix should be exactly the same as the selected string ‘S.
Find the string ‘S’ such that the cost of the array ‘Arr’ is minimized. If multiple strings exist, then find the lexicographically smallest string amongst them.
For Example :
If the array of strings is: {co, code, studio, codingninjas, coding, debug, coder, cipher} 
Then the original cost of the array is 2 + 4 + 6 + 12 + 6 + 5 + 5 + 6 = 46.

If we select the new string as “cod” and delete the matching prefixes if exists then the array becomes: {co, e, studio, ingninjas, ing, debug, er, cipher}, and the cost now becomes: 2 + 1 + 6 + 9 + 3 + 5 + 2 + 6 = 34.

You can check for any other possible string, the cost will not become less than 34, hence the optimal answer for this case is “cod”.
```cpp
string matchingPrefix(int n, vector < string > s) {
   if(s.empty()) return "";
   int mn = 1e9;
   string ans;

   for(int i=0; i<n; ++i){
      for(int j=0; j<s[i].size(); ++j){
         int cost = 0;
         int len = j+1;
         string pf = s[i].substr(0, len);

         for(int k=0; k<n; ++k){
            cost += s[k].size();
            if(s[k].size()>= len){
               string ns = s[k].substr(0, len);
               if(ns == pf)
                  cost -= len;
            }
         }

        if(cost < mn){
           mn = cost;
           ans = pf;
        }
        if(cost == mn)
            if(ans>pf)
               ans = pf;
      }
   }
   return ans;
}
```
## Longest Palindromic Substring
You are given a string (STR) of length N.
Your task is to find the longest palindromic substring. If there is more than one palindromic substring with the maximum length, return the one with the smaller start index.
Note:
A substring is a contiguous segment of a string.
For example :
The longest palindromic substring of "ababc" is "aba", since "aba" is a palindrome and it is the longest substring of length 3 which is a palindrome. There is another palindromic substring of length 3 is "bab". Since starting index of "aba" is less than "bab", so "aba" is the answer.
```cpp
#include <bits/stdc++.h>

#define ar array

string join(const string &s, char c) {
  string joined;
  for (int i = 0; i < s.length(); ++i) {
    joined += s[i];
    if (i != s.length() - 1)
      joined += c;
  }
  return joined;
}

string longestPalinSubstring(string s){
  // @ and $ signs are sentinels appended to each end to avoid bounds checking
  const string &t = join('@' + s + '$', '#');
  const int n = t.length();
  // t[i - maxExtends[i]..i) ==
  // t[i + 1..i + maxExtends[i]]
  vector<int> maxExtends(n);
  int center = 0;

  for (int i = 1; i < n - 1; ++i) {
    const int rightBoundary = center + maxExtends[center];
    const int mirrorIndex = center - (i - center);
    maxExtends[i] =
        rightBoundary > i && min(rightBoundary - i, maxExtends[mirrorIndex]);

    // Attempt to expand palindrome centered at i
    while (t[i + 1 + maxExtends[i]] == t[i - 1 - maxExtends[i]])
      ++maxExtends[i];

    // If palindrome centered at i expand past rightBoundary,
    // adjust center based on expanded palindrome.
    if (i + maxExtends[i] > rightBoundary)
      center = i;
  }

  // Find the maxExtend and bestCenter
  int maxExtend = 0;
  int bestCenter = -1;

  for (int i = 0; i < n; ++i)
    if (maxExtends[i] > maxExtend) {
      maxExtend = maxExtends[i];
      bestCenter = i;
    }

  const int l = (bestCenter - maxExtend) / 2;
  const int r = (bestCenter + maxExtend) / 2;
  return s.substr(l, r - l);
}

// const int mxN = 1e3;
// int p[2 * mxN + 3];
// char c[2 * mxN + 3];

// string longestPalinSubstring(string s){
    // int n = s.size();

    // c[0] = '!';
    // c[1] = '*';
    // for (int i = 0; i < n; ++i) {
    //   c[2 * i + 2] = s[i];
    //   c[2 * i + 3] = '*';
    // }

    // c[2 * n + 2] = '@';
    // int d = 0;
    // for (int i = 1; i < 2 * n + 2; ++i) {
    //   if (i <= d + p[d])
    //     p[i] = min(p[2 * d - i], d + p[d] - i);
    //   while (c[i - p[i]] == c[i + p[i]])
    //     ++p[i];
    //   --p[i];
    //   if (i + p[i] > d + p[d])
    //     d = i;
    // }
    // vector<ar<int, 2>> ans;

    // for (int i = 1; i < 2 * n + 2; ++i)
    //     ans.push_back({p[i], (i-p[i])/2});
    // //   ans = max(ar<int, 2>{p[i], (i - p[i]) / 2}, ans);
    // sort(ans.rbegin(), ans.rend());


    // string res;
    // for (int i = ans[0][1]; i < ans[0][1] + ans[0][0]; ++i)
    //   res += s[i];
    
    // return res;
// }

// vector<int> manacher_odd(string s) {
//   int n = s.size();
//   s = "$" + s + "^";
//   vector<int> p(n + 2);
//   int l = 1, r = 1;
//   for (int i = 1; i <= n; i++) {
//     p[i] = max(0, min(r - i, p[l + (r - i)]));
//     while (s[i - p[i]] == s[i + p[i]]) {
//       p[i]++;
//     }
//     if (i + p[i] > r) {
//       l = i - p[i], r = i + p[i];
//     }
//   }
//   return vector<int>(begin(p) + 1, end(p) - 1);
// // }

// vector<int> manacher(string s) {
//   string t;
//   for (auto c : s) {
//     t += string("#") + c;
//   }
//   auto res = manacher_odd(t + "#");
//   return vector<int>(begin(res) + 1, end(res) - 1);
// }

// string longestPalinSubstring(string t){
//     string s;
//     for(int i=0; i<t.size(); ++i){
//         s += "#";
//         s += t[i];
//     }
//     s += "#";

//     int n = s.size();
//     vector<int> p(n);

//     int c=0, r=0;
//     for(int i=1; i<n-1; ++i){
//         int other = 2*c-i;
//         if(i<r) p[i] = min(p[other], r-i);
//         while(s[i+p[i]+1] == s[i-p[i]-1] && i-p[i]-1>=1 && i+p[i]+1<n-1)
//             p[i]++;
//         if (i + p[i] > r) {
//           c = i;
//           r = i + p[i];
//         }
//     }

//     int it = max_element(begin(p), end(p)) - p.begin();
//     int len = p[it];
//     int st = (it - len) / 2, ed = (it + len) / 2;

//     return t.substr(st, ed - st);
// }
```
## Longest common prefix (LCP using suffix array)
Find the longest common prefix from an array of all the suffixes
```cpp
#include <bits/stdc++.h>
using namespace std;
struct suffix
{
int index;
int rank[2];
};
int cmp(struct suffix a, struct suffix b)
{
return (a.rank[0] == b.rank[0])?
(a.rank[1] < b.rank[1] ?1: 0):
(a.rank[0] < b.rank[0] ?1: 0);
}
vector<int> buildSuffixArray(string txt, int n)
{
struct suffix suffixes[n];
for (int i = 0; i < n; i++)
{
suffixes[i].index = i;
suffixes[i].rank[0] = (int)txt[i];
suffixes[i].rank[1] = ((i+1) < n)?
(int)txt[i + 1]: -1;
}
sort(suffixes, suffixes+n, cmp);
int ind[n];
for (int k = 4; k < 2*n; k = k*2)
{
int rank = 0;
int prev_rank = suffixes[0].rank[0];
suffixes[0].rank[0] = rank;
ind[suffixes[0].index] = 0;
for (int i = 1; i < n; i++)
{
if (suffixes[i].rank[0] == prev_rank &&
suffixes[i].rank[1] == suffixes[i-1].rank[1])
{
prev_rank = suffixes[i].rank[0];
suffixes[i].rank[0] = rank;
}
else
{
prev_rank = suffixes[i].rank[0];
suffixes[i].rank[0] = ++rank;
}
ind[suffixes[i].index] = i;
}
for (int i = 0; i < n; i++)
{
int nextindex = suffixes[i].index + k/2;
suffixes[i].rank[1] = (nextindex < n)?
suffixes[ind[nextindex]].rank[0]: -1;
}
sort(suffixes, suffixes+n, cmp);
}
vector<int>suffixArr;
for (int i = 0; i < n; i++)
suffixArr.push_back(suffixes[i].index);
return suffixArr;
}
vector<int> kasai(string txt, vector<int> suffixArr)
{
int n = suffixArr.size();
vector<int> lcp(n, 0);
vector<int> invSuff(n, 0);
for (int i=0; i < n; i++)
invSuff[suffixArr[i]] = i;
int k = 0;
for (int i=0; i<n; i++)
{
if (invSuff[i] == n-1)
{
k = 0;
continue;
}
int j = suffixArr[invSuff[i]+1];
while (i+k<n && j+k<n && txt[i+k]==txt[j+k])
k++;
lcp[invSuff[i]] = k;
if (k>0)
k--;
}
return lcp;
}
void solve(){
string s;
cin>>s;
int n = s.length();
vector<int> suffixArr = buildSuffixArray(s, n);
vector<int> lcp = kasai(s, suffixArr);
cout<<"suffix array ";
for(auto i : suffixArr) cout<<i<<" ";
cout<<"\n";
cout<<"lcp array ";
for(auto i : lcp) cout<<i<<" ";
cout<<"\n";
}
int main(){
solve();
}
```

## Palindromes and Indexes
You are given a string S consisting of lowercase characters only, an index ‘i’ and
length ‘len’. Your task is to find the count of all palindromic substrings in the string
‘S’ which start at index ‘i’ and have a length of at least ‘len’.
A string is called palindromic if it reads the same backward as forward. For
example, "aba" is a palindrome but "abaab" is not a palindrome.
```cpp
#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
string modify(string s){
string newString="";
for(int i=0;i<s.size();i++){
newString+=(char)('#');
newString+=(char)(s[i]);
}
newString+=(char)('#');
return newString;
}
vector<int> manchers(string s){
int n = s.size();
vector<int>arr(n);
int center=0,r=0;
for(int i=1;i<s.size()-1;i++){
int other = 2*center -i;
if(i<r) arr[i] = min(arr[other],r-i);
while(i-arr[i]-1>=1 && i+arr[i]+1<n-1 && s[i+arr[i]+1] ==
s[i-arr[i]-1]) arr[i]++;
if(i+arr[i]>r){
center=i;
r=i+arr[i];
}
}
return arr;
}
void solve(){
string text;
cin>>text;
int ind,len;
cin>>ind>>len;
text = modify(text);
int ans=0;
ind--;
vector<int>arr = manchers(text);
int newInd = 2*ind+1;
for(int i=2*ind+len;i<text.size();i++){
if(i-arr[i] <= newInd){
ans++;
}
}
cout<<ans<<"\n";
return;
}
int main(){
int t;
cin>>t;
while(t--){
solve();
}
return 0;
}
```
## Distinct Substrings:
Given a string 'S', you are supposed to return the number of distinct
substrings(including empty substring) of the given string.
```cpp
#include <bits/stdc++.h>
using namespace std;
struct suffix {
int index,rank[2];
};
int cmp(struct suffix a, struct suffix b) {
return (a.rank[0] == b.rank[0])?
(a.rank[1] < b.rank[1] ?1: 0):
(a.rank[0] < b.rank[0] ?1: 0);
}
vector<int> buildSuffixArray(string txt, int n) {
struct suffix suffixes[n];
for (int i = 0; i < n; i++)
{
suffixes[i].index = i;
suffixes[i].rank[0] = (int)txt[i];
suffixes[i].rank[1] = ((i+1) < n)?
(int)txt[i + 1]: -1;
}
sort(suffixes, suffixes+n, cmp);
int ind[n]; // This array is needed to get the
for (int k = 4; k < 2*n; k = k*2)
{
int rank = 0;
int prev_rank = suffixes[0].rank[0];
suffixes[0].rank[0] = rank;
ind[suffixes[0].index] = 0;
for (int i = 1; i < n; i++) {
if (suffixes[i].rank[0] == prev_rank && suffixes[i].rank[1] == suffixes[i-1].rank[1]) {
prev_rank = suffixes[i].rank[0];
suffixes[i].rank[0] = rank;
}
else // Otherwise increment rank and assign
{
prev_rank = suffixes[i].rank[0];
suffixes[i].rank[0] = ++rank;
}
ind[suffixes[i].index] = i;
}
for (int i = 0; i < n; i++)
{
int nextindex = suffixes[i].index + k/2;
suffixes[i].rank[1] = (nextindex < n)?
suffixes[ind[nextindex]].rank[0]: -1;
}
sort(suffixes, suffixes+n, cmp);
}
vector<int>suffixArr;
for (int i = 0; i < n; i++)
suffixArr.push_back(suffixes[i].index);
return suffixArr;
}
vector<int> kasai(string txt, vector<int> suffixArr)
{
int n = suffixArr.size();
vector<int> lcp(n, 0);
vector<int> invSuff(n, 0);
for (int i=0; i < n; i++)
invSuff[suffixArr[i]] = i;
int k = 0;
for (int i=0; i<n; i++)
{
if (invSuff[i] == n-1)
{
k = 0;
continue;
}
int j = suffixArr[invSuff[i]+1];
while (i+k<n && j+k<n && txt[i+k]==txt[j+k])
k++;
lcp[invSuff[i]] = k; // lcp for the present suffix.
if (k>0)
k--;
}
return lcp;
}
void solve(){
string s;
cin>>s;
int n = s.length();
vector<int> suffixArr = buildSuffixArray(s, n);
vector<int> lcp = kasai(s, suffixArr);
int result = (n*(n+1))/2;
for(auto i : lcp) result-=i;
cout<<result<<"\n";
}
int main(){
int t;
cin>>t;
while(t--){
solve();
}
}
```
