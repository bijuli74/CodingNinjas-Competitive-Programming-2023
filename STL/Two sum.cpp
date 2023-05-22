#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> twoSum(vector<int>& arr, int target, int n)
{
	unordered_map<int, int> mp;
	vector<pair<int, int>> ans;
	for(int i=0; i<n; ++i)
		++mp[arr[i]];

	for(int i=0; i<n; ++i){
		int x=target-arr[i];
		if(x==arr[i]){
			if(mp[arr[i]]>1){
				mp[arr[i]]-=2;
				ans.push_back(make_pair(arr[i], arr[i]));
			}
			
			}
			else if(mp[arr[i]]>0 && mp[x]>0){
				ans.push_back(make_pair(arr[i], x));
				mp[arr[i]]--;
				mp[x]--;
			}
	}
	
	if(ans.empty()) ans.push_back(make_pair(-1, -1));
	return ans;
}
