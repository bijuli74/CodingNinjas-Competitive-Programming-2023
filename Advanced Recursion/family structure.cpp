int solve(int n, long long k) {
        if(n==1 || k==1) return 0;
		long long a = solve(n-1, k/2+k%2);
		if(k%2==0)
			return a==0;
		return a;
}

string kthChildNthGeneration(int n, long long int k){
	if(solve(n, k)) return "Female";
	return "Male";
}
