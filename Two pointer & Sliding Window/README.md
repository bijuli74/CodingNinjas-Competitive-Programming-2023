## Max Sum of K Consecutive Elements
given an array of ‘N’ integers. You have to find the maximum sum over all subarrays of size ‘K’.
For example:
If N=3, K=2 and array elements are [ -100, 20, 40 ]. Following are the subarrays of size 2:
[ -100, 20 ] having sum = -100 + 20 = -80.
[ 20, 40 ] having sum = 20 + 40 = 60.

The maximum sum between -80 and 60 is 60. Hence, the output is 60.
Sample Input 1 :
```
2
3 2 
-100 20 40
2 1
12 -34
Sample output 1 :
60
12
```
Explanation For Sample Output 1:
For the first test case,
N=3, K=2 and array elements are [ -100, 20,40 ]. Following are the subarrays of size 2:
[-100, 20] having sum = -100 + 20 = -80.
[20, 40] having sum = 20 + 40 = 60.

The maximum sum between -80 and 60 is 60. Hence, the output is 60.

For the second test case,
N=2, K=1 and array elements are [ 12, -34 ]. Following are the subarrays of size 1:
[12] having sum =12.
[-34] having sum = -34.

The maximum sum between 12 and -34  is 12. Hence, the output is 12.

```cpp
int maxOfK(int n, int k, vector<int> &a)
{
    int cursum=0, ans;
    deque<int> q;
    for(int i=0; i<k; ++i){
        cursum+=a[i];
        q.push_back(a[i]);
    }
    ans=cursum;
    for(int i=k; i<n; ++i){
        int x = q.front();
        q.pop_front();
        ans = max(cursum, cursum-x);

    }
    return ans;
}
```


## Longest Substring with Atmost Two Distinct Characters 
You are given a string ‘S’, you need to find the length of the longest substring that contains at most two distinct characters.
Note:
A string ‘B’ is a substring of a string ‘A’ if ‘B’ that can be obtained by deletion of, several characters(possibly none) from the start of ‘A’ and several characters(possibly none) from the end of ‘A’. 
Follow up :
Can you try to solve this problem in O(N) time and O(1) space.
Example :
If ‘S’ = “ninninja”

Then, “ninnin” is the longest substring that contains at most two distinct characters. We will print the length of this substring which is equal to 6.
```cpp
int lengthOfLongestSubstring(string s) {
    int ans=0,  distinct=0;
    vector<int> cnt(128);
    for(int l=0, r=0; r<s.size(); ++r){
        if(++cnt[s[r]]==1)
            ++distinct;
        while(distinct==3)
            if(--cnt[s[l++]]==0)
                --distinct;
        ans = max(ans, r-l+1);
    }

    return ans;
}
```

## Reverse Words In A String $
You are given a string of length N. You need to reverse the string word by word. There can be multiple spaces between two words and there can be leading or trailing spaces but in the output reversed string you need to put a single space between two words, and your reversed string should not contain leading or trailing spaces.
For example :
If the given input string is "  Welcome to   Coding  Ninjas", then you should return "Ninjas Coding to Welcome" as the reversed string has only a single space between two words and there is no leading or trailing space.

```cpp

#include <algorithm>
void reverseWords(string& s, int n) {
    int i = 0, j = 0;
     while (i < n) {
      while (i < j || i < s.length() && s[i] == ' ')
        ++i;
      while (j < i || j < s.length() && s[j] != ' ')
        ++j;
      reverse(begin(s) + i, begin(s) + j);
    }
 }
  // Trim leading, trailing, and middle spaces
string cleanSpaces(string& s, int n) {
    int i = 0, j = 0;

    while (j < n) {
      while (j < n && s[j] == ' ')  // Skip spaces
        ++j;
      while (j < n && s[j] != ' ')  // Keep non spaces
        s[i++] = s[j++];
      while (j < n && s[j] == ' ')  // Skip spaces
        ++j;
      if (j < n)  // Keep only one space
        s[i++] = ' ';
    }

    return s.substr(0, i);
  }

string reverseString(string s)
{
    reverse(begin(s), end(s));
    reverseWords(s, s.length());
    return cleanSpaces(s, s.length();
}
```

## Container With Most Water
Given a sequence of ‘N’ space-separated non-negative integers A[1],A[2],A[3],......A[i]…...A[n]. Where each number of the sequence represents the height of the line drawn at point 'i'. Hence on the cartesian plane, each line is drawn from coordinate ('i',0) to coordinate ('i', 'A[i]'), here ‘i’ ranges from 1 to ‘N’. Find two lines, which, together with the x-axis forms a container, such that the container contains the most area of water.

```cpp
#include <algorithm>
int maxArea(vector<int>& a) {
  int i=0, j=a.size()-1, ans=0;
  while(i<j){
      int w=j-i;
      ans = max(ans, w*min(a[i], a[j]));
      if(a[i]>a[j]) --j;
      else if(a[i]<a[j]) ++i;
      else ++i, --j;

  }
  return ans;
}
```

## Longest Sub-string with at most K Distinct Characters $
You are given string S of length N, and an integer K. Your task is to find the length of the longest substring that contains at most K distinct characters.

```cpp
#include <vector>
int getLengthofLongestSubstring(int k, string s)
{
   vector<int> cnt(26);
   int ans=0;
   int distinct=0;
   for(int l=0, r=0; r<s.length(); ++r){
      if(++cnt[s[r]-'a']==1)
         ++distinct;
      while(distinct==k+1)
         if(--cnt[s[l++]-'a']==0)
            --distinct;
      
      ans = max(ans, r-l+1);
   }
   return ans;
}
```