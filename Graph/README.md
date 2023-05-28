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

## Coding Ninjas $
Given a NxM matrix containing Uppercase English Alphabets only. Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .
There is a path from any cell to all its neighbouring cells. A neighbour may share an edge or a corner.
```
Sample Input :
1
2 11
CXDXNXNXNXA
XOXIXGXIXJX
Sample Output :
1
```
```cpp
#include<bits/stdc++.h>
using namespace std;

const int d8i[8] = {-1, -1, 0, 1, 1, 1, 0, -1},
          d8j[8] = {0, 1, 1, 1, 0, -1, -1, -1};

bool dfs(vector<vector<char>>& g, int i, int j, string& s, int k, int n, int m){
    if(i<0 || i>=n || j<0 || j>=m)
        return false;
    if(g[i][j] != s[k] || g[i][j] =='*') //  * to mark visited
        return false;
    if(k == s.length()-1)
        return true;
    
    char cache = g[i][j];
    g[i][j] = '*';
    
    // bool ok = dfs(g, i+d8i[0], j+d8j[0], s, k+1, n, m);
    // for(int x=1; x<8; ++i){
    //     ok = ok || dfs(g, i+d8i[x], j+d8j[x], s, k+1, n, m);
    // }
    
    bool ok= dfs(g, i-1, j, s, k+1, n, m) || dfs(g, i-1, j+1, s, k+1, n, m) || dfs(g, i, j+1, s, k+1, n, m) || dfs(g, i+1, j+1, s, k+1, n, m) || dfs(g, i+1, j, s, k+1, n, m)
                    || dfs(g, i+1, j-1, s, k+1, n, m) || dfs(g, i, j-1, s, k+1, n, m) || dfs(g, i-1, j-1, s, k+1, n, m);
                    
    g[i][j] = cache;

    return ok;

}
bool solve(vector<vector<char>>& g, string s, int n, int m){
    for(int i=0; i<n; ++i){
      for (int j = 0; j < m; ++j) {
        if (dfs(g, i, j, s, 0, n, m))
          return true;
        }
    }
    return false;
}




// const int d8i[8] = {-1, -1, 0, 1, 1, 1, 0, -1},
//           d8j[8] = {0, 1, 1, 1, 0, -1, -1, -1};

// bool dfs(vector<vector<char>> &g, string &s, int r, int c, int n, int m) {
//   if (g[r][c] != s[0]) // If the first char doesnt match start
//     return 0;

//   int len = s.size()-1;

//   for (int i = 0; i < 8; ++i) {
//     int new_r = r + d8i[i];
//     int new_c = c + d8j[i];
//     int k;
//     for (k = 1; k < len; ++k) {
//       // if(0<= new_r && new_r <n && 0<=new_c && new_c<m &&
//       // (g[new_r][new_c]==s[k])){
//       //     new_r += d8i[i];
//       //     new_c += d8j[i];
//       // }

//       if (new_r >= n || new_r < 0 || new_c >= m ||
//           new_c < 0) // out of bounds break
//         break;

//       if (g[new_r][new_c] != s[k]) // If not match break
//         break;

//       new_r += d8i[i]; // mo
//       new_c += d8j[i];
//     }
//     if (k == len) // all chars of s matched return true
//       return 1;
//   }
//   return 0;
// }

// int solve(vector<vector<char>> &g, string &s, int n, int m) {
//   for (int r = 0; r < n; ++r)
//     for (int c = 0; c < m; ++c)
//       if (dfs(g, s, r, c, n, m))
//         return 1;
//   return 0;
// }


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin>>t;
    while(t--){
        int n, m; 
        cin>>n>>m;

        vector<vector<char>> g(n, vector<char>(m));
        for(int i=0; i<n; ++i)
            for(int j=0; j<m; ++j)
                cin>>g[i][j];
        
        // string g[n];
        // for(int i=0; i<n; ++i)
        //     cin>>g[i];

        string s = "CODINGNINJA";
         cout << solve(g, s, n, m) <<endl;

        
        // int ans = wordSearch(g, n, m, s);
        // if(ans>=1) cout<<1<<'\n';
        // else cout<<0<<'\n';
    }
}
```
## Connecting Dots
Gary has a board of size NxM. Each cell in the board is a coloured dot. There exist only 26 colours denoted by uppercase Latin characters (i.e. A,B,...,Z). Now Gary is getting bore and wants to play a game. The key of this game is to find a cycle that contain dots of same colour. Formally, we call a sequence of dots d1, d2, ..., dk a cycle if and only if it meets the following condition:
1. These k dots are different: if i ≠ j then di is different from dj.
2. k is at least 4.
3. All dots belong to the same colour.
4. For all 1 ≤ i ≤ k - 1: di and di + 1 are adjacent. Also, dk and d1 should also be adjacent. Cells x and y are called adjacent if they share an edge.
Since Gary is colour blind, he wants your help. Your task is to determine if there exists a cycle on the board.
```cpp
#include<bits/stdc++.h>
using namespace std;

// const int mxN = 405;
// string a[mxN];
// int vis[mxN][mxN];
// int n, m; 

// bool dfs(int i, int j, char ch){
//     int up=0;
//     if(i-1>0)
//         up = vis[i-1][j];
//     int down=0;
//     if(i+1<n-1)
//         down = vis[i+1][j];
//     int right=0;
//     if(j<m+1)
//         right = vis[i][j+1];
//     int left=0;
//     if(j>0)
//         left = vis[i][j-1];

//     int sum = up+down+right+left;
//     if(sum==2)
//         return true;
    
//     bool ok = false;
//     if(i>0 && a[i-1][j]==ch && !vis[i-1][j]){
//         vis[i-1][j]=1;
//         if(dfs(i-1, j, ch))
//             ok=true;
//         else
//             vis[i-1][j]=0;
//     }
//     if(j>0 && a[i][j-1]==ch && !vis[i][j-1]){
//         vis[i][j-1]=1;
//         if(dfs(i, j-1, ch))
//             ok=true;
//         else
//             vis[i][j-1]=0;
//     }

//     if(i<n-1 && a[i+1][j]==ch && !vis[i+1][j]){
//         vis[i+1][j]=1;
//         if(dfs(i+1, j, ch))
//             ok=true;
//         else
//             vis[i+1][j]=0;
//     }

//     if(j<m-1 && a[i][j+1]==ch && !vis[i][j+1]){
//         vis[i][j+1]=1;
//         if(dfs(i, j+1, ch))
//             ok=true;
//         else
//             vis[i][j+1]=0;
//     }

//     return ok;
// }

// int solve(){
//   cin >> n >> m;

//   for (int i = 0; i < n; ++i) {
//     for (int j = 0; j < m; ++j) {
//       if (dfs(i, j, a[i][j]))
//         return 1;
//       for (int p = 0; p < n; ++p)
//         for (int q = 0; q < m; ++q)
//           vis[p][q] = 0;
//     }
//   }
//   return 0;
// }

// int main(){
//     cout << solve() << endl;
//     return 0;
// }

const int MAXN = 405;
bool checker(char arr[][MAXN], int n, int m, int i, int j, bool **visited,
             char current_character) {
  int condition_up = 0;
  if (i - 1 > 0) {
    condition_up = (int)visited[i - 1][j];
  }
  int condition_down = 0;
  if (i + 1 < n - 1) {
    condition_down = (int)visited[i + 1][j];
  }
  int condition_right = 0;
  if (j < m + 1) {
    condition_right = (int)visited[i][j + 1];
  }
  int condition_left = 0;
  if (j > 0) {
    condition_left = (int)visited[i][j - 1];
  }
  int sum = condition_up + condition_down + condition_right + condition_left;
  if (sum == 2) {
    return true;
  }

  //////////////////////////////everything above this is a base case.
  bool check = false;
  if (i > 0 && arr[i - 1][j] == current_character && !visited[i - 1][j]) // up
  {
    visited[i - 1][j] = true;
    if (checker(arr, n, m, i - 1, j, visited, current_character)) {
      check = true;
    } else {
      visited[i - 1][j] = false;
    }
  }

  if (j > 0 && arr[i][j - 1] == current_character && !visited[i][j - 1]) // left
  {
    visited[i][j - 1] = true;
    if (checker(arr, n, m, i, j - 1, visited, current_character)) {
      check = true;
    } else {
      visited[i][j - 1] = false;
    }
  }

  if (i < n - 1 && arr[i + 1][j] == current_character &&
      !visited[i + 1][j]) // down
  {
    visited[i + 1][j] = true;
    if (checker(arr, n, m, i + 1, j, visited, current_character)) {
      check = true;
    } else {
      visited[i + 1][j] = false;
    }
  }

  if (j < m - 1 && arr[i][j + 1] == current_character &&
      !visited[i][j + 1]) // right
  {
    visited[i][j + 1] = true;
    if (checker(arr, n, m, i, j + 1, visited, current_character)) {
      check = true;
    } else {
      visited[i][j + 1] = false;
    }
  }
  return check;
}

int solve(char arr[][MAXN], int n, int m) {
  bool **visited = new bool *[n];
  for (int i = 0; i < n; i++) {
    visited[i] = new bool[m];
    for (int j = 0; j < m; j++) {
      visited[i][j] = false;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (checker(arr, n, m, i, j, visited, arr[i][j])) {
        return 1;
      }
      for (int p = 0; p < n; p++) {
        for (int q = 0; q < m; q++) {
          visited[p][q] = false;
        }
      }
    }
  }
  return 0;
}

int main(){
    char arr[MAXN][MAXN];
    int n, m;

    cin>>n>>m;
    for(int i=0; i<n; ++i)
        for(int j=0; j<m; ++j)
            cin>>arr[i][j];
    
    cout<<solve(arr, n, m);
}
```

## Largest Piece $
Its Gary's birthday today and he has ordered his favourite square cake consisting of '0's and '1's . But Gary wants the biggest piece of '1's and no '0's . A piece of cake is defined as a part which consist of only '1's, and all '1's share an edge with eachother on the cake. Given the size of cake N and the cake , can you find the size of the biggest piece of '1's for Gary ?

```cpp
#include <bits/stdc++.h>
using namespace std;

const int d4i[4] = {-1, 0, 1, 0}, d4j[4] = {0, 1, 0, -1};

void dfs(vector<vector<char>>& g, int r, int c, vector<vector<bool>>& vis, int& sz, int n){
  vis[r][c]=true;
  
  for(int i=0; i<4; ++i){
    int new_r = r+d4i[i];
    int new_c = c+d4j[i];
    
    if(0<= new_r && new_r<n && 0<=new_c && new_c<n && (g[new_r][new_c]=='1' && !vis[new_r][new_c])){
      ++sz;

      dfs(g, new_r, new_c, vis, sz, n);
    }
  }
}
int solve(vector<vector<char>>& g, int n){
  vector<vector<bool>> vis(n, vector<bool>(n, false));

  int ans = 0;
  for(int i=0; i<n; ++i){
   for(int j=0; j<n; ++j){
     if(g[i][j]=='1' && !vis[i][j]){
       int sz=1;
       dfs(g, i, j, vis, sz, n);
       ans = max(ans, sz);
     }
   }
  }
  return ans;
}

int main(){
  int t; cin>>t;
  while(t--){
    int n; cin>>n;
    vector<vector<char>> g(n, vector<char>(n));

    for(int i=0; i<n; ++i)
      for(int j=0; j<n; ++j)
        cin>>g[i][j];
    
    cout << solve(g, n) << '\n';

  }
}
```

## 3 Cycle
Given a graph with N vertices (numbered from 1 to N) and Two Lists (U,V) of size M where (U[i],V[i]) and (V[i],U[i]) are connected by an edge , then count the distinct 3-cycles in the graph. A 3-cycle PQR is a cycle in which (P,Q), (Q,R) and (R,P) are connected an edge.
```cpp
#include<bits/stdc++.h>
using namespace std;

int count_cycles(int **arr, int n) {
  int count = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != j && arr[i][j] == 1) {
        for (int k = 0; k < n; k++) {
          if (j != k && k != i && arr[j][k] == 1) {
            if (arr[i][k] == 1) {
              count += 1;
            }
          }
        }
      }
    }
  }
  return count;
}
int solve(int n, int m, vector<int> u, vector<int> v) {
  int **arr = new int *[n];
  for (int i = 0; i < n; i++) {
    arr[i] = new int[n];
    for (int j = 0; j < n; j++) {
      arr[i][j] = 0;
    }
  }
  for (int i = 0; i < m; i++) {
    arr[u[i] - 1][v[i] - 1] = 1;
    arr[v[i] - 1][u[i] - 1] = 1;
  }
  return count_cycles(arr, n) / 6;
}
int main(){
    int n, m;
    cin>>n>>m;
    vector<int>u(m), v(m);
    for(int i=0; i<m; ++i){
        cin>>u[i];
    }
    for(int i=0; i<m; ++i)
        cin>>v[i];
    
    cout << solve(n, m, u, v) << '\n';
    return 0;
}
```

## Shortest Path In A Binary Maze
Given a maze in the form of a binary rectangular matrix of size M*N, where each element can either be 0 or 1, the task is to find the length of the shortest path in a maze from a given source cell to a destination cell.
The path can only be created out of a cell if its value is 1 and at any given moment, we can only move one step in one of the four directions. The valid moves are:
Up: (x, y) -> (x - 1, y)
Left: (x, y) -> (x, y - 1)
Down: (x, y) -> (x + 1, y)
Right: (x, y) -> (x, y + 1)
If there is no path from a given source cell to a destination cell, return -1.

```cpp

#include <queue>

int ROW, COL;

class queueNode {
public:
  pair<int, int> pt;
  int dist;
public:
  queueNode(pair<int, int> pt, int dist) {
    this->pt = pt;
    this->dist = dist;
  }
};


bool isValid(int row, int col) {
  return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL);
}

const int d4i[4] = {-1, 0, 1, 0}, d4j[4] = {0, 1, 0, -1};

int shortestPathBinaryMatrix(vector<vector<int>> &g, pair<int, int> src,
                             pair<int, int> t) {

  ROW = g.size();
  COL = g[0].size();

  if (g[src.first][src.second] != 1 || g[t.first][t.second] != 1) 
    return -1;
  

  vector<vector<bool>> vis(ROW, vector<bool>(COL, 0));

  vis[src.first][src.second] = 1;
  queue<queueNode> q;

  queueNode s(src, 0);
  q.push(s);

  while (!q.empty()) {
    queueNode u = q.front();
    pair<int, int> pt = u.pt;

    if (pt.first == t.first && pt.second == t.second) {
      return u.dist;
    }
    q.pop();

    for (int i = 0; i < 4; i++) {
      int row = pt.first + d4i[i];
      int col = pt.second + d4j[i];

      if (isValid(row, col) && g[row][col] == 1 && !vis[row][col]) {
        vis[row][col] = 1;
        queueNode v(pair<int, int>(row, col), u.dist + 1);
        q.push(v);
      }
    }
  }

  return -1;
}
```

## Minimum number of swaps required to sort an array
You have been given an array 'ARR' of 'N' distinct elements.
Your task is to find the minimum no. of swaps required to sort the array.
For example:
For the given input array [4, 3, 2, 1], the minimum no. of swaps required to sort the array is 2, i.e. swap index 0 with 3 and 1 with 2 to form the sorted array [1, 2, 3, 4].
```cpp
int minSwaps(vector<int> &arr){
	
int n = arr.size();

  int count = 0;

  vector<int> temp = arr;

  sort(temp.begin(), temp.end());

  map<int, int> mp;
  for (int i = 0; i < n; i++)
  	mp[arr[i]] = i;
  

  for (int i = 0; i < n; i++){

    // check whether curr element is at correct place or not

    if (arr[i] != temp[i]){

      count++;

      int x = arr[i];

      swap(arr[i], arr[mp[temp[i]]]);

      mp[x] = mp[temp[i]];

      mp[temp[i]] = i;
    }
  }

  return count;
}
```
## Minimum steps to reach target by a Knight $
You have been given a square chessboard of size ‘N x N’. The position coordinates of the Knight and the position coordinates of the target are also given.
Your task is to find out the minimum steps a Knight will take to reach the target position.
```cpp
#include <bits/stdc++.h>
using namespace std;

const int dx[8] = {2, 2, 1, 1, -1, -1, -2, -2};
const int dy[8] = {1, -1, 2, -2, 2, -2, 1, -1};

int minSteps(pair<int, int> st, pair<int, int> ed, int n) {
    vector<vector<bool>> vis(n+1, vector<bool>(n+1));
    queue<pair<int, int>> q;
    vis[st.first][st.second]=1;
    int ans=0;
    q.push(st);

    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            pair<int, int> u = q.front();
            q.pop();
            int x = u.first, y = u.second;
            if(x==ed.first && y==ed.second)
                return ans;
            
            for(int k=0; k<8; ++k){
                int x1 = x+dx[k];
                int y1 = y+dy[k];
            
            if(0<x1 && x1<=n && 0<y1  && y1<=n && !vis[x1][y1]){
              q.push({x1, y1});
              vis[x1][y1] = 1;
            }
        }
    }
    
    ++ans;
    }

    return -1;
}
```
## Kruskal's Algorithm
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the total weight of Minimum Spanning Tree (MST) using Kruskal's algorithm.
```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll                long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define ff                first
#define ss                second
#define ii                pair<int,int>
#define mp                make_pair
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll
#define fast_io          ios::sync_with_stdio(0); cin.tie(0);
#define nl                 '\n'
#define vt                vector
#define vi                vector<int>
#define ar                array

//I DSU MST Kosaraju
struct dsu{
	vi p, sz;
	ll size;
	void init(ll n){
		size=n;
		p.resize(n+1); sz.resize(n+1);
		for(ll i=0; i<n; ++i){
			p[i]=i;
			sz[i]=1;
		}
	}
	ll find (ll x){
		return x^p[x]?p[x]=find(p[x]):x;
	}
	void join(ll x, ll y){
		if((x=find(x)) == (y=find(y)))
			return;
		if(sz[x]<sz[y]){
			p[x]=y;
			sz[y]+=sz[x];
		} else{
			p[y]=x;
			sz[x]+=sz[y];
		}
	}
};

void solve(){
	ll n, m; 
	cin>>n>>m;
	
	vector<pair<ll, ii>> edges;
	
	for(ll i=0; i<m; ++i){
		ll u, v, w;
		cin>>u>>v>>w;
		edges.pb({w, {u, v}});
	}
	sort(edges.begin(), edges.end());
	ll ans=0;
	dsu ds;
	ds.init(n);
	for(auto e: edges){
		ll w=e.ff; ll u=e.ss.ff; ll v=e.ss.ss;
		if(ds.find(u)==ds.find(v))
			continue;
		ans+=w;
		ds.join(u, v);
	}
	cout<<ans<<nl;

}

int main(){
    fast_io
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
```

## Prim's Algorithm
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the total weight of Minimum Spanning Tree (MST) using Prim's algorithm.
```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define all(x) (x).begin(), (x).end()
#define uniq(v) (v).erase(unique(all(v)), (v).end())
#define sz(x) (int)((x).size())
#define ff first
#define ss second
#define ii pair<int, int>
#define mp make_pair
#define rep(i, a, b) for (int i = a; i < b; i++)
#define mem1(a) memset(a, -1, sizeof(a))
#define mem0(a) memset(a, 0, sizeof(a))
#define ppc __builtin_popcount
#define ppcll __builtin_popcountll
#define fast_io                                                                \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);
#define nl '\n'
#define vt vector
#define vi vector<int>
#define ar array

// I DSU MST Kosaraju
struct dsu {
  vi p, sz;
  ll size;
  void init(ll n) {
    size = n;
    p.resize(n + 1);
    sz.resize(n + 1);
    for (ll i = 0; i < n; ++i) {
      p[i] = i;
      sz[i] = 1;
    }
  }
  ll find(ll x) { return x ^ p[x] ? p[x] = find(p[x]) : x; }
  void join(ll x, ll y) {
    if ((x = find(x)) == (y = find(y)))
      return;
    if (sz[x] < sz[y]) {
      p[x] = y;
      sz[y] += sz[x];
    } else {
      p[y] = x;
      sz[x] += sz[y];
    }
  }
};

void solve() {
  ll n, m;
  cin >> n >> m;

  vector<pair<ll, ii>> edges;

  for (ll i = 0; i < m; ++i) {
    ll u, v, w;
    cin >> u >> v >> w;
    edges.pb({w, {u, v}});
  }
  sort(edges.begin(), edges.end());
  ll ans = 0;
  dsu ds;
  ds.init(n);
  for (auto e : edges) {
    ll w = e.ff;
    ll u = e.ss.ff;
    ll v = e.ss.ss;
    if (ds.find(u) == ds.find(v))
      continue;
    ans += w;
    ds.join(u, v);
  }
  cout << ans << nl;
}

int main() {
  fast_io int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
```
## Dijkstra's Algorithm
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the shortest distance from the source vertex (i.e. Vertex 0) to all other vertices (including source vertex also) using Dijkstra's Algorithm.
Print the ith vertex number and the distance from source in one line separated by space. Print different vertices in different lines.
Note : Order of vertices in output doesn't matter.
```cpp
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define ar array
#define vi vector<int>
#define fast_io                                                                \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);
#define nl '\n'

const int mxN = 1e3 + 5, mxM = 1e3 + 5;
int n, m;
vector<ar<ll, 2>> adj[mxN];
ll d[mxN];
bool vis[mxN];
// Djikstra
void djikstra(int bi) {
  priority_queue<ar<ll, 2>, vector<ar<ll, 2>>, greater<ar<ll, 2>>> pq;

  for (int i = 0; i < n; ++i) {
    d[i] = 1e18;
    vis[i] = 0;
  }
//   memset(d, 0x3f, sizeof(d));
//   memset(vis, 0, sizeof(vis));
  pq.push({0, bi});
  d[bi] = 0;
  while (pq.size()) {
    ar<ll, 2> u = pq.top();
    pq.pop();

    // if(u[0]>d[u[1]])
    // continue;
    if (vis[u[1]])
      continue;
    vis[u[1]] = 1;

    for (ar<ll, 2> v : adj[u[1]]) {
      if (d[v[1]] > u[0] + v[0]) {
        d[v[1]] = u[0] + v[0];
        pq.push({d[v[1]], v[1]});
      }
    }
  }
}

void solve() {
  cin >> n >> m;

  for(int i=0; i<mxN; ++i)
    adj[i].clear();

  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].pb({c, b});
    adj[b].pb({c, a});
  }
  
  djikstra(0);
  for(int i=0; i<n; ++i)
    cout<< i << " " << d[i] <<'\n';

}

int main(){
      fast_io 
      int t; cin>>t;

      while(t--){
          solve();
      }
      return 0;
}
```

## Bellman-Ford Algorithm
you are given a weighted directed graph G with n vertices and m edges, and two specified vertex src and des. You want to find the length of shortest paths from vertex src to des. The graph may contain the edges with negative weight.
```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define all(x) (x).begin(), (x).end()
#define uniq(v) (v).erase(unique(all(v)), (v).end())
#define sz(x) (int)((x).size())
#define ff first
#define ss second
#define ii pair<int, int>
#define mp make_pair
#define rep(i, a, b) for (int i = a; i < b; i++)
#define mem1(a) memset(a, -1, sizeof(a))
#define mem0(a) memset(a, 0, sizeof(a))
#define ppc __builtin_popcount
#define ppcll __builtin_popcountll
#define fast_io                                                                \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);
#define nl '\n'
#define vt vector
#define vi vector<int>
#define ar array

const int mxN = 205, mxM = 805;
const int INF = 1e9;

struct edge {
  int a, b, cost;
};

int n, m, src;
vector<edge> e(mxM);
vt<int> d(mxN, INF);

void solve() {
  int n, m, src, des;
  cin >> n >> m;
  cin>> src >> des, --src, --des;

  for (int i = 0; i <m; i++){
    cin>>e[i].a >> e[i].b >> e[i].cost, --e[i].a, --e[i].b;
  }

  d[src] = 0;
  for (;;) {
    bool any = false;

    for (int j = 0; j < m; ++j)
      if (d[e[j].a] < INF)
        if (d[e[j].b] > d[e[j].a] + e[j].cost) {
          d[e[j].b] = d[e[j].a] + e[j].cost;
          any = true;
        }

    if (!any)
      break;
  }
  
  cout << d[des] << nl;
}

int main(){
    fast_io
    int t; cin>>t;
    while(t--){
        e.clear();
        d.clear();
        d.assign(mxN, INF);

        solve();
    }
}
```

## Floyd-Warshall Algorithm
You are given an undirected weighted graph G with n vertices. And Q queries, each query consists of two integers a and b and you have print the distance of shortest path between a and b.
Note: If there is no path between a and b print 10^9
```cpp
#include<bits/stdc++.h>
using namespace std;

#define fast_io                                                                \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);

const int mxN = 100;
int n, m, q;
int d[mxN][mxN];

void solve(){
    cin>>n>>m;
    memset(d, 0x3f, sizeof(d));
    for (int i = 0; i < m; ++i) {
      int a, b, c;
      cin >> a >> b >> c, --a, --b;
      d[a][b] = min(d[a][b], c);
      d[b][a] = min(d[b][a], c);
    }

    for(int i=0; i<n; ++i)
        d[i][i]=0;
    
    for(int k=0; k<n; ++k)
        for(int i=0; i<n; ++i)
            for(int j=0; j<n; ++j)
                d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
    
    int q; cin>>q;
    while(q--){
        int a, b;
        cin>>a>>b, --a, --b;
        // cout << (d[a][b] >= 1e9 ? 1e9 : d[a][b]) << '\n';
        cout << d[a][b] <<'\n';
    }

    
}
int main(){
    
    fast_io
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
```

## Permutation Swaps
Kevin has a permutation P of N integers 1, 2, ..., N, but he doesn't like it. Kevin wants to get a permutation Q.
He also believes that there are M good pairs of integers (ai, bi). Kevin can perform following operation with his permutation:
Swap Px and Py only if (x, y) is a good pair.
Help him and tell if Kevin can obtain permutation Q using such operations.

```cpp
#include <bits/stdc++.h>
using namespace std;

#define fast_io          ios::sync_with_stdio(0); cin.tie(0);
struct dsu{
    vector<int> p, sz;
    int size;
    void init(int n){
        size=n;
        p.resize(n+1); sz.resize(n+1);
        for(int i=0; i<n; ++i){
            p[i]=i;
            sz[i]=1;
        }
    }
    int find (int x){
        return x^p[x]?p[x]=find(p[x]):x;
    }
    void join(int x, int y){
        if((x=find(x)) == (y=find(y)))
            return;
        if(sz[x]<sz[y]){
            p[x]=y;
            sz[y]+=sz[x];
        } else{
            p[y]=x;
            sz[x]+=sz[y];
        }
    }
};

void solve(){
    int n, m; 
    cin >> n >> m;
    vector<int> p(n), q(n);
    for(int i=0; i<n; ++i) cin>>p[i];
    for(int i=0; i<n; ++i) cin>>q[i];

    dsu ds;
    ds.init(n);
    
    for(int i=0; i<m; ++i){
        int a, b;
        cin>>a>>b, --a, --b;
        ds.join(p[a], p[b]); //a, b are index pos & not the actual nos
    }
    
    for(int i=0; i<n; ++i){
        if(p[i]!=q[i] && ds.find(p[i]) != ds.find(q[i])){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    return;
}
int main(){
    fast_io
    int t; cin>>t;
    while(t--){
        solve();
    }
}
```

## Monk and the Islands
Monk visits the land of Islands. There are a total of N islands numbered from 1 to N. Some pairs of islands are connected to each other by Bidirectional bridges running over water.
Monk hates to cross these bridges as they require a lot of efforts. He is standing at Island #1 and wants to reach the Island #N. Find the minimum the number of bridges that he shall have to cross, if he takes the optimal route.

```cpp
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ar array
#define vi vector<int>
#define fast_io                                                                \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);
#define nl '\n'

const int mxN = 1e4;
int n, m;
vector<ar<int, 2>> adj[mxN];
int d[mxN];
bool vis[mxN];
// Djikstra
void djikstra(int bi) {
  priority_queue<ar<int, 2>, vector<ar<int, 2>>, greater<ar<int, 2>>> pq;

  for (int i = 0; i < n; ++i) {
    d[i] = 1e9;
    vis[i] = 0;
  }
  //   memset(d, 0x3f, sizeof(d));
  //   memset(vis, 0, sizeof(vis));
  pq.push({0, bi});
  d[bi] = 0;
  while (pq.size()) {
    ar<int, 2> u = pq.top();
    pq.pop();

    // if(u[0]>d[u[1]])
    // continue;
    if (vis[u[1]])
      continue;
    vis[u[1]] = 1;

    for (ar<int, 2> v : adj[u[1]]) {
      if (d[v[1]] > u[0] + v[0]) {
        d[v[1]] = u[0] + v[0];
        pq.push({d[v[1]], v[1]});
      }
    }
  }
}

void solve() {
  cin >> n >> m;
  
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b, --a, --b;
    adj[a].pb({1, b});
    adj[b].pb({1, a});
  }

  djikstra(0);

  cout << d[n-1] << '\n';
}

int main() {
  fast_io int t;
  cin >> t;

  while (t--) {
    for (int i = 0; i < mxN; ++i)
      adj[i].clear();

    solve();
  }
  return 0;
}
```

## Fill the Matrix $$
A matrix B (consisting of integers) of dimension N × N is said to be good if there exists an array A (consisting of integers) such that B[i][j] = |A[i] - A[j]|, where |x| denotes absolute value of integer x.
You are given a partially filled matrix B of dimension N × N. Q of the entries of this matrix are filled by either 0 or 1. You have to identify whether it is possible to fill the remaining entries of matrix B (the entries can be filled by any integer, not necessarily by 0 or 1) such that the resulting fully filled matrix B is good.
```cpp
#include <bits/stdc++.h>
using namespace std;

#define fast_io          ios::sync_with_stdio(0); cin.tie(0);
#define next next_  ///////////////////////

const int mxN = 1e5;
int node[mxN], next[mxN], to[mxN], w[mxN], e;

void ins(int x, int y, int v){
	e++;
	next[e] = node[x];
	node[x] = e;
	to[e] = y;
	w[e] = v;
}

int N, Q, ans;
int vis[mxN], parity[mxN];
void dfs(int x){
	vis[x]=1;
	for(int j=node[x]; j; j=next[j])
		if(!vis[to[j]]){
			parity[to[j]] = parity[x]^w[j];
			dfs(to[j]);
		}else if(parity[to[j]]^parity[x]^w[j])
			ans = 0;
}

void clr(){
	for(int i=0; i<N; ++i)
		node[i]=vis[i]=parity[i]=0;
	for(int i=0; i<e; ++i)
		next[i]=to[i]=w[i]=0;
	e=0;
	ans=1;
}

void solve(){
	int i, j, v;
	cin>>N>>Q;
	while(Q--){
		cin>>i>>j>>v, --i, --j;
		ins(i, j, v);
		ins(j, i, v);
	}
	for(int i=0; i<N; ++i)
		if(!vis[i])
			dfs(i);
	
	cout << (ans ? "yes\n" : "no\n");
}

int main(){
	fast_io
	int t; cin>>t;
	while(t--){
		clr();
		solve();
	}
	return 0;
}


// #include <bits/stdc++.h>
// using namespace std;
// #define ll                long long
// #define pb                push_backl
// #define fast_io          ios::sync_with_stdio(0); cin.tie(0);
// #define vt                vector
// #define vi                vector<int>
// #define ar                array

// const int mxN = 1e5;

// struct dsu{
// 	vi p, sz;
// 	int size;
// 	void init(int n){
// 		size=n;
// 		p.resize(n+1); sz.resize(n+1);
// 		for(int i=0; i<n; ++i){
// 			p[i]=i;
// 			sz[i]=1;
// 		}
// 	}
// 	int find (int x){
// 		return x^p[x]?p[x]=find(p[x]):x;
// 	}
// 	void join(int x, int y){
// 		if((x=find(x)) == (y=find(y)))
// 			return;
// 		if(sz[x]<sz[y]){
// 			p[x]=y;
// 			sz[y]+=sz[x];
// 		} else{
// 			p[y]=x;
// 			sz[x]+=sz[y];
// 		}
// 	}
// };

// bool solve(){
	
//     int n, m; 
//     cin>>n>>m;
// 	dsu ds;
// 	ds.init(n+1);

//     vector<vector<int>> B(n+1, vector<int>(n+1, -1));
//     // vector<ar<int, 3>> Q(m+1);
//     vector<vector<int>> Q(m+1, vector<int>(3, 0));

//     for(int i=0; i<m; ++i){
//         int a, b, c;
//         cin>>a>>b>>c;
//         Q[i][0]=a; Q[i][1]=b; Q[i][2]=c;
//     }
//     bool ok = 1;
	
//     for(int q=0; q<m; ++q){
//         int i, j, val;
//         i=Q[q][0]; j=Q[q][1]; val=Q[q][2];
        
// 		if(i==j && val==1){
// 			ok=0;
// 			return ok;
// 		}
// 		if(B[i][j]!=-1){
// 			if(val != B[i][j]){
// 				ok=0;
// 				return ok;
// 			}
// 		}else{
// 			B[i][j] = val;
//             B[j][i] = val;
// 		}
		
// 		if(val==0){
// 			ds.join(i, j);
// 		}
// 	}
	
// 	for(int q=0; q<m; ++q){
//         int i, j, val;
//         i=Q[q][0]; j=Q[q][1]; val=Q[q][2];
        
// 		if(val==1){
// 			if(ds.find(i) == ds.find(j)){
// 				ok=0;
// 				return ok;
// 			}
// 		}
// 	}
// 	return ok;
    
// }

// int main(){
    
//     fast_io
//     int t; cin>>t;
//     while(t--){
//         bool ok = solve();
//         cout << (ok ? "yes\n": "no\n") ;
//     }
//     return 0;
// }
```
## Minimum Travel Cost
Ninjaland is a country having 'N' states numbered from 1 to 'N'. These 'N' states are connected by 'M' bidirectional roads. Each road connects to different states and has some cost to travel from one state to another. Now, the chief wants you to select 'N' - 1 roads in such a way that the tourist bus can travel to every state at least once at minimum 'COST'.
```cpp
// I DSU MST Kosaraju
#include <bits/stdc++.h>
using namespace std;

struct dsu {
  vector<int> p, sz;
  int size;
  void init(int n) {
    size = n;
    p.resize(n + 1);
    sz.resize(n + 1);
    for (int i = 0; i < n; ++i) {
      p[i] = i;
      sz[i] = 1;
    }
  }
  int find(int x) { return x ^ p[x] ? p[x] = find(p[x]) : x; }
  void join(int x, int y) {
    if ((x = find(x)) == (y = find(y)))
      return;
    if (sz[x] < sz[y]) {
      p[x] = y;
      sz[y] += sz[x];
    } else {
      p[y] = x;
      sz[x] += sz[y];
    }
  }
};

vector<vector<int>> findMST(vector<vector<int>> &edges, int n, int m)
{
  vector<vector<int>> ans;
  sort(edges.begin(), edges.end(), [](const vector<int>& x, const vector<int>& y){ return x[2] < y[2]; });
  dsu ds;
  ds.init(n);
  for(auto e: edges){
      int w = e[2], u = e[0], v=e[1];
      if(ds.find(u)==ds.find(v)) 
        continue;
    
    ans.push_back(e);
    ds.join(u, v);
  }
  return ans;
}
```

## Min Efforts Required
The Ultimate Ninja Ankush, after training hard, goes for a good meal at the ninja cafe, for that he follows the path given on the map, which may or may not lead him to the ninja cafe. The map is a directed graph. Since he is also very lazy, he wants to minimize the effort to travel. The effort is defined as the product of all the distance it takes to reach from the dojo (source) to the ninja cafe (destination). Can you help him find the path with the minimum effort it would take The Ultimate Ninja Ankush to reach the destination?
More Formally, you are given a directed graph with ‘N’ nodes and ‘M’ edges where the distance of each edge is greater than 0, also given a source ‘src’ and a destination ‘dest’. The task is to find the minimum product of edges from src’ to ‘dest’. If there is no path from ‘src’ to ‘dest’, then return -1.
For example
Given:
‘N’ = 3, ‘M’ = 3. 
‘edges’ = 
    [[0 1 1],
     [1 2 1],
     [0 2 3]]
‘src’ = 0, ‘dest’ = 2.

There are two possible paths, that is to go from node-0 to node-2 directly, which will take 2 units of effort, or go from node-0 to node-1 and then node-1 to node-2, which will take 1 unit of effort.

```cpp
ll minEffortsRequired(vector<pair<pair<int, int>, ll>>&edges, int n, int src, int des)
{
	if (src == des) return 0;
	
	vector<ll> d(n + 1, 1e18);
	int m = edges.size();

	d[src] = 1;
	//relaxing edges N-1 times
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < m ; j++)
		{
			int u = edges[j].first.first;
			int v = edges[j].first.second;
			ll w = edges[j].second;
			d[v] = min(d[v], d[u] * w);
		}
	}
	
	return d[des]>=1e18 ? -1 : d[des];
}
```
