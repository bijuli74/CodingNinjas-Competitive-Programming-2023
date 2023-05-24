#include<bits/stdc++.h>
using namespace std;
int main(){
    
    int n, w; cin>>n>>w;
    vector<array<double, 3>> a(n);
    double sumw = 0, sumv=0;
    for(int i=0; i<n; ++i){
        cin>>a[i][1]>>a[i][2];
        sumw+=a[i][2];
        sumv+=a[i][1];
        a[i][0]=a[i][1]/a[i][2];
    }
    if(sumw<=w) { cout<<fixed<<setprecision(6)<<sumv<<"\n";  return 0; }
   
    sort(begin(a), end(a), greater<array<double, 3>>());
    double ans=0;
    int it;
    for(int i=0; i<n && w>0; ++i){
    	it=i;
    	if(a[i][2]>w) break;
        ans+=a[i][1];
        w-=a[i][2];
        

    }
    if(w>0){
        ans += (w*a[it][0]);
    }
    cout<<fixed<<setprecision(6)<<ans<<"\n";
    
    return 0;
}
