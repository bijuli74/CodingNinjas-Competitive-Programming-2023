## All Subsets Generation
You are given an array ‘arr’ of ‘N’ distinct integers. Your task is to find all the non-empty subsets of the array.
Note: You can return the subsets in any order, you don’t have to specifically sort them.

```cpp
void subsets(vector<int>& arr, int i, vector<int> tmp, int n, vector<vector<int>>& ans){
    if(i==arr.size()){
        if(tmp.size()>0) ans.push_back(tmp);
        return;
    }
    subsets(arr, i+1, tmp, n, ans);

    tmp.push_back(arr[i]);
    subsets(arr, i+1, tmp, n, ans);
}
vector<vector<int>> FindAllSubsets(int n, vector<int> &arr){
    vector<vector<int>> ans;
    vector<int> tmp;
    subsets(arr, 0, tmp, n, ans);
    return ans;

}
```

## Permutations of a String
You are given a string 'STR' consisting of lowercase English letters. Your task is to return all permutations of the given string in lexicographically increasing order.
String A is lexicographically less than string B, if either A is a prefix of B (and A ≠ B), or there exists such i (1 <= i <= min(|A|, |B|)), that A[i] < B[i], and for any j (1 <= j < i) A[i] = B[i]. Here |A| denotes the length of the string A.
For example :
If the string is “bca”, then its permutations in lexicographically increasing order are { “abc”, “acb”, “bac”, “bca”, “cab”, “cba” }.

```cpp
 #include <algorithm>
void permute(string &str, int idx, vector<string>& ans, int n) {
  if (idx >= n) {
    ans.push_back(str);
    return;
  }
  for (int i = idx; i < n; ++i) {
    swap(str[idx], str[i]);

    permute(str, idx + 1, ans, n);

    swap(str[idx], str[i]); // come back to original state
  }
}

vector<string> generatePermutations(string &str)
{
    int n=str.size();
    sort(str.begin(), str.end());

    vector<string> ans;
    permute(str, 0, ans, n);
    
    // sort(ans.begin(), ans.end());
    return ans;
}
```

## Combination Sum
You are given an array/list ARR of N distinct positive integers. You are also given a non-negative integer B.
Your task is to find all unique combinations in the array whose sum is equal to B. A number can be chosen any number of times from array/list ARR.
Elements in each combination must be in non-decreasing order.
For example:
Let the array ARR be [1, 2, 3] and B = 5. Then all possible valid combinations are-

(1, 1, 1, 1, 1)
(1, 1, 1, 2)
(1, 1, 3)
(1, 2, 2)
(2, 3)

```cpp
#include <bits/stdc++.h>
void helper(vector<int> &A, int idx, int n, int X, vector<int> &tmp, vector<vector<int>>& ans) {
  if(X==0)
    ans.push_back(tmp);
    
  if (idx >= n || X - A[idx] < 0) {
    return;
  }
  tmp.push_back(A[idx]);

  helper(A, idx, n, X - A[idx], tmp, ans);
  tmp.pop_back();

  helper(A, idx + 1, n, X, tmp, ans);
}

vector<vector<int>> combSum(vector<int> &A, int X) {
  sort(A.begin(), A.end());
  int n = A.size();
  vector<int> tmp;
  vector<vector<int>> ans;

  helper(A, 0, n, X, tmp, ans);
  return ans;
}
```

## Print Keypad - String
Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.

```cpp
void printer(vector<string>& keypad, int n, string ans){
    if(n==0) {
        cout<<ans<<'\n';
        return;
    }
    int last_digit=n%10;
    string s=keypad[last_digit];

    for(int i=0; i<s.size(); ++i){
        printer(keypad, n/10, s[i]+ans);
    }
    if(s.size()==0)
        printer(keypad, n/10, ans);
}

void printKeypad(int n){
    vector<string> keypad(10);
    keypad = {"", "",   "abc",  "def", "ghi",
                                 "jkl", "mno", "pqrs", "tuv", "wxyz"};
    printer(keypad, n, "");

}
```

## Print Series
You have given two positive integers N and K. Your task is to print a series of numbers i.e subtract K from N until it becomes 0 or negative then add K until it becomes N. You need to do this task without using any loop.
For Example:
For  N = 5 , K = 2 
Series = [ 5, 3, 1, -1, 1, 3, 5]
```cpp
vector<int> printSeries(int n, int k)
{
    vector<int> ans;
    int x=n;
    while(n>0){
      ans.push_back(n);
      n -= k;
        
    }
    while(n!=x){
      ans.push_back(n);
      n += k;
       
    }
    ans.push_back(x);
    return ans;
}
```

## Family Structure
Aakash is a member of Ninja club. He has a weird family structure. Every male member (M) gives birth to a male child first and then a female child, whereas every female (F) member gives birth to a female child first and then to a male child. Aakash analyses this pattern and wants to know what will be the Kth child in his Nth generation. Can you help him?

```cpp
int solve(int n, long long k) {
        if(n==1 || k==1) return 0;
		long long a = solve(n-1, k/2+k%2);
		if(k%2==0)
			return a==0;
		return a;
}

string kthChildNthGeneration(int n, long long int k){
	if(solve(n, k)) return "Female";
	return "Male";
}
```

## E. Creating Expression1
Given two numbers N,Xand an array Aof Nnumbers. Determine if there is a way to put '+' or '-' signs between every two numbers in the array Ain order to make an expression that is equal to X

Note: Solve this problem using recursion.

Input
First line contains two numbers N
 and X
 (1≤N≤20,−109≤X≤109)

Second line contains N
 distinct numbers A1,A2,....AN
 (1≤Ai≤105)

Output
Print "YES" if you can put '+' or '-' signs between every two number to create an expression that is equal to X
 otherwise, print "NO".
 
```cpp
 ll n,x;
bool f(int sum,int k, vector<ll> v,int i){
    if(i==v.size()){
        if(sum==x){
            return true;
        }
        return false;
    }
    bool b =f(sum-v[i],k,v,i+1);
    bool c=f(sum+v[i],k,v,i+1);
	return b||c;
}               
signed main()
{
    
    cin>>n>>x;
    vector<ll> v(n);
    fori(i,0,n){
        cin>>v[i];
    }
    if(f(v[0],x,v,1)==1){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }


}
```

## Return Subsets Sum to K $
Given an integer array 'ARR' of size 'N' and an integer 'K', return all the subsets of 'ARR' which sum to 'K'.
Subset of an array 'ARR' is a tuple that can be obtained from 'ARR' by removing some (possibly all) elements of 'ARR'.
Note :
The order of subsets is not important. 
The order of elements in a particular subset should be in increasing order of the index.
```cpp
void subsets(vector<int>& a, int id, int n, int k, vector<vector<int>>& ans, vector<int>& tmp, int sum){
    if(id>=n){
        if(sum==k) ans.push_back(tmp);
        return;
    }
    tmp.push_back(a[id]); // Take
    sum+=a[id];
    subsets(a, id+1, n, k, ans, tmp, sum);

    tmp.pop_back(); // Dont take
    sum-=a[id];
    subsets(a, id+1, n, k, ans, tmp, sum);
    return;
}
vector<vector<int>> findSubsetsThatSumToK(vector<int> a, int n, int k){
    vector<vector<int>> ans;
    vector<int> tmp;
    int sum=0;
    subsets(a, 0, n, k, ans, tmp, sum);
    return ans;
}
// Bitmasking Solution
//  vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k){
//      vector<vector<int>> ans;
//      for (int i = 0; i < (1 << n); i++){
//          vector<int> temp;
//          long long int sum = 0;
//          for (int j = 0; j < n; j++){
//            if (i & (1 << j)) {
//              temp.push_back(arr[j]);
//              sum += arr[j];
//            }
//          }
//         if (sum == k) ans.push_back(temp);
//     }
//  return ans;
// }
```

## Count derangements
A Derangement is a permutation of ‘N’ elements, such that no element appears in its original position. For example, an instance of derangement of {0, 1, 2, 3} is {2, 3, 1, 0}, because 2 present at index 0 is not at its initial position which is 2 and similarly for other elements of the sequence.
Given a number ‘N’, find the total number of derangements possible of a set of 'N’ elements.

```cpp
#include <vector>
long long int countDerangements(int n) {
    const int M=1e9+7;
    vector<long long> dp(n+1);
    dp[0]=1;

    for(int i=2; i<=n; ++i){
        dp[i]=(i-1LL)*(dp[i-1]+dp[i-2])%M;
    }
    return dp[n];
}
```

## Verbal Arithmetic Puzzle $
You are given an array of the strings “words” of size 'M' and another string “result”. You have to treat it as an equation in which the left side is represented by the array “words” and the right side is represented by the string "result". Your task is to determine whether the equation is solvable or not under the following conditions:
1. Each character is decoded as a digit in the range [0, 9].
2. Each character must have only one mapping, and every pair of characters must map to different digits.
3. Each element of the array “words” and the string “result” are decoded as one number without the leading zeros.
4. The sum of the numbers on the left-hand side (words) must equal the number on the right-hand side (result).
```cpp
#include <bits/stdc++.h>
using namespace std;


bool isAnyMapping(vector<string> &words, int row, int col, int bal, unordered_map<char, int> &letToDig, vector<char> &digToLet,
int totalRows, int totalCols) {
  if (col == totalCols) {
    return bal == 0;
  }

  if (row == totalRows) {
    return (bal % 10 == 0 && isAnyMapping(words, 0, col + 1, bal / 10, letToDig, digToLet, totalRows, totalCols));
  }

  string w = words[row];

  
  if (col >= w.length()) 
    return isAnyMapping(words, row + 1, col, bal, letToDig, digToLet, totalRows, totalCols);
    
    char letter = w[w.length() - 1 - col];

  int sign;

  if (row < totalRows - 1) sign = 1;
  else sign = -1;
  
  if (letToDig.count(letter) && (letToDig[letter] != 0 || (letToDig[letter] == 0 && w.length() == 1) || col != w.length() - 1)) {

    return isAnyMapping(words, row + 1, col, bal + sign * letToDig[letter], letToDig, digToLet, totalRows, totalCols);

  }
  // Choose a new mapping.
  else {
    for (int i = 0; i < 10; i++) {
      if (digToLet[i] == '-' &&
          (i != 0 || (i == 0 && w.length() == 1) || col != w.length() - 1)) {
        digToLet[i] = letter;
        letToDig[letter] = i;

        bool x = isAnyMapping(words, row + 1, col, bal + sign * letToDig[letter], letToDig, digToLet, totalRows, totalCols);

        if (x == true) 
          return true;
        
        digToLet[i] = '-';
        if (letToDig.find(letter) != letToDig.end()) {
          letToDig.erase(letter);
        }
      }
    }
  }


  return false;
}

bool isSolvable(int m, vector<string> &words, string result) {
  words.push_back(result);

  int totalRows;
  int totalCols;

  totalRows = words.size();

  totalCols = 0;

  for (int i = 0; i < words.size(); i++) {
    if (totalCols < words[i].size()) {
      totalCols = words[i].size();
    }
  }
  unordered_map<char, int> letToDig;

  vector<char> digToLet(10, '-');

  return isAnyMapping(words, 0, 0, 0, letToDig, digToLet, totalRows, totalCols);
}
```