## Search Engine
Let us see how search engines work. Consider the following simple auto complete feature. When you type some characters in the text bar, the engine automatically gives best matching options among it's database. Your job is simple. Given an incomplete search text, output the best search result.
Each entry in engine's database has a priority factor attached to it. We consider a result / search suggestion best if it has maximum weight and completes the given incomplete search query. For each query in the input, print the maximum weight of the string in the database, that completes the given incomplete search string. In case no such string exists, print -1.
Note: All the strings in database will be unique.
```
CONSTRAINTS
1 ≤ n, weight, len(s), len(t) ≤ 10^6
1 ≤ q ≤ 10^5
total length of all strings in database entries ≤ 10^6
total length of all query strings ≤ 10^6
SAMPLE INPUT
2 1
potential 10
potent 8
pot
SAMPLE OUTPUT
10
```
```cpp
typedef struct Node {
    Node *nxt[26];
    int maxSubtree;

    Node(){
        maxSubtree = 0;
        for(int i=0; i<26; ++i) nxt[i] = NULL;
    }
} Node;

void insert(Node *cur, pair<string, int>& db, int idx){
    if(idx == db.first.size()){
        cur->maxSubtree = db.second;
        return;
    }

    cur->maxSubtree = max(cur->maxSubtree, db.second);
    int nxtIdx = (int)(db.first[idx]-'a');

    if(cur->nxt[nxtIdx] == NULL)
        cur->nxt[nxtIdx] = new Node();
    
    insert(cur->nxt[nxtIdx], db, idx+1);
}

int query(Node *cur, string& t, int idx){
    if(cur==NULL) return -1;
    if(idx == t.size())
        return cur->maxSubtree;
    
    int nxtIdx = (int)(t[idx]-'a');
    return query(cur->nxt[nxtIdx], t, idx+1);
}

vector<int> searchEngine(vector<pair<string, int> > db, vector<string> t)
{
    Node *root = new Node();
    for(int i=0; i<db.size(); ++i)
        insert(root, db[i], 0);
    
    vector<int> ans;
    for(int i=0; i<t.size(); ++i){
        string txt = t[i];
        int res = query(root, txt, 0);
        ans.push_back(res);
    }
    return ans;
    
}
```
