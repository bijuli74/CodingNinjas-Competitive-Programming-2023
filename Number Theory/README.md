## Find Prime Numbers
You are given a positive integer ‘N’. Your task is to print all prime numbers less than or equal to N.
Note: A prime number is a natural number that is divisible only by 1 and itself. Example - 2, 3, 17, etc.
You can assume that the value of N will always be greater than 1. So, the answer will always exist.

```cpp
vector<int> primeNumbersTillN(int N) 
{ //Linear sieve method
 	vector<int> lp(N+1), pr;
	 for(int i=2; i<=N; ++i){
		 if(lp[i]==0){
			 lp[i]=i;
			 pr.push_back(i);
		 }
		 for(int j=0; i*pr[j]<=N; ++j){
			 lp[i*pr[j]] = pr[j];
			 if(pr[j]==lp[i])
			 	break;
		 }
	 }

	 return pr;
}
```

## Segmented Sieve Problem
In this problem you have to print all primes from given interval.

```cpp
#include<bits/stdc++.h>
using namespace std;

vector<char> segmentedSieveNoPreGen(long long L, long long R) {
    vector<char> isPrime(R - L + 1, true);
    long long lim = sqrt(R);
    for (long long i = 2; i <= lim; ++i)
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;
    return isPrime;
}

int main(){
    
    int t; cin>>t;
    int L, R;
   
    while(t--){
        vector<char> ans;
        cin>>L>>R;
        ans = segmentedSieveNoPreGen(L, R);
        for(int i=0; i<ans.size(); ++i)
            if(ans[i]) cout<<i+L<<" ";
        cout<<'\n';
    }
    return 0;
}
```

## Super Prime $
A number is called super-prime if it has exactly two distinct prime divisors
Example 10 , 6
You are supposed to find the count of super-prime numbers between 1 and N (inclusive).

```cpp
#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000000

int *spf = new int[MAXN];

void sieve() {
  spf[1] = 1;

  for (int i = 2; i < MAXN; i++)

    spf[i] = i;

  for (int i = 4; i < MAXN; i += 2)
    spf[i] = 2;

  for (int i = 3; i * i < MAXN; i++) {
    if (spf[i] == i) {
      for (int j = i * i; j < MAXN; j += i)

        if (spf[j] == j)
          spf[j] = i;
    }
  }
}

int findFactors(int x) {
  set<int> ret;
  while (x != 1) {
    ret.insert(spf[x]);
    x = x / spf[x];
  }

  return ret.size();
}

int superPrime(int n) {

  vector<int> nprimeArr;

  bool isPrime[n + 1];
  for (int i = 0; i <= n; i++) {
    isPrime[i] = true;
  }

  isPrime[0] = false;
  isPrime[1] = false;

  for (int i = 2; i * i <= n; i++) {
    if (isPrime[i] == true) {
      for (int j = i * i; j <= n; j += i) {
        isPrime[j] = false;
      }
    }
  } // O(NloglogN)

  for (int i = 1; i <= n; i++) {
    if (isPrime[i] == false) {
      nprimeArr.push_back(i);
    }
  } // O(n)

  int ansCount = 0;

  for (int j = 1; j < nprimeArr.size(); j++) {

    int p = findFactors(nprimeArr[j]); // O(logn)

    if (p == 2) {
      ansCount++;
    }
  }

  return ansCount;
}

int main() {

  // write your code here

  int n;
  cin >> n;

  sieve(); // O(nloglogn)

  int ans = superPrime(n);

  cout << ans << endl;
  return 0;
}
```

## Ninja and Flowers $
Ninja wants to get N flowers and he will pay i + 1 amount of money for the Ith flower, example (if n=3 he will pay {2,3,4})
Now he wants to pack these N flowers in boxes of different colours. With one condition if the cost of a flower is a prime divisor of another flower they needed to be of a different colour.
As we know that ninja is a little money minded he wants to minimize the number of different colours of boxes that he needs.

```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    if(n==1){
        cout<<1<<'\n';
        cout<<1<<'\n';
        return 0;
    }
    if(n==2){
        cout<<1<<'\n';
        cout<<2<<'\n';
    }

    vector<int> lpf(n+2);
    vector<int> pfs;
    for(int i=2; i<=n+1; ++i){
        if(!lpf[i]){
            pfs.push_back(i);
            lpf[i]=i;
        }
        for(int j=0; j<pfs.size()&& pfs[j]<=lpf[i]&& i*pfs[j]<=n+1; ++j)
            lpf[i*pfs[j]] = pfs[j];
    }

    int p = pfs.size();
    cout<<2<<'\n';
    cout<<min(p, n-p)<<" "<<max(p, n-p)<<'\n';
    return 0;
}
```

## Special Prime
Special Prime is a prime number that can be written as the sum of two neighbouring primes and 1.
You are given an integer N and you are supposed to find the number special prime in the range: [1, N].
Example of special prime 19 = 7 + 11 + 1
Neighbouring primes are prime number such that there is no other prime number between them.

```cpp
#include<bits/stdc++.h>
using namespace std;


void sieve(vector<bool>& is_prime, int n){
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
}
int main(){
    int n, ans=0;
    cin>>n;
    vector<bool> is_prime(n + 1, true);
    sieve(is_prime, n);
    vector<int> pr;
    for(int i=0; i<=n; ++i){
        if(is_prime[i])
            pr.push_back(i);
    }
    // for(int p: pr) cout<<p<<" ";
    for(int i=0; i<pr.size()-1; ++i){
        int x = pr[i]+pr[i+1]+1;
        if(x>n) break;
        if(is_prime[x]) ++ans;
    }
    cout<<ans<<'\n';
    return 0;
}
```

## Number Of Factors $
A number is called n-factorful if it has exactly n distinct prime factors. Given positive integers a, b, and n, your task is to find the number of integers between a and b, inclusive, that are n-factorful. We consider 1 to be 0-factorful.

```cpp
#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int mxA = 1e6;
void sieve(vector<int>& is_prime){
    for(int i=2; i<=mxA; ++i){
        if(!is_prime[i])
            for(int j=1; i*j<=mxA; ++j)
                is_prime[i*j] += 1;
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;

    vector<int> is_prime(mxA+1, 0);
    vector<vector<int>> dp(11, vector<int>(mxA+1));

    sieve(is_prime);
    for(int i=0; i<=10; i++){
        dp[i][0]=0;
        dp[i][1]=0;
        for(int j=2; j<=mxA; ++j)
            dp[i][j] = i==is_prime[j] ? dp[i][j-1]+1 : dp[i][j-1];
    }

    while(t--){
        int a, b, n;
        cin>>a>>b>>n;
        if(a==1 && n==0){
            cout<<1<<'\n';
            continue;
        }
        cout<< dp[n][b] - dp[n][a-1] << '\n';
    }

return 0;
}
```

## Sachin and Varun Problem
Varun and you are talking about a movie that you have recently watched while Sachin is busy teaching Number Theory. Sadly, Sachin caught Varun talking to you and asked him to answer his question in order to save himself from punishment. The question says:
Given two weights of a and b units, in how many different ways you can achieve a weight of d units using only the given weights? Any of the given weights can be used any number of times (including 0 number of times).
Since Varun is not able to answer the question, he asked you to help him otherwise he will get punished.
Note: Two ways are considered different if either the number of times a is used or a number of times b is used is different in the two ways.

```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Triplet {
public:
  ll gcd;
  ll x;
  ll y;
};
Triplet gcdExtendedEuclid(ll a, ll b) {
  // Base Case
  if (b == 0) {
    Triplet myAns;
    myAns.gcd = a;
    myAns.x = 1;
    myAns.y = 0;
    return myAns;
  }
  Triplet smallAns = gcdExtendedEuclid(b, a % b);
  // Extended euclid says
  Triplet myAns;
  myAns.gcd = smallAns.gcd;
  myAns.x = smallAns.y;
  myAns.y = (smallAns.x - ((a / b) * (smallAns.y)));
  return myAns;
}
ll modInverse(ll A, ll M) {
  ll x = gcdExtendedEuclid(A, M).x;
  return (x % M + M) % M;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    ll a, b, d;
    cin >> a >> b >> d;
    ll g = __gcd(a, b);
    // Special Cases
    if (d % g) {
      cout << 0 << endl;
      continue;
    }
    if (d == 0) {
      cout << 1 << endl;
      continue;
    }
    a /= g;
    b /= g;
    d /= g;
    ll y1 = ((d % a) * modInverse(b, a)) % a;
    ll firstValue = d / b;
    if (d < y1 * b) {
      cout << 0 << endl;
      continue;
    }
    ll n = (firstValue - y1) / a;
    ll ans = n + 1;
    cout << ans << endl;
  }
  return 0;
}
```

## Totient function
You are given an integer N and are supposed to find the value of Euler toient function for N phi(N)

```cpp

#include<bits/stdc++.h>
using namespace std;

long long phi(int n){
    if(n == 1) return 1;
    long long res = n;
    
    for(int i=2;i*i<=n;i++)
		if(n % i == 0){
            res = res * (i - 1);
			res = res / i;
            while(n % i == 0) n = n / i;
        }

    if(n > 1){
		res = res * (n - 1);
		res = res / n;
	}

	return res;

}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
	int t , n; cin>>t;
    while(t--){
		cin>>n;
        cout<<phi(n)<<endl;
	}

}

// const int N = 1e9;
// int phi[N + 1];

// void preprocess() {
//   for (int i = 1; i <= N; ++i)
//     phi[i] = i;

//   for (int i = 2; i <= N; ++i)
//     if (phi[i] == i) {
//       for (int j = i; j <= N; j += i) {
//         phi[j] = phi[j] / i;
//         phi[j] = phi[j] * (i - 1);
//       }
//     }
// }

// int main() {
//   int t;
//   cin >> t;
//   preprocess();

//   while (t--) {
//     int n;
//     cin >> n;
//     cout << phi[n] << '\n';
//   }
//   return 0;
// }
```

## GCD Sum
Consider all numbers from 1 to ‘N’, your task is to find the sum of gcd of all pairs (i, j) such that 1 <= i < j <= N.
For example for N = 3, all pairs are { (1, 2), (1, 3), (2, 3) }.
Note :
Gcd of two numbers (X, Y) is defined as the largest integer that divides both ‘X’ and ‘Y’. 

```cpp

vector<int> eulerTotient(int n) {
  vector<int> phi(n + 1);

  for (int i = 1; i <= n; i++) {
    phi[i] = i;
  }

  for (int i = 2; i <= n; i++) {
    if (phi[i] == i) {
      for (int j = i; j <= n; j += i) {
        phi[j] /= i;
        phi[j] *= (i - 1);
      }
    }
  }

  return phi;
}

// Function to calculate gcd sum of pairs (i, x) such that i <= x for all 'x'.
vector<int> preCompute(int n, vector<int> &phi) {
  // Declare an array to store 'f(x)' for all 'x' 1 to 'n'.
  vector<int> pre(n + 1);

  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j += i) {
      pre[j] += (i * phi[j / i]);
    }
  }

  return pre;
}

long long gcdSum(int n) {
  // Declare a variable to store gcd sum.
  long long answer = 0;

  // Declare an array 'phi' for Euler's totient fucntion values.
  vector<int> phi = eulerTotient(n);

  // Declare an array 'pre' to store 'f(x)' for each 'x' from 1 to 'n'.
  vector<int> pre = preCompute(n, phi);

  // Find sum of each f(x) for all 'x' such that: 1 <= x <= n.
  for (int i = 1; i <= n; i++) {
    answer += pre[i];
    answer -= i;
  }

  // Return answer.
  return answer;
}
```

## Divisors of Factorial
Given a number, find the total number of divisors of the factorial of the number.
Since the answer can be very large, print answer modulo 10^9+7.

```cpp
#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int mxA = 5e4;
const int M = 1e9+7;
vector<ll> lpf(mxA + 1);
vector<ll> pfs;

void preprocess() {

  for (ll i = 2; i <= mxA; ++i) {
    if (!lpf[i]) {
      pfs.push_back(i);
      lpf[i] = i;
    }
    for (ll j = 0;
         j < (int)pfs.size() && pfs[j] <= lpf[i] && i * pfs[j] <= mxA; ++j)
      lpf[i * pfs[j]] = pfs[j];
  }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    preprocess();
    while(t--){
        ll n; cin>>n;
        ll ans=1;
        for(ll& p: pfs){
            if(p>n) break;
            ll num=n;
            ll k=0;
            while(num>0){
                k=(k+num/p)%M;
                num /=p;
            }
            ans = (ans*(k+1)%M)%M;
        }
        cout<<ans<<endl;
    }
    return 0;
}
```

## Strange order
Given an integer n . Initially you have permutation p of size n : p[i] = i . To build new array a from p following steps are done while permutation p is not empty:
Choose maximum existing element in p and define it as x ; Choose all such y in p that gcd ( x , y ) ≠ 1 ; Add all chosen numbers into array a in decreasing order and remove them from permutation. Your task is to find a after p became empty.
Note: gcd ( a , b ) is the greatest common divisor of integers a and b .

```cpp
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ii pair<int, int>
#define fast_io     ios::sync_with_stdio(0);  cin.tie(0);

const int mxN=1e6;
vector<int> a(mxN);
void sieve(){
    iota(a.begin(), a.end(), 0);
    for(int i=2; i*i<=mxN; ++i)
        for(int j=i*i; j<=mxN; j+=i)
            if(a[j]>i) a[j]=i;
}

int main(){
    fast_io
    int n, k=0; cin>>n;
    sieve();

    vector<int> ans(n);
    vector<bool> vis(n+1, 0);
    for(int i=n; i>=1; --i){
        if(!vis[i]){
            int lpf = a[i];
            int x=i;
            vector<int> v;
            vis[i]=1;
            v.push_back(i);
            while(x>1){
                for(int j=i-lpf; j>=1; j=j-lpf)
                    if(!vis[j]){
                        vis[j]=1;
                        v.push_back(j);
                    }
                while(x%lpf==0)
                    x /= lpf;

                lpf=a[x];
            }
            sort(begin(v), end(v), greater<int>());
            for(int i=0; i<v.size(); ++i){
                ans[k]=v[i];
                ++k;
            }
        }
    }
    ans[n-1]=1;
    for(auto& i: ans) cout<<i<<" ";
    cout<<'\n';

    return 0;
}
```

## Card Game $
Vova again tries to play some computer card game.
The rules of deck creation in this game are simple. Vova is given an existing deck of n cards and a magic number k. The order of the cards in the deck is fixed. Each card has a number written on it; number ai is written on the i-th card in the deck.
After receiving the deck and the magic number, Vova removes x (possibly x = 0) cards from the top of the deck, y (possibly y = 0) cards from the bottom of the deck, and the rest of the deck is his new deck (Vova has to leave at least one card in the deck after removing cards). So Vova's new deck actually contains cards x + 1, x + 2, ... n - y - 1, n - y from the original deck.
Vova's new deck is considered valid iff the product of all numbers written on the cards in his new deck is divisible by k. So Vova received a deck (possibly not a valid one) and a number k, and now he wonders, how many ways are there to choose x and y so the deck he will get after removing x cards from the top and y cards from the bottom is valid?

```cpp
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ii pair<int, int>
#define fast_io ios::sync_with_stdio(0); cin.tie(0);

int main(){
	fast_io
	ll n, k, tmpK, ans=0;
	cin>>n>>k;
	tmpK=k;
	vector<ll> a(n);
	for(int i=0; i<n; ++i) cin>>a[i];

	vector<ii> pf;
	for(int i=2; i*i<=tmpK; ++i){
		if(tmpK%i==0){
			int cnt=0;
			while(tmpK%i==0){
				tmpK/=i;
				cnt++;
			}
			pf.push_back({i, cnt});
		}
	}
	if(tmpK!=1)
		pf.push_back({tmpK, 1});
	
	vector<ii> pf0 = pf;
	for(int i=0; i<pf0.size(); ++i)
		pf0[i].second =0;
	
	
	for(int i=0, j=0; i<n; ++i){
		for(int p=0; p<pf.size(); ++p){
			if(a[i]%pf[p].first ==0){
				tmpK=a[i];
				int c=0;
				while(tmpK%pf[p].first==0){
					tmpK/=pf[p].first;
					c++;
				}
				pf0[p].second += c;
			}
		}
		while(j<=i){
			int q;
			for(q=0; q<pf.size(); ++q)
				if(pf[q].second > pf0[q].second)
					break;
			
			if(q != pf.size())
				break;
			
			ans += n-i;

			for(q=0; q<pf.size(); ++q){
				if(a[j]%pf[q].first==0){
					tmpK = a[j];
					int c=0;
					while(tmpK%pf[q].first==0){
						tmpK /=pf[q].first;
						c++;
					}
					pf0[q].second -= c;
				}
			}
			++j;
		}
	}
	cout<<ans;

	return 0;
}
```

## Find The Cube Free Number
A cube free number is a number who’s none of the divisor is a cube number (A cube number is a cube of a integer like 8 (2 * 2 * 2) , 27 (3 * 3 * 3) ). So cube free numbers are 1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12, 13, 14, 15, 17, 18 etc (we will consider 1 as cube free). 8, 16, 24, 27, 32 etc are not cube free number. So the position of 1 among the cube free numbers is 1, position of 2 is 2, 3 is 3 and position of 10 is 9. Given a positive number you have to say if its a cube free number and if yes then tell its position among cube free numbers.
Note: we will consider 1 as the 1st cube free number

```cpp
#include<bits/stdc++.h>
using namespace std;

const int mxN=1e6;
vector<int> a(mxN+1, 0);

void sieve(){
    a[1]=1;
    for(int i=2; i<=100; ++i){
        int x = i*i*i;
        for(int j=1; x*j<=mxN; ++j)
            a[x*j]=-1;      //mark cubic nos as -1
    }
    int k=1;
    for(int i=1; i<=mxN; ++i)
        if(a[i]!=-1){
            a[i]=k;
            ++k;
        }
}
int main(){
    int t; cin>>t;
    
    sieve();

    while(t--){
        int n; cin>>n;
        if(a[n]==-1) cout<<"Not Cube Free"<<'\n';
        else cout<<a[n]<<'\n';
    }

    return 0;
}
```

## Euler Totient Function Sum
You are given a positive integer ‘N’, your task is to return an array/list of integers such that the sum of Euler Totient Function values of each integer of the array is equal to ‘N’.
Euler Totient Function:
In number theory, Euler's totient function counts the positive integers up to a given integer ‘N’ that is relatively prime to ‘N’.

```cpp
vector<int> eulerTotientFunction(int n){
    vector<int> ans;
    for(int i=1; i*i<=n; ++i){
        if(n%i==0){
            ans.push_back(i);
            if(n != (i*i))
                ans.push_back(n/i);
        }
    }
    return ans;
}
```

## Find the good sets! $
You are given array a consisting of n distinct integers. A set s of numbers is called good if you can rearrange the elements in such a way that each element divides the next element in the order, i.e. 'si' divides 'si + 1', such that i < |s|, where |s| denotes size of set |s|.
Find out number of distinct good sets that you can create using the values of the array. You can use one value only once in a particular set; ie. a set cannot have duplicate values. Two sets are said to be different from each other if there exists an element in one set, which does not exist in the other.
As the answer could be large, print your answer modulo 10^9 + 7.

```cpp
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 7.5e5;
const int M = 1e9 + 7;

vector<ll> a(mxN + 1);
int n;
void sieve() {
  vector<ll> sv(mxN + 1, 0);
  for (int i = 0; i < n; ++i)
    sv[a[i]] = 1;
  for (int i = 1; i <= mxN; ++i) {
    if (sv[i] != 0)
      for (int j = 2; j * i <= mxN; ++j)
        if (sv[j * i] != 0)
          sv[j * i] = (sv[j * i] % M + sv[i] % M) % M;
  }
  ll sum = 0;
  for (int i = 0; i <= mxN; ++i)
    sum = (sum % M + sv[i] % M) % M;
  cout << sum << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;

  while (t--) {
    cin >> n;
    for (int i = 0; i < n; ++i)
      cin >> a[i];
    sieve();
  }
  return 0;
}
```

## Fibonacci Sum  $$
The fibonacci sequence is defined by the following relation:
 F(0) = 0
 F(1) = 1
 F(N) = F(N - 1) + F(N - 2), N >= 2
Your task is very simple. Given two non-negative integers N and M (N <= M), you have to calculate and return the sum (F(N) + F(N + 1) + ... + F(M)) mod 1000000007.

```cpp
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector
#define mat vt<vt<ll>>
#define sz(x) (int)(x).size()

const int M = 1e9 + 7;
const ll M2 = (ll)M * M;

mat cn(int n, int m) { return vt<vt<ll>>(n, vt<ll>(m)); }

mat mult(mat &a, mat &b) { // Matrix Multiply
  mat c = cn(sz(a), sz(b[0]));
  for (int i = 0; i < (int)a.size(); ++i) {
    for (int k = 0; k < (int)b.size(); ++k) {
      for (int j = 0; j < (int)b[0].size(); ++j) {
        c[i][j] += a[i][k] * b[k][j];
        if (c[i][j] >= M2)
          c[i][j] -= M2;
      }
    }
  }

  for (int i = 0; i < (int)a.size(); ++i)
    for (int j = 0; j < (int)b[0].size(); ++j)
      c[i][j] %= M;

  return c;
}

ll solve(ll &n) {

  mat r = {{0, 1}};
  mat b = {{1, 1}, {1, 0}};

  while (n) { // Binary Exponentiation
    if (n & 1)
      r = mult(r, b);
    b = mult(b, b);
    n /= 2;
  }
  return r[0][1] % M;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    ll n, m;
    cin >> n >> m;
    n += 2; //need to modify n & m to +1 to work with my template my series 0, 1, 1, 2.. | Qs series 1, 1, 2, 3..
    m += 3;
    cout << (solve(m) - solve(n) + M) % M << '\n'; //F(M+2)-F(N+1)=ans
  }

  return 0;
}
```

## Sehwag and ETF $$
Sehwag has been solving a lot of mathematical problems recently. He was learning ETF (Euler Totient Function) and found the topic quite interesting. So, he tried solving a question on ETF. He will be given two numbers L and R. He has to find the probability that the ETF of a number in the range [L, R] is divisible by a number K.
Input Format:
The first line contains an integer T, representing the number of test cases.
The next T lines will contain three integers L, R and K.

```cpp
#include<bits/stdc++.h>
#define ll long long
#define MAX 1100001
#define ss(n) scanf("%lld", &n)
using namespace std;
bool primes[MAX];
ll phi[MAX];
ll p[300001];
ll num[MAX];
int main()
{
    ll t, a, b, k, i, j, x, base;
    cin >> t;
    for (i = 3; i < MAX; i += 2)
        primes[i] = 1;
    primes[2] = 1;
    for (i = 3; i * i < MAX; i += 2)
    {
        if (primes[i])
        {
            for (j = i * i; j < MAX; j += 2 * i)
                primes[j] = 0;
        }
    }
    p[0] = 2;
    ll c = 1;
    for (i = 3; i < MAX; i += 2)
    {
        if (primes[i])
            p[c++] = i;
    }
    while (t--)
    {
        cin >> a >> b >> k;
        if (k == 1)
        {
            std::cout << std::fixed;
            std::cout << std::setprecision(6) << 1 << endl;
            continue;
        }
        for (i = a; i <= b; i++)
        {
            phi[i - a] = i;
            num[i - a] = i;
        }
        for (i = 0; p[i] * p[i] <= b; i++)
        {
            base = a / p[i] * p[i];
            while (base < a)
                base += p[i];
            while (base < p[i])
                base += p[i];
            if (base == p[i])
            {
                // cout<<phi[base-a]<<endl;
                base += p[i];
            }
            for (j = base; j <= b; j += p[i])
            {
                while (num[j - a] % p[i] == 0)
                    num[j - a] /= p[i];
                phi[j - a] -= phi[j - a] / p[i];
                //cout<<j<<" "<<phi[j-a]<<endl;
            }
        }
        for (i = a; i <= b; i++)
        {
            if (num[i - a] > 1)
                phi[i - a] -= phi[i - a] / num[i - a];
            num[i - a] = 1;
        }
        ll c = 0;
        for (i = a; i <= b; i++)
        {
            //cout<<i<<" "<<phi[i-a]<<endl;
            if (phi[i - a] % k == 0)
                c++;
        }
        double ans = c;
        ans /= (b - a + 1);
        std::cout << std::fixed;
        std::cout << std::setprecision(6) << ans << endl;
    }
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long

// const ll mxN=1e12, mxA=1e6;

// unordered_map<ll, vector<ll>> mp;

// // vector<ll> lpf(mxA+1);
// // vector<ll> pfs;

// // void sieve(){
    
// //     for(int i=2; i<=mxA; ++i){
// //         if(!lpf[i]){
// //             pfs.push_back(i);
// //             lpf[i]=i;
// //         }
// //         for(int j=0; j<(int)pfs.size()&&pfs[j]<=lpf[i]&&i*pfs[j]<=mxA; ++j)
// //             lpf[i*pfs[j]]=pfs[j];
// //     }
// // }



// vector<bool> is_prime(mxN+1, 1);
// vector<ll> pfs;

// void sieve(){
// 	is_prime[0]=is_prime[1]=0;
// 	for(ll i=2; i*i<=mxN; ++i){
// 		if(is_prime[i]){
// 			for(ll j=i*i; j<=mxN; j+=i)
// 				is_prime[j]=0;
// 		}
// 	}
// }

// ll phi(ll n){
// 	if(n==1) return 1;
// 	ll res = n;
	
// 	for(ll i=2; i*i<=n; ++i)
// 		if(n%i==0){
// 			res *=(i-1);
// 			res /=i;
// 			while(n%i==0)
// 				n /=i;
// 		}
// 	if(n>1){
// 		res *=(n-1);
// 		res /=n;
// 	}
// 	return res;
// }

// void solve(){
// 	ll l, r, k; cin>>l>>r>>k;
// 	long double ans=0;
// 	for(ll i=0; i<=mxA; ++i){
// 		ll p = pfs[i];
// 		if(p>r) break;

// 		ll pos = (r/p)*p;
// 		for(ll i=2; i<=pos; ++i){
// 			if(i<l)
// 				break;
// 			mp[i].push_back(p);
// 			i-=p;
// 		}
// 	}
	
// 	for(ll i=l; i<=r; ++i)
// 		if(phi(i)%k==0)
// 			ans++;
	
// 	ans /= (r-l+1);
// 	cout<< fixed << setprecision(6) << ans<<'\n';
// }

// int main(){
// 	ios::sync_with_stdio(0);
// 	cin.tie(0);

// 	ll t; cin>>t;
	
// 	sieve();

//     for(ll i=0; i<=mxN; ++i)
//         if(is_prime[i])
//             pfs.push_back(i);

// 	while(t--){
// 		solve();
// 	}
// 	return 0;
// }
```

## Sanchit And Nuclear Reactor
Sanchit, an eccentric physicist, challenges his engineer friend Howard to solve a problem related to Sanchit's nuclear reactor. The reactor has a special condition where atoms reach a stable state when their number is a multiple of a prime number called the Cooper number. Howard needs to calculate the reactor's energy output after a given time T.
Input Format
The first line of input contains T(number of the test case), each test case follows as.
contian two space-separated integers N and M where M is a prime number.
Output Format
You have to determine the energy output after time T. As the number can be quite large so output it modulo Cooper number m.
```
Constraints:
1 <= T <= 100
1 <= N <= 10^18
1 <= M <= 10^4
Sample Input
2
1 5
2 5
Sample Output
1
2
Explanation
After 1 seconds, there is only 1 atom in the tank. Hence energy output is 1. After 2 seconds, there are 2 atoms which reacts to give energy output of 2.
```

```cpp
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define fast_io  ios::sync_with_stdio(0);  cin.tie(0);
//wilsons theoram application (p-1)! % p = p-1 where p is prime no
void solve(){
  ll n, m; cin>>n>>m;
  ll k=n/m;
  ll ans;
  if(k&1) ans=m-1;
  else ans=1;
  for(int i=1; i<= n%m; ++i)
    ans = (ans*i)%m;
  cout<<ans<<endl;
}
// ll fact(int x, int M){
//     ll res = 1;
//     for(int i=2; i<=x; ++i)
//         res= (res%M * i%M)%M;
//     return res;
// }

// void solve() {
//   ll t, M;
//   cin >> t >> M;
//   if (t < M) {
//     if (M - t == 1) {
//       cout << 1 << endl;
//       return;
//     } else {
//       cout << fact(t, M) % M << endl;
//       return;
//     }
//   } 
//   else {
//     ll last = t % M;
//     ll f = fact(last, M) % M;

//     if ((t / M) % 2 == 0){
//       cout << f << endl;
//     }
//     else{
//       cout << ((M - 1) % M * f % M) % M << endl;
//     }
//   }
//   return;
// }

int main() {
    fast_io
  int tt;
  cin >> tt;

  while (tt--) {
    solve();
  }
  return 0;
}
```

## GCD Extreme
Given the value of N, you will have to find the value of G. The meaning of G is given in the following code
G=0;
for(i = 1 ; i < N ; i++)
   for(j = i+1 ; j <= N ; j++) 
       G+=gcd(i,j);
Here gcd() is a function that finds the greatest common divisor of the two input numbers.

```cpp
const int mxN = 1e6 + 1;
vector<ll> phi(mxN);
vector<ll> S(mxN), G(mxN);

void precal() {
  phi[1] = 1;
  FOR(i, 2, mxN, 2) phi[i] = i / 2;
  FOR(i, 3, mxN, 2) {
    if (!phi[i]) {
      phi[i] = i - 1;
      FOR(j, i << 1, mxN, i) {
        if (!phi[j])
          phi[j] = j;
        phi[j] = phi[j] / i * (i - 1);
      }
    }
  }
  FOR(mxN)
  S[i] = phi[i];
  FOR(i, 2, mxN)
  for (int j = 2; j * i < mxN; ++j)
    S[i * j] += j * phi[i];

  G[1] = 0;
  FOR(i, 2, mxN)
  G[i] = G[i - 1] + S[i];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  read(t);

  precal();
  FOR(t) {
    // write("Case #", i+1, ": ");
    ll n;
    cin >> n;
    write(G[n], '\n');
  }
}
```

## Innocent Swaps and His Emotions $$
There are only three phases in Swaps life: Sleep, Play and Study. Also, there are two types of emotions Swaps experiences: Happy and Sad. Each phase of his life brings either kind of emotions.
The sleep and the play phase makes Swaps happy whereas the study phase makes him sad. Quite obvious, isn't it? But we know that life isn't that great, one cannot be happy all the time.
Swaps, being a very sensitive guy, doesn't like to mix his emotions on a particular day. So each day, he is in exactly one of the three phases.
Given N which denotes the number of days and K which denotes the exact number of days Swaps needs to be happy out of these N days, can you tell him in how many ways can he achieve this? Since the output value can be very large, take modulo with 1000000007(10^9+7)

```cpp
const int mxA = 1e6, M = 1e9 + 7;
ll iv[mxA + 1], f1[mxA + 1], f2[mxA + 1];

void solve() {

  iv[1] = 1; // Calculating mod inverse of all nos 2 to mxA
  for (int i = 2; i <= mxA; ++i)
    iv[i] = M - M / i * iv[M % i] % M;

  f1[0] = f2[0] = 1;
  for (int i = 1; i <= mxA; ++i) {
    f1[i] = i * f1[i - 1] % M;
    f2[i] = f2[i - 1] * iv[i] % M;
  }
}

ll power(ll b, ll p){      //modular Binary Exponentiation Function a^b 
	b%=M;
	ll r=1;
	while(p>0){
		if(p&1)
			r=r*b%M;
		b=b*b%M;
		p >>=1;  //p /=2
	}
	
	return r;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  read(t);

  solve();
  FOR(t) {
    // write("Case #", i+1, ": ");
    int n, k;
    read(n, k);
    ll ans = 0;

    ans = power(2, k)%M * f1[n]%M * f2[k] % M * f2[n - k] % M;  // nCk * 2^k (for either sleep/play to be happy)
    write(ans, '\n');
  }
}
```

## Cubic Square
Varun is learning method of successive squaring so that he can calculate a^b mod m quickly. To give himself practice he wrote many tuples of a, b and m and went to school thinking that he will do it after school.
After school he found that tuples he wrote are modified by his little sister. His sister converted each b into base 3. Varun wrote everything in base 10.

```cpp
#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll power(ll b, ll p, ll M){
    ll r = 1;
    b %=M;
    while(p>0){
        if(p&1)
            r = r*b%M;
        b = b*b%M;
        p>>=1;
    }
    return r;
}
int main(){
    int t; cin>>t;
    while(t--){
        ll a, M; 
        string b; 
        cin>>a>>b>>M;
        ll ans=1;
        ll y=0;
        ll x=0;
        for(ll i= b.size()-1; ~i; --i){
            // x = ( x+ (b[i]-'0') * power(3, p, M));
            // ll c = b[i]-'0';
            // x = x+c*(ll)pow(3, y);
            // ++y;

             if(b[i]=='2') ans = (((ans*a)%M) * a)%M;
            else if(b[i]=='1'){
                ans = (ans*a)%M;
            }

            a = (((a*a)%M) * a)%M;
        }
        ans = power(a, x, M);

        cout<<ans<<'\n';
    }
    return 0;
}
```

## Find the N-th term
You want to get tutelage under the Ultimate Ninja Ankush, but for that you have to pass his test. His test is simple: he has given you a relation function, F(n) = 2*F(n-1) + 3*F(n-2),where F(0) = F(1) = 1 and wants you to find the ‘N’th term for the function.
The 'N'th term can be very large, return it after modulus 10^9 + 7.
For example:
Given ‘N’ = 3,
F(3) = 13,This is because F(0) = 1, F(1) = 1, Therefore F(2) = 2*F(1) + 3*F(1), therefore F(2) = 5, and F(3) = 2*F(2) + 3*F(1), therefore F(3) = 13.

```cpp
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vt vector
#define mat vt<vt<ll>>
#define sz(x) (int)(x).size()

const int M = 1e9 + 7;
const ll M2 = (ll)M * M;

mat cn(int n, int m) { return vt<vt<ll>>(n, vt<ll>(m)); }

mat mult(mat &a, mat &b) { // Matrix Multiply
  mat c = cn(sz(a), sz(b[0]));
  for (int i = 0; i < (int)a.size(); ++i) {
    for (int k = 0; k < (int)b.size(); ++k) {
      for (int j = 0; j < (int)b[0].size(); ++j) {
        c[i][j] += a[i][k] * b[k][j];
        if (c[i][j] >= M2)
          c[i][j] -= M2;
      }
    }
  }

  for (int i = 0; i < (int)a.size(); ++i)
    for (int j = 0; j < (int)b[0].size(); ++j)
      c[i][j] %= M;

  return c;
}

ll solve(ll n) {

  mat r = {{0, 1}};
  mat b = {{2, 3}, {1, 0}};

  while (n) { // Binary Exponentiation
    if (n & 1)
      r = mult(r, b);
    b = mult(b, b);
    n /= 2;
  }
  // return r[0][1]%M;
  return (r[0][0]+r[0][1])% M;
}

 
long long int nthTerm(long long int n) {
	return solve(n);
}
```

## Find The Kth Prime
Ninja is given a crucial task. He is given a positive integer ‘K’, and he has to tell the ‘Kth’ prime number.
For example:
The first prime number is ‘2’, and the second prime number is ‘3’.

```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int kthPrime(int K)
{
	const int mxA=1e6;
	int p[mxA+1]={0};
	vector<ll> pfs;
	for(ll i=2; i<=mxA; ++i)
		if(!p[i]){
			for(ll j=i*i; j<=mxA; j+=i)
				p[j]=1;
			pfs.push_back(i);
		}

	
	return pfs[K-1];
}
```

## Remainder Check $$
You just learnt about the “mod” operation and you’re fascinated by it. ‘X’ mod ‘Y’ is defined as the remainder that ‘X’ leaves when divided by ‘Y’.
You are now given two integers ‘X’ and ‘Y’ and ‘Q’ queries of the type ‘L’, ’R’ and you want to find the number of integers ‘T’ in the range (L , R) (both ‘L’ and ‘R’ included) such that
( ( T mod X ) mod Y ) ≠ ( ( T mod Y ) mod X ) 
For example:
If ‘X’=4 and ‘Y’=6, and the range is [1,7], then the answer will be 2, as both 6 and 7 satisfy the above condition. 

```cpp
/*
Time Complexity: O(X*Y + Q)
Space Complexity: O(X*Y)
where 'X' and 'Y' are the given numbers
and 'Q' is the number of queries.
*/
// Returns number of valid integers on the range [0,t].
int countTill(int t, int len, vector<int> &pref) {
  return (t / len) * pref[len - 1] + pref[t % len];
}
vector<int> countValidNumbers(int x, int y, int q,
                              vector<pair<int, int>> queries) {
  // Vector to be returned.
  vector<int> ret(q);
  // Length of our array
  int len = x * y;
  // Prefix sum array computation.
  vector<int> pref(len);
  pref[0] = 0;
  for (int i = 1; i < len; ++i) {
    pref[i] = pref[i - 1];
    if ((i % x) % y != (i % y) % x) pref[i]++;
  }
  for (int i = 0; i < q; ++i) {
    int l = queries[i].first;
    int r = queries[i].second;
    // Number of valid integers ON [L,R] will be [0,R] - [0,L-1].
    int ans = countTill(r, len, pref) - countTill(l - 1, len, pref);
    ret[i] = ans;
  }
  return ret;
}
```

## Boring Factorials
Sameer and Arpit want to overcome their fear of Maths and so they have been recently practising Maths problems a lot. Aman, their friend has been helping them out. But as it goes, Sameer and Arpit have got bored with problems involving factorials. Reason being, the factorials are too easy to calculate in problems as they only require the residue modulo some prime and that is easy to calculate in linear time. So to make things interesting for them, Aman - The Mathemagician, gives them an interesting task. He gives them a prime number P and an integer N close to P, and asks them to find N! modulo P. He asks T such queries.

```cpp
#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll power(ll b, ll p, ll m){      //modular Binary Exponentiation Function a^b 
	b%=m;
	ll r=1;
	while(p>0){
		if(p&1)
			r=(r*b)%m;
		b=(b*b)%m;
		p >>=1;  //p /=2
	}
	
	return r;
}
void solve(){
    ll n, p; cin>>n>>p;
    ll ans=0;
    if(n>=p){
        cout<<ans<<'\n';
    }
    else{
        ans=p-1;
        for(int i=p-1; i>=n+1; --i){
            ans= ans*power(i, p-2, p)%p;  //modinv(i) = i^(p-2) % p from Fermat Little Theoram
        }
        cout<<ans<<'\n';
    }
    return;

}
int main(){
    
    int t; cin>>t;

    while(t--){
        solve();
    }
    return 0;
}
```

## Numbers and Remainders
Ninja is learning about the mathematical division and remainders. So in curiosity, he forms two lists of numbers ‘ARR’ and ‘REM’ both having ‘N’ numbers. Now Ninja is interested in finding the minimum positive number ‘X’ such that ‘X’ satisfies the following condition for all ‘N’ values:
X % ‘ARR’[i] = ‘REM’[i] (Remainder of X / ARR[i] should be equal to  ‘REM’[i]).
You are given two arrays ‘ARR’ and ‘REM’ both having ‘N’ values corresponding to the numbers and remainders. Your task is to find the smallest positive integer ‘X’ fulfilling the given conditions.

```cpp
#define ll long long
// Extended Euclid:
ll extendedGCD(ll a, ll b, ll &x, ll &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  ll x1, y1;
  ll d = extendedGCD(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return d;
}

ll numbersAndRemainders(int n, vector<int> &a, vector<int> &rem) {
  ll ans = 0, P = 1;
  for (ll i = 0; i < n; ++i) P *= a[i];

  for (ll i = 0; i < n; i++) {
    ll temp = (rem[i] * (P / a[i])) % P;
    ll x, y;
    ll g = extendedGCD(P / a[i], a[i], x,
                       y);  // To find the mod inverse of (P/a[i])%a[i]

    x = ((x % a[i]) + a[i]) % a[i];

    temp = (temp * x) % P;

    ans = (ans + temp) % P;
  }

  return ans;
}
```

## Income On Nth Day
Daulat Ram is an affluent business man. After demonetization, IT raid was held at his accommodation in which all his money was seized. He is very eager to gain his money back, he started investing in certain ventures and earned out of them. On the first day, his income was Rs. X, followed by Rs. Y on the second day. Daulat Ram observed his growth as a function and wanted to calculate his income on the Nth day.
The function he found out was FN = FN-1 + FN-2 + FN-1×FN-2
Given his income on day 0 and day 1, calculate his income on the Nth day (yeah Its that simple).

```cpp
#include <iostream>
#define ll long long
#define mod 1000000007
using namespace std;
ll fib(ll n) {
  if (n == 0 || n == 1 || n == 5)
    return n;
  if (n == 2)
    return 1;
  n--;
  ll a[2][2] = {1, 1, 1, 0};
  ll ans[2][2] = {1, 0, 0, 1};
  ll temp[2][2];
  ll m = mod - 1, i, j, k;
  while (n) {
    if (n & 1) {
      // ans=ans*a
      for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++) {
          temp[i][j] = 0;
          for (k = 0; k < 2; k++) {
            temp[i][j] += a[i][k] * ans[k][j];
            temp[i][j] %= m;
          }
        }
      for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
          ans[i][j] = temp[i][j];
    }
    // a=a*a
    for (i = 0; i < 2; i++)
      for (j = 0; j < 2; j++) {
        temp[i][j] = 0;
        for (k = 0; k < 2; k++) {
          temp[i][j] += a[i][k] * a[k][j];
          temp[i][j] %= m;
        }
      }
    for (i = 0; i < 2; i++)
      for (j = 0; j < 2; j++)
        a[i][j] = temp[i][j];
    n >>= 1;
  }
  return ans[0][0];
}
ll mpow(ll a, ll b) {
  ll ans = 1;
  while (b) {
    if (b & 1)
      ans = (ans * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return ans;
}
int main() {
  int t;
  ll a, b, c, n, i, x, y;
  cin >> t;
  while (t--) {
    cin >> a >> b >> n;
    if (n == 0)
      cout << a << endl;
    else if (n == 1)
      cout << b << endl;
    else {
      x = fib(n - 1);
      y = fib(n);
      // cout<<x<<" "<<y<<endl;
      c = mpow(a + 1, x) * mpow(b + 1, y);
      c--;
      c = c % mod;
      if (c < 0)
        c += mod;
      cout << c << endl;
    }
  }
  return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long
// #define vt vector
// #define mat vt<vt<ll>>
// #define sz(x) (int)(x).size()

// const int M = 1e9 + 7;
// const ll M2 = (ll)M * M;

// mat cn(ll n, ll m) { return vt<vt<ll>>(n, vt<ll>(m)); }

// mat mult(mat &a, mat &b) { // Matrix Multiply
//   mat c = cn(sz(a), sz(b[0]));
//   for (ll i = 0; i < (int)a.size(); ++i) {
//     for (ll k = 0; k < (int)b.size(); ++k) {
//       for (ll j = 0; j < (int)b[0].size(); ++j) {
//         c[i][j] += a[i][k]%M * b[k][j%M];
//         if (c[i][j] >= M2)
//           c[i][j] -= M2;
//       }
//     }
//   }

//   for (ll i = 0; i < (int)a.size(); ++i)
//     for (ll j = 0; j < (int)b[0].size(); ++j)
//       c[i][j] %= M;

//   return c;
// }

// pair<ll, ll> solve(ll n) {

// //   mat r = {{0, 1}, {1, 0}};
// mat r = {{0, 1}};
//   mat b = {{1, 1}, {1, 0}};

//   while (n) { // Binary Exponentiation
//     if (n & 1)
//       r = mult(r, b);
//     b = mult(b, b);
//     n /= 2;
//   }
//   // return r[0][0] % M;
//   return {r[0][0] % M, r[0][1] % M};
// }

// ll power(ll b, ll p) { // modular Binary Exponentiation Function a^b
//   b %= M;
//   ll r = 1;
//   while (p > 0) {
//     if (p & 1)
//       r = (r * b) % M;
//     b = (b * b) % M;
//     p >>= 1; // p /=2
//   }

//   return r;
// }
// int main() {
//     ios::sync_with_stdio(0); cin.tie(0);
//   int t;
//   cin >> t;
//   while (t--) {
//     ll A, B, n;
//     cin >> A >> B >> n;

//     pair<ll, ll> fib = solve(n);
//     ll fib_n = fib.first, fib_n_1 = fib.second;
//     // cout << fib_n_1 << " " << fib_n << endl;

//     ll ans = power(A + 1, fib_n_1) % M * power(B + 1, fib_n) % M;
//     // ans = (ans - 1 + M) % M;
//     cout << ans-1 << '\n';
//   }

//   return 0;
// }
```

## Fermat Little Theorem
You are given two integers 'n' and 'r' and a prime number 'p'. Your task is to find (nCr) % p where nCr can be calculated as n! / (r! * (n - r)!).
Note :
N!  =  1 * 2 * 3 *... N

```cpp
#define ull unsigned long long
const int mxA=500;
ull iv[mxA+1], f1[mxA+1], f2[mxA+1];
ull fermatLittle(int n, int r, int M){
    
    iv[1]=1;
    for(int i=2; i<=n; ++i)
        iv[i]=M-M/i*iv[M%i]%M;
    f1[0]=f2[0]=1;
    for(int i=1; i<=n; ++i){
        f1[i]=i*f1[i-1]%M;
        f2[i]=f2[i-1]*iv[i]%M;
    }

    return f1[n]*f2[r]%M*f2[n-r]%M;
}
```

## Number Of Sequence
A sequence is called nice by a coding ninja if the following conditions are met:
0 <= ‘ARR’[k] <= k 
‘ARR’[k] = ‘ARR’[m] mod k, for all pairs of k,m such that k divides m.
You are given a sequence of integers ‘ARR’ where some numbers may be -1. Find and print the number of nice sequences you can create by changing each -1 to a non-negative integer. As this number can be quite large, your answer must be modulo it by 10 ^ 9 + 7.
For example:
Given ‘N’ = 3, 
'A' = {0, -1, -1} 
Then the answer is 6 because following sequences are possible:[0, 0, 0], [0, 1, 0], [0, 1, 1], [0, 1, 2], [0, 0, 1], [0, 0, 2].

```cpp
#include <bits/stdc++.h>
using namespace std;

const long N = 1e5, MOD = 1e9+7;


int solve(vector<int> a){
    long n=a.size();
  long ans = 1;
vector<long> p(N+1), pn(N+1), pr(N+1);

iota(p.begin(), p.end(), 0);

  for(int i=2; i<=n; ++i)
    if (p[i] == i)
      for (long j = i*i; j <= n; j += i)
        p[j] = i;

    for(int i=0; i<n; ++i) {
    if (a[i] >= 0)
      for (long j = i+1; j>1; ) {
        long pp = p[j], jj = j, c = 1;
        while ((jj /= p[j]) % p[j] == 0) {
          c++;
          pp *= p[j];
        }
        if (c > pn[p[j]]) {
          pn[p[j]] = c;
          pr[p[j]] = a[i]%pp;
        }
        j = jj;
      }
  }
  for(int i=2; i<=n; ++i)
    if (p[i] == i) {
      long pp = i, c = 1;
      while (pp*i <= n) {
        pp *= i;
        c++;
      }

    for(int _=0; _<c-pn[i]; _++)
        ans = ans*i%MOD;
    }


  return ans;
   
}
```

## Factorial Again
Ninja Kate has finally calmed down and decides to forgive Little Ninja Deepu, but she will not forgive him just like that. Finally, she agrees to forgive him because he can solve a mathematical question for her.
She gives Ninja Deepu a large number ‘N’ and a prime number ‘P’ and asks him to calculate ((3 * ‘N’ ) ! / ( 3! ^ ‘N’ ) )% ‘P.’
Your task is to help Little Ninja Deepu get back together with Ninja Kate.
For example:
Given ‘N’ = 2, ‘P’ = 11. 
Then the answer will be 9. Because (6!) / (6 ^ 2) = 20, and 20 remainder 11 is 9. Therefore the answer is 9.

```cpp
#define ll  long long int
ll  power(ll  b, ll  p, ll  m){
	ll  r=1;
	b%=m;
	while(p>0){
		if(p&1){
			r = r * b % m;
		}
		b= b * b % m;
		p>>=1;
	}
	return r;
}

ll  factorialAgain(ll  n, ll  p)
{
	n =  ( (n*3)%p + p)%p;   //most weird shit ever. Giving WA otherwise
	ll  dem = power(6, n/3, p);
	//weird cannot gives WA if dem is calculated before hand like power(6, n, p);
	ll  num = p-1;
	for(int i=n+1; i<=p-1; ++i)
		num = (num * power(i, p-2, p))%p;
	ll  ans = num * power(dem, p-2, p)%p;
	return ans;
}
```

## Cover The Points
You are given ‘N’ points that you need to cover. To cover all the points from a point at ‘x’ to a point at ‘y’, the cost will be
c + (x − y)^2, where c is a constant. 
Given the points and the constant c, what is the minimum cost to cover all the points?
For Example:
If N=2 and C=3 and points are [1,2]. 

If we follow path 1 → 2, the total cost incurred would be (3+(1−2)^2)=4. We can prove that this is the minimum cost incurred.

Hence, the output will be 4.
```cpp
struct Line {
  int m, b;

  int eval(int x) { return m * x + b; }

  void init(int i, vector<int> &x, vector<int> &dp) {
    m = -int(2) * int(x[i - 1]);
    b = int(x[i - 1]) * int(x[i - 1]) + dp[i];
  }
};

double calcInter(const Line &a, const Line &b) {
  double r = (b.b - a.b) / double(a.m - b.m);

  return r;
}

int getMin(int x, int &sz, vector<double> &inters, vector<Line> &hull) {
  int i = 0;

  if (sz == 1) {
    i = 0;
  } else if (x < inters[sz - 2]) {
    i = sz - 1;
  } else {
    int lo = 0, hi = sz - 2, mi;
    while (lo < hi) {
      mi = (lo + hi) >> 1;

      if (inters[mi] > x) {
        lo = mi + 1;
      } else {
        hi = mi;
      }
    }

    i = lo;
  }

  return hull[i].eval(x);
}

int coverAllPoints(int n, int c, vector<int> &points) {
  vector<int> dp(n);
  vector<double> inters(n);

  dp[n - 1] = c;
  int sz = 0;

  vector<Line> hull(n);

  hull[sz++].init(n - 1, points, dp);

  for (int i = n - 2; i >= 0; --i) {
    dp[i] = c + (points[n - 1] - points[i]) * (points[n - 1] - points[i]);
    dp[i] = min(dp[i], getMin(points[i], sz, inters, hull) +
                           (points[i]) * (points[i]) + (c));

    if (i) {
      hull[sz++].init(i, points, dp);
    }

    if (sz - 2 >= 0) {
      inters[sz - 2] = calcInter(hull[sz - 1], hull[sz - 2]);
    }

    while (sz > 2 && inters[sz - 2] > inters[sz - 3]) {
      hull[sz - 2] = hull[sz - 1];
      sz--;

      if (sz - 2 >= 0) {
        inters[sz - 2] = calcInter(hull[sz - 1], hull[sz - 2]);
      }
    }
  }

  return dp[0];
}

// This is an implementation of a solution to the "Minimum Time to Collect All Keys" problem, where you are given the number of keys, n, and the cost of traveling one unit, c, and a list of the points at which the keys are located. The goal is to find the minimum time to collect all the keys, given that you start at one point and have to visit all other points exactly once.

// The solution uses dynamic programming, where dp[i] is an array that stores the minimum time to collect all keys starting from point i. The code uses a variant of the dynamic programming called "Convex Hull Optimization" to optimize the time complexity.

// The Line struct represents a line in the 2D space, and it has two properties: m which represents the slope of the line, and b which represents the y-intercept of the line. The eval function evaluates the line at a given x, and the init function initializes the line by setting the slope and y-intercept based on the values of i, x, and dp.

// The calcInter function calculates the intersection of two lines, a and b, and returns the x-coordinate of the intersection.

// The getMin function finds the line in the "convex hull" (a set of lines) with the minimum value of dp[i] for a given x.

// The coverAllPoints function implements the main logic of the solution. It starts by initializing dp[n-1] to c and creating the first line in the "convex hull". Then, it iterates over the remaining points in reverse order and calculates dp[i] as the minimum time to reach all keys starting from point i. The code uses the getMin function to find the line in the "convex hull" with the minimum value of dp[i] for a given x, and updates the "convex hull" as needed. Finally, it returns dp[0], which is the minimum time to reach all keys starting from the first point.
```

