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
```Algorithm:
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
keep the answer to the i - th query in ansi .```
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
