bool CheckSumPairs(int a[], int n, int k, int m) {
 	if(n&1) return 0;
     unordered_map<int, int> mp;
     for(int i=0; i<n; ++i)
        ++mp[a[i]%k];
    for(auto it=mp.begin(); it!=mp.end(); ++it){
        int rem=it->first;
        if(rem*2==m){
            if(mp[rem]&1) return 0;
        }else{
            if(mp[rem] != mp[(m-rem+k)%k])
                return 0;
        }
    }
    return 1;
}
