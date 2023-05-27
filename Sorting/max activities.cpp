#include <algorithm>
int maximumActivities(vector<int> &start, vector<int> &finish) {
  int n = start.size();
  vector<pair<int, int>> a(n);

  for (int i = 0; i < n; i++) {
    a[i].first = finish[i];
    a[i].second = start[i];
  }

  sort(a.begin(), a.end());

  int maxa = 1;
  int currentTime = a[0].first;

  for (int i = 1; i < n; i++) {

  
    if (a[i].second >= currentTime) {
      maxa++;
      currentTime = a[i].first;
    }
  }
  return maxa;
}
