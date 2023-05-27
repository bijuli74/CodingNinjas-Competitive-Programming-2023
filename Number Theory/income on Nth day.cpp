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
