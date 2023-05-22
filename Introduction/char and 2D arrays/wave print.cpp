void wavePrint(int **a, int n, int m)
{
    for(int j=0; j<m; ++j){
        if(j%2==0){
            for(int i=0; i<n; ++i)
                cout<<a[i][j]<<" ";
        }
        else{
            for(int i=n-1; ~i; --i) 
                cout<<a[i][j]<<" ";
        }
    }
}
