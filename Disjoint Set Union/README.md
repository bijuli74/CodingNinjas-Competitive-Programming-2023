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

## CF Roads not only in Berlin

```cpp
#include<bits/stdc++.h>

using namespace std;

class DSU{
	vector<int> parent;
	vector<int> subtree;

public:
	DSU(int n){
		for(int i=0; i<=n; i++){
			parent.push_back(i);
			subtree.push_back(1);
		}
	}

	int findRoot(int x){
		while(x!=parent[x]){
			parent[x] = parent[parent[x]];
			x = parent[x];
		}

		return x;
	}

	bool combine(int u, int v){
		int ru = findRoot(u);
		int rv = findRoot(v);

		if(ru == rv) return false;

		if(subtree[ru] > subtree[rv]){
			parent[rv] = ru;
			subtree[ru] += subtree[rv];
		} else{
			parent[ru] = rv;
			subtree[rv] += subtree[ru];
		}
		return true;
	}
};

int main(){
	freopen("input.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int n;
	cin>>n;
	pair<int, int> edges[n-1];
	for(int i=0; i<n-1; i++){
		cin>>edges[i].first>>edges[i].second;
	}
	DSU dsu = DSU(n);
	vector<int> cycleEdges;
	for(int i=0; i<n-1; i++){
		bool isAdded = dsu.combine(edges[i].first, edges[i].second);
		if(!isAdded) cycleEdges.push_back(i); 
	}

	set<int> roots;

	for(int i=1; i<=n; i++){
		int ri = dsu.findRoot(i);
		roots.insert(ri);
	}

	cout<<cycleEdges.size()<<"\n";

	if(cycleEdges.size() > 0){
		auto it = roots.begin(); 
		it++;

		for(int i=0; i<cycleEdges.size(); i++){
			int idx = cycleEdges[i];
			cout<<edges[idx].first<<" "<<edges[idx].second<<" "<<*it<<" "<<*roots.begin()<<"\n";
			it++;
		}
	}



	return 0;
}
```

## Spoj KOICOST

```cpp
#include<bits/stdc++.h>

using namespace std;
const int MAX = (int)(1e5+5);
class DSU{
	int parent[MAX];
	int subtree[MAX];
public:
	DSU(int n){
		for(int i=0; i<=n; i++){
			parent[i] = i;
			subtree[i] = 1;
		}
	}

	int findRoot(int u){
		while(u != parent[u]){
			parent[u] = parent[parent[u]];
			u = parent[u];
		}

		return u;
	}

	void combine(int u, int v){
		int ru = findRoot(u);
		int rv = findRoot(v);

		if(ru == rv) return;
		else if(subtree[ru] > subtree[rv]){
			parent[rv] = ru;
			subtree[ru] += subtree[rv];
		} else{
			parent[ru] = rv;
			subtree[rv] += subtree[ru];
		}
	}

	long long getSize(int u){
		int ru = findRoot(u);
		return subtree[ru] * 1ll;
	}

};

int main(){
	freopen("input.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	const long long mod = 1000000000;
	int n, m;
	cin>>n>>m;
	pair<int, pair<int, int> > edges[m];

	for(int i=0; i<m; i++){
		int u, v, w;
		cin>>u>>v>>w;
		edges[i] = {w, {u, v}};
	}

	sort(edges, edges + m);

	long long csum[m];
	csum[0] = edges[0].first;
	for(int i=1; i<m; i++){
		csum[i] = csum[i-1] + 1ll * edges[i].first;
	}

	DSU dsu = DSU(n);

	long long ans = 0;

	for(int i=m-1; i>=0; i--){
		int u = edges[i].second.first;
		int v = edges[i].second.second;

		int ru = dsu.findRoot(u);
		int rv = dsu.findRoot(v);
		if(ru == rv){
			continue;
		}

		long long current = ((dsu.getSize(ru) * dsu.getSize(rv)) % mod) * csum[i];
		current %= mod;
		ans += current;
		ans %= mod;
		dsu.combine(u, v);
	}

	cout<<ans;

	return 0;
}
```
## Ninja attack
Ninja has built his team of ninjas to fight with the enemies in his city. Ninja made a plan of attacking all his enemies. In his team, every ninja has his own range of hitting and they had secretly got the hitting range of their enemies as well. So Ninja allowed some swaps between his ninjas so that they can minimize the hamming distance that is the number of positions where the hitting range of enemies and ninjas are different.
Your task is to write a code that can minimize the hamming distance. You are being provided with two arrays ‘ninja’ and ‘enemies’ both of the same size and an array ‘allowedSwaps’ where each allowedSwaps[i] = [ ai, bi ] indicates that you are allowed to swap the elements at index ai and index bi.
The Hamming distance of two arrays of the same length, ninja, and enemies, is the number of positions where the elements are different.
Example :
Consider the case ‘ninja’array is [ 1, 2, 3, 4 ], ‘enemies’array is [ 2, 1, 4, 5 ] and ‘allowedSwaps’ are  = [ [ 0, 1 ], [ 2, 3 ] ] so after swapping in best manner according to ‘allowedSwaps’ our ‘ninja’ array becomes [ 2, 1, 4, 3 ]. So minimum Hamming distance is ‘1’ as now there is only one different element as compared to ‘ninja’ and ‘enemies’ array index.
```cpp
#include <bits/stdc++.h>
using namespace std;

int find(vector<int> &ds, int i) {
    return ds[i] < 0 ? i : ds[i] = find(ds, ds[i]);
}
int ninjaAttack(vector<int> s, vector<int> t, vector<vector<int>> allowedSwaps) {
    int sz = s.size(), res = 0;
    vector<int> ds(sz, -1);
    for (auto &sw: allowedSwaps) {
        int i = find(ds, sw[0]), j = find(ds, sw[1]);
        if (i != j) {
            if (ds[i] > ds[j])
                swap(i, j);
            ds[i] += ds[j];
            ds[j] = i;
        }
    }
    vector<unordered_multiset<int>> cycles(sz);
    for (auto i = 0; i < sz; ++i)
        if (s[i] != t[i])
            cycles[find(ds, i)].insert(s[i]);
    for (auto i = 0; i < sz; ++i) {
        if (s[i] != t[i]) {
            auto &cycle = cycles[find(ds, i)];
            auto it = cycle.find(t[i]);
            if (it != end(cycle)) {
                cycle.erase(it);
            } else
                ++res;
        }
    }        
    return res;
}
```
## Evaluate Division
You are given an array of pairs of strings 'EQUATIONS', and an array of real numbers 'VALUES'. Each element of the 'EQUATIONS' array denotes a fraction where the first string denotes the numerator variable and the second string denotes the denominator variable, and the corresponding element in 'VALUES' denotes the value this fraction is equal to.
You are given ‘Q’ queries, and each query consists of two strings representing the numerator and the denominator of a fraction. You have to return the value of the given fraction for each query. Return -1 if the value cannot be determined.
Example :
'EQUATIONS' = { {“a”, ”s”} , {“s”, “r”} }
'VALUES' = { 1.5, 2 }
queries = { {“a”, “r” } }

For the above example (a / s) = 1.5 and (s / r) = 2 therefore (a / r) = 1.5 * 2 = 3.
```cpp
#include <bits/stdc++.h>
using namespace std;

// Returns A / C
  double divide(const unordered_map<string, unordered_map<string, double>>& graph, const string& A, const string& C, unordered_set<string>&& seen) {
    if (A == C)
      return 1.0;
    seen.insert(A);
    // Value := A / B
    for(const pair<string, double>& X: graph.at(A) ){
        const string B = X.first;
        const double value = X.second;
    // for (const auto& [B, value] : graph.at(A)) {
      if (seen.count(B))
        continue;
      const double res = divide(graph, B, C, move(seen));  // B / C
      if (res > 0)                                         // Valid result
        return value * res;  // A / C = (A / B) * (B / C)
    }

    return -1;  // Invalid result
  }
vector<double> evaluateEquations(vector<pair<string,string>>& equations, vector<pair<string, string>>& queries, vector<double>& values) {
    vector<double> ans;
    // graph[A][B] := A / B
    unordered_map<string, unordered_map<string, double>> graph;
    for (int i = 0; i < equations.size(); ++i) {
      const string& A = equations[i].first;
      const string& B = equations[i].second;
      graph[A][B] = values[i];
      graph[B][A] = 1 / values[i];
    }
    for (const auto& query : queries) {
      const string& A = query.first;
      const string& C = query.second;
      if (!graph.count(A) || !graph.count(C))
        ans.push_back(-1);
      else
        ans.push_back(divide(graph, A, C, unordered_set<string>()));
    }
    return ans;
  }
```
## Identical sentences
You are given two sentences, ‘word1’ and ‘word2’, represented as an array of strings of size ‘n’ and ‘m’, respectively. You are also given an array called ‘pairs’. Each element in ‘pairs’ is of the form ‘[u, v]’ where ‘u’ and ‘v’ are strings.
Properties of the array ‘pairs’:
If ‘[u, v]’ or ‘[v, u]’ is present in ‘pairs’, then the words (or strings) ‘u’ and ‘v’ are identical.
If ‘u’ and ‘x’ are identical, and ‘v’ and ‘x’ are identical, then the words ‘u’ and ‘v’ are identical.
Every word is identical to itself, i.e., the word ‘u’ and ‘u’ are always identical.
For two sentences, ‘word1’ and ‘word2’ to be identical:
For every word (‘word1[i]’) in ‘word1’, the words ‘word1[i]’ and ‘word2[i]’ must be identical.
‘word1’ and ‘word2’ must have the same number of words.
Using the array ‘pairs’, you have to determine if ‘word1’ and ‘word2’ are identical.
Example :
‘word1’ = [“exceptional”, “coding”, “skills”]
‘word2’ = [“great”, “coding”, “talent”]
‘pairs’ = [ [“exceptional”, “good”], [“great”, “good”], [“skills”, “talent”] ]

For each word in ‘word1’, we have:
1. “exceptional” = “great”, because “exceptional” = “good” and “good” = “great”
2. “coding” = “coding”, as every word is identical to itself.
3. “skills” = “talent”, because [“skills”, “talent”] is present in ‘pairs’.

As every word in ‘word1’ is identical to the corresponding word in ‘word2’, the given sentences are identical.
```cpp
#include<bits/stdc++.h> 

class DSU{
private: 
    unordered_map<string, string> parent;
    unordered_map<string, int> rank;
    
public:
    DSU(vector<vector<string>>& dictionary){
        for(auto words: dictionary){
            string word1 = words[0];
            string word2 = words[1];
            if(!exists(word1)){
                parent[word1] = word1;
                rank[word1] = 1;                                
            }
            
            if(!exists(word2)){
                parent[word2] = word2;
                rank[word2] = 1;
            }            
      }            
        
        for(auto words : dictionary){
            string word1 = words[0];
            string word2 = words[1];
            unionByRank(word1, word2);
        }
    }
    
    bool exists(string word){
        if(parent.find(word) == parent.end())
            return false;
        return true;
    }
    
    string find(string word){
        if(parent[word] == word) return word;
        return parent[word] = find(parent[word]);
    } 
    
    void unionByRank(string u, string v){
        string pu = find(u);
        string pv = find(v);
        if(pu != pv){
            if(rank[pu] < rank[pv]){
                parent[pu] = pv;
            }else if(rank[pv] < rank[pu]){
                parent[pv] = pu;
            }else{
                parent[pv] = pu;
                rank[pu]++;
            }
        }
    }
   
};

bool identicalSentences(vector<string> word1, vector<string> word2, vector<vector<string>> pairs, int n, int m, int p) {
    if(n!=m) return false;
    
    DSU dictionary(pairs);
    
    for(int i=0; i<n; i++){
        if(word1[i] == word2[i]) continue;
        if(!dictionary.exists(word1[i]) 
           || !dictionary.exists(word2[i]) 
           || dictionary.find(word1[i]) != dictionary.find(word2[i])){
            return false;
        }   
    }
    return true;
}
```

## Number of operations to make Graph connected.
You have been given a graph consisting of ‘N’ vertices numbered from 1 to ‘N’. The graph has ‘M’ edges. In an operation, you can shift an edge between two directly connected vertices to between pair of disconnected vertices to make them directly connected. Return the minimum number of operations to make the graph connected. If it is not possible to make graph connected return -1.
```cpp
void dfs(const vector<vector<int>>& g, int u, unordered_set<int>& vis){
	for(const int v: g[u])
		if(vis.insert(v).second)
			dfs(g, v, vis);
	}

int makeGraphConnected(int n, vector < pair < int,int > > edges, int m) {
	if(m<n-1) return -1;

	int ans=0;
	
	vector<vector<int>> g(n);
	unordered_set<int> vis;

	for(pair<int, int>& e: edges){
		int u = e.first, v=e.second;
		--u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	for(int i=0; i<n; ++i){
		if(vis.insert(i).second){
			dfs(g, i, vis);
			++ans;
		}
	}

	return ans-1;
}
```

## String Queries
You are a string ‘S’ containing lower case English alphabets. You need to process ‘Q’ queries. For each query, you are given two integers, one denoting the type ‘Type’ of the query and the second denoting the index ‘Idx’ (0 ≤ Idx ≤ |S| - 1) for this query. The two types of queries are:
1) For each query of type-1, you need to find the largest substring that contains the same elements and the substring must include the Idx’th index, ie: you need to find the largest substring [L, R] such that L ≤ Idx ≤ R and all the elements in the substring are the same. Note that if the element at S[Idx] is equal to ‘#’ then you have to print “-1”.

2) For each query of type-2, you need to replace the character at S[Idx] with ‘#’.
For each query of type-1, find the largest substring if it exists, else print “-1”.
```cpp
vector<int> stringQueries(string s, int q, vector<vector<int>> query) {
    vector<int> ans;
    for(int x=0; x<q; ++x){
        int idx = query[x][1];
        
        if(query[x][0]==2){
            s[idx]='#';
         
        }

        if(query[x][0]==1){
            int left=0, right=0;
            if(s[idx]=='#'){
                ans.push_back(-1);
                continue;
            }

            for(int i=idx; s[i]==s[idx] && i>=0; --i){
                ++left;
            }
            for(int j=idx+1; s[j]==s[idx] && j<s.size(); ++j){
                ++right;
            }
            ans.push_back(left+right);
            
        }
    }
    return ans;
}
```

## Largest Component
You are given an array 'ARR' of size 'N' containing positive integers. Consider an undirected graph using the given array with the following conditions:
-> The graph consists of 'N' vertices.
-> The ith vertex has a value 'ARR[i]'.
-> There is an edge between two vertices 'i' and 'j' (where 'i' < 'j'), if and only if GCD('ARR[i]', 'ARR[j]') is greater than 1.
GCD(a, b) is the maximum number x such that both a and b are divisible by x.
Your task is to find the size of the largest component in the graph.
A component of an undirected graph is a subgraph in which any two vertices are connected to each other by paths, and which is connected to no additional vertices in the rest of the graph. The size of a component is the number of vertices in it.

```cpp
#include <bits/stdc++.h>
using namespace std;

#define ll long long
struct dsu{
    vector<int> p, sz;
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

int largestComponent(vector<int>& a, int N){
    dsu ds;
    int ans=0;
    bool all1=1;
   for(int i=0; i<N; ++i){
       if(a[i] != 1){
           all1 = 0;
           break;
       }
   }
    if(all1) return 1;
    
    int n = *max_element(begin(a), end(a));
    
    ds.init(n);
    unordered_map<int, int> count;
    
    for(int i: a){
        for(int x=2; x<=sqrt(i); ++x){
            if(i%x==0){
                ds.join(i, x);
                ds.join(i, i/x);
            }
        }
    }
    
    for(int i: a)
        if(i!=1)
             ans = max(ans, ++count[ds.find(i)]);
     
    
    return ans;
}
```
