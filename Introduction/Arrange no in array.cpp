void arrange(int *arr, int n)
{
    for(int i=0, x=1; i<n/2; ++i, x+=2){
        arr[i]=x;
    }
    if(n%2==0){
        for(int i=n/2, x=n; i<n; ++i, x-=2) arr[i]=x;
        }
    else{
        arr[n/2]=n;
        for(int i=n/2+1, x=n-1; i<n; ++i, x-=2) arr[i]=x;
    }
    
        
}
