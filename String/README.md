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
## Count Special Palindromic Substrings
You are given a string 'STR'. Your task is to count the number of special palindromic substrings of size greater than 1 that the given string contains. A substring is said to be a special palindrome in the following two cases:
If all the characters in the substring are the same.

If the length of the substring is odd and only the middle element is different, while all the other characters are the same. 
Example:
“aba” is a special palindrome, while “abaa” is not
```cpp
int specialPalindromes(string &s)
{
    int n = s.size();
    int ans = 0;
    int sameChar[n] = { 0 };

    int i=0;
    while(i<n){
        int cnt = 1;
        int j = i+1;
        while(s[i]==s[j] && j<n)
            cnt++, j++;
        
        ans += (cnt * (cnt+1)/2);
        sameChar[i] = cnt;
        i=j;
    }

    for(int j=1; j<n; ++j){
        if(s[j] == s[j-1])
            sameChar[j] = sameChar[j-1];
        if(j>0 && j<(n-1) && (s[j-1]==s[j+1] && s[j]!=s[j-1]))
            ans += min(sameChar[j-1], sameChar[j+1]);
    }
    ans -= n;
    return ans;
}
```
## Find all distinct palindromic substrings of a given string
Ninja did not do homework. As a penalty, the teacher has given a string ‘S’ to ninja and asked him to print all distinct palindromic substrings of the given string. A string is said to be palindrome if the reverse of the string is the same as the string itself. For example, the string “bccb” is a palindrome, but the string “def” is not a palindrome.
```cpp
#include <bits/stdc++.h>

bool isPalin(string s){
    for(int i=0, j=s.size()-1; i<j; ++i, --j)
        if(s[i]!=s[j]) return false;
    return true;
}
vector<string> distinctPalindrome(string &s)
{
    int n = s.size();
    set<string> st;
    for(int i=0; i<n; ++i){
        for(int d=1; d<=n; ++d){
            string cur;
            cur = s.substr(i, d);
            if(isPalin(cur)) st.insert(cur);
        }
    }
    vector<string> ans(st.begin(), st.end());
    return ans;
}
```
## Last Substring In Lexicographical Order
You are given a string ‘Str’ of length ‘N’. Find the last substring of ‘Str’ in lexicographical order.
In Lexicographical order string ‘S1’ comes before string ‘S2’ if S1 is the prefix of S2 and (|S1| < |S2|), or if none of them is a prefix of the other and at the first position where they differ, the character in ‘S1’ is smaller than the character in ‘S2’.
Example :
Consider string ‘Str’ = “abba”, then its substring in lexicographical order is [“a”, “ab”, “abb”, “abba”, “b”, “bb”, “bba”].  Clearly, the last substring in lexicographical order is  “bba”. 
```cpp
string findLastSubstring(string &s) {
    int n = s.size();
    string ans, cur_sf;
    for(int i=n-1; ~i; --i){
        cur_sf = s[i] + cur_sf;
        if(cur_sf > ans)
            ans = cur_sf;
    }
    return ans;
}
```
## Longest Chunked Palindrome Decomposition
You are given a string ‘S’. Your task is to find the length of it’s longest possible chunked palindrome. In other words, you have to split the string ‘S’ into ‘K’ substrings ((Sub)1, (Sub)2, (Sub)3, ..., (Sub)K) such that:
1. The substring ‘(Sub)i’ is a non-empty string, for all 1 <= i <= K.
2. (Sub)1 + (Sub)2 + (Sub)3 + … + (Sub)K = ‘S’, which means the concatenation of all the substrings is equal to ‘S’.
3. (Sub)i = (Sub)(K-i+1), for all 1 <= i <= ‘K’.
You have to find the largest possible value of ‘K’
```cpp
int longestChunkedPal(string &s)
{
	int ans = 0;
	int l = 0;
	for(int r=1; 2*r <=s.size(); ++r){
		if(equal(begin(s)+l, begin(s)+r, end(s)-r)){
			ans += 2;
			l = r;
		}
	}
	return ans + (2*l < s.size());
}
```
## Palindrome Partitioning III
On Valentine’s Day, Alice and Bob planned to go on a dinner date, but Alice is still unsure about Bob, so she decided to give him a task. She gave him a string ‘S’ of length ‘N’ containing only lowercase English letters and an integer ‘K’ and told him that he could:
Change some characters of ‘S’ to other lowercase letters  (if required).

Divide ‘S’ into ‘K’ non-empty disjoint substrings such that each substring is a palindrome.
She asked Bob to find the minimum number of characters he needs to change to divide the given string in the required condition. Since Bob is busy preparing a perfect date for her, he called you to solve Alice’s challenge. Can you help Bob to impress her?

```cpp
int paliPartitioning(string &s, int K){
    int n = s.size();
    vector<vector<int>> dp(n+1, vector<int>(K+1, n)); //dp[i][k] = min cost to make k palindromes by s[0..i)
    vector<vector<int>> cost(n, vector<int>(n)); // cost[i][j] = min cost to make s[i..j] palindromes
    
    for(int d=1; d<n; ++d)
        for(int i=0, j=d; j<n; ++i, ++j)
            cost[i][j] = (s[i] != s[j]) + cost[i+1][j-1];

    for(int i=1; i<=n; ++i)
        dp[i][1] = cost[0][i-1];
    
    for(int k=2; k<=K; ++k)
        for(int i=k; i<=n; ++i)
            for(int j=k-1; j<i; ++j)
                dp[i][k] = min(dp[i][k], dp[j][k-1]+cost[j][i-1]);
    
    return dp[n][K];
}
```
## Most Lucky String $
Mr. X is planning to visit Ninja Land. Ninja Land has 'N' cities numbered from 0 to 'N-1' and 'M' bidirectional roads. Each road connects two of the 'N' cities, and no two cities have multiple roads between them. All the 'N' cities have a certain 3 letter code given in the array 'ARR'. Mr. X will stay at Ninja land for exactly 'K' days, and he does not like to stay in the same city for two consecutive days. Therefore, he needs to change his city every day of his stay. He also has a special string that is initially empty. Mr. X has a habit that whenever he visits a city, he appends the code of that city to his special string.
Mr. X has a lucky string 'S' of length '3*K'. Mr. X wants to plan his stay in such a manner that the number of places where the final special string differs from the lucky string is the minimum possible. Your task is to find any such order of cities that Mr. X should visit satisfying the above conditions.
```
Constraints :
1 <= T <= 10
2 <= N <= 1000
1 <= M  <= min(1000,(N*(N-1))/2)
1 <= K <= 100
|ARR[i]| = 3 
|S| = 3*K 
0 <= City1, City2 <= N-1

Every city is reachable from every other city, any two cities are directly connected by at most one road and all the input strings contain uppercase English letters only.

Where 'T' denotes the number of test cases, 'N' denotes the number of cities, 'M' denotes the number of roads, 'K' denotes the number of cities that Mr. X will visit, ARR[i] denotes the 'i'th' element of the array 'ARR', 'S' denotes the lucky string, 'City1' and 'City2' denotes the two cities that are connected by the 'i'th' road, .

Time Limit : 1 sec
Sample Input 1 :
2
3 2 2
AAB BBD ABC
AABABCBBD
0 2
1 2
4 3 1
AAA BBD CCD BBC
BFC
1 2
0 3
1 3
Sample Output 1 :
valid
valid
Explanation for Sample Input 1 :
For the first test case : 
Mr. X can start his journey at City-0, then go to City-2 and then end his journey at City-1. The special string will be "AABABCBBD" which is exactly same as the lucky string.

For the second test case :
Mr. X should visit City-3 only, as the special string in this case differs by the lucky string at only one place.
```
```cpp
vector<int> findOptimalOrder(vector<string> &a, vector<vector<int>> &roads, string &s)
{
   int n = a.size(), m = roads.size(), k = (s.size())/3;
   vector<vector<int>> dp(n, vector<int>(k, 1e9));
   vector<vector<int>> dp2(n, vector<int>(k, -1));

   for(int i=0; i<n; ++i){
       dp[i][0] = 0;
       for(int l=0; l<3; ++l)
        dp[i][0] += (a[i][l] != s[l]);
   }

   for(int i=1; i<k; ++i){
       for(auto& r : roads){
           int city0 = r[0], city1 = r[1];
           int cost0 = 0, cost1 = 0;
           for (int l = 0; l < 3; ++l) {
             cost0 += (a[city0][l] != s[3 * i + l]);
             cost1 += (a[city1][l] != s[3 * i + l]);
           }

               if(dp[city0][i] > dp[city1][i-1] + cost0){
                   dp[city0][i] = dp[city1][i-1] + cost0;
                   dp2[city0][i] = city1;
               }
               if (dp[city1][i] > dp[city0][i - 1] + cost1) {
                 dp[city1][i] = dp[city0][i - 1] + cost1;
                 dp2[city1][i] = city0;
               }
           
       }
   }
   int mncost = 1e9;
   int st = -1;
   for(int i=0; i<n; ++i){
       if(mncost > dp[i][k-1]){
           st = i;
           mncost = dp[i][k-1];
       }
   }

   vector<int> ans(k);
   int days = k-1;
   while(days>=0){
       ans[days] = st;
       st = dp2[st][days];
       --days;
   }
   return ans;
}
```

