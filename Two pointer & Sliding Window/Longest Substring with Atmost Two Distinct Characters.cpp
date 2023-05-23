int lengthOfLongestSubstring(string s) {
    int ans=0,  distinct=0;
    vector<int> cnt(128);
    for(int l=0, r=0; r<s.size(); ++r){
        if(++cnt[s[r]]==1)
            ++distinct;
        while(distinct==3)
            if(--cnt[s[l++]]==0)
                --distinct;
        ans = max(ans, r-l+1);
    }

    return ans;
}
