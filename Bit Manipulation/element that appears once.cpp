int elementThatAppearsOnce(vector<int> arr) {
	int ans=0;
	int mask, onesCount;
	for(int i=0; i<31; ++i){
		onesCount=0;
		mask = (1<<i);
		for(int j=0; j<arr.size(); ++j){
			if(arr[j] & mask) ++onesCount;
		}
		if(onesCount%3 != 0) 
			ans |= mask;

	}
	return ans;
}
