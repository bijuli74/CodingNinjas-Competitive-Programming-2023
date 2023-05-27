#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define fast_io  ios::sync_with_stdio(0);  cin.tie(0);
//wilsons theoram application (p-1)! % p = p-1 where p is prime no
void solve(){
  ll n, m; cin>>n>>m;
  ll k=n/m;
  ll ans;
  if(k&1) ans=m-1;
  else ans=1;
  for(int i=1; i<= n%m; ++i)
    ans = (ans*i)%m;
  cout<<ans<<endl;
}
// ll fact(int x, int M){
//     ll res = 1;
//     for(int i=2; i<=x; ++i)
//         res= (res%M * i%M)%M;
//     return res;
// }

// void solve() {
//   ll t, M;
//   cin >> t >> M;
//   if (t < M) {
//     if (M - t == 1) {
//       cout << 1 << endl;
//       return;
//     } else {
//       cout << fact(t, M) % M << endl;
//       return;
//     }
//   } 
//   else {
//     ll last = t % M;
//     ll f = fact(last, M) % M;

//     if ((t / M) % 2 == 0){
//       cout << f << endl;
//     }
//     else{
//       cout << ((M - 1) % M * f % M) % M << endl;
//     }
//   }
//   return;
// }

int main() {
    fast_io
  int tt;
  cin >> tt;

  while (tt--) {
    solve();
  }
  return 0;
}
