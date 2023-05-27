bool check(vector<int> &a, int cap, int k) {
  int cnt_painters = 1, remCap= cap;
  for (int i = 0; i < a.size(); ++i) {
    remCap-=a[i];
    if(remCap<0){
        cnt_painters++;
        remCap=cap-a[i];
    }
  }
  return cnt_painters <= k;
}

int findLargestMinDistance(vector<int> &A, int k) {
    int mx=0, sum=0;
    for(int i=0; i<A.size(); ++i){
        mx = max(mx, A[i]);
        sum+=A[i];
    }
  int l = mx, r = sum;
  int ans = 0;
  while (l <= r) {
    int mid = l + (r - l) / 2;
    if (check(A, mid, k)) {
      r = mid - 1;
      ans = mid;
    } else {
      l = mid + 1;
    }
  }
  return ans;
}

