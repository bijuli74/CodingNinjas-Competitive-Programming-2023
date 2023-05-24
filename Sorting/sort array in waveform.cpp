vector<int> waveFormArray(vector<int> &a, int n) {
    sort(begin(a), end(a));
    vector<int> ans(n);
    for(int i=0, j=n-1, k=0; i<=j; ++i, --j){
        ans[k++]=a[j];
        ans[k++]=a[i];
    }
    // for(auto i: ans) cout<<i<<" ";
    return ans;
}
