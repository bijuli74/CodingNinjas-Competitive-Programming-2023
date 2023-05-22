void sortZeroesAndOne(int *a, int n)
{
    int c1=0, c0=0;
    for(int i=0; i<n; ++i)
        if(a[i]) ++c1;
    	else ++c0;
    
    fill(a, a+c0, 0);
    fill(a+c0, a+n, 1);
    
}
