## Chessboard Game
There is a chessboard of dimensions 15 X 15, and Alice and Bob start playing a game on it. The game is not chess, and involves just one coin.
The coordinates of the top left cell are (1,1) and the bottom right are (15,15). The coin is initially at (x,y). In each turn, the player whose turn it is can move the coin to any of the four cells (provided they are inside the board):
(x-2,y+1)
(x-2,y-1)
(x+1,y-2)
(x-1,y-2)
The figure below shows the possible moves of a coin at (5,4) (An 8 x 8 board is given in the image, but in the problem, it will always be a 15 x 15 board).
```cpp
vector<vector<int>> g(16, vector<int>(16, -1));

bool valid(int x, int y) {
    if(x<=0 || x>15 || y<=0 || y>15)
        return false;
    return true;
}

int f(int x, int y) {
  if (g[x][y] != -1)
    return g[x][y];

  else {
    bool isWin = false;
    if (valid(x - 1, y - 2)) {
      if (f(x - 1, y - 2) == 0)
        isWin = true;
    }

    if (valid(x + 1, y - 2)) {
      if (f(x + 1, y - 2) == 0)
        isWin = true;
    }

    if (valid(x - 2, y - 1)) {
      if (f(x - 2, y - 1) == 0)
        isWin = true;
    }

    if (valid(x - 2, y + 1)) {
      if (f(x - 2, y + 1) == 0)
        isWin = true;
    }

    if (isWin)
      g[x][y] = 1;
    else
      g[x][y] = 0;
    return g[x][y];
  }
}
string winnerOfGame(int x, int y)
{
    g[1][1]=g[1][2]=g[2][1]=g[2][2]=0;

    if(f(x, y)) return "First";
    else return "Second";

}
```
## Nim Game
Ninja and his friend are playing a game. They are having ‘N’ piles and each pile contains ‘A[i]’ amount of stones in it. Ninja will make the first move.
In each move, a player can choose any pile and remove any number of stones ( at least one ) from that pile. The player who cannot make a move loses the game.
Assuming both players play optimally, output 1 if Ninja wins the game and 0 if Ninja loses the game.
```cpp
int ninjaGame(vector<int> &a, int n) {
    int x = 0;
    for(int i=0; i<n; ++i)
        x^=a[i];
    
    return x ? 1 : 0;
}
```

## Calculate Grundy Number
Calculate the Grundy Number for the given 'n' in the game.
The game starts with a number- ‘n’ and the player to move divides the number- ‘n’ with 2, 3 or 6 and then takes the floor. If the integer becomes 0, it is removed. The last player to move wins. Which player wins the game?
```cpp
#include<bits/stdc++.h>
using namespace std;

const int mxN = 1e6;
vector<int> grundy(mxN+1, -1);

int mex(set<int> &s) {
  int mex = 0;
  while (s.count(mex))
    mex++;
  return mex;
}

int calculateGrundy(int n) {
  if (grundy[n] != -1)
    return grundy[n];
  set<int> S;
  S.insert(calculateGrundy(n / 2));
  S.insert(calculateGrundy(n / 3));
  S.insert(calculateGrundy(n / 6));
  grundy[n] = mex(S);
  return grundy[n];
}

int main(){
    int t; cin>>t;

    grundy[0]=0;

    while(t--){
     int n; cin>>n;
     int res = calculateGrundy(n);
     cout << res << '\n';
    }
    return 0;
}
```

## Floor Division Game
Jack and Michael are waiting in a room, eager to join the CodeKaze elimination Round. They decide to pass the time by playing a game.
In this game's setup, they write ‘N’ positive integers on a blackboard. Then the players take turns, starting with Jack. In one turn, a player selects one of the integers, divides it by 2, 3, 4, 5 or 6, and then takes the floor to make it an integer again. If the integer becomes 0, it is erased from the board. The player who makes the last move wins.
Jack and Michael are very competitive, so aside from wanting to win CodeKaze, they also want to win this game. Assuming they play with the optimal strategy, your task is to predict who wins the game.
```cpp
long long G[12] = {0, 1, 2, 2, 3, 3, 0, 0, 0, 0, 0, 0};

long long grundy(long long n){
	if(n<12) return G[n];
	else return grundy(n/12);
}
string game(int N, vector<long long> A)
{
	long long x = 0;
	for(auto& a: A)
		x ^= grundy(a);
	
	return x ? "Jack" : "Michael";
}
```
## Coin game winner where every player has three choices
Two players 'X' and 'Y', are playing a coin game. Initially, there are 'N' coins. Each player can pick exactly 'A' coins or 'B' coins or 1 coin. A player loses the game if he is not able to pick any coins. 'X' always starts the game, and each player plays optimally. You are supposed to find which player wins the coin game.
```cpp
int coinGameWinner(int n, int a, int b)
{
	int dp[n+1];
	dp[0]=0, dp[1]=1;
	// A wins game for n coins only when B loses for coins n-1 or n-a or n-b
	for(int i=2; i<=n; ++i){
		if(i-1>=0 && !dp[i-1])
			dp[i]=1;
		else if(i-a>=0 && !dp[i-a])
			dp[i]=1;
		else if(i-b>=0 && !dp[i-b])
			dp[i]=1;
		else
			dp[i]=0;
	}

	return dp[n];
}
```

## Game of Stones
Given the count of total stones in a game. Two-player ‘Ale’ and ‘Bob’ are playing the game. Your task is to find who will win the game if both the players are playing optimally.
Rules of the game.
1. In a single turn, a player can choose a single stone or ‘even’ number of stones.
2. They will play alternatively, which means in the first chance ‘Ale’ will collect the stones, in second-chance ‘Bob’ will collect the stones. And always ‘Ale’ will start the game.
3. If any player is not able to take any stones then another player will win the game.
```cpp
string gameOfStones(int n) {
   if(n%2==0) return "Ale"; //even nos stone P1 wins
   if( n == 3) return "Bob";
   else return "Ale";
}
```
## Coin game
Raman is playing a game with his friend Moni. They have a pile containing N coins. Players take alternate turns, removing some coins from the pile. On each turn, a player can remove either one coin or coins equal to some prime power. Game ends when the pile becomes empty. The player who picks the last stone wins.
Your task is to find out who will win the game if Raman plays first.
```cpp
void whoWins(int n){
	cout<< (n%6 ? "Raman" : "Moni") << '\n';
}
```
## Coin Tower
Whis and Beerus are playing a new game today. They form a tower of N coins and make a move in alternate turns. Beerus plays first. In one step, the player can remove either 1, X, or Y coins from the tower. The person to make the last move wins the game. Can you find out who wins the game?
```cpp
string findWinner(int n, int x, int y)
{
	int dp[n+1];
	dp[0]=0, dp[1]=1;
	for(int i=2; i<=n; ++i){
		if(i-1>=0 && !dp[i-1]) dp[i]=1;
		else if (i-x>=0 && !dp[i-x]) dp[i]=1;
		else if(i-y>=0 && !dp[i-y]) dp[i]=1;
		else dp[i]=0;
	}
	return dp[n] ? "Beerus" : "Whis";
}
```

## The Choco Game
Aahad and Harshit are playing a game. In this game, they have a chocolate of n X m dimensions. In each move, they can cut the chocolate horizontally or vertically. After cutting the chocolate into two pieces, the next player can choose any of the parts. Aahad always starts the game. Both of them are playing the game optimally. The one who cannot make a move will lose the game. You have to tell the name of winner.
```cpp
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, n, m;
	cin>>t; 
	while(t--){
		cin>>n>>m;
		cout << ( (n*m)&1 ? "Harshit": "Aahad" ) <<'\n';
	}
	return 0;
}
```

## Winner Of Candies
You and your friend met after a long time and decided to have candies. You brought ‘X’ candies while your friend brought ‘Y’ candies. Since you both were bored you decided to play a game where each of you will play one by one and you will start first. The game goes as follows :
In the ith move, the person will give i candies to the other person.
The person who is unable to donate the required amount of candies will lose. You are required to find out who will win the game.
For Example:
For X = 1, Y = 2 the game goes as follows - 
You will donate 1 candy. So you now have 0 and your friend has 3 candies.
Your friend will donate 2 candies. So you now have 2 and your friend has 1 candy.
You are required to donate 3 candies but you only have 2 candies.
Hence your friend wins.
```cpp
string winnerOfCandies(int x, int y){
    bool xWin = false;
    int i=1;
    while(true){
        if(i&1){
            if(x-i>=0){
                x-=i;
                y+=i;
            } else {
              break;
            }
        }
        else{
            if(y-i>=0){
                x+=i;
                y-=i;
            }else{
                xWin = true;
                break;
            }
        }
        ++i;
    }
    return xWin ? "Win" : "Lose";
}
```

## Game of Nim
Game of Nim Rules :
1. Given a number of piles,each pile contains some numbers of stones. 
2. The players take alternate turns. If the bitwise XOR of all piles equals 0 before a player's turn, then that player wins the game.
3. In his/her turn, a player must choose one of the remaining piles and remove it. (Note that if there are no piles, that player already won.)
Decide which player wins, given that both play optimally.

```cpp
void findWinner(int * arr, int n ){
  // https://www.codechef.com/problems/TWONIM
  cout << ((n & 1) ? "Second" : "First") << '\n';

  // int n;
  // read(n);
  // vt<int> a(n);
  // read(a);
  // int x = 0;
  // EACH(i, a) x ^= i;
  // bool ok = 1;
  // if (x != 0) {
  //   if (n & 1)
  //     ok = 0;
  // }
  // cout << (ok ? "First" : "Second") << '\n';
}
```
