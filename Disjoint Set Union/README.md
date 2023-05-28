## Cycle Detection In Undirected Graph
You have been given an undirected graph with 'N' vertices and 'M' edges. The vertices are labelled from 1 to 'N'.
Your task is to find if the graph contains a cycle or not.
A path that starts from a given vertex and ends at the same vertex traversing the edges only once is called a cycle.
```cpp
// DSU
#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e4, mxM = 2e4;
int p[mxN];
int s[mxN];

int find(int x) { return x ^ p[x] ? p[x] = find(p[x]) : x; }

bool join(int x, int y) {
  if ((x = find(x)) == (y = find(y)))
    return 0;
  p[x] = y;
  s[y] += s[x];
  return 1;
}


string cycleDetection (vector<vector<int>>& e, int n, int m)
{
  iota(p, p + n, 0);
  fill(s, s + n, 1);

  for (int i = 0; i < m; ++i) {
    if (join(e[i][0], e[i][1])==0)
      return "Yes";
      
  }
  return "No";
}
```
