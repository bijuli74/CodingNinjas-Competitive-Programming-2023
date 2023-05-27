
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
