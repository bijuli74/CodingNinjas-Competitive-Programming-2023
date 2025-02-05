## N-Queens
You are given an integer 'N'. For a given 'N' x 'N' chessboard, find a way to place 'N' queens such that no queen can attack any other queen on the chessboard.
A queen can be killed when it lies in the same row, or same column, or the same diagonal of any of the other queens. You have to print all such configurations.
```cpp
void addSol(vector<vector<int>> &board, int n, vector<vector<int>> &ans) {
  vector<int> state;
  for (auto i : board) 
    for (auto j : i)
      state.push_back(j);
  

  ans.push_back(state);
  return;
}

bool isValid(vector<vector<int>> & board, int row, int col) {
  // check this row on the left
  for (int i = 0; i < col; ++i) {
    if (board[row][i] == 1)
      return false;
  }
  // check upper left diagonal
  for (int i = row, j = col; i >= 0 && j >= 0; --i, --j)
    if (board[i][j] == 1)
      return false;

  // check lower left diagonal
  for (int i = row, j = col; i < board.size() && j >= 0; ++i, --j)
    if (board[i][j] == 1)
      return false;
  // if its safe to place the queen
  return true;
}

void dfs(vector<vector<int>> &board, int col, int n, vector<vector<int>> &ans) {
  // base case
  if (col >= n) {
    addSol(board, n, ans);
    return;
  }
  // iterate over all the rows
  for (int row = 0; row < n; row++) {
    if (isValid(board, row, col)) {
      // mark this state with queen
      board[row][col] = 1;

      // recursive all the helper function
      dfs(board, col + 1, n, ans);

      // backtrack to the prev state
      board[row][col] = 0;
    }
  }
  return;
}

 vector<vector<int>> solveNQueens(int n) {
  vector<vector<int>> ans;
  vector<vector<int>> board(n, vector<int>(n, 0));
  dfs(board, 0, n, ans);
  return ans;
}
```

## Paths in a Maze
You are given a 2-D matrix consisting of 0’s and 1’s with ‘N’ rows and ‘N’ columns, you are supposed to find all paths from the cell (0,0) (top-left cell) to the cell (N-1, N-1)(bottom-right cell). All cells with value 0 are blocked and cannot be travelled through while all cells with value 1 are open.
If you are currently at cell (x,y) then you can move to (x+1,y)(denoted by ‘D’), (x-1,y)(denoted by ‘U’), (x,y+1)(denoted by ‘R’), (x,y-1)(denoted by ‘L’) in one move. You cannot move out of the grid.
```cpp
void dfs(vector<vector<bool>> &arr, vector<string> &paths, string path,
          int row, int col) {
  int n = arr.size();

  if (row == -1 || row == n || col == -1 || col == n)
    return;

  if (row == n - 1 && col == n - 1 && arr[row][col] == 1) {
    paths.push_back(path);
    return;
  }

  if (arr[row][col] == 1) {
    arr[row][col] = 0;

    dfs(arr, paths, path + "U", row - 1, col); //    up
    dfs(arr, paths, path + "R", row, col + 1); //    right
    dfs(arr, paths, path + "D", row + 1, col); //    down
    dfs(arr, paths, path + "L", row, col - 1); //    left

    arr[row][col] = 1;
  }
}

vector<string> findAllPaths(vector<vector<bool>> &arr) {
  //    Write your code here.
  vector<string> paths;
  dfs(arr, paths, "", 0, 0);
  return paths;
}

```

## Reach the destination
Given a source point (sx, sy) and a destination point (dx, dy), the task is to check if it is possible to reach the destination point using the following valid moves:
(a, b) -> (a + b, b)
(a, b) -> (a, a + b)
Your task is to find if it is possible to reach the destination point using only the desired moves or not.

```cpp
bool reachDestination(int sx, int sy, int dx, int dy) {
    if(sx==dx && sy==dy) return 1;
    if(sx>dx || sy>dy) return 0;
    
   if(dx>dy) reachDestination(sx, sy, dx-dy, dy);
   else reachDestination(sx, sy, dx, dy-dx);
}
```

## Crossword $
Send Feedback
CodingNinjas has provided a crossword of 10*10 grid. The grid contains '+' or '-' as its cell values. Now, you are also provided with a word list that needs to placed accurately in the grid. Cells marked with '-' are to be filled with word list.
For example, The following is an example for the input crossword grid and the word list.
```
+-++++++++
+-++-+++++
+-------++
+-++-+++++
+-++-+++++
+-++-+++++
++++-+++++
++++-+++++
++++++++++
----------
CALIFORNIA;NIGERIA;CANADA;TELAVIV
Output for the given input should be:
+C++++++++
+A++T+++++
+NIGERIA++
+A++L+++++
+D++A+++++
+A++V+++++
++++I+++++
++++V+++++
++++++++++
CALIFORNIA
```
```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 10;

void printout(vector<string>& mat, int n){
    for(int i=0; i<n; i++)
			cout<<mat[i]<<'\n';
}

vector<string> checkHorz(int x, int y, vector<string> mat, string cur_word){
	int n = cur_word.size();
	for(int i=0; i<n; i++){
		if(mat[x][y+i]=='-' || mat[x][y+i]==cur_word[i])
			mat[x][y+i] = cur_word[i];
		else{
			mat[0][0] = '@';
			return mat;
		}
	}
	return mat;
}

vector<string> checkVert(int x, int y, vector<string> mat, string cur_word){
	int n = cur_word.size();
	for(int i=0; i<n; i++){
		if(mat[x+i][y]=='-' || mat[x+i][y]==cur_word[i])
			mat[x+i][y] = cur_word[i];
		else{
			mat[0][0] = '@';
			return mat;
		}
	}
	return mat;
}

void solve(vector<string>& words, vector<string> mat, int idx, int n){
	if(idx < words.size()){
		string cur_word = words[idx];
		int mx_len = n - cur_word.size();

		for(int i=0; i<n; i++){
			for(int j=0; j<=mx_len; j++){
				vector<string> tmp = checkVert(j, i, mat, cur_word);
				if(tmp[0][0] != '@')
					solve(words, tmp, idx+1, n);
			}
		}

		for(int i=0; i<n; i++){
			for(int j=0; j<=mx_len; j++){
				vector<string> tmp = checkHorz(i, j, mat, cur_word);

				if(tmp[0][0] != '@')
					solve(words, tmp, idx+1, n);
			}
		}

	}
	else{
		printout(mat, n);
        cout<<endl;

		return;
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	vector<string> mat;
    
	for(int i=0; i<10; ++i){
        string s; cin>>s;
        mat.push_back(s);
    }

	vector<string> words;
	string s; cin>>s;
	int st=0;
	for(int i=0; i<s.size(); ++i){
		if(s[i]==';'){
			words.push_back(s.substr(st, i-st));
			st=i+1;
		}
	}
	words.push_back(s.substr(st, s.size()-st));
    
    //for(auto m: mat) cout<<m<<endl;
    //for(auto w: words) cout<<w<<" ";

	solve(words, mat, 0, N);
    return 0;
}
```

## Subset Sum
You are given an array of integers and a target K. You have to find the count of subsets of the given array that sum up to K.
Note:
1. Subset can have duplicate values.
2. Empty subset is a valid subset and has sum equal to zero.

```cpp
#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n, k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin>>a[i];

    int ans=0;
    for(int i=0; i<(1<<n); ++i){
        long long sum = 0;
        for(int j=0; j<n; ++j){
            if(i & (1<<j))
                sum +=a[j];
        }
        if(sum==k) ans++;
    }
    cout<<ans<<'\n';

}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t=1; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
```

## Valid Sudoku
You have been given a 9 X 9 2D matrix 'MATRIX' with some cells filled with digits(1 - 9), and some empty cells (denoted by 0).
You need to find whether there exists a way to fill all the empty cells with some digit(1 - 9) such that the final matrix is a valid Sudoku solution.
A Sudoku solution must satisfy all the following conditions-
1. Each of the digits 1 - 9 must occur exactly once in each row.
2. Each of the digits 1 - 9 must occur exactly once in each column.
3. Each of the digits 1 - 9 must occur exactly once in each of the 9, 3 x 3 sub-matrices of the matrix.

```cpp
bool check(int mat[9][9],int no,int i,int j){
    //checking row and column
    for(int k=0;k<9;k++){
        if(mat[i][k]==no || mat[k][j]==no){
            return false;
        }
    }
    //checking 3x3 subgrid
    int si=i-i%3;
    int sj=j-j%3;
    for(int i=si;i<si+3;i++){
        for(int j=sj;j<sj+3;j++){
            if(mat[i][j]==no){
                return false;
            }
        }
    }
    return true;
}
bool solveSudoku(int board[9][9], int i, int j)
{
    if(i==9) return true;
    if(j==9) return solveSudoku(board, i+1, 0);
    if(board[i][j] != 0) return solveSudoku(board, i, j+1);

    for(int c=1; c<=9; c++)
    {
        if(check(board, c, i, j)==true)
        {
            board[i][j] = c;
            if(solveSudoku(board, i, j+1)==true) return true;
            //otherwise backtrack
            board[i][j] = 0;
        }
    }
        
    return false;
}
bool isItSudoku(int matrix[9][9]) {
    // Write your code here.
   if(solveSudoku(matrix,0,0)==true){
       return true;
   }
    return  false;
}
```

## Construct the Lexicographically Largest Valid Sequence
You are given a positive integer N. Your task is to create the lexicographically largest sequence of length 2*N - 1 containing integers between 1 to N such that:
1. 1 occurs in the sequence exactly once.
2. Each integer between 2 to N(inclusive) occurs in the sequence exactly twice.
3. For each integer i between 2 to N, the distance between the two occurrences of i should be exactly i.

```cpp
vector<int> dfs(vector<int>& a, vector<int>& nums, int p){
    if(p==a.size()) 
        return a;
    if(a[p]!=0) 
        return dfs(a, nums, p+1);
    
    for(int i=nums.size()-1; i>=1; --i){
        int dist = i==1 ? 0: i;
        if(nums[i]!=0 && dist+p<a.size() && a[p+dist]==0){
            a[p] = a[p+dist] = i;
            nums[i] = 0;
            vector<int> ans = dfs(a, nums, p+1);

            if(!ans.empty())
                return ans;
            nums[i]=1;
            a[p] = a[p+dist] = 0;
        }
    }
    return {};
}
vector<int> validSequence(int n) {
    vector<int> a(2*n-1), nums(n+1, 1);
    return dfs(a, nums, 0);
}
```

## 24 Game
Ninja is feeling lonely, so he started playing online games. While searching for fun, he found an exciting game. In this game, Ninja has to choose four cards at random. On each card, there is a number between 1 to 9, both inclusive. For Ninja to win, he has to make the number 24 using the number on cards and the following operator *, /, +, -, (, ).
Help Ninja to find whether he will win the game or not, on the basis of his selection. If Ninja can win the game, print true otherwise, print false.
Example:-
If the cards Ninja chooses are 4, 1, 8, 7. Then Ninja can make 24 by (8 - 4) * (7 - 1). Hence Ninja can win, so you have to return true.

```cpp
bool find24(vector<double> vec) {


  if (vec.size() == 1) {
    return abs(vec[0] - 24.0) <= 0.0000001;
  }


  vector<char> operations = {'+', '-', '*', '/'};

  for (int i = 0; i < vec.size(); ++i) {

    for (int j = 0; j < vec.size(); ++j) {
      if (i == j) {
        continue;
      }

      vector<double> res;
      for (int k = 0; k < vec.size(); ++k) {
        if (k != i && k != j) {
          res.push_back(vec[k]);
        }
      }

      for (auto op : operations) {
        if ((op == '+' || op == '*') && i > j) {

          continue;
        }
        if (op == '/' && vec[j] == 0.0) {
          continue;
        }

        switch (op) {
        case '+':
          res.push_back(vec[i] + vec[j]);
          break;
        case '-':
          res.push_back(vec[i] - vec[j]);
          break;
        case '*':
          res.push_back(vec[i] * vec[j]);
          break;
        case '/':
          res.push_back(vec[i] / vec[j]);
          break;
        }

        if (find24(res)) {
          return true;
        }

        res.pop_back();
      }
    }
  }
  return false;
}

bool judge(vector<int> &nums) {
  vector<double> vec;
  for (auto n : nums) {

    vec.push_back(n * 1.0);
  }

  return find24(vec);
}
```

# SPOJ DIGGER OCTAVES

After many years spent playing Digger, little Ivan realized he was not taking advantage of the octaves. Oops, sorry! Most of you were not born when Digger came to light!

Digger is a Canadian computer game, originally designed for the IBM personal computer, back in 1983. The aim of the game is to collect precious gold and emeralds buried deep in subterranean levels of and old abandoned mine.

We Digger gurus call a set of eight consecutive emeralds an octave. Notice that, by consecutive we mean that we can collect them one after another. Your Digger Mobile is able to move in the four directions: North, South, West and East.

In a simplified Digger version, consisting only of emeralds and empty spaces, you will have to count how many octaves are present for a given map.

Input
Input starts with an integer T, representing the number of test cases (1 ≤ T ≤ 20). Each test case consists of a map, described as follows:

An integer N (1 ≤ N ≤ 8), representing the side length of the square-shaped map. N lines follow, N characters each. A 'X' character represents an emerald, and a '.' represents an empty space.

Output
For each test case print the number of octaves on a single line.

Example
Input:
2
3
XXX
X.X
XXX
3
XXX
XXX
XXX

Output:
1
5

```cpp
#include <bits/stdc++.h>
 // spoj 
// https://www.spoj.com/problems/UCI2009D/
using namespace std;
bool vis[10][10];
vector<string>mine(10);
set< vector<pair<int,int>>> paths ;
int dirX[] = {0 , 0 , -1 , 1};
int dirY[] = {-1 , 1 , 0 , 0};

bool isSafe(int r, int c, int n, int m){
    return (r>=0 && r<n && c>=0 && c<m);
}

void countOct(int n, int r, int c, int total, vector<pair<int,int>>way){
    //base condition
    if(!isSafe(r,c,n,n) || mine[r][c]=='.' || vis[r][c]==1) return;
    vis[r][c]=1;
    way.push_back({r,c});

    // collected  8 gems
    if(total == 8){
        sort(way.begin(), way.end());
        paths.insert(way);
        vis[r][c]=0;
        return;
    }

    // not collected 8 gems
    for(int i=0;i<4;i++){
        int newR = r + dirX[i];
        int newC = c + dirY[i];
        countOct(n,newR,newC,total+1,way);
    }
    vis[r][c]=0;
}
 
 
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>mine[i];
        }
        paths.clear();
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                vector<pair<int,int>>way;
                countOct(n,i,j,1,way);
            }
        }
        cout<<paths.size()<<"\n";
    }
    return 0;
} 
```

# SPOJ MAKING JUMPS

```cpp
#include <iostream>
#include <bits/stdc++.h>
#define ll long long
const ll mod= 1e9+7;
const ll INF=2e14+10;
using namespace std;

// https://www.spoj.com/problems/MKJUMPS/
typedef struct{
    int ymin;
    int ymax;
}LIMIT;


LIMIT row[12];
bool visited[12][12];
int n;
int totalCells=0,okCells=0;


int dirX[] = {-2,-1, 1, 2, 2, 1,-1,-2};
int dirY[] = { 1, 2, 2, 1,-1,-2,-2,-1};


bool isValid(int x, int y){
    if(x<1 || x>n || y< row[x].ymin || y>row[x].ymax) return false;
    return true;
}


void solve(int x, int y, int total){
    // base condition
    if(total>okCells) okCells = total;
    
    for(int i=0;i<8;i++){
        int newX = x + dirX[i];
        int newY = y + dirY[i];
        if(isValid(newX,newY) && visited[newX][newY]==false){
            visited[newX][newY]=true;
            solve(newX,newY,total+1);
            visited[newX][newY]=false;
        }
    }
    return;
}
                
int main(){
    cin>>n;
    int t=1;
    do{
        totalCells=0;
        for(int i=1;i<=n;i++){
            int col,len;
            cin>>col>>len;
            row[i].ymin = col+1;
            row[i].ymax = row[i].ymin + len -1;
            totalCells+=len;
            
            for(int j=row[i].ymin ;j<=row[i].ymax;j++) visited[i][j]=false;
        }
        okCells=0;
        visited[1][1]=true;
        solve(1,1,1);
        cout<<"Case "<<t++ <<", "<<(totalCells-okCells);
        if(totalCells-okCells == 1) cout<<" square can not be reached.";
        else cout<<" squares can not be reached.";
        cout<<"\n";
        cin>>n;
    }while(n!=0);
    return 0;
}
```