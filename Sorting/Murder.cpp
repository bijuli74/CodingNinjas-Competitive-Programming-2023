#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll merge(ll *arr, ll left, ll mid, ll right) {
  ll i = left, k = 0, j = mid, sum = 0;
  ll *temp = new ll[right - left + 1];
  while (i < mid && j <= right) {
    if (arr[i] < arr[j]) {
      sum += (arr[i] * (right - j + 1)); //
      temp[k++] = arr[i++];
    } else {
      temp[k++] = arr[j++];
    }
  }
  while (i < mid) temp[k++] = arr[i++];
  while (j <= right) temp[k++] = arr[j++];
  for (int i = left, k = 0; i <= right; i++, k++) 
    arr[i] = temp[k];
  delete[] temp;
  return sum;
}
ll merge_sort(ll *arr, ll left, ll right) {
  ll count = 0;
  if (right > left) {
    ll mid = (right + left) / 2;
    count += merge_sort(arr, left, mid);
    count += merge_sort(arr, mid + 1, right);
    count += merge(arr, left, mid + 1, right);

    return count;
  }
  return count;
}
ll solve(ll *arr, ll n) {
  return merge_sort(arr, 0, n - 1);
  
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  ll t; cin >> t;
  while (t--) {
    ll n; cin >> n;
    ll *arr = new ll[n];
    for (ll i = 0; i < n; i++)  cin >> arr[i];
    cout << solve(arr, n) << endl;
  }
}
