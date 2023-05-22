#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin>>n;
    vector<bool> is_prime(n+1, 1);
    is_prime[0]=is_prime[1]=0;
    for(int i=2; i*i<=n; ++i){
        if(is_prime[i]){
            for(int j=i*i; j<=n; j+=i)
                is_prime[j]=0;
        }
    }
    
    for(int i=2; i<=n; ++i){
        if(is_prime[i]) cout<<i<<"\n";
    }
  
}
