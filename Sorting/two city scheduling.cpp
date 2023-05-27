int findMinCost(int n, vector<vector<int>> &cost)
{
	vector<int> a_b;
	int ans=0;
	for(int i=0; i<n*2; ++i){
		a_b.push_back(cost[i][1]-cost[i][0]);
		ans+=cost[i][0];
	}
	sort(begin(a_b), end(a_b));
	for(int i=0; i<n; ++i)
		ans+=a_b[i];
	return ans;
}
