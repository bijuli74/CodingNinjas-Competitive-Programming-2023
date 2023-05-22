void merge(int *arr1, int n, int *arr2, int m, int *ans){
    // if(n==0){ans=arr2; return;}
    // if(m==0){ ans=arr1; return;}
    
    int a=n-1, b=m-1, i=m+n-1;
    while(a>=0&&b>=0){
        ans[i--]=arr1[a]>arr2[b]? arr1[a--]: arr2[b--];
        
    }
    while(a>=0){
        ans[i--]=arr1[a--];
    }
    while(b>=0){
        ans[i--]=arr2[b--];
    }
}
