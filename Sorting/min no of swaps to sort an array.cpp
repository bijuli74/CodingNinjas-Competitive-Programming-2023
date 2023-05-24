int minSwaps(vector<int> &a){
	int n=a.size();
	vector<vector<int>> v(n, vector<int>(2));
	for(int i=0; i<n; ++i){
		v[i][0]=a[i];
		v[i][1]=i;
	}
	sort(begin(v), end(v));
	vector<bool> vis(n, false);
	int ans=0;
	for(int i=0; i<n; ++i){
		if(vis[i] || v[i][1]==i) continue;
		int cyc=0;
		int j=i;
		while(!vis[j]){
			vis[j]=1;
			j=v[j][1];
			cyc++;
		}
		if(cyc>0) ans+=(cyc-1);
	}
	return ans;
}
