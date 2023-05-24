#include <algorithm>
vector<int> sortArrayByKBit(int n, int k, vector<int> &a) {
    int mask=1<<(k-1);
    vector<int> left, right, ans;
    for(int i=0; i<n; ++i){
        if((a[i]&mask)==0) left.push_back(a[i]);
        else right.push_back(a[i]);
    }
  for(int i: right) left.push_back(i);
  return left;

}
