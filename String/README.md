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
