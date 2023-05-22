int tripletSum(int *a, int n, int x)
{
	int ans=0;
    for(int i=0; i<n ;++i){
        for(int j=i+1; j<n; ++j){
            for(int k=j+1; k<n; ++k){
                if(a[i]+a[j]== x-a[k]) ++ans;
            }
        }
    }
    
    return ans;
}
