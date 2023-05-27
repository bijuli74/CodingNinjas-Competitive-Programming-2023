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
