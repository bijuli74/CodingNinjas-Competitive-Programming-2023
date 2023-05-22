#include <algorithm>
pair<int, int> findFirstLastPosition(vector<int> &arr, int n, int x)
{
  const int l = lower_bound(begin(arr), end(arr), x) - begin(arr);
  if (l == arr.size() || arr[l] != x)
    return {-1, -1};
  const int r = upper_bound(begin(arr), end(arr), x) - begin(arr) - 1;
  return {l, r};
}
