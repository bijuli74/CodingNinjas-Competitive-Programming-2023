## Minimum Absolute Difference in Array
Given an integer array A of size N, find and return the minimum absolute difference between any two elements in the array.
We define the absolute difference between two elements ai and aj (where i != j ) as |ai - aj|.

```cpp
#include<bits/stdc++.h>
using namespace std;
#define vit vector<int>::iterator
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        for(int i=0; i<n; ++i) cin>>a[i];
        int ans=INT_MAX;
        sort(begin(a), end(a));
        for(int i=0; i<n-1; ++i){
            ans = min(ans, abs(a[i]-a[i+1]));
        }

        cout<<ans<<"\n";
    }
    return 0;
}
```

## Fractional Knapsack
You are given weights and values of N items. You have to select and put these selected items in a knapsack of capacity W. Select the items in such a way that selected items give the maximum total value possible with given capacity of the knapsack.
Note: You are allowed to break the items in parts.
```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
    
    int n, w; cin>>n>>w;
    vector<array<double, 3>> a(n);
    double sumw = 0, sumv=0;
    for(int i=0; i<n; ++i){
        cin>>a[i][1]>>a[i][2];
        sumw+=a[i][2];
        sumv+=a[i][1];
        a[i][0]=a[i][1]/a[i][2];
    }
    if(sumw<=w) { cout<<fixed<<setprecision(6)<<sumv<<"\n";  return 0; }
   
    sort(begin(a), end(a), greater<array<double, 3>>());
    double ans=0;
    int it;
    for(int i=0; i<n && w>0; ++i){
    	it=i;
    	if(a[i][2]>w) break;
        ans+=a[i][1];
        w-=a[i][2];
        

    }
    if(w>0){
        ans += (w*a[it][0]);
    }
    cout<<fixed<<setprecision(6)<<ans<<"\n";
    
    return 0;
}
```

## Maximum Activity Subset
You are given n activities with their start and finish times. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.

```cpp
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
    int n; cin>>n;
    vector<vector<int>> a(n, vector<int>(2));
    for(int i=0; i<n; ++i)
        cin>>a[i][1]>>a[i][0];
    
    sort(a.begin(), a.end());
    int ans=1, l=0;
    for(int i=1; i<n; ++i){
        if(a[i][1]>=a[l][0]){
            l=i;
            ++ans;
        }
    }
    cout<<ans<<'\n';
    return 0;
}
```

## Weighted Jobs
You are given N jobs where every job is represented as:
1. Start Time
2. Finish Time
3. Profit Associated
Find the maximum profit subset of jobs such that no two jobs in the subset overlap.

## Minimum number of swaps $
You are given a string ‘S’ of length ‘N’, an array A of length ‘M’ ( consisting of lowercase letters). and a positive integer ‘K’. You can take a character from 'A' and change any character in 'S' with this character. The task is to minimize the number of swaps required ( between ‘S’ and ‘A’ ) to make the string ‘S’ ‘k’-periodic.
Note:
1. A string ‘S’ is said to be ‘K’ periodic, if for each position  ‘i’ in the string S[i] = S[i+K].

   Consider string ‘S’,
   if S = ”abcabc”, it is 3 periodic string.
   if S= ”aaaaa”,  it is 1 periodic string.

2. In one move, only one character of ‘S’ can be swapped with a character of ‘A’.

3. The characters in ‘A’ can be used more than once.

4. All characters of K-periodic string ‘S’ are elements of array ‘A’.

```cpp
int minSwap (int n, int m, int k, string& s, vector<char> &a)
{
    vector<vector<int>> dp(k, vector<int>(26, 0));
    vector<int> fa(26, 0);
    for(int i=0; i<m; ++i) fa[a[i]-'a']=1;
    int ans = 0;
    for(int i=0; i<n; ++i) dp[i%k][s[i]-'a']++;

    for(int i=0; i<k; ++i){
        int maxi=0, sum=0;
        for(int j=0; j<26; ++j){
            sum+=dp[i][j];
            if(dp[i][j]>maxi && fa[j]==1)
                maxi = dp[i][j];
        }
        ans += (sum-maxi);

    }
    return ans;
```

## Minimum Number of Platforms
You have been given two arrays, 'AT' and 'DT', representing the arrival and departure times of all trains that reach a railway station.
Your task is to find the minimum number of platforms required for the railway station so that no train needs to wait.

```cpp
int calculateMinPatforms(int at[], int dt[], int n) {
    int ans=0;
    sort(at, at+n);
    sort(dt, dt+n);
    for(int i=0, j=0; i<n; ++i)
        if(at[i] <= dt[j]) ++ans;
        else ++j;
    return ans;
}
```

## Gas Tank $
You have a car with a gas tank of infinite capacity. There are ‘N’ gas stations along a circular route. Gas stations are numbered from 0 to N - 1. You begin the journey with an empty tank at one of the gas stations. You want to travel around the circular route once in the clockwise direction. I.e if you start to travel from station ‘i’, then you will go to i + 1, i + 2, …, n - 1, 0, 1, 2, i - 1 and then return back to ‘i’.
You are given two integer arrays ‘gas’ and ‘cost’. ‘gas[i]’ gives the amount of gas available at station ‘i’ and cost[i] gives the amount of gas required to travel from station ‘i’ to next station i.e station ‘i’+1 (or 0 if the station is N - 1).
Return the starting gas station's index if it is possible to complete cycle of given circular route once in the clockwise direction. If there are multiple possible starting gas station’s indexes, then return the minimum of those gas station indexes. If there is no such gas station then return -1.

```cpp
#include <algorithm>
int minimumStartingIndex(vector<int> &gas, vector<int> &cost, int n) 
{
    const int gasses = accumulate(begin(gas), end(gas), 0);
    const int costs = accumulate(begin(cost), end(cost), 0);
    if(gasses-costs<0) return -1;
    int ans=0, sum=0;
    for(int i=0; i<gas.size(); ++i){
        sum+=gas[i]-cost[i];
        if(sum<0){
            sum=0;
            ans=i+1;
        }
    }
    return ans;
}
```

## Ninja’s Pay $
Ninja works in an XYZ MNC which follows a very strict rule regarding the pay. Ninja has been assigned ‘N’ tasks. Each task requires some days to finish, which is given in the form of an array ‘TIME’. For each day of delay before starting to work in task ‘i’ a loss is incurred on Ninjas’ pay which is given in an array ‘LOSS’. Ninja asks you for help to find the order in which the tasks should be completed such that there is a minimum loss in Ninjas’ pay.
Note:
If there are multiple solutions, print the order with smaller indices first.
Example:
Let ‘TIME’ array be: [2, 4, 1]
Let ‘LOSS’ array be: [1, 2, 3]
Order 1 2 3 will cause loss of 4 + 18 = 22
Order 3 1 2 will cause loss of 1+ 6 = 7 which is the minimum possible loss.
Hence the answer is [3, 1, 2].

```cpp
#include <algorithm>

bool comp(vector<int>& x, vector<int>& y){
    
    if(x[1]*y[2]<x[2]*y[1]) return 1;
    else if(x[1]*y[2]>x[2]*y[1]) return 0;
    else {
        if(x[0]<y[0]) return 1;
        else return 0;
    }
}

vector<int> minLoss(int n, vector<int> &time, vector<int> &loss) {
    vector<vector<int>> a(n, vector<int>(3));
    vector<int> ans;
    for(int i=0; i<n; ++i){
        a[i][0]=i+1;
        a[i][1]=time[i];
        a[i][2]=loss[i];
    }
    sort(begin(a), end(a), comp);
    for(int i=0; i<n; ++i) ans.push_back(a[i][0]);
    return ans;

}
```

## Candies
Prateek is a kindergarten teacher. He wants to give some candies to the children in his class. All the children stand in a line and each of them has a grade according to his or her performance in the class. Prateek wants to give at least one candy to each child. If two children are standing adjacent to each other, then the one with the higher rating must get more candies than the other. Prateek wants to minimize the total number of candies he must buy.
Given an array 'STUDENTS' of size 'N' that contains the grades for each student, your task is to find what is the minimum number of candies Prateek must buy so that he can distribute them among his students according to the criteria given above.
Example :
Given students' ratings : [5, 8, 1, 5, 9, 4]. 
He gives the students candy in the following minimal amounts : [1, 2, 1, 2, 3, 1]. He must buy a minimum of 10 candies.
```cpp
int requiredCandies(vector<int>& a) {
    int ans=0, n=a.size();
    if(n==1) return 1;
    vector<int> v(n, 1);
    for(int i=0; i<n-1; ++i){
        if(a[i+1]>a[i]) v[i+1]=v[i]+1;
    }
    for(int i=n-2; ~i; --i){
        if(a[i]>a[i+1] && v[i]<=v[i+1]){
            v[i]=v[i+1]+1;
        }
        ans+=v[i];
    }
    ans+=v[n-1];
    return ans;
}
```

## Call of War $$
DecenTile Games have launched a new First Person Shooter soldier game, called the Call of War, that young gamers can play on their website.
Our protagonist, Ninja (played by you) is a soldier whose mission is to kill all the enemies plotting against you. Your enemies are standing in a circle, numbered clockwise from 1 to n. Initially, the i-th enemy has ai health.
You have only one pistol, and infinite bullet magazines. You have to shoot the enemies in order to kill them. Each bullet fired at the enemy decreases their health by 1 (deals 1 damage to it). When the health of some enemy i becomes 0 or less than 0, he dies and his grenade drops down and explodes, dealing bi damage to the next enemy (enemy i+1, if i<n, or enemy 1, if i=n). If the next enemy is already dead, then nothing happens. If the frag from the grenade kills the next enemy, even he drops a grenade, damaging the enemy after him and possibly triggering another explosion, and so on.
You have to calculate the minimum number of bullets you need in order to kill all the enemies and win the game.
Input Format:
First line of input will contain T(number of test cases), each test case follows as.
Line 1: contain an integer N
Next N line contains two space separated integers a and b
Output Format:
For each test case print the output in a new line.
```
Constraints:
1 <= T <= 100
1 <= N <= 10^4
1 <= a, b <= 10^12
Sample Input:
1
3
7 15
2 14
5 3
Sample Output:
6
```
```cpp
/*
Time complexity: O(N*log(N))
Space complexity: O(N)
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll fun_(vector<pair<ll, ll>> &temp, int index, int n){
  bool vis[n];
  memset(vis, false, sizeof(vis));
  ll a = 0, cost = 0;
  while (a < n) {
    cost += temp[index].first;
    ll b = temp[index].second;
    index++;
    index = (n + index) % n;
    temp[index].first = max(0ll, temp[index].first - b);
    a++;
  }
  return cost;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    ll a = 0, c, d;
    vector<pair<ll, ll>> arr;
    for (int i = 0; i < n; i++) {
      cin >> c >> d;
      arr.push_back({c, d});
    }
  vector<pair<ll, ll>> store;
  c = arr[n - 1].second;
  for (int i = 1; i < n; i++) {
    ll f = arr[i].first + arr[0].first - min(arr[0].first, arr[n - 1].second);
    ll g = arr[0].first + arr[i].first - min(arr[i].first, arr[i - 1].second);
    store.push_back({f - g, i});
  }
  sort(store.begin(), store.end());
  if (store.size() > 0 && store[0].first < 0) {
    a = store[0].second;
  } else
    a = 0;
    ll ans = fun_(arr, a, n);
    cout << ans << endl;
  }
}
```