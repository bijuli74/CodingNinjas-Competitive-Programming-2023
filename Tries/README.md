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
## Spoj ADAINDEX
```cpp
#include<bits/stdc++.h>

using namespace std;


typedef struct Node{
	Node *next[26];
	int cnt;

	Node() {
		for(int i=0; i<26; i++) next[i] = NULL;
		cnt = 0;
	}
}Node;

void insert(Node *curr, string &s, int index) {
	if(s.length() == index) {
		curr->cnt += 1;
		return;
	}
	curr->cnt += 1;
	int nextIndex = (int)(s[index] - 'a');
	if(curr->next[nextIndex] == NULL) {
		curr->next[nextIndex] = new Node();
	}

	insert(curr->next[nextIndex], s, index+1);

}

int search(Node *curr, string &s, int index) {
	if(curr == NULL) return 0;
	if(index == s.length()) {
		return curr->cnt;
	}

	int nextIndex = (int)(s[index] - 'a');
	return search(curr->next[nextIndex], s, index + 1);
}


int main() {
	freopen("input.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, q;
	cin>>n>>q;

	Node *root = new Node();
	for(int i=0; i<n; i++) {
		string word;
		cin>>word;
		insert(root, word, 0);
	}

	while(q--) {
		string s;
		cin>>s;
		cout<<search(root, s, 0)<<"\n";
	}
	return 0;
}
```
## Maximum XOR
You are given two arrays of non-negative integers say ‘arr1’ and ‘arr2’. Your task is to find the maximum value of ( ‘A’ xor ‘B’ ) where ‘A’ and ‘B’ are any elements from ‘arr1’ and ‘arr2’ respectively and ‘xor’ represents the bitwise xor operation.
```cpp
typedef struct Node{
    Node *next[2];

    Node(){
        for(int i=0; i<2; ++i) next[i]=NULL;
    }
} Node;

void insert(Node *cur, int x, int i){
    if(i<0) return;
    if((x & (1<<i)) > 0){
        if(cur->next[1] == NULL)
            cur->next[1] = new Node();
        insert(cur->next[1], x, i-1);
    }else{
        if(cur->next[0] == NULL)
            cur->next[0] = new Node();
        insert(cur->next[0], x, i-1);
    }
}

int search(Node *cur, int x, int i){
    if(i<0) return 0;
    if((x & (1<<i)) > 0){
        if(cur->next[0] != NULL)
            return ((1<<i) + search(cur->next[0], x, i-1));
        else
            return search(cur->next[1], x, i-1);
    }else{
        if(cur->next[1] != NULL)
            return ((1<<i) + search(cur->next[1], x, i-1));
        else
            return search(cur->next[0], x, i-1);
    }
}
int maxXOR(int n, int m, vector<int> &a1, vector<int> &a2) 
{
    Node *root = new Node();
    int M = 30;
    int ans = 0;

    for(int i=0; i<n; ++i)
        insert(root, a1[i], M);
    
    for(int i=0; i<m; ++i)
         ans = max(ans, search(root, a2[i], M));
    
    return ans;
}
```

## CF Vasily's multiset

```cpp
#include<bits/stdc++.h>
#define int long long

using namespace std;

typedef struct Node {
	Node *left, *right;
	int cnt;

	Node() {
		left = right = NULL;
		cnt = 0;
	}
}Node;

void insert(Node *curr, int x, int i) {
	curr->cnt += 1;
	if(i == -1) return;

	if((x&(1ll<<i)) > 0) {
		if(curr->right == NULL) {
			curr->right = new Node();
		}
		insert(curr->right, x, i-1);
	} else {
		if(curr->left == NULL) {
			curr->left = new Node();
		}
		insert(curr->left, x, i-1);
	}
}

Node *remove(Node *curr, int x, int i) {
	curr->cnt -= 1;
	if(curr->cnt == 0) return NULL;
	if(i == -1) return curr;
	if((x&(1ll<<i)) > 0) {
		curr->right = remove(curr->right, x, i-1);
	} else{
		curr->left = remove(curr->left, x, i-1);
	}
	return curr;
}

int search(Node *curr, int x, int i) {
	if(i == -1) return 0;
	if((x&(1ll<<i)) > 0) {
		if(curr->left != NULL) {
			return ((1ll<<i) + search(curr->left, x, i-1));
		}
		return search(curr->right, x, i-1);
	} else{
		if(curr->right != NULL) {
			return ((1ll<<i) + search(curr->right, x, i-1)); 
		}
		return search(curr->left, x, i-1);
	}
}

signed main() {
	freopen("input.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	Node * root = new Node();
	int M = 31;
	insert(root, 0, M);
	int q;
	cin>>q;
	while(q--) {
		string type;
		int x;
		cin>>type>>x;

		if(type == "+") {
			insert(root, x, M);
		} else if(type == "-") {
			root = remove(root, x, M);
		} else {
			cout<<search(root, x, M)<<"\n";
		}
	}
	return 0;
}
```

## Spell Checker
You are given a list of strings, ‘DICTIONARY[]’ that represents the correct spelling of words and a query string ‘QUERY’ that may have incorrect spelling. You have to check whether the spelling of the string ‘QUERY’ is correct or not. If not, then return the list of suggestions from the list ‘DICTIONARY’. Otherwise, return an empty list which will be internally interpreted as the correct string.
Note:
1) The suggested correct strings for the string  ‘QUERY’ will be all those strings present in the ‘DICTIONARY[]’ that have the prefix same as the longest prefix of string ‘QUERY’.

2) The ‘DICTIONARY[]’ contains only distinct strings.

```cpp
typedef struct Node{
    Node *next[26];
    bool isEnd;

    Node() {
      for (int i = 0; i < 26; ++i)
        next[i] = NULL;
      isEnd = false;
    }

} Node;

void insert(Node* cur, string& s){
    int i=0;
    while(i<s.size()){
        int index = s[i]-'a';
        if(cur->next[index] == NULL)
            cur->next[index] = new Node();
        
        cur = cur->next[index];
        i++;
    }

    cur->isEnd = true;

}

void search(Node* cur, string res, vector<string>& ans){
    if(cur->isEnd){
        ans.push_back(res);
        return;
    }

    for(int i=0; i<26; ++i){
        if(cur->next[i] != NULL){
            res.push_back(i+'a');
            search(cur->next[i], res, ans);
            res.pop_back();
        }
    }
}
vector<string> spellChecker(vector<string> &dict, string &query){
    Node *root = new Node();
    for(int i=0; i<dict.size(); ++i)
        insert(root, dict[i]);
    
    vector<string> ans;
    for(int i=0; i<query.size(); ++i){
        int index = query[i]-'a';
        if(root->next[index] == NULL){
            string pf = query.substr(0, i);
            search(root, pf, ans);
            return ans;
        }
        root = root->next[index];
    }

    if(root->isEnd == true)
        return ans;
    
    search(root, query, ans);
    return ans;
}
```

## Help Pradyumana!
Send Feedback
Pradyumn is tired of using auto - correct feature in his smartphone. He needs to correct his auto - correct more times than the auto - correct corrects him. Pradyumn is thinking to make his own app for mobile which will restrict auto - correct feature, instead it will provide auto - completion. Whenever Pradyumn types factorial, auto - correct changes it to fact. Pradyumn's App will show options such as fact, factorial, factory. Now, he can chose from any of these options. As Pradyumn is busy with his front - end work of his App. He asks you to help him. He said "You will be given set of words(words may repeat too but counted as one only). Now, as user starts the app, he will make queries(in lowercase letters only). So, you have to print all the words of dictionary which have the prefix same as given by user as input. And if no such words are available, add this word to your dictionary." As you know, Pradyumn want this app to be as smart as him :P So, implement a program for him such that he can release it on Fun Store.
Input Format:
Single integer N which denotes the size of words which are input as dictionary
N lines of input, where each line is a string of consisting lowercase letter
Single integer Q which denotes the number of queries.
Q number of lines describing the query string on each line given by user
```
Constraints:
1 ≤ N ≤ 30000
sum(len(string[i])) ≤ 2∗10^5
1 ≤ Q ≤ 10^3
Output Format:
If auto - completions exists, output all of them in lexicographical order else output "No suggestions" without quotes
Sample Input 1:
3
fact
factorial
factory
2
fact
pradyumn
Sample Output 1:
fact
factorial
factory
```
```cpp
#include <bits/stdc++.h>
using namespace std;

typedef struct Node {
  Node *next[26];
  bool isLeaf;

  Node() {
    for (int i = 0; i < 26; ++i)
      next[i] = NULL;
    isLeaf = false;
  }

} Node;

void insert(string s, Node* root){
    if(s.size()==0){
        root->isLeaf = true;
        return;
    }
    Node* cur;
    int idx = s[0]-'a';
    if(root->next[idx] != NULL)
        cur = root->next[idx];
    else{
        cur = new Node();
        root->next[idx] = cur;
        cur = root->next[idx];
    }
    insert(s.substr(1), cur);
}

void helper(Node* cur, string pf){
    bool ok = true;
    if(cur->isLeaf)
        cout << pf << '\n';
    
    for(int i=0; i<26; ++i){
        Node* tmp = cur;
        if(tmp->next[i] != NULL){
            char sf = (int)i + (int)'a';
            helper(cur->next[i], pf+sf);
        }
    }
}

void printer(Node* root, string s){
    Node* cur = root;
    for(int i=0; i<s.size(); ++i){
        int idx = s[i]-'a';
        if(cur->next[idx] != NULL)
            cur = cur->next[idx];
        else{
            cout << "No suggestions" <<'\n';
            insert(s, root);
            return;
        }
    }
    helper(cur, s);
}

int main(){
    int n; cin>>n;
    Node* root = new Node();
    for(int i=0; i<n; ++i){
        string s; cin>>s;
        insert(s, root);
    }
    int q; cin>>q;
    for(int i=0; i<q; ++i){
        string s; cin>>s;
        printer(root, s);
    }
}
```

## Word Ladder
You are given two strings BEGIN and END and an array of strings DICT. Your task is to find the length of the shortest transformation sequence from BEGIN to END such that in every transformation you can change exactly one alphabet and the word formed after each transformation must exist in DICT.
Note:
1. If there is no possible path to change BEGIN to END then just return -1.
2. All the words have the same length and contain only lowercase english alphabets.
3. The beginning word i.e. BEGIN will always be different from the end word i.e. END (BEGIN != END).

```cpp
#include <bits/stdc++.h>
int wordLadder(string st, string ed, vector<string> &dict) 
{
	unordered_map<string, bool> mp;
	for(int i=0; i<dict.size(); ++i) mp[dict[i]] = false;
	if(!mp.count(ed)) return -1;
	//bfs
	int ans = 1;
	queue<string> q;
	q.push(st);
	while(q.size()){
		int m = q.size();
		for(int i=0; i<m; i++){
			string s = q.front();
			q.pop();
			if(s==ed) return ans;
			string cur = s;
			for(int j=0; j<s.size(); ++j){
				for(int k=0; k<26; ++k){
					cur[j] = 'a'+k;
					if(mp.count(cur) && !mp[cur]){
						mp[cur] = true;
						q.push(cur);
					}
					cur = s;
				}
			}
		}
		ans++;
	}
	return -1;
}
```

## Sub - XOR
Given an array of positive integers, you have to print the number of subarrays whose XOR is less than K. Subarrays are defined as a sequence of continuous elements Ai, Ai + 1, ..., Aj. XOR of a subarray is defined as Ai ^ Ai + 1 ^ ... ^ Aj. Symbol ^ is Exclusive Or.
```cpp
#include<bits/stdc++.h>
using namespace std;
class trienode {
public:
  int left_count, right_count;
  trienode *left;
  trienode *right;
  trienode() {
    left_count = 0;
    right_count = 0;

    // Left denotes 0
    left = NULL;

    // Right denotes 1
    right = NULL;
  }
};
void insert(trienode *root, int element) {
  for (int i = 31; i >= 0; i--) {
    int x = (element >> i) & 1;

    // If the current bit is 1
    if (x) {
      root->right_count++;
      if (root->right == NULL)
        root->right = new trienode();
      root = root->right;
    } else {
      root->left_count++;
      if (root->left == NULL)
        root->left = new trienode();
      root = root->left;
    }
  }
}
int query(trienode *root, int element, int k) {
  if (root == NULL)
    return 0;
  int res = 0;
  for (int i = 31; i >= 0; i--) {
    bool current_bit_of_k = (k >> i) & 1;
    bool current_bit_of_element = (element >> i) & 1;

    // If the current bit of k is 1
    if (current_bit_of_k) {
      // If current bit of element is 1
      if (current_bit_of_element) {
        res += root->right_count;
        if (root->left == NULL)
          return res;
        root = root->left;
      }

      // If current bit of element is 0
      else {
        res += root->left_count;
        if (root->right == NULL)
          return res;
        root = root->right;
      }
    }

    // If the current bit of k is zero
    else {
      // If current bit of element is 1
      if (current_bit_of_element) {
        if (root->right == NULL)
          return res;
        root = root->right;
      }

      // If current bit of element is 0
      else {
        if (root->left == NULL)
          return res;
        root = root->left;
      }
    }
  }
  return res;
}

int main(){

  
  int n, k; cin>>n>>k;
  int arr[n];
  for(int i=0; i<n; ++i) cin>>arr[i];

  // Below three variables are used for storing
  // current XOR
  int temp, temp1, temp2 = 0;
  trienode *root = new trienode();
  insert(root, 0);
  long long total = 0;
  for (int i = 0; i < n; i++) {
    temp = arr[i];
    temp1 = temp2 ^ temp;
    total += query(root, temp1, k);
    insert(root, temp1);
    temp2 = temp1;
  }

  cout << total << endl;

  return 0;
}
```
## Count Distinct Substrings
Given a string 'S', you are supposed to return the number of distinct substrings(including empty substring) of the given string. You should implement the program using a trie.
Note :
A string ‘B’ is a substring of a string ‘A’ if ‘B’ that can be obtained by deletion of, several characters(possibly none) from the start of ‘A’ and several characters(possibly none) from the end of ‘A’. 

Two strings ‘X’ and ‘Y’ are considered different if there is at least one index ‘i’  such that the character of ‘X’ at index ‘i’ is different from the character of ‘Y’ at index ‘i’(X[i]!=Y[i]).
```cpp
struct Node{
    Node *links[26];
    
    bool containsKey(char ch){
        return (links[ch-'a'] != NULL);
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void insert(char ch, Node* node){
        links[ch-'a'] = node;
    }
};

int countDistinctSubstrings(string &s)
{
    Node *root = new Node();
    int cnt = 0;
    for(int i=0; i<s.size(); ++i){
        Node *node = root;
        for(int j=i; j<s.size(); ++j){
            if(!node->containsKey(s[j])){
                cnt++;
                node->insert(s[j], new Node());
            }
            node = node->get(s[j]);
        }
    }
    return cnt+1;
}
```

## Unique Matrix
You are given a binary matrix 'MATRIX' of 'N' rows and 'M' columns.
Your task is to return all the unique rows in the order they appear in the matrix.
For example:
Matrix = [ [1,0,1], [0,0,1 ], [1,0,1 ]] 
Result = [ [1,0,1], [0,0,1] ]. 
The row [1,0,1] is before [0,0,1] as it appears before in matrix.
Note: In the binary matrix, all the entries are either 0 or 1.
```cpp
#include <bits/stdc++.h>
vector<vector<int>> uniqueRow(vector<vector<int>> &g, int n, int m)
{
      vector<vector<int>> ans;

      unordered_map<string, int> mp;
      for(int i=0; i<n; ++i){
            string s;
            for(int j=0; j<m; ++j){
                  s += to_string(g[i][j]);
            }
            if (!mp.count(s)) {
              mp[s] = 1;
              ans.push_back(g[i]);
            }
      }
      return ans;
}
```
