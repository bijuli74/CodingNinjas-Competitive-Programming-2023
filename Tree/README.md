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
