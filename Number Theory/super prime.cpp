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
