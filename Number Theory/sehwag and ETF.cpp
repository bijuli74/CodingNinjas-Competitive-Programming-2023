#include<bits/stdc++.h>
#define ll long long
#define MAX 1100001
#define ss(n) scanf("%lld", &n)
using namespace std;
bool primes[MAX];
ll phi[MAX];
ll p[300001];
ll num[MAX];
int main()
{
    ll t, a, b, k, i, j, x, base;
    cin >> t;
    for (i = 3; i < MAX; i += 2)
        primes[i] = 1;
    primes[2] = 1;
    for (i = 3; i * i < MAX; i += 2)
    {
        if (primes[i])
        {
            for (j = i * i; j < MAX; j += 2 * i)
                primes[j] = 0;
        }
    }
    p[0] = 2;
    ll c = 1;
    for (i = 3; i < MAX; i += 2)
    {
        if (primes[i])
            p[c++] = i;
    }
    while (t--)
    {
        cin >> a >> b >> k;
        if (k == 1)
        {
            std::cout << std::fixed;
            std::cout << std::setprecision(6) << 1 << endl;
            continue;
        }
        for (i = a; i <= b; i++)
        {
            phi[i - a] = i;
            num[i - a] = i;
        }
        for (i = 0; p[i] * p[i] <= b; i++)
        {
            base = a / p[i] * p[i];
            while (base < a)
                base += p[i];
            while (base < p[i])
                base += p[i];
            if (base == p[i])
            {
                // cout<<phi[base-a]<<endl;
                base += p[i];
            }
            for (j = base; j <= b; j += p[i])
            {
                while (num[j - a] % p[i] == 0)
                    num[j - a] /= p[i];
                phi[j - a] -= phi[j - a] / p[i];
                //cout<<j<<" "<<phi[j-a]<<endl;
            }
        }
        for (i = a; i <= b; i++)
        {
            if (num[i - a] > 1)
                phi[i - a] -= phi[i - a] / num[i - a];
            num[i - a] = 1;
        }
        ll c = 0;
        for (i = a; i <= b; i++)
        {
            //cout<<i<<" "<<phi[i-a]<<endl;
            if (phi[i - a] % k == 0)
                c++;
        }
        double ans = c;
        ans /= (b - a + 1);
        std::cout << std::fixed;
        std::cout << std::setprecision(6) << ans << endl;
    }
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long

// const ll mxN=1e12, mxA=1e6;

// unordered_map<ll, vector<ll>> mp;

// // vector<ll> lpf(mxA+1);
// // vector<ll> pfs;

// // void sieve(){
    
// //     for(int i=2; i<=mxA; ++i){
// //         if(!lpf[i]){
// //             pfs.push_back(i);
// //             lpf[i]=i;
// //         }
// //         for(int j=0; j<(int)pfs.size()&&pfs[j]<=lpf[i]&&i*pfs[j]<=mxA; ++j)
// //             lpf[i*pfs[j]]=pfs[j];
// //     }
// // }



// vector<bool> is_prime(mxN+1, 1);
// vector<ll> pfs;

// void sieve(){
// 	is_prime[0]=is_prime[1]=0;
// 	for(ll i=2; i*i<=mxN; ++i){
// 		if(is_prime[i]){
// 			for(ll j=i*i; j<=mxN; j+=i)
// 				is_prime[j]=0;
// 		}
// 	}
// }

// ll phi(ll n){
// 	if(n==1) return 1;
// 	ll res = n;
	
// 	for(ll i=2; i*i<=n; ++i)
// 		if(n%i==0){
// 			res *=(i-1);
// 			res /=i;
// 			while(n%i==0)
// 				n /=i;
// 		}
// 	if(n>1){
// 		res *=(n-1);
// 		res /=n;
// 	}
// 	return res;
// }

// void solve(){
// 	ll l, r, k; cin>>l>>r>>k;
// 	long double ans=0;
// 	for(ll i=0; i<=mxA; ++i){
// 		ll p = pfs[i];
// 		if(p>r) break;

// 		ll pos = (r/p)*p;
// 		for(ll i=2; i<=pos; ++i){
// 			if(i<l)
// 				break;
// 			mp[i].push_back(p);
// 			i-=p;
// 		}
// 	}
	
// 	for(ll i=l; i<=r; ++i)
// 		if(phi(i)%k==0)
// 			ans++;
	
// 	ans /= (r-l+1);
// 	cout<< fixed << setprecision(6) << ans<<'\n';
// }

// int main(){
// 	ios::sync_with_stdio(0);
// 	cin.tie(0);

// 	ll t; cin>>t;
	
// 	sieve();

//     for(ll i=0; i<=mxN; ++i)
//         if(is_prime[i])
//             pfs.push_back(i);

// 	while(t--){
// 		solve();
// 	}
// 	return 0;
// }



