## BFS Traversal
Given an undirected graph G(V, E), print its BFS traversal.
Here you need to consider that you need to print BFS path starting from vertex 0 only.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Note :
1. Take graph input in the adjacency matrix.
2. Handle for Disconnected Graphs as well

```cpp
#include<bits/stdc++.h>
using namespace std;

const int mxN = 1005;
vector<int> adj[mxN];
int vis[mxN];

void bfs(int cur){
  queue<int> q;
  q.push(cur);
  vis[cur] = 1;
  while (q.size()) {
    int u = q.front();
    cout << u << " ";
    q.pop();
    for (int v : adj[u]) {
      if (!vis[v]) {
        vis[v] = 1;
        q.push(v);
      }
    }
  }
}
int main(){
    int n, m; cin>>n>>m;

    for(int i=0; i<m; ++i){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=0; i<n; ++i){
        sort(adj[i].begin(), adj[i].end());
    }

    for(int i=0; i<n; ++i){
        if(!vis[i])
            bfs(i);
    }

   
    return 0;
}
```
## Has Path
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), check if there exists any path between them or not. Print true or false.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
```cpp
#include<bits/stdc++.h>
using namespace std;

const int mxN = 1005;
vector<int> adj[mxN];
int vis[mxN];

void dfs(int u){
    vis[u]=1;
    for(int v: adj[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
    // return;
}
void solve(){
    int n, m;
    cin>>n>>m;
    for(int i=0; i<m; ++i){
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int st, ed;
    cin>>st>>ed;

    dfs(st);
   if(vis[ed]) cout<<"true\n";
   else cout<<"false\n";

}
int main(){
    int t; cin>>t;
    while(t--){
      for (int i = 0; i < mxN; ++i) {
        adj[i].clear();
        vis[i] = 0;
      }

        solve();
    }
    
    
    return 0;
}
```
## Detect Cycle in a Directed Graph
Given a directed graph, check whether the graph contains a cycle or not. Your function should return true if the given graph contains at least one cycle, else return false.
```cpp
bool dfs(int u, vector<int>& vis, vector<int>* adj){
	vis[u]=1;
	for(int v: adj[u]){
		if(vis[v]==1)
			return 1;
		if(vis[v]==0 && dfs(v, vis, adj))
			return 1;
	}
	vis[u]=2;
	return 0;
}


bool isCyclic(vector<vector<int>>& edges, int v, int e)
{
	vector<int> adj[v+1];
	for(int i=0; i<e; ++i)
		adj[edges[i][0]].push_back(edges[i][1]);
	//vis/color 0 not vis, 1 now visiting, 2 finish vis
	vector<int> vis(v, 0);
	for(int i=0; i<v; ++i){
		if(vis[i]==0 && dfs(i, vis, adj))
			return 1;
	}
	return 0;
}
```
## Topological Sorting
Given a DAG(direct acyclic graph), print Topological Sorting of a given graph
```cpp
#include <bits/stdc++.h>
using namespace std;
//Topsort BFS method
void topsort(int n, vector<int>& ind, vector<int>* adj, vector<int>& ans){
   queue<int> q;
   for(int i=0; i<n; ++i)
      if(ind[i]==0)
         q.push(i);
   
   while(!q.empty()){
      int u = q.front();
      q.pop();
      ans.push_back(u);
      for(int v: adj[u]){
         --ind[v];
         if(ind[v]==0)
            q.push(v);
      }
   }
}
vector<int> topologicalSort(vector<vector<int>> &g, int m, int n) {
   vector<int> adj[n];
   vector<int> ind(n, 0), ans;

   for (int i = 0; i < m; ++i) {
     int a = g[i][0], b = g[i][1];
     adj[a].push_back(b);
     ind[b]++;
   }

   topsort(n, ind, adj, ans);
   return ans;
}
```

## Islands
An island is a small piece of land surrounded by water . A group of islands is said to be connected if we can reach from any given island to any other island in the same group . Given N islands (numbered from 0 to N - 1) and M pair of integers (u and v) denoting island, u is connected to island v and vice versa. Can you count the number of connected groups of islands?
```cpp
#include<bits/stdc++.h>
using namespace std;

const int mxN = 1005;
vector<int> adj[mxN];
int vis[mxN];
int ans;

void dfs(int u){
    vis[u]=1;
    for(int v: adj[u]){
        if(!vis[v])
            dfs(v);
    }
}
void solve(){
    int n, m; cin>>n>>m;
    for(int i=0; i<m; ++i){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i=0; i<n; ++i){
        if(!vis[i]){
            dfs(i);
            ++ans;
        }
    }
    cout<<ans<<'\n';
    return;
}
int main(){
    int t; cin>>t;
    while(t--){
        ans=0;
        for(int i=0; i<mxN; ++i){
            adj[i].clear();
            vis[i]=0;
        }
        solve();
    }
    return 0;
}
```
