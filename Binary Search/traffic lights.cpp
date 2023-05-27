 vector<int> trafficLights(int n, int x, vector<int> &pos)
{
	set<int> lights;
	multiset<int> d;
	lights.insert(0); 
	lights.insert(x);
	d.insert(x);
	vector<int> ans;
	for(int i=0; i<n; ++i){
		int p=pos[i];
		auto ub = lights.upper_bound(p);
		auto lb = ub; --lb;
		d.erase(d.find(*ub-*lb));
		d.insert(p-*lb);
		d.insert(*ub-p);
		lights.insert(p);

		auto res=d.end();
		--res;
		ans.push_back(*res);
	}
	return ans;
}
