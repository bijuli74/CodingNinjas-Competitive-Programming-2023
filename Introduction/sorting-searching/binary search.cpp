int binarySearch(int *a, int n, int val)
{
	int lo=0, hi=n;
    while(lo<=hi){
        int m = lo+(hi-lo)/2;
        if(a[m]==val) return m;
        else if(val<a[m]) hi=m-1;
        else lo=m+1;
    }
    return -1;
}
