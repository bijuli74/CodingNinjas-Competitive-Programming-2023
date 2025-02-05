## Count Inversions
For a given integer array/list 'ARR' of size 'N' containing all distinct values, find the total number of 'Inversions' that may exist.
An inversion is defined for a pair of integers in the array/list when the following two conditions are met.
A pair ('ARR[i]', 'ARR[j]') is said to be an inversion when:

1. 'ARR[i] > 'ARR[j]' 
2. 'i' < 'j'

Where 'i' and 'j' denote the indices ranging from [0, 'N').

## Kth Smallest and Largest Element of Array
You are given an array ‘Arr’ consisting of ‘N’ distinct integers and a positive integer ‘K’. Find out Kth smallest and Kth largest element of the array. It is guaranteed that K is not greater than the size of the array.

## Sort 0 1 2
You are given an integer array/list(ARR) of size N. It contains only 0s, 1s and 2s. Write a solution to sort this array/list in a 'single scan'.
'Single Scan' refers to iterating over the array/list just once or to put it in other words, you will be visiting each element in the array/list just once.

## Sort an array in wave form
You have been given an unsorted array ‘ARR’.
Your task is to sort the array in such a way that the array looks like a wave array.
Example:
If the given sequence ‘ARR’ has ‘N’ elements then the sorted wave array looks like - 
‘ARR[0] >= ARR[1]’ and ‘ARR[1] <= ARR[2]’
‘ARR[2] >= ARR[3]’ and ‘ARR[3] <= ARR[4]’
‘ARR[4] >= ARR[5]’ and ‘ARR[5] <= ARR[6]’  And so on.
```
Sample Input 1:
2
5 
2 3 1 4 2
6
4 3 2 5 4 1
Sample Output 1:
2 1 3 2 4
4 3 5 2 4 1
```

```cpp
#include <bits/stdc++.h> 
long long merging(long long *A, int st, int mid, int ed){
   vector<long long>left, right;
   for(int i=st; i<=mid; ++i) left.push_back(A[i]);
   for(int i=mid+1; i<=ed; ++i) right.push_back(A[i]);
   int n=left.size(), m=right.size();

   long long cnt=0;
   int i=0, j=0, k=st;
    while(i<n && j<m){
        if(left[i]<=right[j]){
            A[k]=left[i];
            i++;
        }else{
            A[k]=right[j];
            j++;
            cnt+=(n-i);
        }
        k++;
    }
    while(i<n) A[k++]=left[i++];
    while(j<m) A[k++]=right[j++];

    return cnt;
}

long long mergesort(long long *A, int st, int ed){
    if(st>=ed) return 0;
    int mid = (st+ed)/2;
    long long ans=0;
    ans+=mergesort(A, st, mid);
    ans+=mergesort(A, mid+1, ed);

    ans+=merging(A, st, mid, ed);
    return ans;
}

long long getInversions(long long *arr, int n){
    return mergesort(arr, 0, n-1);

}
```

## Sort By Kth Bit $
You are given an array/list ‘ARR’ of ‘N’ positive integers and an integer ‘K’. Your task is to group all the array elements with ‘K-th’ bit (rightmost bit is ‘1st’ bit) equal to 0 followed by all the elements with ‘K-th’ bit equal to 1.
Note 1: The relative order inside both the groups should remain as it was in the input.
Note 2: You have to return the modified array/list..

```cpp
#include <algorithm>
vector<int> sortArrayByKBit(int n, int k, vector<int> &a) {
    int mask=1<<(k-1);
    vector<int> left, right, ans;
    for(int i=0; i<n; ++i){
        if((a[i]&mask)==0) left.push_back(a[i]);
        else right.push_back(a[i]);
    }
  for(int i: right) left.push_back(i);
  return left;

}
```

## Minimum number of swaps required to sort an array $
You have been given an array 'ARR' of 'N' distinct elements.
Your task is to find the minimum no. of swaps required to sort the array.
For example: For the given input array [4, 3, 2, 1], the minimum no. of swaps required to sort the array is 2, i.e. swap index 0 with 3 and 1 with 2 to form the sorted array [1, 2, 3, 4].

```cpp
int minSwaps(vector<int> &a){
	int n=a.size();
	vector<vector<int>> v(n, vector<int>(2));
	for(int i=0; i<n; ++i){
		v[i][0]=a[i];
		v[i][1]=i;
	}
	sort(begin(v), end(v));
	vector<bool> vis(n, false);
	int ans=0;
	for(int i=0; i<n; ++i){
		if(vis[i] || v[i][1]==i) continue;
		int cyc=0;
		int j=i;
		while(!vis[j]){
			vis[j]=1;
			j=v[j][1];
			cyc++;
		}
		if(cyc>0) ans+=(cyc-1);
	}
	return ans;
}
```

## Relative Sorting $
Given two arrays ‘ARR’ and ‘BRR’ of size ‘N’ and ‘M’ respectively. Your task is to sort the elements of ‘ARR’ in such a way that the relative order among the elements will be the same as those are in ‘BRR’. For the elements not present in ‘BRR’, append them in the last in sorted order.
For example
Consider the arrays as ARR = { 9, 5, 8, 4, 6, 5 } and BRR = { 8, 4, 5 }
The output for the above example  is { 8, 4, 5, 5, 6, 9 }.
Note:
Elements of ‘BRR’ are non repeating.

```cpp
#include <bits/stdc++.h>
vector<int> relativeSorting(vector<int> &a, vector<int> &b, int n, int m)
{
    map<int, int> mp;
    for(int i: a) mp[i]++;
    int k=0;
    for (int i : b) {
      while (mp[i]-- > 0)
        a[k++] = i;
    }
    for(auto it: mp){
        while(it.second-- >0)
            a[k++]=it.first;
    }
    return a;
}
```

## Sorting the Skills
Send Feedback
There is a company named James Peterson & Co. The company has ‘n’ employees. The employees have skills, which is denoted with help of an integer. The manager of James Peterson & Co. wants to sort the employees on the basis of their skills in ascending order. He is only allowed to swap two employees which are adjacent to each other. He is given the skills of employees in an array of size ‘n’. He can swap the skills as long as the absolute difference between their skills is 1. You need to help the manager out and tell whether it is possible to sort the skills of employees or not.
Input Format:
First Line will have an integer ‘t’ denoting the no. of test cases.
First line of each test case contains an integer ‘n’ denoting the no. of employees in the company.
Second line of each test case contains ‘n’ integers.
Output Format:
For each test case, print “Yes” if it is possible to sort the skills otherwise “No”.
```
Constraints:
1 <= t <= 10^4
1 <= n <= 10^5
Sum of n over all test cases doesn't exceed 10^6
Sample Input:
2
4
1 0 3 2
3
2 1 0
Sample Output:
Yes
No
Explanation:
In first T.C., [1, 0, 3, 2] -> [0, 1, 3, 2] -> [0, 1, 2, 3]
In second T.C., [2, 1, 0] -> [1, 2, 0]  OR  [2, 1, 0] -> [2, 0, 1] So, it is impossible to sort.
```

```cpp
#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin>>a[i];
    bool ok=1;
    int i=0, j=1;
    while(i<n&&j<n){
        if(a[i]==a[j]+1){
            swap(a[i], a[j]);
            while(i>0 && a[i]==a[i-1]-1){
                swap(a[i], a[i-1]);
                i--;
            }
        i=j;
        j=i+1;
        }else{
            i++;
            j++;
        }
    }
    for(int i=1; i<n; ++i){
        if(a[i-1]>a[i]){
            ok=0;
            break;
        }
    }

    if(ok) cout<<"Yes"<<'\n';
    else cout<<"No"<<'\n';
    return;


}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
} 
```

## Murder $$
Once detective Saikat was solving a murder case. While going to the crime scene he took the stairs and saw that a number is written on every stair. He found it suspicious and decides to remember all the numbers that he has seen till now. While remembering the numbers he found that he can find some pattern in those numbers. So he decides that for each number on the stairs he will note down the sum of all the numbers previously seen on the stairs which are smaller than the present number. Calculate the sum of all the numbers written on his notes diary.
Answer may not fit in integer . You have to take long.
Input Format:
First line of input contains an integer T, representing number of test case.
For each test case, first line of input contains integer N, representing the number of stairs.
For each test case, second line of input contains N space separated integers, representing numbers written on the stairs.
```
Constraints
T<=10^5
1<=N<=10^5
All numbers will be between 0 and 10^9
Sum of N over all test cases doesn't exceed 5*10^5
Output Format
For each test case output one line giving the final sum for each test case.
Sample Input 1:
1
5
1 5 3 6 4
Sample Output 1:
15
```
Explanation:
For the first number, the contribution to the sum is 0.
For the second number, the contribution to the sum is 1.
For the third number, the contribution to the sum is 1.
For the fourth number, the contribution to the sum is 9 (1+5+3).
For the fifth number, the contribution to the sum is 4 (1+3).
Hence the sum is 15 (0+1+1+9+4).

```cpp
#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll merge(ll *arr, ll left, ll mid, ll right) {
  ll i = left, k = 0, j = mid, sum = 0;
  ll *temp = new ll[right - left + 1];
  while (i < mid && j <= right) {
    if (arr[i] < arr[j]) {
      sum += (arr[i] * (right - j + 1)); //
      temp[k++] = arr[i++];
    } else {
      temp[k++] = arr[j++];
    }
  }
  while (i < mid) temp[k++] = arr[i++];
  while (j <= right) temp[k++] = arr[j++];
  for (int i = left, k = 0; i <= right; i++, k++) 
    arr[i] = temp[k];
  delete[] temp;
  return sum;
}
ll merge_sort(ll *arr, ll left, ll right) {
  ll count = 0;
  if (right > left) {
    ll mid = (right + left) / 2;
    count += merge_sort(arr, left, mid);
    count += merge_sort(arr, mid + 1, right);
    count += merge(arr, left, mid + 1, right);

    return count;
  }
  return count;
}
ll solve(ll *arr, ll n) {
  return merge_sort(arr, 0, n - 1);
  
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  ll t; cin >> t;
  while (t--) {
    ll n; cin >> n;
    ll *arr = new ll[n];
    for (ll i = 0; i < n; i++)  cin >> arr[i];
    cout << solve(arr, n) << endl;
  }
}
```


## Kth Smallest and Largest Element
```cpp
#include <algorithm>
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	sort(begin(arr), end(arr));
	int small=arr[k-1], large=arr[n-k];
	return {small, large};
}
```

## Sort array in a waveform
```cpp
vector<int> waveFormArray(vector<int> &a, int n) {
    sort(begin(a), end(a));
    vector<int> ans(n);
    for(int i=0, j=n-1, k=0; i<=j; ++i, --j){
        ans[k++]=a[j];
        ans[k++]=a[i];
    }
    // for(auto i: ans) cout<<i<<" ";
    return ans;
}
```
# Sort 0 1 2
```cpp
void sort012(int *arr, int n)
{
  int f[3] = { 0 };
  for (int i = 0; i < n; ++i) f[arr[i]]++;
  int i=0;
  while(i<n){
    for (int num = 0; num < 3; num++) {
      for (int j = 0; j < f[num]; ++j)
        arr[i++] = num;
    }
  }
}
```
# Test

## Party Over
Ninja is coming after a long party to his home, but he faces a monster while returning. Monster puts up a condition to Ninja in order to free him. The monster gives him ‘n’ strings and asks him to sort them. However, he adds an extra condition to him.
Since the monster knows that Ninja could do it easily, the monster wants him to sort them using the last letter of each string. If there are strings with the same last character, sort them based on their second last character and so on.

```cpp
vector<string> ninjaParty(vector<string> &a)
{
    int n=a.size();
    for(string& s: a){
        reverse(s.begin(), s.end());
    }
    sort(begin(a), end(a));
    for(string& s: a){
        reverse(s.begin(), s.end());
    }
    return a;
}
```

## 3Sum $
You are given an array/list ARR consisting of N integers. Your task is to find all the distinct triplets present in the array which adds up to a given number K.
An array is said to have a triplet {ARR[i], ARR[j], ARR[k]} with sum = 'K' if there exists three indices i, j and k such that i!=j, j!=k and i!=j and ARR[i] + ARR[j] + ARR[k] = 'K'.
Note:
1. You can return the list of values in any order. For example, if a valid triplet is {1, 2, -3}, then {2, -3, 1}, {-3, 2, 1} etc is also valid triplet. Also, the ordering of different triplets can be random i.e if there are more than one valid triplets, you can return them in any order.
2. The elements in the array need not be distinct.
3. If no such triplet is present in the array, then return an empty list, and the output printed for such a test case will be "-1".

## Maximum activities
You are given N activities with their start time Start[] and finish time Finish[]. You need to tell the maximum number of activities a single person can perform.
Note:
A person can only work on a single activity at a time. The start time of one activity can coincide with the end time of another.

```cpp
#include <algorithm>
int maximumActivities(vector<int> &start, vector<int> &finish) {
  int n = start.size();
  vector<pair<int, int>> a(n);

  for (int i = 0; i < n; i++) {
    a[i].first = finish[i];
    a[i].second = start[i];
  }

  sort(a.begin(), a.end());

  int maxa = 1;
  int currentTime = a[0].first;

  for (int i = 1; i < n; i++) {

  
    if (a[i].second >= currentTime) {
      maxa++;
      currentTime = a[i].first;
    }
  }
  return maxa;
}
```

## Two City Scheduling $
Ninja is planning to organize an exhibition in which ‘2N’ peoples are coming. The hall’s capacity in which the exhibition is going to take place is only ‘N’. So, ninja thinks of organizing two exhibitions in 2 different cities, ‘CITY_A’ and ‘CITY_B’, each of capacity ‘N’. All ‘2N’ people will come to the exhibition but in the group of ‘N’ in two different cities. Ninja wants your help in organizing this event.
You are given an array ‘COST’ where “COST[i] = [COST_TO_Ai, COST_TO_Bi]”, in which ‘COST_TO_Ai’ is the cost of the ith person to fly to the city A, and ‘COST_TO_Bi’ is the cost of the ith person to fly to the city B. Your task is to find the minimum cost of organizing the exhibition in which every person flies to a city such that exactly ‘N’ people arrive in each city.
Note:
The intersection of the set of the persons who go to ‘CITY_A’ to those going to ‘CITY_B’ is to be disjoint set, whereas the union must be the ‘2N’.
```cpp
int findMinCost(int n, vector<vector<int>> &cost)
{
	vector<int> a_b;
	int ans=0;
	for(int i=0; i<n*2; ++i){
		a_b.push_back(cost[i][1]-cost[i][0]);
		ans+=cost[i][0];
	}
	sort(begin(a_b), end(a_b));
	for(int i=0; i<n; ++i)
		ans+=a_b[i];
	return ans;
}
```