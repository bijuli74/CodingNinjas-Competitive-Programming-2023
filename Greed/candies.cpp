int requiredCandies(vector<int>& a) {
    int ans=0, n=a.size();
    if(n==1) return 1;
    vector<int> v(n, 1);
    for(int i=0; i<n-1; ++i){
        if(a[i+1]>a[i]) v[i+1]=v[i]+1;
    }
    for(int i=n-2; ~i; --i){
        if(a[i]>a[i+1] && v[i]<=v[i+1]){
            v[i]=v[i+1]+1;
        }
        ans+=v[i];
    }
    ans+=v[n-1];
    return ans;
}
