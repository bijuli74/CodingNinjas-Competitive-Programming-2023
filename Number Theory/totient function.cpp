
#include<bits/stdc++.h>
using namespace std;

long long phi(int n){
    if(n == 1) return 1;
    long long res = n;
    
    for(int i=2;i*i<=n;i++)
		if(n % i == 0){
            res = res * (i - 1);
			res = res / i;
            while(n % i == 0) n = n / i;
        }

    if(n > 1){
		res = res * (n - 1);
		res = res / n;
	}

	return res;

}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
	int t , n; cin>>t;
    while(t--){
		cin>>n;
        cout<<phi(n)<<endl;
	}

}

// const int N = 1e9;
// int phi[N + 1];

// void preprocess() {
//   for (int i = 1; i <= N; ++i)
//     phi[i] = i;

//   for (int i = 2; i <= N; ++i)
//     if (phi[i] == i) {
//       for (int j = i; j <= N; j += i) {
//         phi[j] = phi[j] / i;
//         phi[j] = phi[j] * (i - 1);
//       }
//     }
// }

// int main() {
//   int t;
//   cin >> t;
//   preprocess();

//   while (t--) {
//     int n;
//     cin >> n;
//     cout << phi[n] << '\n';
//   }
//   return 0;
// }
