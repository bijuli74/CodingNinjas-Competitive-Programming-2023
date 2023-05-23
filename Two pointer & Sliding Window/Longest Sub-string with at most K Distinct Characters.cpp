#include <vector>
int getLengthofLongestSubstring(int k, string s)
{
   vector<int> cnt(26);
   int ans=0;
   int distinct=0;
   for(int l=0, r=0; r<s.length(); ++r){
      if(++cnt[s[r]-'a']==1)
         ++distinct;
      while(distinct==k+1)
         if(--cnt[s[l++]-'a']==0)
            --distinct;
      
      ans = max(ans, r-l+1);
   }
   return ans;
}
