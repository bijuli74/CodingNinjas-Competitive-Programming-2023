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
