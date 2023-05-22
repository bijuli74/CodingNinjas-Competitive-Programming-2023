void sort012(int *a, int n)
{	
    int c1=0, c2=0, c0=0;
    for(int i=0; i<n; ++i){
        if(a[i]==0) ++c0;
        else if(a[i]==1) ++c1;
        else ++c2;
    }
    
    fill(a, a+c0, 0); fill(a+c0, a+c0+c1, 1); fill(a+c0+c1, a+n, 2);
    
}
