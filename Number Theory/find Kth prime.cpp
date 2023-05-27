#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int kthPrime(int K)
{
	const int mxA=1e6;
	int p[mxA+1]={0};
	vector<ll> pfs;
	for(ll i=2; i<=mxA; ++i)
		if(!p[i]){
			for(ll j=i*i; j<=mxA; j+=i)
				p[j]=1;
			pfs.push_back(i);
		}

	
	return pfs[K-1];
}
