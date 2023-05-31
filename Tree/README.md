## Center of an N-ary tree $$
Ninjaland is the beautiful empire comprised of ‘N’ kingdoms connected by N-1 bidirectional roads such that no cycle is formed. While exploring Ninjaland, Ninja thought about the kingdoms which are located at the center of the Ninjaland. Can you help Ninja to find such kingdoms?
You are given a tree having ‘N’ nodes and ‘N’-1 edges. Your task is to find the node(s) at the center of the given tree.
Note:-
The Center of an N-ary tree is the vertex having the minimum eccentricity. The eccentricity of any vertex in a given tree is the maximum distance between the given vertex and any other tree vertex.
Hence, it means that to find the center, we have to minimize this eccentricity.  
If there are two centers print the smaller one first.
```cpp
const int mxN = 1e6+5;

vector<int> adj[mxN];

bool getDiameter(int u, int t, int p, vector<int> &path) {
  if (u == t) {
    path.push_back(u);
    return 1;
  }

  for (auto i : adj[u]) {
    if (i == p)
      continue;

    if (getDiameter(i, t, u, path)) {
      path.push_back(u);
      return 1;
    }
  }

  return 0;
}

void dfs(int u, int p, int h, int &mxH, int &mxHv) {
  if (h > mxH) {
    mxH = h;
    mxHv = u;
  }

  for (auto i : adj[u]) {
    if (i == p)
      continue;

    dfs(i, u, h + 1, mxH, mxHv);
  }
}

vector<int> solve(int n) {
    vector<int> ans;

  int mxH = -1;
  int mxHv = -1;

  dfs(0, -1, 0, mxH, mxHv);
  int leaf1 = mxHv;

  mxH = -1;
  dfs(mxHv, -1, 0, mxH, mxHv);
  int leaf2 = mxHv;

  vector<int> path;

  getDiameter(leaf1, leaf2, -1, path);

  int sz = path.size();
  if (sz & 1)
    ans.push_back(path[sz/2]);
  else{
      
      ans.push_back(path[(sz-1)/2]);
      ans.push_back(path[sz / 2]);
  }
    
  return ans;
}



vector<int> Center(int n, vector<vector<int>> &edges) {
  for (int i = 0; i < mxN; ++i) {
    adj[i].clear();
  }

  int m = edges.size();
  for (int i = 0; i < m; ++i) {
    int a = edges[i][0], b = edges[i][1];

    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  return solve(n);
}
```
## Tree Diameter
You are given a tree with N vertex and N - 1 edge and you are supposed to find the diameter of the tree.
Diameter of a tree is defined as the maximum distance between any pair of leaves of a tree.
```cpp
#include<bits/stdc++.h>
using namespace std;

const int mxN = 1e4+5;
vector<int> adj[mxN];
int ans;
// vector<int> d(mxN);
int dfs(int u, int p){
    int d1=0, d2=-1;
    for(int v: adj[u]){
        if(v!=p){
            int d = dfs(v, u);
            if(d > d1){
                d2 = d1;
                d1 = d;
            }else if(d > d2){
                d2 = d;
            }
        }
    }
    ans = max(ans, d1+d2);
    return 1+d1;

    // for(int v: adj[u]){ //MAX DIST BTW ANY TWO NODES
    //     if(v==p) continue;
    //     dfs(v, u, ans);
    //     ans = max(d[u]+d[v]+1, ans);
    //     d[u] = max(d[u], d[v]+1);
    // }
}

void solve(){
    int n; cin>>n;
    ans=0;
    for(int i=0; i<n-1; ++i){
        int u, v; 
        cin>>u>>v, --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, -1);

    cout << ans <<'\n';
}

int main(){
    int t; cin>>t;
    while(t--){
        for(int i=0; i<mxN; ++i)
            adj[i].clear();
        // d.clear();

        solve();
    }
    return 0;
}
```

## XOR Query
You are given a tree(root 0) with N vertex having N - 1 edges. You are also given an array ‘QUERY’ of size ‘Q’, where each query consists of an integer that denotes a node. You have to print the xor of all the values of nodes in the sub-tree of the given node.
```cpp
#include <bits/stdc++.h>

const int mxN = 1e5;
vector<int> adj[mxN+1];
vector<int> pf(mxN+1);

void dfs(int u = 0, int p = 0) {
  pf[u] = u;
  for (int v : adj[u]) {
    if (v != p) {
      dfs(v, u);
      pf[u] ^= pf[v];
    }
  }
}
vector<int> XORquery(int n, vector<vector<int>> &edges, int q, vector<int> &query) {
    for(int i=0; i<=n; ++i) 
        adj[i].clear();

    vector<int> ans;

    for(int i=0; i<edges.size(); ++i){
        int u = edges[i][0], v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs();

    for (int i = 0; i < q; ++i) {
      int u = query[i];
      ans.push_back(pf[u]);
    }

    return ans;
}
```
## CF Gardener and Tree
```cpp
#include<bits/stdc++.h>

using namespace std;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t;
	cin>>t;
	while(t--){
		int n, k;
		cin>>n>>k;

		vector<int> tree[n+1];
		vector<int> degree(n+1, 0);

		for(int i=0; i<n-1; i++){
			int u, v;
			cin>>u>>v;
			tree[u].push_back(v);
			tree[v].push_back(u);
			degree[u] ++;
			degree[v] ++;
		}

		vector<int> timeOfRemoval(n+1, 0);

		queue<int> q;

		for(int i=1; i<=n; i++){
			if(degree[i] == 1){
				timeOfRemoval[i] = 1;
				q.push(i);
			}
		}

		while(!q.empty()){
			int u = q.front();
			q.pop();


			for(int v: tree[u]){
				degree[v] --;
				if(degree[v] <= 1 and timeOfRemoval[v] == 0){
					timeOfRemoval[v] = timeOfRemoval[u] + 1;
					q.push(v);
				}
			}
		}

		int ans = 0;
		for(int i=1; i<=n; i++){
			if(timeOfRemoval[i] > k) ans++;
		}

		cout<<ans<<"\n";
	}

	return 0;
}
```
## CF Military Problem
```cpp
#include<bits/stdc++.h>

using namespace std;

const int N = (int)(2e5+5);

vector<int> tree[N];

vector<int> dfs_order;

int first_index[N], last_index[N];

void dfs(int s){
	dfs_order.push_back(s);
	first_index[s] = dfs_order.size() - 1;

	for(int v: tree[s]){
		dfs(v);
	}

	last_index[s] = dfs_order.size() - 1;
}


int main(){
	freopen("input.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int n, q;
	cin>>n>>q;

	for(int i=2; i<=n; i++){
		int pi;
		cin>>pi;
		tree[pi].push_back(i);
	}

	dfs(1);

	while(q--){
		int ui, ki;
		cin>>ui>>ki;
		int index = first_index[ui];
		index += ki-1;
		if(index > last_index[ui]){
			cout<<"-1\n";
		} else{
			cout<<dfs_order[index]<<"\n";
		}
	}


	return 0;
}
```
## Is it a tree?
Given a graph with N nodes, numbered from 1 to N and M edges. Determine if it is a tree ?
Input Format :
Line 1 : Two integers N and M
Next M lines : M edges, each line contains a pair (u, v) means there is an edge between node u and node v

```cpp
#include <bits/stdc++.h>
using namespace std;

const int mxN = 2005;
vector<int> adj[mxN];
vector<int> vis(mxN);
//Must visit all the nodes via dfs from root
void dfs(int u=0){
	vis[u]=1;
	for(int v: adj[u]){
		if(!vis[v])
			dfs(v);
	}
}
int main() {
	int n, m; cin>>n>>m;
	for(int i=0; i<m; ++i){
		int u, v; 
		cin>>u>>v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs();
	for(int i=0; i<n; ++i)
          if (!vis[i]) {
            cout << "NO\n";
            return 0;
          }
        cout<< "YES\n";

}
```

## Ninja And Numbers
Ninja is learning tree data structures. His friend is helping him learn by giving him problems to solve. He gives him a tree with N nodes numbered from 0 to N - 1 in the form of a parent array parent where parent[i] is the parent of the ith node. The root of the tree is node 0. Now Ninja has to find the kth ancestor of a given node. The kth ancestor of a tree node is the kth node in the path from that node to the root node.
```cpp
const int mxN = 1e5;
int n, d[mxN], anc[mxN][17];
vector<int> adj[mxN];

void dfs(int u=0, int p=-1){
    anc[u][0]=p;
    for(int i=1; i<16; ++i)
        anc[u][i]= ~anc[u][i-1] ? anc[anc[u][i-1]][i-1]: -1;
    
    for(int v: adj[u]){
        if(v==p)
            continue;
        d[v] = d[u]+1;
        dfs(v, u);
    }
}
int kthAncestor(int n, vector<int> & parent, int node, int k){
    for(int i=0; i<mxN; ++i){
        adj[i].clear();
        // d[i]=0;
    }
    for(int i=0; i<n; ++i){
        adj[parent[i]].push_back(i);
    }
    
    dfs();
    if(d[node]<k)
        return -1;
    else{
        for(int i=16; ~i; --i)
            if(k>>i&1)
                node = anc[node][i];
            return node;
    }
}
```

## ZigZag N-ary Tree Traversal
You are given an n-ary tree consisting of ‘N’ nodes. Your task is to return the zigzag level order traversal of the nodes' values of the given tree. Zigzag traversal means starting from left to right, then right to the left for the next level and then again left to right, and so on in an alternate manner.
```cpp
/**************************************************
   
    class TreeNode
    {
    public:
        int val;
        vector < TreeNode* > child;
        
        TreeNode(int val)
        {
            this->val = val;
        }

        ~TreeNode()
        {
            for( int i=0 ; i<child.size();i++)
            {
                delete child[i];
            }
        }
    };
    
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

vector<int> zigzagLevelOrder(int n, TreeNode* root)

{   
    if(root==nullptr)
      return {};

    vector<int> res;

    vector<vector<int>> ans(1000);
    queue<TreeNode*> q;
    q.push(root);
    q.push(nullptr);
    int d = 1;

    while (!q.empty()) {
      TreeNode* u = q.front();
      q.pop();
      if (u == nullptr) {
        if (q.size() > 0) {
          q.push(nullptr);
          d++;
        }
      } else {
        ans[d].push_back(u->val);
        for (int i = 0; i < u->child.size(); ++i)
          q.push(u->child[i]);
      }
    }

    for (int i = 1; i <= d; ++i) {
      if (i % 2 == 0)
        reverse(ans[i].begin(), ans[i].end());
    }

    for (vector<int> &v : ans) {
      for (int i=0; i<v.size(); ++i)
        res.push_back(v[i]);

    }

    return res;
}
```

## Check for Mirror Trees
While learning DSA, Ninja found two N-ary trees and wants to check whether they are mirror images of each other or not. But, he can’t find a suitable method to check the same. Can you help Ninja to solve this problem?
You are given two N-ary trees, ‘TREEA’ and ‘TREEB’ having ‘N’ vertices labeled from 0 to ‘N’-1, and both the trees are rooted at node 0. Your task is to find whether the trees are mirror images of each other or not. Edges of the tree are in order from left to right.

```cpp
#include <bits/stdc++.h>
using namespace std;
//constraints given in Qs are wrong
const int mxN = 100005;
vector<int> adj1[mxN], adj2[mxN];

bool dfs(int u) {
  if (adj1[u].size() != adj2[u].size())
    return 0;
  vector<int> a = adj1[u];
  vector<int> b = adj2[u];
  reverse(begin(b), end(b));
  if (a != b)
    return 0;

  for (int v : adj1[u]) {
    if (!dfs(v))
      return 0;
  }

  return 1;
}

bool checkMirror(int n, vector<vector<int>> &A, vector<vector<int>> &B)
{
  for(int i=0; i<mxN; ++i){
    adj1[i].clear();
    adj2[i].clear();
  }

  for (int i = 0; i < A.size(); ++i) {
    adj1[A[i][0]].push_back(A[i][1]);
    // adj1[A[i][1]].push_back(A[i][0]);
  }
  for (int i = 0; i < B.size(); ++i) {
    adj2[B[i][0]].push_back(B[i][1]);
    // adj2[B[i][1]].push_back(B[i][0]);
  }

  return dfs(0);
 
}
```

## Maximum Path Sum
You are given an n-ary tree consisting of ‘N’ nodes. Your task is to return the maximum sum of the path from the root to the leaf node.

```cpp
/************************************************************

   Following is the TreeNode class structure

   class TreeNode {
    public:
        int data;
        vector<TreeNode*> children;

        TreeNode(int data) {
            this->data = data;
        }
   }

************************************************************/

void dfs(TreeNode* root,int sum,int& ans){
    if(root->children.size() == 0){//reached leaf node
        sum+=root->data;
        ans = max(ans, sum);
        return;
    }
    sum+=root->data;
    
    for(int i=0;i<root->children.size();i++)
        dfs(root->children[i], sum, ans);
    
    
}
int findMaxSum(int n, TreeNode* root)
{
    int sum = 0;
    int ans = -1;
    dfs(root, sum, ans);
    return ans;
}
```

## Count elements in all subtrees
You are given an arbitrary tree consisting of 'N' nodes numbered from 0 to 'N' - 1. You need to find the total number of elements in all the subtrees of the given tree. In other words, given a generic tree, find the count of elements in the subtrees rooted at each node.
A subtree of a tree T is a tree S consisting of a node in T and all of its descendants in T. The subtree corresponding to the root node is the entire tree. For better understanding, refer to the image below:-
alt text
Note:
1. The tree will always be rooted at 0. 
2. You can return the count of nodes in any order.
3. The root of any subtree is also counted in the subtree thus the count of nodes in a subtree rooted at a leaf node is 
4. You can return the numbers in any order.

```cpp
int dp[1005];
void dfs(int s, int p, vector<vector<int>>& adj){//p = parent
	dp[s]=1;

	for(auto u=adj[s].begin(); u!=adj[s].end(); ++u){
		if(*u == p)
			continue;
			
		dfs(*u, s, adj);
		
		dp[s]+=dp[*u];
	}

}

vector<int> countNodesInAllSubtrees(int n, vector<vector<int>> &adj) {
	// Write your code here.
	// adj[i] will contain all nodes adjacent to the ith node(0-based indexing)
	vector<int> ans(n);

	dfs(0, -1, adj);
	for(int i=0; i<n; ++i)
		ans[i]=dp[i];
	return ans;
}
```
## Kth Ancestor
Ninja found a family tree with ‘N’ members labeled from 0 to ‘N’-1. These ‘N’ members are connected by ‘N’-1 edges in the form of an N-ary tree. Now, Ninja is excited to find the K’th ancestor of each of the members of the family. Can you help Ninja to find the Kth ancestor of each of the members?
You are given an N-ary tree having ‘N’ vertices labeled from 0 to ‘N’-1 and an integer ‘K’. Your task is to find the Kth ancestor of each node. If the Kth ancestor doesn’t exist, print -1 corresponding to that.

```cpp
#include <bits/stdc++.h>
using namespace std;

// const int mxN = 1e6;
// int d[mxN], anc[mxN][20];
// vector<int> adj[mxN];

// void dfs(int u = 0, int p = -1) {
//   anc[u][0] = p;
//   for (int i = 1; i < 19; ++i)
//     anc[u][i] = ~anc[u][i - 1] ? anc[anc[u][i - 1]][i - 1] : -1;

//   for (int v : adj[u]) {
//     if (v == p)
//       continue;
//     d[v] = d[u] + 1;
//     dfs(v, u);
//   }
// }


// vector<int> kthAncestor(int n, int k, vector<vector<int>> &edges)
// {
//   for (int i = 0; i < mxN; ++i) {
//     adj[i].clear();
//     // d[i]=0;
//   }
//   for (int i = 0; i < edges.size(); ++i) {
//     int p, c;
//     p = edges[i][0];
//     c = edges[i][1];
//     adj[p].push_back(c);
//   }

//   dfs();

//   vector<int> ans;
//   for(int node=0; node<n; ++node){

//     if (d[node] < k)
//       ans.push_back(-1);
//     else {
//       for (int i = 19; ~i; --i)
//         if (k >> i & 1)
//           node = anc[node][i];
          
//       ans.push_back(node);
//     }
    
//   }

//   return ans;
// }

const int N = 1e6 + 1;
vector<int> graph[N];
int parent[N];

void dfs(int u, int p) {
  parent[u] = p;
  for (int v : graph[u]) {
    if (v != p) {
      dfs(v, u);
    }
  }
}

void clr() { for (int i = 0; i < N; ++i) {
  graph[i].clear();
  parent[i]=0;
}
}
vector<int> kthAncestor(int n, int k, vector<vector<int>> &edges) {
  clr();

  vector<int> ans(n);
  for (auto e : edges) {
    graph[e[0]].push_back(e[1]);
    graph[e[1]].push_back(e[0]);
  }
  dfs(0, -1);
  for (int i = 0; i < n; i++) {
    int p = i;
    for (int j = 0; j < k; j++) {
      if (p == -1) {
        ans[i] = -1;
        break;
      }
      p = parent[p];
    }
    ans[i] = p;
  }
  return ans;
}
```

## Subtree Queries
On the occasion of Christmas, one of your friends gifted you a special tree. But this tree is a bit different from other Christmas trees. The tree has 'N' nodes numbered as 1, 2, 3, …., N. The topmost node is node-1, i.e., assume that the tree is rooted at node-1. You are also given an integer array 'V' of size 'N', where i-th element denotes the weight assigned to the i-th node in the tree.
Your friend asked you to perform the following type of queries on the tree and tell him the results.
"1 s w": change the weight of node 's' to 'w'.
"2 s": calculate the sum of weights in the subtree of node 's' (node s inclusive) and return it.
```cpp
#define ll long long
//solving using BIT/Fenwick Tree
const int mxN = 1e5;
ll n, d[mxN], anc[mxN][19], c[mxN], de[mxN], ds[mxN], dt;
ll ft[mxN+1];
vector<int> adj[mxN];

void upd(int i, int x){
    for(++i; i<=n; i+=i&-i)
        ft[i]+=x;
}

ll qry(int i){
    ll r=0;
    for(; i; i-=i&-i)
        r+=ft[i];
    return r;
}

void dfs(int u=0, int p=-1){
    anc[u][0]=p;
    for(int i=1; i<19; ++i)
        anc[u][i]=~anc[u][i-1] ? anc[anc[u][i-1]][i-1]:-1;
    ds[u]=dt++;
    for(int v: adj[u]){
        if(v==p)
            continue;
        d[v]=d[u]+1;
        dfs(v, u);
    }
    de[u]=dt;
}

int lca(int u, int v){
    if(d[u]<d[v])
        swap(u, v);
    for(int i=18; ~i; --i)
        if(d[u]-(1<<i) >= d[v])
            u=anc[u][i];
    
    if(u==v)
        return u;
    for(int i=18; ~i; --i)
        if(anc[u][i]^anc[v][i])
            u=anc[u][i], v=anc[v][i];
    
    return anc[u][0];
}
vector<ll> treeSum(int N, int Q, vector<int>& V, vector<vector<int>>& edges, vector<vector<int>>& queries)
{   
    n = N;
    vector<ll> ans;
    for(int i=0; i<edges.size(); ++i){
        int a=edges[i][0], b=edges[i][1];
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs();
    for(int i=0; i<n; ++i)
        upd(ds[i], V[i]);
    
    for(int i=0; i<Q; ++i){
        int qt=queries[i][0];
        if(qt==1){
            int s, x;
            s=queries[i][1], x=queries[i][2];
            --s;
            upd(ds[s], x-V[s]);
            V[s]=x;
        }else{
            int s=queries[i][1]; --s;
            ll res = qry(de[s])-qry(ds[s]);
            ans.push_back(res);
        }
    }
    return ans;
}
```

## CF New Year Tree
```cpp
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = (int)(4e5+5);
vector<int> tree[N];
int colors[N];

int in[N], out[N], rin[N];

int T = 0;

void dfs(int s, int p){
	in[s] = T++;
	rin[in[s]] = (1ll<<colors[s]);
	for(int v: tree[s]){
		if(v!=p){
			dfs(v, s);
		}
	}
	out[s] = T;
}

int st[4*N];
int lazy[4*N];

void propagate(int beg, int end, int pos){
	if(lazy[pos] != -1){
		st[pos] = (1ll<<lazy[pos]);
		if(beg != end){
			lazy[2*pos+1] = lazy[pos];
			lazy[2*pos+2] = lazy[pos];
		}
		lazy[pos] = -1;
	}
}

void build(int beg, int end, int pos){
	if(beg == end){
		st[pos] = rin[beg];
		return;
	}

	int mid = (beg + end) / 2;
	build(beg, mid, 2*pos+1);
	build(mid+1, end, 2*pos+2);
	st[pos] = st[2*pos+1] | st[2*pos+2];
}


void update(int beg, int end, int ql, int qr, int col, int pos){
	propagate(beg, end, pos);
	if(ql<=beg and qr>=end){
		lazy[pos] = col;
		propagate(beg, end, pos);
		return;
	} else if(qr<beg or ql>end) return;

	int mid = (beg+end)/2;
	update(beg, mid, ql, qr, col, 2*pos+1);
	update(mid+1, end, ql, qr, col, 2*pos+2);
	st[pos] = st[2*pos+1] | st[2*pos+2];
}

int query(int beg, int end, int ql, int qr, int pos){
	propagate(beg, end, pos);
	if(ql<=beg and qr>=end){
		return st[pos];
	} else if(ql>end or qr<beg){
		return 0;
	}

	int mid = (beg+end)/2;
	return query(beg, mid, ql, qr, 2*pos+1) | query(mid+1, end, ql, qr, 2*pos+2);
}


signed main(){
	freopen("input.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, q;
	cin>>n>>q;

	for(int i=1; i<=n; i++){
		cin>>colors[i];
		colors[i] -= 1;
	}

	for(int i=0; i<n-1; i++){
		int u, v;
		cin>>u>>v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	dfs(1, 0);

	build(0, n-1, 0);

	fill(lazy, lazy+4*N, -1);

	while(q--){
		int type;
		cin>>type;
		if(type == 1){
			int s, col;
			cin>>s>>col;
			col -= 1
			;
			update(0, n-1, in[s], out[s]-1, col, 0);
		} else{
			int s;
			cin>>s;
			int ans = query(0, n-1, in[s], out[s] - 1, 0);
			int num = 0;
			for(int i=0; i<60; i++){
				if(ans&(1ll<<i)) num++;
			}

			cout<<num<<"\n";
		}
	}

	return 0;
}
```

## Spoj Gao on Tree
```cpp
#include<bits/stdc++.h>

using namespace std;

typedef struct query {
	int l, r, idx, lca, c;

	query() {
		l = r = idx = lca = c = -1;
	}
} query;

const int N = (int)(1e5+5);
const int LGN = 20;
const int BLK_SZ = 1000;
vector<int> tree[N];
int val[N];

int in[N], out[N], rin[N<<1];
int freq[N];
bool visited[N];

int h[N];
int dp[LGN][N];
int T = 0;

void dfs(int s, int p, int ht=0){
	in[s] = T++;
	rin[in[s]] = s;
	h[s] = ht;
	dp[0][s] = p;

	for(int i=1; i<LGN; i++) {
		dp[i][s] = dp[i-1][dp[i-1][s]];
	}

	for(int v: tree[s]){
		if(v != p){
			dfs(v, s, ht+1);
		}
	}

	out[s] = T++;
	rin[out[s]] = s;
}

inline int lca(int u, int v){
	if(h[u] < h[v]) swap(u, v);
	for(int i=0; i<LGN; i++) {
		if((h[u] - h[v])&(1<<i)){
			u = dp[i][u];
		}
	}

	if(u == v) return u;

	for(int i=LGN-1; i>=0; i--){
		if(dp[i][u] != dp[i][v]) {
			u = dp[i][u];
			v = dp[i][v];
		}
	}

	return dp[0][u];
}

bool cmp(query a, query b) {
	int blk_a = a.l / BLK_SZ;
	int blk_b = b.l / BLK_SZ;

	if(blk_a != blk_b) return blk_a < blk_b;

	return a.r < b.r;
}

void add(int u) {
	if(visited[u]){
		visited[u] = false;
		freq[val[u]] --;
	} else {
		visited[u] = true;
		freq[val[u]] ++;
	}
}

void cleanup(int n){
	T = 0;
	for(int i=0; i<=n; i++) {
		tree[i].clear();

		in[i] = out[i] = h[i] = 0;

		for(int j=0; j<LGN; j++) dp[j][i] = 0;
		freq[i] = 0;
		visited[i] = false;
	}
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int n, m;
	while(scanf("%d %d", &n, &m) != EOF) {
		cleanup(n);
		for(int i=1; i<=n; i++) scanf("%d", &val[i]);

		for(int i=0; i<n-1; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			tree[u].push_back(v);
			tree[v].push_back(u);
		}

		dfs(1, 0);

		query queries[m];
		for(int i=0; i<m; i++) {
			int u, v, c;
			scanf("%d %d %d", &u, &v, &c);

			queries[i].idx = i;
			queries[i].c = c;

			int l = lca(u, v);

			if(in[u] > in[v]) swap(u, v);

			if(l == u) {
				queries[i].l = in[u];
				queries[i].r = in[v];
			} else {
				queries[i].l = out[u];
				queries[i].r = in[v];
				queries[i].lca = l;
			}
		}

		sort(queries, queries+m, cmp);

		bool ans[m];

		int l_ptr = queries[0].l;
		int r_ptr = l_ptr - 1;
		for(int i=0; i<m; i++){
			while(l_ptr < queries[i].l) {
				add(rin[l_ptr]);
				l_ptr++;
			}			

			while(l_ptr > queries[i].l) {
				l_ptr--;
				add(rin[l_ptr]);
			}

			while(r_ptr < queries[i].r) {
				r_ptr++;
				add(rin[r_ptr]);
			}

			while(r_ptr > queries[i].r) {
				add(rin[r_ptr]);
				r_ptr--;
			}

			if(freq[queries[i].c] > 0) {
				ans[queries[i].idx] = true;
			} else if(queries[i].lca != -1 and queries[i].c == val[queries[i].lca]) {
				ans[queries[i].idx] = true;
			} else ans[queries[i].idx] = false;
		}

		for(int i=0; i<m; i++){
			if(ans[i]) printf("Find\n");
			else printf("NotFind\n");
		}
		printf("\n");
	} 

	return 0;
}
```
## Unique Colors
You are given a tree(rooted at 1) with ‘N’ vertex having ‘N’ - 1 edge. Each vertex has a color associated with it given in the array ‘COLOR’. Your task is to print the count of unique colors for each node in the subtree of that node.
```cpp
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
//Segment Tree Distinct Value Queries Qs
const int mxN = 1e5;
int n, d[mxN], anc[mxN][19], de[mxN], ds[mxN], x[mxN], dt;
// ll ft[mxN+1];
vector<int> adj[mxN];
vector<ar<int, 2>> ta[mxN];
// int ans[mxN];

struct node{
    ll mn, s, lz;
} st[1<<19];
 
void app(int i, ll x, int l2, int r2){
     st[i].mn += x;
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
     st[i].mn = min(st[2*i].mn, st[2*i+1].mn);
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
     st[i].mn = min(st[2*i].mn, st[2*i+1].mn);
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
// void upd(int i, int x){
//     for(++i; i<=n; i+=i&-i)
//         ft[i]+=x;
// }

// int qry(int i){
//     int r=0;
//     for(; i; i-=i&-i)
//         r+=ft[i];
//     return r;
// }

void dfs(int u=0, int p=-1){
    anc[u][0]=p;
    for(int i=1; i<19; ++i)
        anc[u][i]=~anc[u][i-1] ? anc[anc[u][i-1]][i-1]:-1;
    ds[u]=dt++;
    for(int v: adj[u]){
        if(v==p)
            continue;
        d[v]=d[u]+1;
        dfs(v, u);
    }
    de[u]=dt;
}

int lca(int u, int v){
    if(d[u]<d[v])
        swap(u, v);
    for(int i=18; ~i; --i)
        if(d[u]-(1<<i) >= d[v])
            u=anc[u][i];
    
    if(u==v)
        return u;
    for(int i=18; ~i; --i)
        if(anc[u][i]^anc[v][i])
            u=anc[u][i], v=anc[v][i];
    
    return anc[u][0];
}

void clear(){

    for(int i=0; i<mxN; ++i){
        adj[i].clear();
        ta[i].clear();
        // anc[i].clear();
        d[i]=de[i]=ds[i]=x[i]=0;
    }
    dt=0;
}
vector<int> uniqueClr(int N, vector<vector<int>> &edges, vector<int> &color) {
    n = N;
    vector<int> ans(n, 0);

    clear();

    for(int i=0; i<edges.size(); ++i){
        int a=edges[i][0], b=edges[i][1];
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs();
    for(int i=0; i<n; ++i)
      ta[de[i] - 1].push_back({ds[i], i}), x[ds[i]]=color[i];
    
    map<int, int> mp;
    for(int i=0; i<n; ++i){
        upd(i, 1);
        if(mp.find(x[i]) != mp.end())
            upd(mp[x[i]], 0);
        mp[x[i]]=i;
        for(ar<int, 2> a: ta[i])
            ans[a[1]]=qry(a[0], i);
    }

    return ans;
}
```

## Path Queries
You are given a tree containing ‘N’ nodes. The nodes are numbered from 0, 1, 2 … N - 1 and node 0 is the root of the tree. You are also given an array ‘ARR’ denoting the value associated with each node of this tree.
You have to process ‘Q’ queries, there are two types of queries:
1) For each query of type-1, you are given an index ‘IDX’ and a value ‘VAL’. The value associated with node 'IDX' must be replaced with the value 'VAL'.

2) For each query of type-2, you are given an index ‘IDX’. You need to calculate the sum of all the node values that lie on the path from the root node to the node ‘IDX’.

```cpp
#define ll long long
//solving using BIT/Fenwick Tree
const int mxN = 1e5;
int n, d[mxN], anc[mxN][19], c[mxN], de[mxN], ds[mxN], dt;
int ft[mxN+1];
vector<int> adj[mxN];

void upd(int i, int x){
    for(++i; i<=n; i+=i&-i)
        ft[i]+=x;
}

int qry(int i){
    int r=0;
    for(; i; i-=i&-i)
        r+=ft[i];
    return r;
}

void dfs(int u=0, int p=-1){
    anc[u][0]=p;
    for(int i=1; i<19; ++i)
        anc[u][i]=~anc[u][i-1] ? anc[anc[u][i-1]][i-1]:-1;
    ds[u]=dt++;
    for(int v: adj[u]){
        if(v==p)
            continue;
        d[v]=d[u]+1;
        dfs(v, u);
    }
    de[u]=dt;
}

int lca(int u, int v){
    if(d[u]<d[v])
        swap(u, v);
    for(int i=18; ~i; --i)
        if(d[u]-(1<<i) >= d[v])
            u=anc[u][i];
    
    if(u==v)
        return u;
    for(int i=18; ~i; --i)
        if(anc[u][i]^anc[v][i])
            u=anc[u][i], v=anc[v][i];
    
    return anc[u][0];
}

void clear(){
    for(int i=0; i<mxN; ++i){
        adj[i].clear();
        d[i]=ds[i]=de[i]=ft[i]=0;
    }
    dt=0;
}
vector<int> pathQueries(int N, vector<int> V, vector<vector<int>> edges,
                                  int Q, vector<vector<int>> queries) {
    
    clear();
    n = N;
    vector<int> ans;
    for(int i=0; i<edges.size(); ++i){
        int a=edges[i][0], b=edges[i][1];
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs();
    for(int i=0; i<n; ++i)
        upd(ds[i], V[i]), upd(de[i], -V[i]);
    
    for(int i=0; i<Q; ++i){
        int qt=queries[i][0];
        if(qt==1){
            int s, x;
            s=queries[i][1], x=queries[i][2];
            upd(ds[s], x-V[s]);
            upd(de[s], V[s]-x);
            V[s]=x;
        }else{
            int s=queries[i][1]; 
            int res = qry(ds[s]+1);
            ans.push_back(res);
        }
    }
    return ans;
}
```
## Tree Queries $
You are given a tree with ‘N’ nodes numbered 0 to ‘N’ - 1 rooted at node 0. Each node contains 0 coins initially. You are also given ‘M’ queries. The queries are of the following two types
1 L Y: Increase the coins of all nodes at ‘L’ distance from root by 'Y'
2 X: Get the sum of all coins of the subtree rooted at node ‘X’
```cpp
#define ll long long
//solving using BIT/Fenwick Tree
const int mxN = 1001;
const int SQN = 35;
int f[SQN][mxN] = {0};
ll val[SQN] = {0}, sum[mxN]={0};
int start[SQN], finish[SQN], ds[mxN], de[mxN], rev[mxN];
int n, sqn, q;
int dt=0;
int level[mxN] = {0}, lookup[mxN];
vector<int> adj[mxN];

void dfs(int u=1, int p=0){
    level[u]=level[p]+1;
    ds[u]= ++dt;  //****** dt++ gives WA
    rev[dt]=u;
    for(int v: adj[u]){
        if(v==p)
            continue;
        dfs(v, u);
    }
    de[u]=dt;
}
void clear(){
    for(int i=0; i<mxN; ++i){
        adj[i].clear();
        sum[i]=level[i]=lookup[i]=rev[i]=ds[i]=de[i]=0;
    }
    for(int i=0; i<SQN; ++i){
        for(int j=0; j<mxN; ++j)
            f[i][j]=0;
    }
    for(int i=0; i<SQN; ++i)
        val[i]=start[i]=finish[i]=0;
    dt=0;
}
vector<ll> treeQueries(vector<vector<int>> &edges, vector<vector<int>> &queries)
{   
    
	n = edges.size()+1;
    vector<ll> ans;
    clear();

    for(int i=0; i<edges.size(); ++i){
        int a=edges[i][0]+1, b=edges[i][1]+1;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs();
    int sqn = sqrt(n);
    int cur=1;
    for(int i=1; i<=n; ){
        int j=i;
        start[cur]=i;
        while(j<i+sqn && j<=n){
            f[cur][level[rev[j]]]++;
            j++;
            lookup[j-1]=cur;
        }
        i=j;
        finish[cur]=j-1;
        ++cur;
    }

    for(int i=0; i<queries.size(); ++i){
        int qt=queries[i][0];
        if(qt==1){
           int L = queries[i][1], x=queries[i][2];
           for (int i = 1; i < cur; ++i) {
             val[i] += 1LL * f[i][L + 1] * x;
           }

            sum[L+1] += x;
        }else{
            int v=queries[i][1]+1;
            int x=lookup[ds[v]], y=lookup[de[v]];
            ll res = 0;
            for(int i=x; i<=y; ++i){
              if (start[i] >= ds[v] && finish[i] <= de[v]) {
                res += val[i];
              } else if (start[i] < ds[v]) {
                for (int j = ds[v]; j <= min(de[v], finish[i]); ++j)
                  res += sum[level[rev[j]]];
              } else {
                for (int j = max(start[i], ds[v]); j <= de[v]; ++j)
                  res += sum[level[rev[j]]];
              }
            }
            ans.push_back(res);
        }
    }
    return ans;
}
```
## Queries $$
You are given a tree that is rooted at node 1. Each vertex ‘v’ of the tree is having some color represented by color[v]. You are also given ‘Q’ queries. Each query is described by 2 integers ‘v’ and ‘k’. You have to answer how many colors are there which are appearing at least ‘k’ times in the subtree of vertex ‘v’.
For Example:
If N=3, edges=[ [1,2], [1,3] ], color=[1,2,2]
If a query is v=1, k=2 then vertex 2 and vertex 3 have color 2 which is having frequency 2 so this will be included in our answer but vertex 1 has color 1 which is having frequency 1 which is less than 2 so it will not be included in our answer. Hence, the output will be 1. 
```
// 4

// 3 1
// 1 2 2
// 1 2
// 1 3
// 1 2

// 4 1
// 1 1 3 3 
// 1 2
// 1 3
// 3 4
// 1 2

// 4 2
// 1 1 2 2
// 1 3
// 3 2
// 2 4
// 1 2
// 4 2

5 2
1 1 2 1 2
1 2
3 5
4 2
2 5
3 1
4 1
```

```cpp
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define uint unsigned int
#define cut 200
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47

const int mxN = 1e5;

struct fin {
    vector<int> T;
 
    int lastone(int x) {return x&(x^(x-1));}
 
    void put(int pos, int val) {
        for(int i =pos+1; i < T.size(); i +=lastone(i)) T[i] +=val;
        }
 
    int get(int pos) {
        int ret =0;
        for(int i =pos+1; i > 0; i -=lastone(i)) ret +=T[i];
        return ret;}
};
// void countI(int R, vector< pair<int,int> > &I, vector<int> &par, vector< vector<int> > &G) {
//     for(auto it=G[R].begin(); it != G[R].end(); it++){
//       if (*it != par[R]) {
//         I[*it].ff = I[R].ss;
//         I[*it].ss = I[R].ss + 1;
//         countI(*it, I, par, G);
//         I[R].ss += I[*it].ss - I[*it].ff;
//       }
//     }
// }



void countI(int R, vector< pair<int,int> > &I, vector<int> &par, vector< vector<int> > &G) {
    ALL_THE(G[R],it) if(*it != par[R]) {
        I[*it].ff =I[R].ss;
        I[*it].ss =I[R].ss+1;
        countI(*it,I,par,G);
        I[R].ss +=I[*it].ss-I[*it].ff;}
    }


vector<int> queries(int N, int Q, vector<int> &color, vector<vector<int>> &edges, vector<vector<int>> &queries)
{
    vector<int> ans;

    // vector<vector<int>> adj(N);

    // int a, b;
    // for(int i=0; i<edges.size(); ++i){
    //     a=edges[i][0], b=edges[i][1];
    //     --a, --b;
    //     adj[a].push_back(b);
    //     adj[b].push_back(a);
    // }


    // vector<int> par(N, -1);
    // vector<int> seq;
    // par[0]=0;
    // queue<int> q;
    // q.push(0);
    // while(!q.empty()){
    //     a=q.front();
    //     seq.push_back(a);
    //     for(auto it= adj[a].begin(); it !=adj[a].end(); it++){
    //         if(par[*it]==-1){
    //             par[*it]=a;
    //             q.push(*it);
    //         }
    //     }
    //     q.pop();
    // }

    // vector<int> seqI(N);
    // for(int i=0; i<N; ++i) seqI[seq[i]]=i;

    // vector<pair<int, int>> I(N, {0, 1});
    // countI(0, I, par, adj);

    // vector<vector<int>> parE(20, vector<int>(N));
    // parE[0] = par;
    // for (int i = 1; i < 20; i++)
    //   for (int j = 0; j < N; j++)
    //     parE[i][j] = parE[i - 1][parE[i - 1][j]];

    // vector<int> pC(mxN + 1, 0);
    // vector<int> isC(mxN + 1, -1);
    // for (int i = 0; i < N; i++)
    //   pC[C[i]]++;

    // int f = 0;
    // for (int i = 0; i <= mxN; i++)
    //   if (pC[i] > 0)
    //     f++;
    // vector<int> C1;
    // for (int i = 0; i <= mxN; i++)
    //   if (pC[i] >= BLK) {
    //     isC[i] = C1.size();
    //     C1.push_back(i);
    //   }
    
    // vector<vector<int>> S1(C1.size(), vector<int>(N+1, 0));
    // for(int i=0; i<N; i++)
    //      if(isC[C[i]] >= 0) S1[isC[C[i]]][I[i].ff+1]++;
         
    // for(uint i =0; i < C1.size(); i++)
    //     for(int j =0; j < N; j++) S1[i][j+1] +=S1[i][j];
    
    // vector<vector<int>> S2(BLK, vector<int>(N, 0));

    // fin F; F.T.resize(N+1,0);
    // vector<vector<int>> sp(mxN+1);

    // for(int i=N-1; i>=0; i--)
    //   if(pC[C[seq[i]]] < BLK) 
    //     sp[C[seq[i]]].push_back(i);
    
    // set<int> S;
    // for(int i=0; i<=mxN; i++){
    //   for(uint j=0; j<sp[i].size(); j++){
    //     F.put( I[seq[sp[i][j]]].ff, 1);
    //     S.insert(sp[i][j]);
    //   }

    //   while(!S.empty()){
    //     a = seq[*S.rbegin()];
    //     S.erase(--S.end());
    //      b = F.get(I[a].ss-1)-F.get(I[a].ff-1);
    //     S2[b][a]++;

    //     if(F.get(N-1)==b) continue;
    //     int x=a, k=19;
    //     while( k >=0 && x>0){
    //       int y = parE[k][x];
    //       if(F.get(I[y].ss-1)-F.get(I[y].ff-1) != b) k--;
    //       else x=y;
    //     }

    //     S.insert(seqI[par[x]]);
    //     S2[b][par[x]]--;
    //   }

    //   for(uint j=0; j<sp[i].size(); j++) F.put( I[seq[sp[i][j]]].ff, -1);
    // }

    // for(int i=1; i<BLK; i++)
    //   for(int j=N-1; j>0; j--)
    //     S2[i][par[seq[j]]] += S2[i][seq[j]];
    
    // for(int i=0; i<N; i++){
    //   a=0;
    //   for(int j=0; j<BLK; j++)
    //     a += S2[j][i];
    //   S2[0][i] = f-C1.size()-a;
    // }

    // for(int i=0; i<N; i++)
    //   for(int j=0; j<BLK-1; j++)
    //     S2[j+1][i] += S2[j][i];
    
    // for(int i=0; i<queries.size(); ++i){
    //   a=queries[i][0]; b=queries[i][1];
    //   a--;
    //   int res=0;
    //   for(uint i=0; i<C1.size(); i++)
    //     res += (int)(S1[i][ I[a].ss] - S1[i][ I[a].ff] >=b);
      
    //   if(b <= BLK) res += f-C1.size()-S2[b-1][a];
    //   ans.push_back(res);
    // }

    vector<int> C(N);

    for(int i=0; i<N; ++i) C[i]= color[i+1];

    // for(auto i: C) cout << i << " ";
    // cout << endl;
    // return {};

    int a, b;
     vector< vector<int> > G(N);
    for(int i =1; i < N; i++) {
        a=edges[i-1][0];
        b=edges[i-1][1];

        G[--a].push_back(--b);
        G[b].push_back(a);}
 
    vector<int> par(N,-1);
    vector<int> seq;
    par[0] =0;
    queue<int> q;
    q.push(0);
    while(!q.empty()) {
        a =q.front();
        seq.push_back(a);
        ALL_THE(G[a],it) if(par[*it] == -1) {
            par[*it] =a;
            q.push(*it);}
        q.pop();}
    vector<int> seqI(N);
    for(int i =0; i < N; i++) seqI[seq[i]] =i;
 
    // skonvertuj na intervaly
    vector< pair<int,int> > I(N,make_pair(0,1));
    countI(0,I,par,G);
 
    // LCA predratanie
    vector< vector<int> > parE(20,vector<int>(N));
    parE[0] =par;
    for(int i =1; i < 20; i++) for(int j =0; j < N; j++)
        parE[i][j] =parE[i-1][parE[i-1][j]];
 
    // caste farby
    vector<int> pC(100000+tisic,0);
    vector<int> isC(100000+tisic,-1);
    for(int i =0; i < N; i++) pC[C[i]]++;
    int f =0;
    for(int i =0; i <= 100000; i++) if(pC[i] > 0) f++;
    vector<int> C1;
    for(int i =0; i <= 100000; i++) if(pC[i] >= cut) {
        isC[i] =C1.size();
        C1.push_back(i);}
    vector< vector<int > > S1(C1.size(),vector<int>(N+1,0));
    for(int i =0; i < N; i++)
        if(isC[C[i]] >= 0) S1[isC[C[i]]][I[i].ff+1]++;
    for(uint i =0; i < C1.size(); i++)
        for(int j =0; j < N; j++) S1[i][j+1] +=S1[i][j];
 
    // vzacne farby
    vector< vector<int> > S2(cut, vector<int>(N,0));
    fin F; F.T.resize(N+1,0);
    vector< vector<int> > sp(100000+tisic);
    for(int i =N-1; i >= 0; i--) if(pC[C[seq[i]]] < cut) sp[C[seq[i]]].push_back(i);
    // i vyskytov
    set<int> S;
    for(int i =0; i <= 100000; i++) {
        for(uint j =0; j < sp[i].size(); j++) {
            F.put(I[seq[sp[i][j]]].ff,1);
            S.insert(sp[i][j]);}
 
        while(!S.empty()) {
            a =seq[*S.rbegin()];
            S.erase(--S.end());
            b =F.get(I[a].ss-1)-F.get(I[a].ff-1);
            S2[b][a]++;
            // binsearch vrchol po ktory to ide
            if(F.get(N-1) == b) continue;
            int x =a, k =19;
            while(k >= 0 && x > 0) {
                int y =parE[k][x];
                if(F.get(I[y].ss-1)-F.get(I[y].ff-1) != b) k--;
                else x =y;}
            S.insert(seqI[par[x]]);
            S2[b][par[x]]--;}
 
        for(uint j =0; j < sp[i].size(); j++) F.put(I[seq[sp[i][j]]].ff,-1);}
 
    // do otcov
    for(int i =1; i < cut; i++) for(int j =N-1; j > 0; j--)
        S2[i][par[seq[j]]] +=S2[i][seq[j]];
    
    for(int i =0; i < N; i++) {
        a =0;
        for(int j =0; j < cut; j++) a +=S2[j][i];
        S2[0][i] =f-C1.size()-a;}
    // dopln na < i
    for(int i =0; i < N; i++) for(int j =0; j < cut-1; j++)
        S2[j+1][i] +=S2[j][i];
 
    // odpovede
    for(int q =0; q < Q; q++) {
       a=queries[q][0];
       b=queries[q][1];
        a--;
        int res=0;
        // prirataj caste
        for(uint i =0; i < C1.size(); i++) res +=(int)(S1[i][I[a].ss]-S1[i][I[a].ff] >= b);
        // prirataj vzacne
        if(b <= cut) res +=f-C1.size()-S2[b-1][a];
        // cout << res << " ";
        ans.push_back(res);

        }
        // cout << endl;
    return ans;
}
```

## Connect Color
You are given a tree having ‘N’ nodes. Each node ‘v’ has color 'color(v)' and cost 'cost(u)'. You have to answer ‘Q’ queries. In each query, you are given two nodes ‘a’ and ‘b’. For every node ‘c’ and ‘d’ which exist in the path from ‘a’ to ‘b’ you can merge them if the following conditions hold:
‘c’ and ‘d’ should have the same color.
They are successive nodes of the same color on path from ‘a’ to ‘b’.
For merging two nodes ‘c’ and ‘d’ which satisfy the above conditions the cost will be (cost[c]-cost[d])^2. You have to merge every possible color node except the color of the LCA of ‘a’ and ‘b’.
You have to output the sum of the cost of merging every possible nodes ‘c’ and ‘d’.
```cpp
#include <bits/stdc++.h>
const int N = 2005;
//https://www.codechef.com/problems/VLB?tab=statement
vector<vector<int>> anc;
vector<int> adj[N], level;
int LOG, C[N], in[N], out[N], who[2*N], timer, BLK;
bool vis[N];
int res, ans[N], h[N];
int n;

struct query{
    int l, r, lc, id;
    bool operator<(const query& rhs){
        if(l/BLK != rhs.l/BLK){
            return l/BLK < rhs.l/BLK;
        }
        return (l/BLK & 1 ? r < rhs.r : r > rhs.r);
    }
};

void dfs(int u=1, int p=0){
    in[u] = ++timer;
    who[timer]=u;
    for(auto i: adj[u]){
        if(i==p) continue;
        level[i] = level[u]+1;
        anc[i][0] = u;
        dfs(i, u);
    }
    out[u] = ++timer;
    who[timer] = u;
}

int lca(int u, int v){
    if(level[u] < level[v]) swap(u, v);
    int k = level[u]-level[v];
    for(int j=LOG-1; ~j; --j){
        if(k & (1<<j))
            u = anc[u][j];
    }
    if(u==v) return u;
    for(int j=LOG-1; ~j; --j){
        if(anc[u][j] != anc[v][j]){
            u = anc[u][j];
            v = anc[v][j];
        }
    }
    return anc[u][0];
}

void build(){
    LOG = __lg(n) + 1;
    anc.resize(n+1);
    for(auto& i: anc) i.resize(LOG);
    level.resize(n+1);
    dfs();
    for(int j=1; j<LOG; ++j)
        for(int i=1; i<=n; ++i)
            anc[i][j] = anc[anc[i][j-1]][j-1];
}

deque<int> tmp;

int dis(int x, int y){
    return (h[x]-h[y])*(h[x]-h[y]);
}

void upd_left(int u, int c){
    if(C[u] != c) return;
    if(vis[u]){
        tmp.pop_front();
        if(!tmp.empty())
            res -= dis(tmp.front(),u);
    }else{
        if(!tmp.empty())
            res += dis(tmp.front(), u);
        tmp.push_front(u);
    }
    vis[u] ^= 1;
}

void upd_right(int u, int c){
    if(C[u] != c) return;
    if(vis[u]){
        tmp.pop_back();
        if(!tmp.empty())
            res -= dis(tmp.back(), u);
    }else{
        if(!tmp.empty())
            res += dis(tmp.back(), u);
        tmp.push_back(u);
    }
    vis[u] ^= 1;
}

void solve(vector<query>& q, int c){
    tmp.clear();
    int l=q[1].l, r=q[1].l-1;
    for(auto& i: q){
        while(l < i.l) upd_left(who[l++], c);
        while(r < i.r) upd_right(who[++r], c);
        while(l > i.l) upd_left(who[--l], c);
        while(r > i.r) upd_right(who[r--], c);

        if(c != C[i.lc])
            ans[i.id] += res;

    }
}
void clear(){
    timer = 0;
    res = 0;
    memset(vis, 0, sizeof(vis));
    memset(in, 0, sizeof(in));
    memset(out, 0, sizeof(out));
    memset(who, 0, sizeof(who));
    memset(ans, 0, sizeof(ans));
    level.clear();
    for(int i=0; i<N; ++i)
        adj[i].clear();
}
vector<int> connectColor(int _n, int nq, vector<int> &color, vector<int> &cost, vector<vector<int>> &edges, vector<vector<int>> &q){
    n = _n;
    clear();
    
    for (int i = 0; i < edges.size(); ++i) {
      int u = edges[i][0];
      int v = edges[i][1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    for(int i=1; i<=n; ++i){
        C[i] = color[i-1];
        h[i] = cost[i-1];
    }

    build();
    
    vector<query> queries(nq+1);
    for(int i=1; i<=nq; ++i){
        int u = q[i-1][0], v = q[i-1][1];
        if(in[u] > in[v]) swap(u, v);
        queries[i].id = i;
        queries[i].lc = lca(u, v);
        if(queries[i].lc == u){
            queries[i].l = in[u];
        }else{
            queries[i].l = out[u];
        }
        queries[i].r = in[v];
    }
    

    BLK = (int) sqrt(timer)+1;
    sort(queries.begin()+1, queries.end());
    for(int c=0; c<=10; ++c){
        res = 0;
        solve(queries, c);
    }
        
    
    vector<int> ret(nq);

    for(int i=1; i<=nq; ++i){
        ret[i-1] = ans[i];
    }
    return ret;

}
```

## Catch Pokemon
There are ‘N’ cities in Pokeland, and they are connected by ‘N-1’ roads. It is possible to reach from any city to any other city and there is a unique path between each pair of cities.
Each city has one Pokemon represented by an integer between 1 and 10^9. In each city. Given queries in the form of pairs of cities ‘U’ and ‘V’, find the number of Pokemon Ash catches while traveling from city ‘U’ to ‘V’. If he already has a Pokemon ‘X’ and he comes across it again, he does NOT catch it.
Note: Each query is independent, that is, he starts each query with zero Pokemon.
```cpp
//no of distinct values in the path btw 2 nodes u, v 
#include <bits/stdc++.h>

const int mxN = 1e4+5, mxM = 1e5+5;
const int LOG = 19;

int a[mxN], level[mxN], anc[LOG][mxN], val[mxN], ans[mxM];
int d[mxN], l[mxN], r[mxN];
int BLK[mxN<<1], ID[mxN<<1];
bool vis[mxN];
vector<int> adj[mxN];
int N, M, cur;

struct query{
    int id, l, r, lc;
    bool operator<(const query& rhs){
        return (BLK[l]==BLK[rhs.l]) ? (r<rhs.r) : (BLK[l]<BLK[rhs.l]);
    }
} Q[mxM];

void dfs(int u, int p){
    l[u] = ++cur;
    ID[cur] = u;
    
    for(int i=1; i<LOG; ++i)
        anc[i][u] = anc[i-1][anc[i-1][u]];

    for(int i=0; i<adj[u].size(); ++i){
        int v = adj[u][i];
        if(v==p) continue;
        level[v]=level[u]+1;
        anc[0][v]=u;
        dfs(v, u);
    }
    r[u] = ++cur;
    ID[cur] = u;
}
int lca(int u, int v){
    if(level[u] > level[v]) swap(u, v);

    for(int i=LOG-1; ~i; --i){
        if(level[v]-(1<<i) >= level[u])
            v = anc[i][v];
    }
    if(u==v) return u;
    for(int i=LOG-1; ~i; --i){
        if(anc[i][u] != anc[i][v]){
            u = anc[i][u];
            v = anc[i][v];
        }
    }
    return anc[0][u];
}
inline void check(int x, int& res){
    if( vis[x] && (--val[a[x]]==0)) res--;
    else if( !vis[x] && (val[a[x]]++ ==0)) res++;
    vis[x] ^=1;
}
void solve(){
     int curL = Q[0].l, curR = Q[0].l - 1, res = 0;

    for (int i = 0; i < M; i++)
    {
        while (curL < Q[i].l) check(ID[curL++], res);

        while (curL > Q[i].l) check(ID[--curL], res);
        
        while (curR < Q[i].r) check(ID[++curR], res);

        while (curR > Q[i].r) check(ID[curR--], res);

        int u = ID[curL], v = ID[curR];

        // If LCA not part of the range
        if (Q[i].lc != u and Q[i].lc != v)
            check(Q[i].lc, res);

        ans[Q[i].id] = res;

        if (Q[i].lc != u && Q[i].lc != v)
            check(Q[i].lc, res);
    }
}
vector<int> countPokemon(int n, vector<pair<int,int>> edges, vector<int> poke, int nq, vector<pair<int,int>> q){
    cur = 0;
    memset(vis, 0, sizeof(vis));
    memset(val, 0, sizeof(val));
    for(int i=1; i<=N; ++i)
        adj[i].clear();

    for(auto i: edges){
        adj[i.first].push_back(i.second);
        adj[i.second].push_back(i.first);
    }

    N = n;
    M = q.size();
    int c = 0;
    map<int, int> mp;

    for(int i=0; i<n; ++i) mp[poke[i]]++;
    for(auto& i: mp) i.second = c++;
    for(int i=1; i<=n; ++i) a[i] = mp[poke[i-1]];

    anc[0][1]=1;
    dfs(1, -1);
    int sz = sqrt(cur);
    for(int i=1; i<=cur; i++)
        BLK[i] = (i-1)/sz+1;
    
    for(int i=0; i<M; ++i){
        int u=q[i].first, v=q[i].second;
        Q[i].lc = lca(u, v);
        if(l[u] > l[v])
            swap(u, v);
        if(Q[i].lc == u)
            Q[i].l = l[u], Q[i].r = l[v];
        else
            Q[i].l = r[u], Q[i].r = l[v];
        Q[i].id = i;
    }

    sort(Q, Q+M);
    solve();

    vector<int> ret(M);
    for(int i=0; i<M; ++i)
        ret[i] = ans[i];
    return ret;
    
}
```
## Tree and Queries $$$
You are given a tree with ‘N’ vertex having ‘N’ - 1 edge. Each edge has a weight ‘W’ associated with it. You are also given an array ‘QUERY’ of size ‘Q’, where each query consists of two nodes ‘U’ and ‘V’ and an integer ‘K’. Your task is to print the XOR of all the edges present between the nodes ‘U’, and ‘V’ and have their weight smaller than or equal to ‘K’.
```cpp
/*
Time complexity: O(N * (log(N)) + Q * (log(Q) + log(N)))
Space complexity: O(N)
Where 'N' is the number of vertices and 'Q' is the number of queries.
*/
#include <unordered_map>
#include <algorithm>
// Function to add edge to the tree.
void addEdge(unordered_map<int, vector<vector<int>>> &tree, vector<int> edge) {
int u = edge[0];
int v = edge[1];
int w = edge[2];
vector<int> tempNode;
tempNode.push_back(v);
tempNode.push_back(w);
tree[u].push_back(tempNode);
tempNode[0] = u;
tree[v].push_back(tempNode);
}
// Function to get the result.
int get(vector<int> &bit, int x) {
// To store the answer.
int ans = 0;
// Find the answer.
while(x > 0) {
ans ^= bit[x];
x -= x & (-x);
}
return ans;
}
// Function to add nodes.
void add(vector<int> &bit, int n, int x, int v) {
// Update bit.
while(x <= n) {
bit[x] ^= v;
x += x & (-x);
}
}
// DFS function.
void dfs(unordered_map<int, vector<vector<int>>> &tree, int u, int parent,
int &timer, vector<int> &st, vector<int> &en) {
// Update timer.
st[u] = ++timer;
for(int i = 0; i < tree[u].size(); ++i) {
// Check if not parent.
if(tree[u][i][0] != parent) {
dfs(tree, tree[u][i][0], u, timer, st, en);
}
}
// Update end timer.
en[u] = timer;
}
vector<int> XORquery(int n, vector<vector<int>> &edges,
int q, vector<vector<int>> &query) {
// Create tree.
unordered_map<int, vector<vector<int>>> tree;
for(int i = 0; i < edges.size(); ++i) {
addEdge(tree, edges[i]);
}
int timer = 0;
// To store timer for entering and exiting the node.
vector<int> st(100010);
vector<int> en(100010);
// Call dfs function.
dfs(tree, 1, -1, timer, st, en);
// To store nodes of the queries.
vector<int> node1(100010);
vector<int> node2(100010);
// To store queries in sorted manner.
vector<vector<int>> sortQ;
for(int i = 0; i < n - 1; ++i) {
// Check which node is greater.
if(st[edges[i][0]] < st[edges[i][1]]) {
swap(edges[i][0], edges[i][1]);
}
vector<int> temp;
temp.push_back(edges[i][2]);
temp.push_back(-edges[i][0]);
// Append in sortQ.
sortQ.push_back(temp);
}
// Store queries.
for(int i = 1; i <= q; ++i) {
// Store nodes.
node1[i] = query[i - 1][0];
node2[i] = query[i - 1][1];
vector<int> temp;
temp.push_back(query[i - 1][2]);
temp.push_back(i);
// Append in sortQ.
sortQ.push_back(temp);
}
// Sort the array.
sort(sortQ.begin(), sortQ.end());
// To store the BIT.
vector<int> bit(100010);
// To store the query temporary results.
vector<int> tempRes(100010);
for(int i = 0; i < sortQ.size(); ++i) {
// Check condition.
if(sortQ[i][1] < 0) {
int node = -sortQ[i][1];
// Add the node.
add(bit, n, st[node], sortQ[i][0]);
add(bit, n, en[node] + 1, sortQ[i][0]);
}
// Answer the query.
else {
// Get index.
int idx = sortQ[i][1];
// Store the result.
tempRes[idx] = get(bit, st[node1[idx]]) ^ get(bit, st[node2[idx]]);
}
}
// To store query results.
vector<int> res;
for(int i = 1; i <= q; ++i) {
res.push_back(tempRes[i]);
}
return res;
}
```
## Tree Distance-1
Ninjaland is the beautiful empire comprised of ‘N’ kingdoms connected by N-1 bidirectional roads such that no cycle is formed. While exploring Ninjaland, Ninja thought about the farthest kingdom from the current kingdom he can travel. Can you help Ninja to find the distance of the farthest kingdom from the ith kingdom?
You are given a tree having ‘N’ nodes and ‘N’-1 edges. Your task is to find ‘ARR’ array where ARR[i] denotes the distance of the farthest node from node i.
```cpp


const int mxN = 1e6+5;

vector<int> adj[mxN];
int d1[mxN], d2[mxN];


void clean(){
    for(int i=0; i<mxN; ++i){
        adj[i].clear();
        d1[i]=d2[i]=0;

    }
}

void dfs1(int u, int p){
    for(int v: adj[u]){
        if( v != p){
            dfs1(v, u);
            d1[u] = max(d1[u], d1[v]+1);
        }
    }
}

void dfs2(int u, int p){
    int mx1 = -1, mx2 = -1;
    for(int v: adj[u]){
        if(v != p){
            if(d1[v] >=mx1){
                mx2 = mx1;
                mx1 = d1[v];
            }else if(d1[v] > mx2){
                mx2 = d1[v];
            }
        }
    }

    for(int v: adj[u]){
        if( v != p){
            int use = mx1;
            if( mx1 == d1[v])
                use = mx2;
            d2[v] = max(d2[u]+1, use+2);
            
            dfs2(v, u);
        }
    }
}

void calc_d1(int u, int p){
    d1[u] = 1+d1[p];
    for(int i=0; i<adj[u].size(); ++i){
        if(adj[u][i] != p){
            calc_d1(adj[u][i], u);
        }
    }
}


vector<int> treeDistance(int n, vector<vector<int>> &edges)
{
    clean();

    for(int i=0; i<edges.size(); ++i){
        int u = edges[i][0], v = edges[i][1];
        ++u; ++v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs1(1, 0); 

    dfs2(1, 0);

    vector<int> ans;
    for(int i=1; i<=n; ++i){
        ans.push_back(max(d1[i], d2[i]));
    }

    return ans;
}
```
