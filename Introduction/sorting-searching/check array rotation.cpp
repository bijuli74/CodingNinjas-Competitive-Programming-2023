int arrayRotateCheck(int *a, int n)
{
    if(n<=1) return 0;
    
    int ans=0;
    
    for(int i=0; i<n-1; ++i){
        ++ans;
        if(a[i+1]<a[i]) return ans;
    }
    if(ans==n-1) return 0;
}
