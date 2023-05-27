#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ii pair<int, int>
#define fast_io ios::sync_with_stdio(0); cin.tie(0);

int main(){
	fast_io
	ll n, k, tmpK, ans=0;
	cin>>n>>k;
	tmpK=k;
	vector<ll> a(n);
	for(int i=0; i<n; ++i) cin>>a[i];

	vector<ii> pf;
	for(int i=2; i*i<=tmpK; ++i){
		if(tmpK%i==0){
			int cnt=0;
			while(tmpK%i==0){
				tmpK/=i;
				cnt++;
			}
			pf.push_back({i, cnt});
		}
	}
	if(tmpK!=1)
		pf.push_back({tmpK, 1});
	
	vector<ii> pf0 = pf;
	for(int i=0; i<pf0.size(); ++i)
		pf0[i].second =0;
	
	
	for(int i=0, j=0; i<n; ++i){
		for(int p=0; p<pf.size(); ++p){
			if(a[i]%pf[p].first ==0){
				tmpK=a[i];
				int c=0;
				while(tmpK%pf[p].first==0){
					tmpK/=pf[p].first;
					c++;
				}
				pf0[p].second += c;
			}
		}
		while(j<=i){
			int q;
			for(q=0; q<pf.size(); ++q)
				if(pf[q].second > pf0[q].second)
					break;
			
			if(q != pf.size())
				break;
			
			ans += n-i;

			for(q=0; q<pf.size(); ++q){
				if(a[j]%pf[q].first==0){
					tmpK = a[j];
					int c=0;
					while(tmpK%pf[q].first==0){
						tmpK /=pf[q].first;
						c++;
					}
					pf0[q].second -= c;
				}
			}
			++j;
		}
	}
	cout<<ans;

	return 0;
}
