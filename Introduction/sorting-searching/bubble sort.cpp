void bubbleSort(int *a, int n)
{
    // for(int i=0; i<n-1; ++i){
    //     int mx=a[i], mx_idx = i;
    //     for(int j=i+1; j<n; ++j){
    //         if(a[j]<mx){
    //             mx=a[j];
    //             mx_idx=j;
    //         }
    //     }
        
    //     swap(a[i], a[mx_idx]);
    // }
    for(int i=0; i<n-1; ++i){
        for(int j=0; j<n-1-i; ++j){
            if(a[j]>a[j+1])
                swap(a[j], a[j+1]);
        }
    }
    
}
