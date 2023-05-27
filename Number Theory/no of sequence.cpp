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
