/*
You can use minimum value of integer as -2147483647 and 
maximum value of integer as 2147483647
*/
void findLargest(int **a, int n, int m)
{	
    const int INT_MIN=-2147483648;
    if(n==0 && m==0) {
        cout<<"row "<<0<<" "<<INT_MIN<<'\n';
        return;
    }
    
    int mx_sum=INT_MIN, idx=0;
    bool row=0;
    for(int i=0; i<n; ++i){
        int sum=0;
        for(int j=0; j<m; ++j){
            sum+=a[i][j];
        }
        if(sum>mx_sum){
            mx_sum=sum;
            idx=i;
            row=1;
        }
    }
    
    for(int j=0; j<m; ++j){
        int sum=0;
        for(int i=0; i<n; ++i)
            sum+=a[i][j];
        
        if(sum>mx_sum){
            mx_sum=sum;
            idx=j;
            row=0;
        }
    }
    
    if(row) cout<<"row "<<idx<<" "<<mx_sum<<'\n';
    else cout<<"column "<<idx<<" "<<mx_sum<<'\n';
}
