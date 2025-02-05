## Search in Rotated Sorted Array
Aahad and Harshit always have fun by solving problems. Harshit took a sorted array consisting of distinct integers and rotated it clockwise by an unknown amount. For example, he took a sorted array = [1, 2, 3, 4, 5] and if he rotates it by 2, then the array becomes: [4, 5, 1, 2, 3].
After rotating a sorted array, Aahad needs to answer Q queries asked by Harshit, each of them is described by one integer Q[i]. which Harshit wanted him to search in the array. For each query, if he found it, he had to shout the index of the number, otherwise, he had to shout -1.
For each query, you have to complete the given method where 'key' denotes Q[i]. If the key exists in the array, return the index of the 'key', otherwise, return -1.
Note:
Can you solve each query in O(logN) ?

```cpp
int search(int* a, int n, int key) {
   int l=0, r=n-1;
   while(l<=r){
       int m=l+(r-l)/2;
       if(a[m]==key) return m;
       if(a[l]<=a[m]){
           if(a[l]<=key && key<a[m]) r=m-1;
           else l=m+1;
       }else{
           if(a[m]<key && key<=a[r]) l=m+1;
           else r=m-1;
       }
   }
   return -1;
}
```

## Aggressive Cows
You are given an array 'arr' consisting of 'n' integers which denote the position of a stall.
You are also given an integer 'k' which denotes the number of aggressive cows.
You are given the task of assigning stalls to 'k' cows such that the minimum distance between any two of them is the maximum possible.

```cpp
int n;
bool canArrange(vector<int>& stalls, int mid, int k){
    int total=1, last=0;
    for(int i=1; i<n; i++){
        if(stalls[i]-stalls[last]>=mid){
            total++;
            last=i;
        }
    }
    return total>=k;
}

int aggressiveCows(vector<int> &stalls, int k)
{   
    n=stalls.size();
    sort(stalls.begin(), stalls.end());
    int l=1, r=stalls[n-1]-stalls[0];
    int ans=1e9+5;
    while(l<=r){
        int mid = l+(r-l)/2;
        if (canArrange(stalls, mid, k)) {
          l = mid + 1;
          ans=mid;
        } else {
          r = mid-1;
        }
    }
    return ans;
}
```

## Recycling Pens
You have 'N' empty pens whose refills have been used up. You have 'R' rupees in your pocket. You have two choices of operations that you can perform each time.
1) Recycle 1 empty pen and get 'K' rupees as a reward.
2) Buy 1 refill for 'C' rupees and combine it with 1 empty pen to make one usable pen.
Your task is to find the maximum number of usable pens that you can get.
For example if you have 'N' = 5 , 'R' = 10 , 'K' = 2 , 'C' = 3. You can recycle one pen and get 2 rupees as a reward so you will have a total of 12 rupees. Now you can buy 4 refills and combine it with 4 pens to make it usable. So your answer is 4.

```cpp
#define ll long long
int recyclePens(int n, int R, int k, int c ){

	int l=0, r=n;
	int ans=0;
	while(l<=r){
		ll mid = (l+r)/2;
		ll recyclecost=(n-mid)*k;
		ll totalcost=recyclecost+R;
		if(totalcost>=mid*c){
			l=mid+1;
			ans=mid;
                } else {
                  r = mid - 1;
                }
        }
        return ans;
}
```

## Painter's Partition Problem
Given an array/list of length ‘N’, where the array/list represents the boards and each element of the given array/list represents the length of each board. Some ‘K’ numbers of painters are available to paint these boards. Consider that each unit of a board takes 1 unit of time to paint.
You are supposed to return the area of the minimum time to get this job done of painting all the ‘N’ boards under a constraint that any painter will only paint the continuous sections of boards.

```cpp
bool check(vector<int> &a, int cap, int k) {
  int cnt_painters = 1, remCap= cap;
  for (int i = 0; i < a.size(); ++i) {
    remCap-=a[i];
    if(remCap<0){
        cnt_painters++;
        remCap=cap-a[i];
    }
  }
  return cnt_painters <= k;
}

int findLargestMinDistance(vector<int> &A, int k) {
    int mx=0, sum=0;
    for(int i=0; i<A.size(); ++i){
        mx = max(mx, A[i]);
        sum+=A[i];
    }
  int l = mx, r = sum;
  int ans = 0;
  while (l <= r) {
    int mid = l + (r - l) / 2;
    if (check(A, mid, k)) {
      r = mid - 1;
      ans = mid;
    } else {
      l = mid + 1;
    }
  }
  return ans;
}

```

## Smart Intervals
You are given an array of intervals, where intervals[i] = [start(i), end(i)] and each start(i) is unique.
The smart interval for an interval ‘i’ is an interval ‘j’ such that start(j) is greater than or equal to end(i) and start(j) should be minimum.
Your task is to return an array of smart interval indices for each interval. If no smart interval exists for an interval ‘i’, then place -1 at index ‘i’ in the output array.
```
Sample Input 1:
1
3
1 2
2 3
3 4
Sample output 1:
1 2 -1
Explanation of Sample output 1:
Smart interval for the interval [1, 2] is [2, 3] because the start point of [2, 3] is equal to the end point of [1, 2]. The index of [2, 3] is 1.
Smart interval for the interval [2, 3] is [3, 4] because the start point of [3, 4] is equal to the end point of [2, 3]. The index of [3, 4] is 2.
Smart interval for the interval [3, 4] does not exist. Hence, -1.
Therefore, the final answer is [1, 2, -1]. 
```
```cpp
#include <bits/stdc++.h>
vector<int> smartInterval(vector<vector<int>> &intervals, int n)
{
	vector<int> starts(n), ans;
	unordered_map<int, int> mp;
	for(int i=0; i<n; ++i){
		starts[i]=intervals[i][0];
		mp[intervals[i][0]]=i;
	}
	sort(begin(starts), end(starts));

	for(int i=0; i<n; ++i){
		int x = *lower_bound(begin(starts), end(starts), intervals[i][1]);
		if(mp.find(x)!=mp.end()) ans.push_back(mp[x]);
		else ans.push_back(-1);
	}
	return ans;
}
```

## Shopping Options
You are given the list of costs of pants in an array “pants”, shirts in an array “shirts”, shoes in an array “shoes”, and skirts in an array “skirts”. You are also given a budget amount ‘X’ to spend. You want to buy exactly 1 item from each list. Your task is to determine the total number of possible combinations that you can buy, given that the total amount of your purchase does not exceed your budget amount

```cpp
#include <algorithm>
int shoppingOptions(vector<int>& pants, vector<int>& shirts, vector<int>& shoes, vector<int>& skirts, int budget)
{
	int cnt=0;
    for(int i=0; i<pants.size(); ++i){
        for(int j=0; j<shirts.size(); ++j){
            for(int k=0; k<shoes.size(); ++k){
                for(int l=0; l<skirts.size(); ++l){
                    if(pants[i]+shirts[j]+shoes[k]+skirts[l]<=budget)
                        cnt++;
                }
            }
        }
    }
    return cnt;
}

/*
Time Complexity: O((R * S + P * Q) * log(P * Q))
Space Complexity: O(P * Q)
Where ‘P’, ‘Q’, ‘R’, and ‘S’ denote the number of pants, shirts, shoes, skirts respectively.
*/
#include<algorithm>
// To find number of smaller values in an array than the given value.
int getSmallerNumbers(vector<int> vec, int val)
{
int left = 0, right = vec.size();
while (left < right)
{
int mid = (left + right) / 2;
if (vec[mid] <= val)
{
left = mid + 1;
}
else
{
right = mid;
}
}
return left;
}
int shoppingOptions(vector<int>& pants, vector<int>& shirts, vector<int>& shoes, vector<int>& skirts, int
budget)
{
//To store number of ways to buy
int answer = 0;
vector<int> sumOfPantsAndShirts((int)(pants.size() * shirts.size()));
int counter = 0;
// To generate every possible combinations of pants and shirts.
for (int i = 0; i < pants.size(); i++)
{
for (int j = 0; j < shirts.size(); j++)
{
// Store the sum in the array
sumOfPantsAndShirts[counter] = pants[i] + shirts[j];
counter = counter + 1;
}
}
// Sort all the combinations in ascending order.
sort(sumOfPantsAndShirts.begin(), sumOfPantsAndShirts.end());
for (int i = 0; i < shoes.size(); i++)
{
for (int j = 0; j < skirts.size(); j++)
{
// To store remaining amount
int remainingAmount = budget - shoes[i] - skirts[j];
// Adding all smaller or equal numbers than remainingAmount.
answer = answer + getSmallerNumbers(sumOfPantsAndShirts, remainingAmount);
}
}
return answer;
}
```

## Traffic Lights $
There is a street of length ‘X’ with 'X' slots numbered from 0 to 'X' (0,1,…, ’X’). Initially, there are no traffic lights in these slots. Later ‘N’ sets of traffic lights are added to the street one after another. The ‘POS’ array tells the position of the ‘i’th light.
Your task is to calculate the length of the longest passage without traffic lights after each addition.
For example:
Given:- ‘X’ = 5 and ‘N’ = 2.
‘POS’[] = 3, 4
The output will be 3 and 3.
Initially, there are no lights, and we install a light at position three; therefore, there is a segment between the 3 and 6. 
Then we install a light at position four; therefore, the largest gap becomes between 0 to 3.

```cpp
 vector<int> trafficLights(int n, int x, vector<int> &pos)
{
	set<int> lights;
	multiset<int> d;
	lights.insert(0); 
	lights.insert(x);
	d.insert(x);
	vector<int> ans;
	for(int i=0; i<n; ++i){
		int p=pos[i];
		auto ub = lights.upper_bound(p);
		auto lb = ub; --lb;
		d.erase(d.find(*ub-*lb));
		d.insert(p-*lb);
		d.insert(*ub-p);
		lights.insert(p);

		auto res=d.end();
		--res;
		ans.push_back(*res);
	}
	return ans;
}
```

## Glowing Bulbs $
Send Feedback
There are an infinite number of electric bulbs. Each bulb is assigned a unique integer starting from 1. There are ‘N’ switches also and each switch is labeled by a unique prime number. If a switch labeled with prime integer ‘p’ is turned ON, then all the bulbs having a number that is multiple of ‘p’ will start glowing. For example, if we turn ON the switch labelled 2, then all the bulbs having numbers 2, 4, 6, 8, 10, ... i.e all bulbs with numbers as multiples of 2 will start glowing.
You are given an array/list ‘LABELS’ consisting of ‘N’ unique prime integers representing the label of the switches and an integer ‘K’. Your task is to find the integer assigned to Kth glowing bulb from the start when all these ‘N’ switches are turned ON.
Note :
1. Some bulbs can glow by multiple switches and some are not glowed by any switch.
2. If any of the switches that can glow a bulb is turned ‘ON’, then the corresponding bulb will glow.
Example :
Consider 3 switches with labels [3, 5,  7] and we need to find the 5th glowing bulb from the start after turning these 3 switches ON.
We can see that bulbs numbered  3, 6, 9, 15, 18 …  will glow if the switch having label 3 is turned ON.
The bulbs numbered 5, 10, 15, 20 … will glow if the switch having label 5 is turned ON.
The bulbs numbered 7, 14, 21, 28 … will glow if the switch having label 7 is turned ON.
It implies that bulbs numbered 3, 5, 6, 7, 9, 10, 14, 15, 18, 20, 21… will glow when these three switches are turned ON.
The 5th glowing bulb from start is assigned integer 9. Thus, we should return 9.

```cpp
#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll func(ll x, vector<int>& primes) {
  int sz = primes.size();
  ll res = 0;
  for (int i = 1; i < 1 << sz; i++) {
    ll p = 1;
    int sign = -1;
    for (int j = 0; j < sz; j++)
      if ((i >> j) & 1) {
        p *= primes[j];
        sign *= -1;
      }
    res += sign * (x / p);
  }
  return res;
}

ll findKthGlowingBulb(vector<int> &labels, ll k) {
	  ll ans = 1, lo = 1, hi = 1e18;

  while (lo <= hi) {
    ll mid = (lo + hi) >> 1;
    if (func(mid, labels) >= k) {
      ans = mid;
      hi = mid - 1;
      } 
      else {
        lo = mid + 1;
    }
  }
  return ans;
}


```

# SPOJ EKO

Lumberjack Mirko needs to chop down M metres of wood. It is an easy job for him since he has a nifty new woodcutting machine that can take down forests like wildfire. However, Mirko is only allowed to cut a single row of trees.

Mirko‟s machine works as follows: Mirko sets a height parameter H (in metres), and the machine raises a giant sawblade to that height and cuts off all tree parts higher than H (of course, trees not higher than H meters remain intact). Mirko then takes the parts that were cut off. For example, if the tree row contains trees with heights of 20, 15, 10, and 17 metres, and Mirko raises his sawblade to 15 metres, the remaining tree heights after cutting will be 15, 15, 10, and 15 metres, respectively, while Mirko will take 5 metres off the first tree and 2 metres off the fourth tree (7 metres of wood in total).

Mirko is ecologically minded, so he doesn‟t want to cut off more wood than necessary. That‟s why he wants to set his sawblade as high as possible. Help Mirko find the maximum integer height of the sawblade that still allows him to cut off at least M metres of wood.

Input
The first line of input contains two space-separated positive integers, N (the number of trees, 1 ≤ N ≤ 1 000 000) and M (Mirko‟s required wood amount, 1 ≤ M ≤ 2 000 000 000).

The second line of input contains N space-separated positive integers less than 1 000 000 000, the heights of each tree (in metres). The sum of all heights will exceed M, thus Mirko will always be able to obtain the required amount of wood.

Output
The first and only line of output must contain the required height setting.

Example
Input:
4 7
20 15 10 17

Output:
15
Input:
5 20
4 42 40 26 46

Output:
36


```cpp
#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;


bool check(vector<long long>&tree, long long m, long long mid){
    int n = tree.size();
    long long total = 0;
    for(int i=0;i<n;i++){
        if(tree[i]-mid>0) total+=(tree[i]-mid);
    }
    return total>=m;
}


void solve(){
    long long n,m;
    cin>>n>>m;
    vector<long long>tree(n);
    for(int i=0;i<n;i++) cin>>tree[i];
    sort(tree.begin(),tree.end());
    long long left = 1, right = *max_element(tree.begin(),tree.end());
    long long ans = 0;
    while(left<=right){
        long long mid = left + (right-left)/2;
        if(check(tree,m,mid)){
            ans = mid;
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }
    cout<<ans;
}
                
int main(){
    ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            cout<<fixed;
            cout<<setprecision(10);
    //        freopen("timber_input.txt", "r", stdin);
    //        freopen("timber_output.txt", "w", stdout);
            int t=1;
            // cin>>t;
            for(int i=1;i<=t;i++){
            //    cout<<"Case #"<<i<<": ";  
                solve();
    }
    return 0;
}
```

# CF 1462 F The Treasure of The Segments

Polycarp found n segments on the street. A segment with the index i is described by two integers li and ri
 — coordinates of the beginning and end of the segment, respectively. Polycarp realized that he didn't need all the segments, so he wanted to delete some of them.

Polycarp believes that a set of k segments is good if there is a segment [li,ri] (1≤i≤k) from the set, such that it intersects every segment from the set (the intersection must be a point or segment). For example, a set of 3
segments [[1,4],[2,3],[3,6]] is good, since the segment [2,3] intersects each segment from the set. Set of 4segments [[1,2],[2,3],[3,5],[4,5]] is not good.

Polycarp wonders, what is the minimum number of segments he has to delete so that the remaining segments form a good set?

Input
The first line contains a single integer t (1≤t≤2⋅105) — number of test cases. Then t
 test cases follow.

The first line of each test case contains a single integer n(1≤n≤2⋅105) — the number of segments. This is followed by n
 lines describing the segments.

Each segment is described by two integers l and r (1≤l≤r≤109) — coordinates of the beginning and end of the segment, respectively.

It is guaranteed that the sum of n
 for all test cases does not exceed 2⋅105
.

Output
For each test case, output a single integer — the minimum number of segments that need to be deleted in order for the set of remaining segments to become good.

Example
inputCopy
4
3
1 4
2 3
3 6
4
1 2
2 3
3 5
4 5
5
1 2
3 8
4 5
6 7
9 10
5
1 5
2 4
3 5
3 8
4 8
outputCopy
0
1
2
0


```cpp
#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;


void solve(){
    // take input of the segments & left-right points
    int n;
    cin>>n;
    vector<pair<int,int>>seg(n);
    vector<int>l(n),r(n);
    for(int i=0;i<n;i++){
        cin>>seg[i].first>>seg[i].second;
        l[i]=seg[i].first;
        r[i]=seg[i].second;
    }


    // sort the left & right points vector
    sort(l.begin(),l.end());
    sort(r.begin(),r.end());
    
    // initalize the maximum ans
    int ans =n-1;


    // binary search for each segment and minimize the ans
    for(int i=0;i<n;i++){
        int right_half = lower_bound(l.begin(),l.end(),seg[i].second+1)-l.begin();
        int left_half = lower_bound(r.begin(),r.end(),seg[i].first)-r.begin();
        ans = min(ans,n-right_half + left_half);
    }
    cout<<ans<<"\n";
}
                
int main(){
    ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            cout<<fixed;
            cout<<setprecision(10);
    //        freopen("timber_input.txt", "r", stdin);
    //        freopen("timber_output.txt", "w", stdout);
            int t=1;
            cin>>t;
            for(int i=1;i<=t;i++){
            //    cout<<"Case #"<<i<<": ";  
                solve();
    }
    return 0;
}
```