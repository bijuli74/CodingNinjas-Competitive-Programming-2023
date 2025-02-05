## Next Geater Element

Given an array, print the Next Greater Element (NGE) for every element. The Next greater Element for an element x, is the first greater element on right side of x in the array. Elements for which no greater element exist, consider next greater element as -1.
Input format :

Line 1 : Size of input array

Line 2 : Array elements (separated by space)

Constraints:
Time Limit: 1 second
Size of input array lies in the range: [1, 1000000]
Sample Input
```
5
3  8  1  2  0
```
Sample Output
```
8 -1  2 -1 -1
```
```cpp
#include <vector>

vector<int> nextGreaterElement(vector<int> a) {
	int n=a.size();
	vector<int> ng(n, -1);
	for(int i=0; i<n; ++i){
		ng[i]=i+1;
		while(ng[i]<n && a[ng[i]]<a[i]){
			ng[i]=ng[ng[i]];
		}
		
	}
	return ng;
	// vector<int> ng;
	// int nxt;
	// for(int i=0; i<n; ++i){
	// 	nxt=-1;
	// 	for(int j=i+1; j<n; ++j){
	// 		if(a[i]<a[j]){
	// 			nxt=a[j];
	// 			break;
	// 		}
	// 	}
	// 	ng.push_back(nxt);
	// }
	// return ng;

}
```

## k-largest element
You are given with an integer k and an array of integers that contain numbers in random order. You have to find k largest numbers from given array. You need to save them in an array and return it.
Note:
1. Time complexity should be O(n * logk) and space complexity should not be more than O(k).
2. Order of elements in the output is not important.

Sample Input 1:
```
13
2 12 9 16 10 5 3 20 25 11 1 8 6 
4
```
Sample Output 1:
```
12 16 20 25
```
```cpp
vector<int> kLargest(int a[], int n, int k) {
    partial_sort(a, a+k, a+n, greater<int>());
    vector<int> ans;
    ans.assign(a, a+k);
    return ans;

}
```

## Valid pairs $
Given an array of integers and numbers k and m, write a function that returns true if given array can be divided into pairs such that the sum of every pair gives remainder m when divided by k.
Input format :
Line 1 : Integer N 
Line 2 : N integers separated be a single space
Line 3 : Integer K
Line 4 : Integer M
Output Format :
 Boolean
```
Constraints :
 1 <= N <= 10^4
 1 <= M < K <= 10^2
Sample Input :
4
2 1 5 7
9
3

Sample Output :
true
Explanation :
Pairs will be (2,1) and (5,7)
```

```cpp
bool CheckSumPairs(int a[], int n, int k, int m) {
 	if(n&1) return 0;
     unordered_map<int, int> mp;
     for(int i=0; i<n; ++i)
        ++mp[a[i]%k];
    for(auto it=mp.begin(); it!=mp.end(); ++it){
        int rem=it->first;
        if(rem*2==m){
            if(mp[rem]&1) return 0;
        }else{
            if(mp[rem] != mp[(m-rem+k)%k])
                return 0;
        }
    }
    return 1;
}
```

## Two sum $

You are given an array of integers 'ARR' of length 'N' and an integer Target. Your task is to return all pairs of elements such that they add up to Target.
Note:
We cannot use the element at a given index twice.
Follow Up:
Try to do this problem in O(N) time complexity. 
```
Constraints:
1 <= T <= 100
1 <= N <= 5000
-10 ^ 9 <= TARGET <=10 ^ 9
-10 ^ 9 <= ARR[i] <=10 ^ 9

Where 'T' denotes the number of test cases, 'N' represents the size of the array, 'TARGET' represents the sum required, and 'ARR[i]' represents array elements.

Time Limit: 1 sec.
Sample Input 1 :
2
4 9
2 7 11 13
5 1
1 -1 -1 2 2
Sample Output 1:
2 7
-1 2
-1 2
Explanation for Sample 1:
For the first test case, we can see that the sum of  2 and 7 is equal to 9 and it is the only valid pair.

For the second test case, there are two valid pairs (-1,2) and (-1,2), which add up to 1.
Sample Input 2 :
1
4 16
2 7 11 13
Sample Output 2 :
-1 -1
```

```cpp
#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> twoSum(vector<int>& arr, int target, int n)
{
	unordered_map<int, int> mp;
	vector<pair<int, int>> ans;
	for(int i=0; i<n; ++i)
		++mp[arr[i]];

	for(int i=0; i<n; ++i){
		int x=target-arr[i];
		if(x==arr[i]){
			if(mp[arr[i]]>1){
				mp[arr[i]]-=2;
				ans.push_back(make_pair(arr[i], arr[i]));
			}
			
			}
			else if(mp[arr[i]]>0 && mp[x]>0){
				ans.push_back(make_pair(arr[i], x));
				mp[arr[i]]--;
				mp[x]--;
			}
	}
	
	if(ans.empty()) ans.push_back(make_pair(-1, -1));
	return ans;
}
```

## First and last position of element in the sorted array

You are given a non-decreasing array 'arr' consisting of 'n' integers and an integer 'x'. You need to find the first and last position of 'x' in the array.
Note:
1. The array follows 0-based indexing, so you need to return 0-based indices.
2. If 'x' is not present in the array, return {-1 -1}.
3. If 'x' is only present once in the array, the first and last position of its occurrence will be the same.
```
Sample Input 1:
5
-10 -5 -5 -5 2
-5
Sample Output 1:
1 3
```

```cpp
#include <algorithm>
pair<int, int> findFirstLastPosition(vector<int> &arr, int n, int x)
{
  const int l = lower_bound(begin(arr), end(arr), x) - begin(arr);
  if (l == arr.size() || arr[l] != x)
    return {-1, -1};
  const int r = upper_bound(begin(arr), end(arr), x) - begin(arr) - 1;
  return {l, r};
}
```

## Time-based Key Value Store $
You are given a stream of tuples which constitute three things ‘Key’, ‘Val’, and the ‘Timestamp’.
Your task is to implement the ‘TimeBased’ class having the two functions:
1) The first function is ‘setKey(string Key, string Val, int Timestamp)’, which stores the ‘Key’ and the ‘Val’ along with the ‘Timestamp’.

2) The second function is ‘getValue(string TargetKey, int TargetTimestamp)’, which returns the value of ‘Val’ associated with the ‘TargetKey’ such that its ‘Timestamp’ value is less than or equal to the ‘TargetTimestamp’. If there are multiple values of ‘Val’, return the value of ‘Val’ with the highest value of ‘Timestamp’ among the valid ones. If there is no valid value of ‘Val’ return “-1” as a string.
‘Timestamps’ will always be in strictly increasing order.
Input format:
The first line of input contains an integer ‘T’, denoting the number of test cases. 

The first line of each test case contains an integer ‘N’, representing the total number of queries.

Then the next ‘N’ lines contain ‘N’ queries. A query can be of two types:
1 Key Val Timestamp  → stores the Key and the Val along with the Timestamp
2 TargetKey TargetTimestamp → returns the value of ‘Val’
Output format:
For each test case, print the value of ‘Val’ for each query of type 2 only, output the answer to the query in a single line.

```
Sample Input 1:
 2
 4
 1 abc def 10
 1 abc ghi 20
 2 abc 10
 2 abc 5
 3
 1 bbb ccc 5
 1 ddd ccc 5
 2 ddd 6 
Sample Output 1:
 def  -1
 ccc
 
 Sample Input 2:
2
3
1 yyy zzz 3
1 yyy xxx 4
2 yyy 4
4
2 fff 13
1 fff ggg 13
1 fff hhh 14
2 fff 14 
Sample Output 2:
xxx
-1 hhh
 ```
 ```cpp
 /*
    Your Timebased object will be instantiated and called as such:

    Timebased* obj = new Timebased();
    obj->setKey(key,value,timestamp);
    string ans = obj->getValue(targetKey,targetTimestamp);
*/
#include <bits/stdc++.h>
using namespace std;
class Timebased {

    public:
      // Timebased() { 
      //     map<string, map<int, string, greater<int>>> m; 
      //     }
      map<string, map<int, string, greater<int>>> mp;
      void setKey(string key, string val, int timestamp) {
        mp[key][timestamp] = val;
    }

    string getValue(string targetKey, int targetTimestamp) {
      if (mp.count(targetKey) == 0)
        return "-1";

      auto it = mp[targetKey].lower_bound(targetTimestamp);
      if (it == mp[targetKey].end())
        return "-1";
      return it->second;
    }
};
```

## Overlapping Intervals
You have been given the start and end times of 'N' intervals. Write a function to check if any two intervals overlap with each other.
Note :
If an interval ends at time T and another interval starts at the same time, they are not considered overlapping intervals.
```
Sample Input 2 :
2
1
100
200
2
2 1
3 4
Sample Output 2 :
false
true
```
```cpp
#include <bits/stdc++.h>
bool checkOverlappingIntervals(long* start, long* end, int n)
{
    vector<pair<long, long>> intervals;
    for(int i=0; i<n; ++i){
        intervals.push_back(make_pair(start[i], end[i]));
     }

     if(intervals.empty())
        return 0;
    
    sort(intervals.begin(), intervals.end() );
    // int cur_end = intervals[0].first;

    for(int i=1; i<n; ++i){
        if(intervals[i-1].second > intervals[i].first)
            return 1;
    }
    return 0;

    // int mx = 0;
    // for(int i=0; i<n; ++i){
    //     if( mx < intervals[i][0])
    //         mx = intervals[i][0];
    // }
    // int aux[mx + 1] = {0};
    // for(int i=0; i<n; ++i){
    //     int st = intervals[i][1];
    //     int ed = intervals[i][0];
    //     aux[st]++, aux[ed]--;
    // }
    // for(int i=1; i<=mx; i++){
    //     aux[i] += aux[i-1];
    //     if(aux[i] > 1)
    //         return 1;
    // }
    // return 0;

}

```

## Maximum length pair chain
You are given ‘N’ pairs of integers in which the first number is always smaller than the second number i.e in pair (a,b) -> a < b always. Now we define a pair chain as the continuous arrangement of pairs in which a pair (c,d) can follow another pair (a,b) only when b < c.
Find the length of the longest pair chain that can be formed using the given pairs.
Example:
Given Pairs =  [3,4], [1,2], [2,3].

The length of the maximum chain will be 2. The longest chain is [1,2] -> [3,4].

```cpp
#include <bits/stdc++.h>
int maxLengthChain(vector<pair<int, int>> &p, int n) {
    sort(p.begin(), p.end(), [](const pair<int, int>& a, const pair<int, int>& b){ return a.second < b.second; });
    int prev=p[0].second;
    int ans=1;
    for(int i=1; i<n; ++i){
        if(p[i].first>prev){
            ans++;
            prev=p[i].second;
        }
    }
    return ans;
}
```

## Closest Distance Pair $

You are given an array containing 'N' points in the plane. The task is to find out the distance of the closest points.
Note :
Where distance between two points (x1, y1) and (x2, y2) is calculated as [(x1 - x2) ^ 2] + [(y1 - y2) ^ 2].
Input Format :
The first line contains a single integer 'N' denoting the number of points.

The next 'N' lines contain two integers separated by a single space, where the first integer represents the x coordinate and the second integer represents the y coordinate.
Output Format :
The only line contains the minimum distance between the 'N' points.
Note:
You do not need to print anything, it has already been taken care of. Just implement the given function.
```
Constraints :
2 <= 'N' <= 10^5
-10^5 <= 'x' <= 10^5 
-10^5 <= 'y' <= 10^5

Time Limit: 1 sec
Sample Input 1:
5
1 2
2 3
3 4
5 6
2 1
Sample Output 1:
2
Explanation of Sample Output 1:
We have 2 pairs which are probable answers (1, 2) with (2, 3) and (2, 3) with (3, 4). The distance between both of them is equal to 2.
```

```cpp
#include <bits/stdc++.h>

long calcdist(int x1, int x2, int y1, int y2){
    long d =( (long)(x1) - (long)(x2) )*( (long)(x1) - (long)(x2) ) + ( (long)(y1) - (long)(y2) )*( (long)(y1) - (long)(y2) );
    return d;
}

long bruteForce(pair<int, int>* a, int n){
    long mn = LONG_MAX;
    for(int i=0; i<n; ++i){
        int x1 = a[i].first, y1 = a[i].second;
        for(int j=i+1; j<n; ++j){
            int x2 = a[j].first, y2 = a[j].second;
            long d = calcdist(x1, x2, y1, y2);
            if(d<mn)
                mn = d;
        }

    }
    return mn;
}

long stripClosest(pair<int, int>* strip, int size, long d){
    long min = d; 
 
    for (int i = 0; i < size; ++i)
        for (int j = i+1; j < size && (strip[j].second - strip[i].second) < min; ++j){
            long dist = calcdist(strip[i].first, strip[j].first, strip[i].second, strip[j].second);
            if ( dist < min)
                min = dist;
        }
 
    return min;
}

long helper(pair<int, int>* a, pair<int, int>* ax, pair<int, int>* ay, int n){
       if(n<=3) return bruteForce(a, n);

    int mid = n/2;
    // pair<int, int> midpoint = ax[mid];

    pair<int, int> ayl[mid];
    pair<int, int> ayr[n-mid];
    int li=0;
    int ri=0;
    for(int i=0; i<n; ++i){
        if((ay[i].first<ax[mid].first || (ay[i].first==ax[mid].first && ay[i].second<ay[i].second)) && li<mid)
            ayl[li++]=ay[i];
            else
                ayr[ri++]=ay[i];
    }

    long dl = helper(a, ax, ayl, mid);
    long dr = helper(a, ax+mid, ayr, n-mid);

    long d = min(dl, dr);
    
    pair<int, int> strip[n];
    int j=0;
    for(int i=0; i<n; i++){
        if(abs(ay[i].first - ax[mid].first) < d)
            strip[j] = ay[i], ++j;
    }
    return stripClosest(strip, j, d);
}

long closestPair(pair<int, int>* a, int n){
    if(n<=1e4){
        return bruteForce(a, n);
    }
    pair<int, int> ax[n];
    pair<int, int> ay[n];
    for (int i = 0; i < n; i++){
        ax[i] = a[i];
        ay[i] = a[i];
    }
 
    sort(ax, ax+n, [](pair<int, int>& a, pair<int, int>& b){ return a.first < b.first;});
    sort(ay, ay+n, [](pair<int, int>& a, pair<int, int>& b){ return a.second < b.second; });
 
    // Use recursive function to find the smallest distance
    return helper(a, ax, ay, n);
}
```

## No of distinct pairs in array whose difference is K $
Problem Statement
Suggest Edit
Ninja has been asked to organize a dance competition. Ninja decided that he will take individual entries
and then will divide them into pairs. As part of the entry, he asked the participants to choose any number.
Ninja then thought of a creative method to divide them into pairs. He decided that he would select a
number 'K', and then select numbers from the list that have a difference equal to 4K'.
You need to help Ninja in finding the number of distinct pairs from the numbers with differences equal to
Example:
Let us suppose the numbers are chosen by participants: [2, 6, 5, 2, 3] and K =
3, then
the distinct pairs having differences equal to K are: [2, 5] and [3, 6] so print 2.
Note:
The list of
pairs.
For example
are: (2, 3)
numbers can contain duplicate numbers, you need to print only the distinct
[2,
and
2,
3, 4] and K =
1, so you need to print 2 as the two distinct pairs
```cpp
#include <bits/stdc++.h> 
int kDiffPairs(vector < int > & arr, int n, int k) {
    
    sort(arr.begin(),arr.end(),greater<int>());
    int ans = 0;
    set<int> seen;
    set<pair<int,int>> s;
    
    for(int i=0;i<n;i++){
      if (seen.count(arr[i] + k) > 0) {
        s.insert(make_pair(arr[i], arr[i] + k));
      }
      seen.insert(arr[i]);
    }
    return s.size();
}

/*
	Time complexity: O(N) 
	Space complexity: O(N)
	
	Where 'N' is the size of the array.
*/

#include<unordered_map>

int kDiffPairs(vector < int > & arr, int n, int k) {

    // Initialise a hashmap to store frequencies.
    unordered_map < int, int > mp;

    // Initialise a variable to store the count.
    int count = 0;

    // Start traversing through the vector.
    for (int i = 0; i < n; i++) {

        // If difference is not equal to zero.
        if (k != 0) {
            if (mp.find(arr[i]) != mp.end()) {

                // Number present in map.
                continue;
            }
            if (mp.find(k + arr[i]) != mp.end()) {

                // Number with difference equal to k found.
                count++;
            }
            if (mp.find(arr[i] - k) != mp.end()) {

                // Number with difference equal to k found.
                count++;
            }

            // Increase frequency.
            mp[arr[i]]++;
        }

        // If k is equal to zero.
        else {

            // Increase frequency.
            mp[arr[i]]++;

            // If frequency equal to two.
            if (mp[arr[i]] == 2) {

                // Pair with difference equal to zero found.
                count++;
            }
        }
    }

    // Return count.
    return count;
}

// #include <bits/stdc++.h> 
// int kDiffPairs(vector < int > & arr, int n, int k) {
    
 // Fails one edges case !!!
    
//     map<int,int> m;
//     int ans = 0;
//     for(int i=0;i<n;i++){
//         m[arr[i]]++;
//     }
    
//     for(auto i : m){
//         if(m.count(i.first+k)>0){
//             ans++;
//         }
//     }
//     return ans;
    
// }
```