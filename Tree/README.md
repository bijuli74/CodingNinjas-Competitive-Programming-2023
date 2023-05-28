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
