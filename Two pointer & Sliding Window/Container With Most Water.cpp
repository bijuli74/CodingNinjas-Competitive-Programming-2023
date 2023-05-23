#include <algorithm>
int maxArea(vector<int>& a) {
  int i=0, j=a.size()-1, ans=0;
  while(i<j){
      int w=j-i;
      ans = max(ans, w*min(a[i], a[j]));
      if(a[i]>a[j]) --j;
      else if(a[i]<a[j]) ++i;
      else ++i, --j;

  }
  return ans;
}
