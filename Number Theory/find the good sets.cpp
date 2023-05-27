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
