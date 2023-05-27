#include <bits/stdc++.h>
vector<int> smartInterval(vector<vector<int>> &intervals, int n)
{
	vector<int> starts(n), ans;
	unordered_map<int, int> mp;
	for(int i=0; i<n; ++i){
		starts[i]=intervals[i][0];
		mp[intervals[i][0]]=i;
	}
	sort(begin(starts), end(starts));

	for(int i=0; i<n; ++i){
		int x = *lower_bound(begin(starts), end(starts), intervals[i][1]);
		if(mp.find(x)!=mp.end()) ans.push_back(mp[x]);
		else ans.push_back(-1);
	}
	return ans;
}
