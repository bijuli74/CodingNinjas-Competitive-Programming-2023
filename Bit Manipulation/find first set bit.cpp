#include<bits/stdc++.h>
using namespace std;
int main(){

  int t;
  cin >> t;
  while (t--) {
    int n, ans;
    cin >> n;
    ans = n & ~(n-1);
    cout<<ans<<'\n';

    // if (n == 0)
    //   return -1;
    // int mask;
    // for (int i = 0; i < 32; ++i) {
    //   mask = (1 << i);
    //   if (n & mask){
    //       ans |= (1<<i);
    //       cout<<ans<<endl;
    //       break;

    //   }
    // }
  }
  return 0;
}
