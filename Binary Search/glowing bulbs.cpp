#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll func(ll x, vector<int>& primes) {
  int sz = primes.size();
  ll res = 0;
  for (int i = 1; i < 1 << sz; i++) {
    ll p = 1;
    int sign = -1;
    for (int j = 0; j < sz; j++)
      if ((i >> j) & 1) {
        p *= primes[j];
        sign *= -1;
      }
    res += sign * (x / p);
  }
  return res;
}

ll findKthGlowingBulb(vector<int> &labels, ll k) {
	  ll ans = 1, lo = 1, hi = 1e18;

  while (lo <= hi) {
    ll mid = (lo + hi) >> 1;
    if (func(mid, labels) >= k) {
      ans = mid;
      hi = mid - 1;
      } 
      else {
        lo = mid + 1;
    }
  }
  return ans;
}


