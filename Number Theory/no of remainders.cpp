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
