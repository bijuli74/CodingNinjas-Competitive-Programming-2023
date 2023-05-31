## Bipartite Graph
Given a graph, check whether the graph is bipartite or not. Your function should return true if the given graph's vertices can be divided into two independent sets, ‘U’ and ‘V’ such that every edge (‘u’, ‘v’) either connects a vertex from ‘U’ to ‘V’ or a vertex from ‘V’ to ‘U’.
You are given a 2D array ‘edges’ which contains 0 and 1, where ‘edges[i][j]’ = 1 denotes a bi-directional edge from ‘i’ to ‘j’.
Note:
If edges[i][j] = 1, that implies there is a bi-directional edge between ‘i’ and ‘j’, that means there exists both edges from ‘i’ to ‘j’ and to ‘j’ to ‘i’.
```cpp
#include <bits/stdc++.h>
using namespace std;

bool isGraphBirpatite(vector<vector<int>> &edges) {
	int n = edges.size()+1;
	vector<int> adj[n], c(n, -1);
	// vector<bool> vis(n);
	bool ok=1;
	for(int i=0; i<n-1; ++i){
		for(int j=i; j<n-1; ++j){
			if(edges[i][j]){
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}

	queue<int> q;
	for(int i=0; i<n; ++i){
		if(c[i]==-1){
			q.push(i);
			c[i]=0;
			while(!q.empty()){
				int u=q.front(); q.pop();
				for(int v: adj[u]){
					if(c[v]==-1){
						c[v]=c[u]^1;
						q.push(v);
					}else{
						ok &= c[v] != c[u];
					}
				}
			}
		}
	}

	return ok;
}
```
## Strongly Connected Components (Tarjan’s Algorithm)
You are given an unweighted directed graph of 'V' vertices and 'E' edges. Your task is to print all the strongly connected components (SCCs) present in the graph.
Input format:
The very first line of input contains an integer ‘T’ denoting the number of test cases.

The first line of every test case contains two space-separated integers ‘V’ and ‘E’ denoting the number of vertices and the number of edges present in the graph. 

The next ‘E’ lines contain two space-separated integers ‘a’ and ‘b’ denoting a directed edge from vertex ‘a’ to ‘b’.
Note:
Use zero-based indexing for the vertices
```cpp
#include <bits/stdc++.h>

const int mxN = 2005;
vector<int> adj[mxN];
int low[mxN], in[mxN];
bool vis[mxN], onSt[mxN];
int id;
stack<int> st;

void dfs(int u, vector<vector<int>>& ans){
    in[u] = low[u] = id++;
    vis[u] = onSt[u] = 1;
    st.push(u);
    for(int v: adj[u]){
        if(vis[v]){
            if(onSt[v]) low[u] = min(low[u], in[v]);
        }else{
            dfs(v, ans);
            low[u] = min(low[u], low[v]);
        }
    }
    if(in[u] == low[u]){
        vector<int> cc;
        while (st.top() != u) {
            // cout << st.top() << " ";
            cc.push_back(st.top());
            onSt[st.top()] = 0;
            st.pop();
        }
        // cout << st.top() <<" ";
        cc.push_back(st.top());
        onSt[st.top()] = 0;
        st.pop();

        ans.push_back(cc);
        // cout << endl;
    }
}
void clear(){
    for(int i=0; i<mxN; ++i){
        adj[i].clear();
        vis[i]=onSt[i]=0;
    }
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges){
    clear();
    vector<vector<int>> ans;
    for(int i=0; i<edges.size(); ++i){
        int a = edges[i][0], b=edges[i][1];
        adj[a].push_back(b);
    }

    for(int i=0; i<n; ++i){
        if(!vis[i])
            dfs(i, ans);
    }

    return ans;
}
```
## Bridges In A Graph
Given an undirected graph of V vertices and E edges. Your task is to find all the bridges in the given undirected graph. A bridge in any graph is defined as an edge which, when removed, makes the graph disconnected (or more precisely, increases the number of connected components in the graph).
```cpp
const int mxN = 1e3;

vector<int> adj[mxN+1];
int in[mxN+1], low[mxN+1];
bool vis[mxN+1];
int timer;
vector<vector<int>> ans;

void dfs(int u=0, int p=-1){
    in[u] = low[u] = timer++;
    vis[u] = 1;

    for(int v: adj[u]){
        if(v==p) continue;
        if(!vis[v]){
            dfs(v, u);
            if(low[v] > in[u])
              ans.push_back({u, v});
            low[u] = min(low[u], low[v]);
        }
        else{
            low[u] = min(low[u], in[v]);
        }
    }
}

void clean(){
    for(int i=0; i<mxN; ++i){
        adj[i].clear();
        in[i]=low[i]=vis[i]=0;
    }
    ans.clear();
    timer=0;
}
vector<vector<int>> findBridges(vector<vector<int>> &edges, int n, int m) {
    clean();
    for(int i=0; i<m;++i){
        int a = edges[i][0], b = edges[i][1];
        adj[a].push_back(b);
        adj[b].push_back(a);

    }
    dfs(0, -1);

    return ans;

}
```
## Articulation point
You are given an undirected unweighted graph and you are supposed to find all articulation in the graph.
```cpp
#include<bits/stdc++.h>
using namespace std;

const int mxN = 1e4+5;
vector<int> adj[mxN];
int par[mxN], art[mxN], low[mxN], num[mxN], ch[mxN], cnt;

void articulation(int u){
    low[u] = num[u] = ++cnt;
    for(int v: adj[u]){
        if(!num[v]){
            par[v] = u; ch[u]++;
            articulation(v);
            if(low[v] >= num[u]) art[u] = 1;
            // if (low[v] >= num[u]) { // u-v is a bridge}
            low[u] = min(low[u], low[v]);
        }
        else if(v != par[u]) low[u] = min(low[u], num[v]);
    }
}
void clear(){
    for(int i=0; i<mxN; ++i){
        adj[i].clear();
        par[i]=art[i]=low[i]=num[i]=ch[i]=0;
    }
    cnt=0;

}
int main(){
    
    int t; cin>>t;
    while(t--){
        clear();
        int n, m; 
        cin>>n>>m;
        for(int i=0; i<m; ++i){
            int a, b; 
            cin>>a>>b, --a, --b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for(int i=0; i<n; ++i){
            if(!num[i])
                articulation(i), art[i] = ch[i]>1;
        }
        for(int i=0; i<n; ++i)
            if(art[i]) cout<<i+1<<" ";
        cout << "\n";
    }
    return 0;
}
```
## Critical Connection $
You are given a network with ‘N’ system nodes [0 to N - 1] and ‘M’ connection. Your task is to find out all critical connections in a given network.
Note: A connection between node ‘u’ and ‘v’ is said to be a critical connection, if after removal of a connection ‘u’ - ‘v’, there is no connection between node ‘u’ and ‘v’ and the network goes down.
```cpp
const int mxN = 1e6+1;
vector<int> adj[mxN];
int in[mxN], low[mxN];
bool vis[mxN];
int timer;
vector<vector<int>> ans;

void clear(){
	for(int i=0; i<mxN; ++i){
		adj[i].clear();
		in[i]=low[i]=vis[i]=0;
	}
	timer=0;
	ans.clear();
}

void dfs(int u, int p=-1){
	in[u] = low[u] = timer++;
	vis[u] = 1;

	for(int v: adj[u]){
		if(v==p) continue;
		if(!vis[v]){
			dfs(v, u);
			if(low[v]>in[u]) ans.push_back({u, v});
			low[u] = min(low[u], low[v]);
		}else{
			low[u] = min(low[u], in[v]);
		}
	}
}
vector< vector<int> > criticalConnections(int n, vector<vector<int>>& edges) 
{
	clear();
	for(int i=0; i<edges.size(); ++i){
		int a=edges[i][0], b=edges[i][1];
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i=0; i<n; ++i){
		dfs(i);
	}
	return ans;
}
```
## City And Bridges
Ninja got a map in his hand with ‘N’ cities numbered 1 to ‘N’, connected with bridges. He asks his sister to delete some cities from the map.
He will ask his sister a ‘Q’ query. Each query is denoted by an integer ‘X’, meaning that he will delete the city ‘X’. He wants to see if the new map obtained after deleting the city node will have more connected components than the previous map.
He wants to build the program for the queries given by his sister for the above condition.
Ninja knows that you are a very good programmer and can help him in writing the code for the above. Help Ninja!
Note:
A connected component in the map is the maximum subset of cities that are connected i.e we can go from one city to any other in that subset.
```cpp
#include <unordered_set>

void articulation(vector<vector<int>> &arr, int u, int par, unordered_set<int> &art, vector<bool> &vis, int &tme, vector<int> & low, vector<int> & discovery)
{
    
    vis[u] = true;
    
    ++tme;
    
    int children = 0;
    
    // Initialize discovery time and low value.
    low[u] = discovery[u] = tme;
    
    // Go through all vertices aadjacent to u.
    for(int i = 0; i < arr[u].size(); i++) 
    {
        
        // 'adjacent' is current adjacent of u
        int adjacent = arr[u][i];
        if(adjacent == par) 
        {
            continue;
        }
        
        if(!vis[adjacent]) 
        {
            ++children;
            articulation(arr, adjacent, u, art, vis, tme, low, discovery);
            
            /*
                Check if the subtree rooted with 'adjacent' has a connection to
                one of the ancestors of u.
            */
            low[u] = min(low[u], low[adjacent]);
            
            // u is an articulation point in following cases.
            // (1) u is root of DFS tree and has two or more chilren.
            if(par == -1 and children > 1) 
            {
                art.insert(u);
            }
            
            /*
                (2) If u is not root and low value of
                one of its child is more than discovery value of u.
            */
            if(par != -1 and low[adjacent] >= discovery[u]) 
            {
                art.insert(u);
            }
        }
        
        // Update low value of u for parent function calls.
        else
        {
            low[u] = min(low[u], discovery[adjacent]);
        }
    }
}

void cityAndBridges(vector<vector<int>> &arr, int n, int m, int q, vector<int> &query) 
{
    unordered_set<int> art;
    int tme = 0;
    vector<bool> vis(n, false);
    vector<int> low(n, -1);
    vector<int> discovery(n, -1);

    for(int i = 0; i < n; i++) 
    {
        if(!vis[i])
        {
            articulation(arr, i, -1, art, vis, tme, low, discovery);
        }
    }
    
    for(int i = 0; i < q; i++) 
    {
        if(art.find(query[i]) != art.end())
        {
            cout << "Yes" << " ";
        }
        
        else
        {
            cout << "No" << " ";
        }
    }
    
}
```
## Connected Horses
You all must be familiar with the chess-board having 8 x 8 squares of alternate black and white cells. Well, here we have for you a similar N x M size board with similar arrangement of black and white cells.
A few of these cells have Horses placed over them. Each horse is unique. Now these horses are not the usual horses which could jump to any of the 8 positions they usually jump in. They can move only if there is another horse on one of the 8-positions that it can go to usually and then both the horses will swap their positions. This swapping can happen infinitely times.
A photographer was assigned to take a picture of all the different ways that the horses occupy the board! Given the state of the board, calculate answer. Since this answer may be quite large, calculate in modulo 10^9+7.
```cpp
#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int M = 1e9+7;

ll factorial(ll n){
    if(n==0 || n==1) return 1;
    ll cur = factorial(n-1);
    ll ans = n*cur;
    return ans%M;
}
void dfs(vector<vector<int>>& g, vector<vector<bool>>& vis, int x, int y, vector<pair<int, int>>& cc, int n, int m){
     int dir[8][2]={{-2,1},{2,-1},{-1,-2},{-1,2},{1,2},{1,-2},{-2,-1},{2,1}};
     cc.push_back({x, y});
     vis[x][y]=1;

     for(int k=0; k<8; ++k){
         int nx= (x+dir[k][0]);
         int ny = (y+dir[k][1]);
         if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] && g[nx][ny]==1){
             dfs(g, vis, nx, ny, cc, n, m);
         }
     }
}
void solve(){
    int n, m, q;
    cin >> n >> m >> q;
   vector<vector<int>> g(n, vector<int>(m, 0));

    for(int i=0; i<q; ++i){
        int x, y;
        cin >> x >> y;
        g[(x-1)][(y-1)]=1;
    }

   vector<vector<bool>> vis(n, vector<bool>(m, false));

    ll res=1;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(g[i][j]==1 && !vis[i][j]){
                vector<pair<int, int>> cc;
                dfs(g, vis, i, j, cc, n, m);
                ll ans = factorial(cc.size());
                res = (((res%M)*(ans%M))%M);
            }
        }
    }

    cout << res << "\n";
}

int main(){
    int t; cin>>t;

    while(t--){
        solve();
    }
    return 0;
}
```
## Ninja and the Bipartiteness
A tree is a connected acyclic graph. A bipartite graph is a graph, whose vertices can be partitioned into 2 sets in such a way, that for each edge (u, v) that belongs to the graph, u and v belong to different sets.
Ninja has given a tree consisting of n nodes and asked to add edges to it in such a way, that the graph is still bipartite. Besides, after adding these edges the graph should be simple (doesn't contain loops or multiple edges). What is the maximum number of edges Ninja can add?
A loop is an edge, which connects a node with itself. The graph doesn't contain multiple edges when for each pair of nodes there is no more than one edge between them. A cycle and a loop aren't the same.
Ninja called you for help as you are his only friend. Help him to solve the problem.
Example :
If the input is:
'N' = 3
Edges=[ [1,2] , [1,3] ]

Output will be: "0"

As the only edge that can be added in such a way, that graph won't contain loops or multiple edges is (2, 3), but adding this edge will make the graph non-bipartite so the answer is 0.
```cpp
const int mxN = 1e4+1;

vector<int> adj[mxN];
int vis[mxN], color[2];

void dfs(int u, int cur_col){
    int nxt_col = (cur_col+1)%2;
    if(!vis[u]){
        color[cur_col]++;
        vis[u]=1;

        for(int v: adj[u]){
            dfs(v, nxt_col);
        }
    }
}

void clear(){
    for(int i=0; i<mxN; ++i){
        adj[i].clear();
        vis[i]=0;
    }
    color[0]=color[1]=color[2]=0;
}
int bipartite(vector<vector<int>>& edges, int n) {
    clear();

    for(int i=0; i<edges.size(); ++i){
        int a=edges[i][0], b=edges[i][1];
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);

    int ans = color[0]*color[1]-(n-1);
    return ans;
}
```
## Checkpoints $$
You have a city consisting of ‘N’ junctions and ‘M’ one-way roads between the junctions ‘U’ and ‘V’. You want to build some police station in some junctions possibly all.
A station at junction ‘i’ can only protect junction ‘j’ if either ‘i = j’ or the police patrol car can go to ‘j’ from ‘i’ and then come back to ‘i’.
Building the police station at junction ‘i’ costs ‘C[i]’ money where ‘C’ is an array of integer numbers. You have to determine the minimum cost of protecting all junctions. Also, you have to ensure security at a minimum price and in addition to the minimum number of stations. Two ways are different if any of the junctions contain a station in one of them and do not contain one in the other.
EXAMPLE:
```
Input: 
'N' = 3, ‘M’ = 3
‘C’ = [1, 2, 3]
Edges =  [[1, 2],
                [2, 3],
                [3, 2]]

Output: 3 1
```
```cpp
#include<bits/stdc++.h>
using namespace std;

const int mxN = 1e5+5;
const int M = 1e9+7;

vector<int> adj[mxN];
int low[mxN], in[mxN], st[mxN], comp[mxN];
int mn[mxN], cnt[mxN];
bool inSt[mxN];
int timer, ncomps, sz;

void tarjan(int u){
    low[u] = in[u] = ++timer;
    st[sz++]=u;
    inSt[u]=1;

    for(int v: adj[u]){
        if(in[v]==-1){
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if(inSt[v]){
            low[u] = min(low[u], in[v]);
        }
    }

    if(in[u] == low[u]){
        ncomps++;
        int v=-1;
        do{
            v = st[--sz];
            inSt[v] = 0;
            comp[v] = ncomps;
        }while(u!=v);
    }
}
void scc(int n){
    ncomps=timer=sz=0;
    memset(in, -1, sizeof(in));
    memset(low, 0, sizeof(low));
    memset(st, 0, sizeof(st));
    memset(comp, 0, sizeof(comp));
    memset(inSt, false, sizeof(inSt));

    for(int i=0; i<n; ++i){
        if(in[i]==-1)
            tarjan(i);
    }

}

void clear(){
    for(int i=0; i<mxN; ++i){
        adj[i].clear();
        // low[i]=tin[i]=vis[i]=scc[i]=0;
    }
    // c=0, d=0;
}

pair<int,int> checkpoints(int n, int m, vector<int> &cost, vector<pair<int,int>> &edges){
    clear();
    for(int i=0; i<m; ++i){
        int a=edges[i].first, b=edges[i].second;
        --a, --b;
        adj[a].push_back(b);
 
    }

    scc(n);
    for(int i=1; i<=ncomps; ++i) mn[i] = 2e9;

    for(int i=0; i<n; ++i){
        int c = comp[i];
        int w = cost[i];
        if(mn[c] > w) mn[c]=w, cnt[c]=1;
        else if(mn[c]==w) cnt[c]++;
    }

    long long ans=0, ways=1;
    for(int i=1; i<=ncomps; ++i){
        ans += mn[i];
        ways *= (long long)cnt[i];
        ways %= M;                     // needed to use Mod even when it wasn't mentioned 

    }
    return { (int)ans, (int)ways };
}
```
## Fill the Matrix
A matrix B (consisting of integers) of dimension N × N is said to be good if there exists an array A (consisting of integers) such that B[i][j] = |A[i] - A[j]|, where |x| denotes absolute value of integer x.
You are given a partially filled matrix B of dimension N × N. Q of the entries of this matrix are filled by either 0 or 1. You have to identify whether it is possible to fill the remaining entries of matrix B (the entries can be filled by any integer, not necessarily by 0 or 1) such that the resulting fully filled matrix B is good.
```cpp
#include<bits/stdc++.h>
using namespace std;

const int mxN=2e5;

int node[mxN], _next[mxN], to[mxN], w[mxN], e;
int vis[mxN], parity[mxN];
int n, q, ans;

void ins(int x, int y, int v){
    e++;
    _next[e] = node[x];
    node[x] = e;
    to[e] = y;
    w[e] = v;
}
void dfs(int u){
    vis[u]=1;
    for(int v=node[u]; v; v=_next[v]){
        if(!vis[to[v]]){
            parity[to[v]] = parity[u]^w[v];
            dfs(to[v]);
        }else if(parity[to[v]] ^ parity[u] ^ w[v]) ans=0;
    }
}
void clear(){
    for(int i=1; i<=n; ++i) node[i] = vis[i] = parity[i] = 0;
    for(int i=1; i<=e; ++i) _next[i] = to[i] = w[i] = 0;
    e=0, ans=1;
}
void solve(){
    int i, j, v;
    clear();
    cin >> n >> q;
    while(q--){
        cin >> i >> j >> v;
        ins(i, j, v);
        ins(j, i, v);

    }
    for(int i=1; i<=n; ++i)
        if(!vis[i]) 
            dfs(i);
    
    cout << (ans ? "yes\n" : "no\n");
    
}
int main(){
    
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
```
## Ninja And Fruits
Ninja wants to eat some fruits but he has an appetite for only two fruits. There are a total of N fruits where each fruit is labelled with a unique id from 0 to N-1. The fruits are placed in a few boxes and you are given the pairs of fruit ids, where each pair is made up of fruits which are placed in the same box.
Ninja wants to eat only those fruits which are placed in different boxes. Can you find the number of ways Ninja can select two fruits which belong to different boxes?
Example :
Let the number of fruits be 4 i.e. N = 4 and the list of pair of fruit ids be { [0, 2], [2, 3] }. From the given list we can say that there are 2 boxes of fruits: [0, 2, 3] and [1]. Therefore Ninja can select two fruits which belong to different boxes as [1, 0], [1, 2], and [1, 3] i.e. a total of 3 ways.
```cpp
void dfs(int u, vector<vector<int>>& adj, vector<bool>& vis, int& s){
	if(vis[u]) return;

	vis[u]=1;
	++s;
	for(int v: adj[u]){
		dfs(v, adj, vis, s);
	}
	return;
}

int countWays(int n, vector<vector<int>> &ids)
{
	int m = ids.size();
	vector<vector<int>> adj(n);
	for(int i=0; i<m; ++i){
		int a=ids[i][0], b=ids[i][1];
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int c=0;
	vector<bool> vis(n, 0);
	vector<int> comp_sz;

	for(int i=0; i<n; ++i){
		if(!vis[i]){
			int s=0;
			dfs(i, adj, vis, s);
			comp_sz.push_back(s);
			++c;
		}
	}
	int ans = (n*(n-1))/2;
	for(int i=0; i<c; ++i)
		ans -= (comp_sz[i]*(comp_sz[i]-1))/2;
	
	return ans;
}
```
## Edges In MST
Your task is to determine the following for each edge of the given graph: whether it
is either included in any MST, included at least in one MST, or not included in any
MST.
```cpp
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;

struct Edge{
	int a , b , w;
	int index;
};

//list of edges
Edge edges[N+1];

//for dsu
int _par[N+1];

//to store result
int result[N+1];

//for graph
vector<pair<int,int> > adj[N+1];

//for bridges
int in[N+1] , low[N+1] , timer;
bool vis[N+1];


bool comp(Edge a , Edge b){
	return a.w < b.w;
}

int find(int a){
	if(_par[a] == a) return a;

	return _par[a] = find(_par[a]);
}

void addEdge(int a , int b , int index){
	a = find(a);
	b = find(b);

	if(a == b) return;

	result[index] = 1;
	adj[a].push_back({b , index});
	adj[b].push_back({a , index});
}

void merge(int a , int b){
	a = find(a);
	b = find(b);

	adj[a].clear();
	adj[b].clear();

	vis[a] = vis[b] = false;

	//merge
	if(a != b) _par[a] = b;
}

void dfs(int node , int edgeIndex){
	in[node] = low[node] = timer++;
	vis[node] = true;

	for(pair<int,int> e : adj[node]){
		int index = e.second;
		int v = e.first;

		if(index == edgeIndex) continue;

		if(vis[v]){
			low[node] = min(low[node] , in[v]);
		}else{
			dfs(v , index);
			low[node] = min(low[node] , low[v]);
		}
	}

	if(edgeIndex != 0){
		if(in[node] == low[node]) result[edgeIndex] = 2;
	}

}

int main(){

	// #ifndef ONLINE_JUDGE
	// freopen("input.txt" , "r" , stdin);
	// freopen("output.txt" , "w" , stdout);
	// #endif
	
	int n , m;

	cin>>n>>m;

	for(int i=1;i<=n;i++) _par[i] = i;

	for(int i=1;i<=m;i++){
		cin>>edges[i].a>>edges[i].b>>edges[i].w;
		edges[i].index = i;
	}
	
	sort(edges + 1 , edges + m + 1 , comp);

	int i = 1;
	while(i <= m){

		int j;
		//STEP 1
		for(j=i; edges[i].w == edges[j].w ; j++) 
			addEdge(edges[j].a , edges[j].b , edges[j].index);


		//STEP 2 : find all bridges
		timer = 0;
		for(j=i; edges[i].w == edges[j].w ; j++) {
			int node = find(edges[j].a);
			if(vis[node] == false) dfs(node , 0);
		}

		//STEP 3 : merge and remove edges
		for(j=i; edges[i].w == edges[j].w ; j++) merge(edges[j].a , edges[j].b);

		i = j;

	}

	for(int i=1;i<=m;i++){
		if(result[i] == 0) cout<<"none\n";
		else
		if(result[i] == 1) cout<<"at least one\n";
		else			   cout<<"any\n";
	}
}
```
## AIRPORTS
The government of a certain developing nation wants to improve transportation in one of its most inaccessible areas, in an attempt to attract investment. The region consists of several important locations that must have access to an airport.
Of course, one option is to build an airport in each of these places, but it may turn out to be cheaper to build fewer airports and have roads link them to all of the other locations. Since these are long distance roads connecting major locations in the country (e.g. cities, large villages, industrial areas), all roads are two-way. Also, there may be more than one direct road possible between two areas. This is because there may be several ways to link two areas (e.g. one road tunnels through a mountain while the other goes around it etc.) with possibly differing costs.
A location is considered to have access to an airport either if it contains an airport or if it is possible to travel by road to another location from there that has an airport. You are given the cost of building an airport and a list of possible roads between pairs of locations and their corresponding costs. The government now needs your help to decide on the cheapest way of ensuring that every location has access to an airport. The aim is to make airport access as easy as possible, so if there are several ways of getting the minimal cost, choose the one that has the most airports.
Input
The first line of input contains the integer T (T < 25), the number of test cases. The rest of the input consists of T cases. Each case starts with two integers N, M and A (0 < N ≤ 10, 000, 0 ≤ M ≤ 100, 000, 0 < A ≤ 10, 000) separated by white space. N is the number of locations, M is the number of possible roads that can be built, and A is the cost of building an airport.
The following M lines each contain three integers X, Y and C (1 ≤ X, Y ≤ N, 0 < C ≤ 10, 000), separated by white space. X and Y are two locations, and C is the cost of building a road between X and Y .
Output
Your program should output exactly T lines, one for each case. Each line should be of the form ‘Case #X: Y Z’, where X is the case number Y is the minimum cost of making roads and airports so that all locations have access to at least one airport, and Z is the number of airports to be built. As mentioned earlier, if there are several answers with minimal cost, choose the one that maximizes the number of airports.
```
Sample Input
2
4 4 100
1 2 10
4 3 12
4 1 41
2 3 23
5 3 1000
1 2 20
4 5 40
3 2 30
Sample Output
Case #1: 145 1
Case #2: 2090 2
```
```cpp
#include<bits/stdc++.h>
using namespace std;

#define ii pair<int, int>

const int mxM = 105, mxN = 1e4+5;

int findPar(vector<int>& p, int x){
	if(p[x] == x) return x;
	return findPar(p, p[x]);
}

int dfs(vector<pair<int, ii>>& edges, vector<int>& p, int n, int m, int a, int *cnt){
	int sumW = 0;
	for(int i=0; i<m; ++i){
		int u = edges[i].second.first;
		int v = edges[i].second.second;
		int w = edges[i].first;

		int p1 = findPar(p, u);
		int p2 = findPar(p, v);

		if(p1 != p2 && w < a){
			sumW += w;
			p[p1] = p2;
		}
	}

	for(int i=0; i<n; ++i){
		if(p[i] == i)
			(*cnt)++;
	}

	sumW += ((*cnt)*a);
	return sumW;
}
void solve(int& c){

	vector<pair<int, ii>> edges;
	int n, m, a; cin >> n >> m >> a;

	for(int i=0; i<m; ++i){
		int u, v, w;
		cin >> u >> v >> w, --u, --v;
		edges.push_back({w, {u, v}});
        // edges.push_back({w, {v, u}});
        }
	
	sort(edges.begin(), edges.end());

	vector<int> p(n+1);
	for(int i=0; i<n; ++i)
		p[i] = i;
	
	int cnt = 0;
	int res = dfs(edges, p, n, m, a, &cnt);

	cout << "Case #" << c << ": " << res << " " << cnt << "\n";

}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; cin>>t;
	int c=1;
	while(t--){
		solve(c);
		c++;
	}
	return 0;
}
```
