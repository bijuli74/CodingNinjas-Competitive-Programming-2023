## Maximum Pair Sum
You are given a sequence A[1], A[2], ..., A[N], ( 0 ≤ A[i] ≤ 10^8 , 2 ≤ N ≤ 10^5 ). There are two types of operations and they are defined as follows:
Update:
This will be indicated in the input of a 'U' followed by space and then two integers i and x.
U i x
This operation sets the value of A[i] to x.
Query:
This will be indicated in the input of a 'Q' followed by a single space and then two integers x and y.
Q x y
You must find two integers i and j such that x ≤ i, j ≤ y and i != j, such that the sum A[i]+A[j] is maximized. Print the sum A[i]+A[j].
```cpp
#include<bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
#define M (beg+end)/2

const int mxN = 1e5;

int a[mxN];
ii st[4*mxN];
ii combine(ii l, ii r){
	if(l.first < r.first) swap(l, r);
	return {l.first, max(l.second, r.first)};
}

void build(int beg, int end, int pos){
	if(beg==end){
		st[pos] = {a[beg], -1};
		return;
	}
	build(beg, M, 2*pos+1);
	build(M+1, end, 2*pos+2);
	st[pos] = combine(st[2*pos+1], st[2*pos+2]);
}

void update(int beg, int end, int idx, int val, int pos){
	if(beg==end){
		st[pos] = {val, -1};
		return;
	}
	if(idx <= M) update(beg, M, idx, val, 2*pos+1);
	else update(M+1, end, idx, val, 2*pos+2);
	
	st[pos] = combine(st[2*pos+1], st[2*pos+2]);
}

ii query(int beg, int end, int ql, int qr, int pos){
	if(ql<=beg && qr>=end){
		return st[pos];
	}else if(ql>end || qr<beg){
		return {-1, -1};
	}
	
	return combine(query(beg, M, ql, qr, 2*pos+1), query(M+1, end, ql, qr, 2*pos+2));
}

int main(){
	int n; cin>>n;
	for(int i=0; i<n; ++i) cin>>a[i];
	
	build(0, n-1, 0);
	
	int q; cin>>q;
	while(q--){
		char qt; cin>>qt;
		int a, b; cin>>a>>b;
		if(qt=='U'){
			update(0, n-1, a-1, b, 0);
		}else{
			--a, --b;
			ii ans = query(0, n-1, a, b, 0);
			cout << (ans.first + ans.second) << '\n';
		}
	}
	return 0;
}
```
## Minimum In Subarray
You are given a sequence A[1], A[2], ..., A[N] of N numbers ( 0 ≤ A[i] ≤ 10^8 , 2 ≤ N ≤ 10^5 ). There are Q queries, and each query is defined in either of the following two ways:
Query on range:
You are given two numbers i and j; the answer to each query is the minimum number between the range (i, j) (including both i and j). Note that in this query, i and j lies in the range: [1, N].
Update query:
You are given two numbers i and B; update A[i] to B. Note that in this query, i lies in the range: [1, N].
```cpp
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mxN = 1e5;
int n, q;
ll x[mxN];

struct node {
    ll mn;
} st[1<<19];

void upd(int l1, int x, int i=1, int l2=0, int r2=n-1){
    if(l2==r2){
        st[i].mn = x;
        return;
    }
    int m2 = (l2+r2)/2;
    if(l1 <= m2)
        upd(l1, x, 2*i, l2, m2);
    else
        upd(l1, x, 2*i+1, m2+1, r2);
    st[i].mn = min(st[2*i].mn, st[2*i+1].mn);
}

int qry(int l1, int r1, int i=1, int l2=0, int r2=n-1){
    if(l1<=l2 && r2<=r1){
        return st[i].mn;
    }
    int m2 = (l2+r2)/2;
    return min(l1<=m2?qry(l1, r1, 2*i, l2, m2):(int)1e9, m2<r1?qry(l1, r1, 2*i+1, m2+1, r2):(int)1e9);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>q;
    for(int i=0; i<n; ++i)
        cin>>x[i], upd(i, x[i]);
    while(q--){
        char ch;
        int a, b;
        cin >> ch >> a >> b, --a, --b;
        if(ch=='u') upd(a, b+1);
        else cout << qry(a, b) << '\n';
    }
    return 0;
}
```

## K - Query Online
Given a sequence of n numbers a1
, a2
, ..., an and a number of k-queries. A k-query is
a triple (i, j, k) (1 ≤ i ≤ j ≤ n). For each k-query (i, j, k), you have to return the number
of elements greater than k in the subsequence ai, ai+1
, ..., aj
.
```
Algorithm:
We can solve this problem by using merge sort tree as follows:
● Imagine we have an array b1, b2, ..., bn which, and bi = 1 if and only
if ai > k, then we can easily answer the query (i, j, k) in O(log(n)) using a
simple segment tree (answer is bi + bi + 1 + ... + bj ).
● First of all, read all the queries and save them somewhere, then sort them in
increasing order of k and also the array a in increasing order (compute the
permutation p1, p2, ..., pn where ap1 ≤ ap2 ≤ ... ≤ apn)
● At first we'll set all array b to 1 and we will set all of them to 0 one by one
● Consider after sorting the queries in increasing order of their k, we have a
permutation w1, w2, ..., wq (of 1, 2, ..., q) where kw1 ≤ kw2 ≤ kw2 ≤ ... ≤ kwq (we
keep the answer to the i - th query in ansi .
```
```cpp
#include<bits/stdc++.h>
#define M (beg + end)/2
using namespace std;
const int N = (int)(3e5+5);
vector<int> st[4*N];
int arr[N];
void build(int beg, int end, int pos) {
if(beg == end) {
st[pos].push_back(arr[beg]);
return;
}
build(beg, M, 2*pos+1);
build(M+1, end, 2*pos+2);
merge(st[2*pos+1].begin(), st[2*pos+1].end(), st[2*pos+2].begin(),
st[2*pos+2].end(), back_inserter(st[pos]));
}
int query(int beg, int end, int ql, int qr, int k, int pos) {
if(ql <= beg && qr >= end) {
auto it = upper_bound(st[pos].begin(), st[pos].end(), k);
int numLesser = it - st[pos].begin();
return (end - beg + 1 - numLesser);
} else if(ql > end or qr < beg) {
return 0;
}
return query(beg, M, ql, qr, k, 2*pos+1) + query(M+1, end, ql, qr, k, 2*pos+2);
}
int main() {
freopen("input.txt", "r", stdin);
freopen("out.txt", "w", stdout);
int n;
cin>>n;
for(int i=0; i<n; i++) cin>>arr[i];
build(0, n-1, 0);
int q;
int ans = 0;
cin>>q;
while(q--) {
int a, b, c;
cin>>a>>b>>c;
a ^= ans;
b ^= ans;
c ^= ans;
if(a < 1) a=1;
if(b > n) b=n;
if(a > b) {
ans = 0;
cout<<ans<<"\n";
continue;
}
a--;
b--;
ans = query(0, n-1, a, b, c, 0);
cout<<ans<<"\n";
}
return 0;
}
```
## Maximum Query
You are given an array of integet of size N and Q queries in form of (l, r). You are supposed to find the maximum value of array between index l and r (both inclusive)
```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mxN = 1e4;
int n, q;
ll x[mxN];

struct node {
  ll mx;
} st[1 << 15];

void upd(int l1, int x, int i = 1, int l2 = 0, int r2 = n - 1) {
  if (l2 == r2) {
    st[i].mx = x;
    return;
  }
  int m2 = (l2 + r2) / 2;
  if (l1 <= m2)
    upd(l1, x, 2 * i, l2, m2);
  else
    upd(l1, x, 2 * i + 1, m2 + 1, r2);
  st[i].mx = max(st[2 * i].mx, st[2 * i + 1].mx);
}

int qry(int l1, int r1, int i = 1, int l2 = 0, int r2 = n - 1) {
  if (l1 <= l2 && r2 <= r1) {
    return st[i].mx;
  }
  int m2 = (l2 + r2) / 2;
  return max(l1 <= m2 ? qry(l1, r1, 2 * i, l2, m2) : (int)-1e9,
             m2 < r1 ? qry(l1, r1, 2 * i + 1, m2 + 1, r2) : (int)-1e9);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> x[i], upd(i, x[i]);

  cin >> q;
  while (q--) {
    int a, b;
    cin >> a >> b;
    cout << qry(a, b) << '\n';
  }
  return 0;
}
```
## This is Sparta!
Send Feedback
King Leonidas of Sparta is preparing his men and country for a war against the Persian King Xerxes. He has N soldiers with him and he has arranged them in a line at The Hot Gates. Let us number them from 1 to N. Leonidas will fight Xerxes' army for Q days, and each day he can send only one of his men to fight.
For each warrior, we know 2 traits: Strength and Cowardice. These are given to us in a form of integer. Each day, Leonidas can choose his warrior from a range Li to Ri, and he will choose the warrior with maximum Strength value. If there is more than one warrior having the same maximum Strength value, he will choose the warrior with minimum Cowardice value. If there is still more than 1 warrior with the same maximum Strength value and same minimum Cowardice value, he chooses the one with lower index in line.
King Leonidas is ready to lay his life for Sparta. You, his right hand man, have to help him save Sparta by helping him choose a warrior for each day.
Input Format:
First line contains a single integer N, denoting the number of warriors Leonidas has. 
Second line contains N space separated integers, representing Strength of ith warrior. 
Third line contains N space separated integers, representing Cowardice of ith warrior
Next line contains a single integer Q, denoting the number of days Queen Vasya chooses a warrior. 
Each of the next Q lines contains 2 integers Li and Ri.
```
Constraints:
1 ≤ N,Q ≤ 10^5
1 ≤ Ai,Bi ≤ 10^9
1 ≤ Li ≤ Ri
Output Format:
For each Li and Ri, print the index of the warrior that King Leonidas should choose.
Sample Input 1:
5
1 8 4 6 8
4 8 6 3 7
4
1 4
2 4
3 4
1 5
Sample Output 1:
2
2
4
5
```
```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mxN = 1e5;
int n, q;

struct warrior{
  int a, b; //a=strength, b=coward
} arr[1<<19];

struct node{
  int a, b;
  int id;
} st[1<<19];

void build(int l, int r, int i){
  if (l == r) {
    st[i].a = arr[l].a;
    st[i].b = arr[l].b;
    st[i].id = l;
    return;
  }
  int m = (l + r) / 2;
  build(l, m, 2 * i + 1);
  build(m + 1, r, 2 * i + 2);

  node lc = st[2 * i + 1];
  node rc = st[2 * i + 2];
  if (lc.a > rc.a){ 
    st[i].a = lc.a;
    st[i].b = lc.b;
    st[i].id = lc.id;
  }
  else if(lc.a < rc.a){
    st[i].a = rc.a;
    st[i].b = rc.b;
    st[i].id = rc.id;
  }
  else{
    if(lc.b < rc.b){
      st[i].a  = lc.a;
      st[i].b = lc.b;
      st[i].id = lc.id;
    }
    else if(lc.b > rc.b){
      st[i].a = rc.a;
      st[i].b = rc.b;
      st[i].id = rc.id;
    }
    else{
      if(lc.id < rc.id){
        st[i].a = lc.a;
        st[i].b = lc.b;
        st[i].id = lc.id;
      }
      else{
        st[i].a = rc.a;
        st[i].b = rc.b;
        st[i].id = rc.id;
      }
    }
  }
}

node qry(int l, int r, int i, int l1, int r1){
  if( l > r1 || r < l1){
    node ans;
    ans.a = INT_MIN;
    ans.b = INT_MAX;
    ans.id = INT_MAX;
    return ans;
  }

  if(l>=l1 && r<=r1)
    return st[i];
  
  int m = (l+r)/2;
  node lc = qry(l, m, 2*i+1, l1, r1);
  node rc = qry(m+1, r, 2*i+2, l1, r1);

  if(lc.a > rc.a) return lc;
  else if(lc.a < rc.a) return rc;
  else{
    if(lc.b < rc.b) return lc;
    else if(lc.b > rc.b) return rc;
    else{
      if(lc.id < rc.id) return lc;
      else return rc;
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i=0; i<n; ++i){
    cin >> arr[i].a;
  }
  for(int i=0; i<n; ++i){
    cin >> arr[i].b;
  }

  build(0, n-1, 0);
  int q; cin >> q;
  while (q--) {
    int a, b;
    cin >> a >> b, --a, --b;
    cout << qry(0, n-1, 0, a, b).id+1 << '\n';
  }
  return 0;
}
```
## 2 vs 3
The fight for the best number in the globe is going to finally come to an end.The top two contenders for the best number are number 2 and number 3.It's the final the entire world was waiting for. Expectorates from all across the globe came to witness the breath taking finals.
The finals began in an astonishing way.A common problem was set for both of them which included both these number.The problem goes like this.
Given a binary string (that is a string consisting of only 0 and 1). They were supposed to perform two types of query on the string.
Type 0: Given two indices l and r.Print the value of the binary string from l to r modulo 3.

Type 1: Given an index l flip the value of that index if and only if the value at that index is 0.

The problem proved to be a really tough one for both of them.Hours passed by but neither of them could solve the problem.So both of them wants you to solve this problem and then you get the right to choose the best number in the globe.
```cpp
#include<bits/stdc++.h>
using namespace std;

const int mxN = 1e5+5;

int st[4*mxN];
int pwr[mxN];

void build(string& s, int l, int r, int i){
    if(l==r){
        st[i] = s[l]-'0';
        return;
    }
    int m = (l+r)/2;
    build(s, l, m, 2*i+1);
    build(s, m+1, r, 2*i+2);

    st[i] = (st[2*i+1] * pwr[r-m] + st[2*i+2]) % 3;
}

void upd(int l, int r, int id, int i){
    if(l>id || r<id) return;
    if(l==r){
        st[i] = 1; //flipping
        return;
    }
    int m = (l+r)/2;
    
    upd(l, m, id, 2*i+1);
    upd(m+1, r, id, 2*i+2);

    st[i] = (st[2*i+1] * pwr[r-m] + st[2*i+2])%3;
}

int qry(int l, int r, int a, int b, int i){
    if(l>b || r<a) return 0;
    if(l>=a && r<=b){
        return (st[i] * pwr[b-r])%3;
    }
    int m = (l+r)/2;
    int lq = qry(l, m, a, b, 2*i+1);
    int rq = qry(m+1, r, a, b, 2*i+2);
    return (lq+rq) % 3;
}

int main(){
    
    ios::sync_with_stdio(false); cin.tie(0);
    int n, q;
    string s;
    cin>>n;
    cin>>s;
   
    pwr[0]=1;
    for(int i=1; i<n; ++i)
        pwr[i] = (pwr[i-1]*2)%3;
    
    build(s, 0, n-1, 0);
    cin>>q;
    while(q--){
        int qt; cin>>qt;
        if(qt==1){
            int idx; cin>>idx;
            if(s[idx]=='0')
                upd(0, n-1, idx, 0);
        }else{
            int a, b; cin>>a>>b;
            cout << qry(0, n-1, a, b, 0) << '\n';
        }
    }
    return 0;
}
```
## The GCD Dillema $
Dwight is always bragging about how amazing he is at solving complicated problems with much ease. Jim got tired of this and gave him an interesting problem to solve.
Jim gave Dwight a sequence of integers a1, a2, ..., an and q queries x1, x2, ..., xq on it. For each query xi Dwight has to count the number of pairs (l, r) such that 1 ≤ l ≤ r ≤ n and GCD(al, al + 1, ..., ar) = xi. Dwight is feeling out of his depth here and asked you to be his Secret Assistant to the Regional Manager. Your first task is to help him solve the problem. Are you up to it?
```cpp
#include<bits/stdc++.h>
using namespace std;
// https://codeforces.com/problemset/problem/475/D
// #define ll long long 
// int gcd(int a, int b){
//     if(a%b == 0) return b;
//     return gcd(b, a%b);
// }
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin>>a[i];

    map<int, ll> ans;
    map<int, int> divisors;
    map<int, int> nxtDivisors;

    for(int i=0; i<n; ++i){
        nxtDivisors.clear();
        for(auto& p: divisors){
            nxtDivisors[__gcd(p.first, a[i])] += p.second;
        }
        nxtDivisors[a[i]]++;

        swap(nxtDivisors, divisors);
        for(auto& p: divisors)
            ans[p.first] += p.second;
    }
   
    int q;
    cin >> q;
    while(q--){
        int x; cin>>x;
        cout << ans[x] << '\n';
    }
    return 0;
}
```
## Sheldon and Trains
Sheldon always tells people, “When you have only one day to visit Los Angeles, make it a Train Day”. He loves spending time while travelling in trains and considers it a fun activity. Sheldon’s mom has come to visit him and he decides to take her out on a train tour of the city of Pasadena, along with his friend Howard. There are n train stations in the city. Howard knows how irritating Sheldon can be during a train ride. So, to keep him busy, Howard gives Sheldon a problem so interesting that he just cannot do anything else other than devote his entire mind to solving it. The problem goes like this. At the i-th station it's possible to buy only tickets to stations from i + 1 to ai (inclusive). No tickets are sold at the last station.
Let ρi, j be the minimum number of tickets one needs to buy in order to get from stations i to station j. Sheldon’s task is to compute the sum of all values ρi, j among all pairs 1 ≤ i < j ≤ n. As brilliant as he may be, he asked for your help.
```cpp
#include<bits/stdc++.h>
using namespace std;
// https://codeforces.com/problemset/problem/675/E
const int maxn = 1 << 18;
pair<int, int> tree[2*maxn];

void build(const vector<int> &a, int n) {
  for (int i = 0; i < n; i++)
    tree[maxn + i] = {a[i], i};
  for (int i = maxn - 1; i > 0; i--)
    tree[i] = max(tree[i * 2], tree[i * 2 + 1]);
}

int get(int l, int r) {
  pair<int, int> ans{-1, -1};
  for (l += maxn, r += maxn + 1; l < r; l >>= 1, r >>= 1) {
    if (l & 1)
      ans = max(ans, tree[l++]);
    if (r & 1)
      ans = max(ans, tree[--r]);
  }
  return ans.second;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> a(n);
  a[n - 1] = n - 1;
  for (int i = 0; i < n - 1; i++) {
    cin >> a[i];
    a[i]--;
  }

  build(a, n);
  vector<long long> dp(n);
  long long ans = 0;
  dp[n - 1] = 0;
  for (int i = n - 2; ~i; i--) {
    int mx = get(i + 1, a[i]);
    dp[i] = dp[mx] - (a[i] - mx) + n - i - 1;
    ans += dp[i];
  }

  cout << ans << '\n';
}
```
## Maximum Sum In Subarray $$
You are given a sequence A[1], A[2], ..., A[N].
A query is defined as follows:
```
Query(x,y) = Max { a[i]+a[i+1]+...+a[j] ; x ≤ i ≤ j ≤ y }. 
```
Given M queries, write a program that outputs the results of these queries.
```cpp
#include<bits/stdc++.h>
using namespace std;

const int mxN = 1e5;
int a[mxN];

struct node {
    int mx, s, mxl, mxr;
} st[1<<19];

void build(int l, int r, int i){
    if(l==r){
        st[i].s = a[l];
        st[i].mx = a[l];
        st[i].mxl = a[l];
        st[i].mxr = a[l];
        return;
    }
    int m = (l+r)/2;
    build(l, m, 2*i+1);
    build(m+1, r, 2*i+2);
    st[i].s = st[2*i+1].s + st[2*i+2].s;
    st[i].mxl = max(st[2*i+1].mxl, st[2*i+2].mxl+st[2*i+1].s);
    st[i].mxr = max(st[2 * i + 2].mxr, st[2 * i + 1].mxr + st[2 * i + 2].s);

    st[i].mx = max(
        st[2 * i+1].mx,
        max(st[2 * i + 2].mx,
            max(st[2 * i+1].s + st[2 * i + 2].mxl,
                max(st[2 * i + 2].s + st[2 * i+1].mxr, st[2 * i+1].mxr + st[2 * i + 2].mxl))));
}

node qry(int l, int r, int i, int l1, int r1){
    if(l>r1 || r<l1)
      return {-100000, -100000, -100000, -100000};

    if(l >= l1 && r <= r1) return st[i];
    
    int m = (l+r)/2;
    node ql = qry(l, m, 2*i+1, l1, r1);
    node qr = qry(m+1, r, 2*i+2, l1, r1);
    node ans;
    ans.s = ql.s + qr.s;
    ans.mxl = max(ql.mxl, ql.s + qr.mxl);
    ans.mxr = max(ql.mxr + qr.s, qr.mxr);
    ans.mx = max(ql.mx, max(qr.mx, max(ql.s+qr.mxl, max(qr.s+ql.mxr, ql.mxr+qr.mxl))));

    return ans;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin>>n;
    for(int i=0; i<n; ++i) cin>>a[i];

    build(0, n-1, 0);
    int q; cin>>q;
    while(q--){
        int a, b; cin>>a>>b, --a, --b;
        cout << qry(0, n-1, 0, a, b).mx << '\n';
    }
    return 0;
}
```
## Legion of Doom $
Lex Luthor’s Legion of Doom is a tough organization to get into, even for greatest supervillains. Recently, a spot has opened up because The Mad Hatter has retired. Harley Quinn doesn't want to waste this opportunity, and jumps at the chance of the interview. But she has a PhD in psychology, not in Computer Science. She has kidnapped you and will let you go only if you are able to solve the evil questions of Lex Luthor.
You are given an array of N elements, which are initially all 0. After that you will be given C commands. They are -
0 p q v - you have to add v to all numbers in the range of p to q (inclusive), where p and q are two indexes of the array.
1 p q - output a line containing a single integer which is the sum of all the array elements between p and q (inclusive)
```cpp
#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int mxN = 1e4;
int n, q;
ll x[mxN];

struct node{
    ll mn, s, lz;
} st[1<<16];

void app(int i, ll x, int l2, int r2){
    // st[i].mn += x;
    st[i].s += x*(r2-l2+1);
    st[i].lz += x;
}
void psh(int i, int l2, int m2, int r2){
    app(2*i, st[i].lz, l2, m2);
    app(2*i+1, st[i].lz, m2+1, r2);
    st[i].lz=0;
}
void upd(int l1, ll x, int i=1, int l2=0, int r2=n-1){
    if(l2==r2){
        st[i].mn=x;
        st[i].s=x;
        return;
    }
    int m2 = (l2+r2)/2;
    psh(i, l2, m2, r2);
    if(l1<=m2)
        upd(l1, x, 2*i, l2, m2);
    else
        upd(l1, x, 2*i+1, m2+1, r2);
    // st[i].mn = min(st[2*i].mn, st[2*i+1].mn);
    st[i].s = st[2*i].s + st[2*i+1].s;
}

void upd2(int l1, int r1, int x, int i=1, int l2=0, int r2=n-1){
    if(l1<=l2 &&r2<=r1){
        app(i, x, l2, r2);
        return;
    }
    int m2 = (l2+r2)/2;
    psh(i, l2, m2, r2);
    if(l1<=m2)
        upd2(l1, r1, x, 2*i, l2, m2);
    if(m2<r1)
        upd2(l1, r1, x, 2*i+1, m2+1, r2);
    // st[i].mn = min(st[2*i].mn, st[2*i+1].mn);
    st[i].s = st[2*i].s + st[2*i+1].s;
}
ll qry(int l1, int r1, int i=1, int l2=0, int r2=n-1){
    if(l1<=l2 && r2<=r1){
        return st[i].s;
    }
    int m2 = (l2+r2)/2;
    psh(i, l2, m2, r2);
    return (l1<=m2? qry(l1, r1, 2*i, l2, m2):0) + (m2<r1? qry(l1, r1, 2*i+1, m2+1, r2):0);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t; cin>>t;

    while(t--){
        cin>>n>>q;
        for(int i=0; i<n; ++i)
            upd(i, 0);
        while(q--){
            int type; cin>>type;
            if (type == 0) {
              int a, b, v;
              cin >> a >> b >> v, --a, --b;
              upd2(a, b, v);
            } else {
                int a, b; cin >> a >> b, --a, --b;
              cout << qry(a, b) << '\n';
            }
        }
        
    }
}

// typedef long long int ll;
// void update_add(ll *tree, ll *lazy, ll start, ll end, ll treenode, ll left,
//                 ll right, ll value) {
//   if (start > end) {
//     return;
//   }
//   if (lazy[treenode] != 0) {
//     tree[treenode] += (end - start + 1) * lazy[treenode];
//     if (start != end) {
//       lazy[2 * treenode] += lazy[treenode];
//       lazy[2 * treenode + 1] += lazy[treenode];
//     }
//     lazy[treenode] = 0;
//   }
//   // completely outside
//   if (start > right || end < left) {
//     return;
//   }
//   // completely inside
//   if (start >= left && end <= right) {
//     tree[treenode] += (end - start + 1) * value;
//     if (start != end) {
//       lazy[2 * treenode] += value;
//       lazy[2 * treenode + 1] += value;
//     }
//     return;
//   }
//   // partial overlap
//   ll mid = (start + end) / 2;
//   update_add(tree, lazy, start, mid, 2 * treenode, left, right, value);
//   update_add(tree, lazy, mid + 1, end, 2 * treenode + 1, left, right, value);
//   tree[treenode] = tree[2 * treenode] + tree[2 * treenode + 1];
//   return;
// }
// ll query_sum(ll *tree, ll *lazy, ll start, ll end, ll treenode, ll left,
//              ll right) {
//   if (start > end) {
//     return 0;
//   }
//   if (lazy[treenode] != 0) {
//     tree[treenode] += (end - start + 1) * lazy[treenode];
//     if (start != end) {
//       lazy[2 * treenode] += lazy[treenode];
//       lazy[2 * treenode + 1] += lazy[treenode];
//     }
//     lazy[treenode] = 0;
//   }
//   // completely outside
//   if (start > right || end < left) {
//     return 0;
//   }
//   // completely inside
//   if (start >= left && end <= right) {
//     return tree[treenode];
//   }
//   // partial overlap
//   ll mid = (start + end) / 2;
//   ll left_child = query_sum(tree, lazy, start, mid, 2 * treenode, left, right);
//   ll right_child =
//       query_sum(tree, lazy, mid + 1, end, 2 * treenode + 1, left, right);
//   return left_child + right_child;
// }
// int main() {
//     ios::sync_with_stdio(0); cin.tie(0);
//   ll t;
//   cin >> t;
//   while (t--) {
//     ll n, c;
//     cin >> n >> c;

//     ll *tree = new ll[4 * n]();
//     ll *lazy = new ll[4 * n]();
//     while (c--) {
//       ll command_type;
//       cin >> command_type;
//       if (command_type == 0) {
//         ll left, right, value;
//         cin >> left >> right >> value;
//         update_add(tree, lazy, 0, n - 1, 1, left - 1, right - 1, value);
//       } else {
//         ll left, right;
//         cin >> left >> right;
//         cout << query_sum(tree, lazy, 0, n - 1, 1, left - 1, right - 1) << endl;
//       }
//     }
//   }
// }
```

## Coder Rating
You are given N coders (1 ≤ N ≤ 300000), conveniently numbered from 1 to N. Each of these coders participates in both High School and Open matches. For each coder, you are also given an Open rating Ai and a High School rating Hi. Coder i is said to be better than coder j if and only if both of coder i's ratings are greater than or equal to coder j's corresponding ratings, with at least one being greater. For each coder i, determine how many coders coder i is better than.
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = (int)(1e6 + 5);

int bit[N];

typedef struct ratings {
  int A, H, index;

  ratings() {
    A = 0;
    H = 0;
    index = 0;
  }
} ratings;

void update(int idx, int delta) {
  idx += 1;
  for (; idx < N; idx += (idx & -idx)) {
    bit[idx] += delta;
  }
}

// Sum [0, r]
int query(int r) {
  int res = 0;
  r += 1;
  for (; r > 0; r -= (r & -r)) {
    res += bit[r];
  }
  return res;
}

bool cmp(ratings a, ratings b) {
  if (a.A != b.A)
    return a.A < b.A;
  return a.H < b.H;
}

int main() {
  int n;
  cin >> n;
  ratings r[n];
  for (int i = 0; i < n; i++) {
    cin >> r[i].A >> r[i].H;
    r[i].index = i;
  }

  sort(r, r + n, cmp);

  int ans[n];
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (i < (n - 1) and r[i].A == r[i + 1].A and r[i].H == r[i + 1].H) {
      cnt++;
      ans[r[i].index] = query(r[i].H);
    } else {
      cnt++;
      ans[r[i].index] = query(r[i].H);
      update(r[i].H, cnt);
      cnt = 0;
    }
  }

  for (int i = 0; i < n; i++) {
    cout << ans[i] << "\n";
  }

  return 0;
}
```

## Distinct Query Problem
Given a sequence of n numbers a1, a2, ..., an and a number of d-queries. A d-query is a pair (i, j) (1 ≤ i ≤ j ≤ n). For each d-query (i, j), you have to return the number of distinct elements in the subsequence ai, ai+1, ..., aj.
```
Input Format:
Line 1: n (1 ≤ n ≤ 30000).
Line 2: n numbers a1, a2, ..., an (1 ≤ ai ≤ 10^6).
Line 3: q (1 ≤ q ≤ 200000), the number of d-queries.
In the next q lines, each line contains 2 numbers i, j representing a d-query (1 ≤ i ≤ j ≤ n).
Output Format:
For each d-query (i, j), print the number of distinct elements in the subsequence ai, ai+1, ..., aj in a single line.
Sample Input 1:
5
1 1 2 1 3
3
1 5
2 4
3 5
Sample Output 1:
3
2
3 
```
```cpp
#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN = 1e5;
int n, q;
ll x[mxN];

struct node {
  ll mn, s, lz;
} st[1 << 19];

void app(int i, ll x, int l2, int r2) {
  st[i].mn += x;
  st[i].s += x * (r2 - l2 + 1);
  st[i].lz += x;
}
void psh(int i, int l2, int m2, int r2) {
  app(2 * i, st[i].lz, l2, m2);
  app(2 * i + 1, st[i].lz, m2 + 1, r2);
  st[i].lz = 0;
}
void upd(int l1, ll x, int i = 1, int l2 = 0, int r2 = n - 1) {
  if (l2 == r2) {
    st[i].mn = x;
    st[i].s = x;
    return;
  }
  int m2 = (l2 + r2) / 2;
  psh(i, l2, m2, r2);
  if (l1 <= m2)
    upd(l1, x, 2 * i, l2, m2);
  else
    upd(l1, x, 2 * i + 1, m2 + 1, r2);
  st[i].mn = min(st[2 * i].mn, st[2 * i + 1].mn);
  st[i].s = st[2 * i].s + st[2 * i + 1].s;
}

// void upd2(int l1, int r1, int x, int i=1, int l2=0, int r2=n-1){
// if(l1<=l2 &&r2<=r1){
// app(i, x, l2, r2);
// return;
//}
// int m2 = (l2+r2)/2;
// psh(i, l2, m2, r2);
// if(l1<=m2)
// upd2(l1, r1, x, 2*i, l2, m2);
// if(m2<r1)
// upd2(l1, r1, x, 2*i+1, m2+1, r2);
// st[i].mn = min(st[2*i].mn, st[2*i+1].mn);
// st[i].s = st[2*i].s + st[2*i+1].s;
//}
ll qry(int l1, int r1, int i = 1, int l2 = 0, int r2 = n - 1) {
  if (l1 <= l2 && r2 <= r1) {
    return st[i].s;
  }
  int m2 = (l2 + r2) / 2;
  psh(i, l2, m2, r2);
  return (l1 <= m2 ? qry(l1, r1, 2 * i, l2, m2) : 0) +
         (m2 < r1 ? qry(l1, r1, 2 * i + 1, m2 + 1, r2) : 0);
}

vector<ar<int, 2>> ta[mxN];
int ans[mxN];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

//   for(int i=0; i<mxN; ++i){
//       ta[i].clear();
//       ans[i]=0;
//   }  
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> x[i];

    cin>>q;
  for (int i = 0; i < q; ++i) {
    int a, b;
    cin >> a >> b, --a, --b;
    ta[b].push_back({a, i});
  }

  map<int, int> mp;
  for (int i = 0; i < n; ++i) {
    upd(i, 1);
    if (mp.find(x[i]) != mp.end())
      upd(mp[x[i]], 0);
    mp[x[i]] = i;

    for (ar<int, 2> a : ta[i])
      ans[a[1]] = qry(a[0], i);
  }

  for (int i = 0; i < q; ++i)
    cout << ans[i] << "\n";

  return 0;
}


// typedef struct query {
//   int l, r, blk_no, i;

//   query() { l = r = blk_no = i = -1; }

//   query(int L, int R, int B, int idx) {
//     l = L;
//     r = R;
//     blk_no = L / B;
//     i = idx;
//   }
// } query;

// const int N = (int)(1e5 + 5);
// int a[N];
// int B;

// const int M = (int)(1e6 + 5);
// int freq[M];

// int ans = 0;

// void add(int i) {
//   freq[a[i]] += 1;
//   if (freq[a[i]] == 1) {
//     ans++;
//   }
// }

// void remove(int i) {
//   freq[a[i]] -= 1;
//   if (freq[a[i]] == 0) {
//     ans--;
//   }
// }

// bool cmp(query &a, query &b) {
//   if (a.blk_no != b.blk_no)
//     return a.blk_no < b.blk_no;
//   return a.r < b.r;
// }

// int main() {

//   int n;
//   cin >> n;
//   for (int i = 0; i < n; i++)
//     cin >> a[i];

//   B = sqrt(n);

//   int q;
//   cin >> q;
//   query queries[q];
//   for (int i = 0; i < q; i++) {
//     int l, r;
//     cin >> l >> r;
//     l--;
//     r--;
//     queries[i] = query(l, r, B, i);
//   }

//   sort(queries, queries + q, cmp);

//   int ans_to_queries[q];

//   int L = queries[0].l, R = queries[0].l - 1;

//   for (int i = 0; i < q; i++) {
//     while (R < queries[i].r) {
//       R++;
//       add(R);
//     }

//     while (R > queries[i].r) {
//       remove(R);
//       R--;
//     }

//     while (L < queries[i].l) {
//       remove(L);
//       L++;
//     }

//     while (L > queries[i].l) {
//       L--;
//       add(L);
//     }

//     ans_to_queries[queries[i].i] = ans;
//   }

//   for (int i = 0; i < q; i++) {
//     cout << ans_to_queries[i] << "\n";
//   }

//   return 0;
// }
```
## Distinct Query with Updates
Given a sequence of n numbers a1, a2, ..., an, and a number of d-queries of the following types.
1. For each d-query (1, i, j),You have to return the number of distinct elements in the subsequence (i,j)i.e., ai, ai+1, ..., aj. where (1 ≤ i ≤ j ≤ n).
2. For each d-query (2, i, x), you have to update a[i]=x. where(1 ≤ x ≤ 10^6)

```cpp
const int BLK = 1000;
typedef struct query {
    int l, r, t, idx;
    query() {
        l = r = t = idx = 0;
    }
} query;

int get(int i){
    return (i/BLK);
}

bool cmp(query& a, query& b){
    if(get(a.l) != get(b.l)) return a.l < b.l;
    else if(get(a.r) != get(b.r)) return a.r < b.r;
    return a.t < b.t;
}

void add(int x, int& ans, unordered_map<int, int>& freq){
    if(freq[x]==0){
        ++ans;
        ++freq[x];
    }else{
        freq[x]++;
    }
}
void del(int x, int& ans, unordered_map<int, int>& freq){
    if(freq[x]==1){
        --ans;
        --freq[x];
    }else{
        freq[x]--;
    }
}

vector <int> distinctQueryWithUpdates(int n, int q, vector <int> & a, vector<vector<int>>& Q) {
    int ans = 0;
    unordered_map<int, int> freq;
    vector<query> queries;
    vector<pair<int, pair<int, int>>> updates;
    int no_updates = 0;
    
    for(int i=0; i<q; ++i){
        int type = Q[i][0];
        if(type==1){
            int l = Q[i][1], r = Q[i][2];
            --l, --r;
            query cur_q;
            cur_q.l = l, cur_q.r = r, cur_q.t = no_updates, cur_q.idx = queries.size();

            queries.push_back(cur_q);
        }
        else{
            int idx = Q[i][1], x = Q[i][2];
            --idx;
            updates.push_back({idx, {x, -1}});
            ++no_updates;
        }
    }
    sort(begin(queries), end(queries), cmp);
    int b[n];
    for(int i=0; i<n; ++i)
        b[i] = a[i];
    
    for(int i=0; i<updates.size(); ++i){
        int idx = updates[i].first;
        int val = updates[i].second.first;
        updates[i].second.second = b[idx];
        b[idx] = val;
    }
    int L = queries[0].l;
    int R = L-1;

    int timestamp = -1;

    int nq = queries.size();
    int query_ans[nq];
    for(int i=0; i<nq; ++i){
        int idx = queries[i].idx, l = queries[i].l, r = queries[i].r, t = queries[i].t;
        while(R<r){
            R++;
            add(a[R], ans, freq);
        }
        while(R>r){
            del(a[R], ans, freq);
            --R;
        }
        while(L<l){
            del(a[L], ans, freq);
            L++;
        }
        while(L>l){
            L--;
            add(a[L], ans, freq);
        }
        while(timestamp < t){
            timestamp++;
            if(timestamp < updates.size()){
                int up_idx = updates[timestamp].first;
                int new_val = updates[timestamp].second.first;
                int old_val = updates[timestamp].second.second;

                if(up_idx >= L && up_idx <=R)
                    del(old_val, ans, freq);
                a[up_idx] = new_val;
                if(up_idx >= L && up_idx <=R)
                    add(new_val, ans, freq);
            }
        }

        while (timestamp > t) {
          timestamp++;
          if (timestamp < updates.size()) {
            int up_idx = updates[timestamp].first;
            int new_val = updates[timestamp].second.second;
            int old_val = updates[timestamp].second.first;

            if (up_idx >= L && up_idx <= R)
              del(old_val, ans, freq);
            a[up_idx] = new_val;
            if (up_idx >= L && up_idx <= R)
              add(new_val, ans, freq);
          }
        }

        query_ans[idx] = ans;
    }

    vector<int> res;
    for(int i=0; i<nq; ++i)
        res.push_back(query_ans[i]);
    
    return res;
}
```
## Shil and Wave Sequence $
Given a sequence A1 , A2 , A3 .. AN of length N. Find total number of wave subsequences having length greater than 1.
Wave subsequence of sequence A1 , A2 , A3 .. AN is defined as a set of integers i1 , i2 .. ik such that Ai1 < Ai2 > Ai3 < Ai4 .... or Ai1 > Ai2 < Ai3 > Ai4 .... and i1 < i2 < ...< ik.Two subsequences i1 , i2 .. ik and j1 , j2 .. jm are considered different if k != m or there exists some index l such that il ! = jl
```cpp
#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int M = 1e9+7;
const int mxN = 1e5;


ll dp_lo[mxN+1], dp_hi[mxN+1];
ll a[mxN+1];

int main(){
    ios::sync_with_stdio(false); cin.tie(0);

    ll n, x, t, s1, s2;
    cin>>n;
    for(ll i=1; i<=n; ++i){
        cin>>x;
        t = mxN;
        s1 = s2 = 0;
        while(t){
            s1 = (s1+dp_hi[t]+a[t])%M;
            t -= (t & (-t));
        }
        t = x;
        while(t){
            s1 = (s1 - dp_hi[t]-a[t]+M)%M;
            t -= (t & (-t));
        }
        t = x-1;
        while(t){
            s2 = (s2+dp_lo[t] + a[t])%M;
            t -= (t & (-t));
        }
        t = x;
        while(t < mxN+1){
            dp_lo[t] = (dp_lo[t] + s1)%M;
            dp_hi[t] = (s2 + dp_hi[t])%M;
            a[t]++;
            t += (t & (-t));
        }

    }
    
    ll ans = 0;
    s1= s2=0;
    t = mxN;
    while(t){
        ans = (ans + dp_hi[t])%M;
        ans = (ans + dp_lo[t])%M;
        t -= (t & (-t));
    }
    cout << ans;
    
    return 0;
}
```
