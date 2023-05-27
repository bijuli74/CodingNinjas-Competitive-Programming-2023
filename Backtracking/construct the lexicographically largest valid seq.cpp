vector<int> dfs(vector<int>& a, vector<int>& nums, int p){
    if(p==a.size()) 
        return a;
    if(a[p]!=0) 
        return dfs(a, nums, p+1);
    
    for(int i=nums.size()-1; i>=1; --i){
        int dist = i==1 ? 0: i;
        if(nums[i]!=0 && dist+p<a.size() && a[p+dist]==0){
            a[p] = a[p+dist] = i;
            nums[i] = 0;
            vector<int> ans = dfs(a, nums, p+1);

            if(!ans.empty())
                return ans;
            nums[i]=1;
            a[p] = a[p+dist] = 0;
        }
    }
    return {};
}
vector<int> validSequence(int n) {
    vector<int> a(2*n-1), nums(n+1, 1);
    return dfs(a, nums, 0);
}
