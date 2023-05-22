void insertionSort(int *a, int n){
    for(int i=1; i<n; ++i){
        int cur=a[i], j;
        for(j=i-1; ~j; --j){
            if(a[j]>cur) a[j+1]=a[j];
            else break;
        }
        a[j+1]=cur;
    }
}
