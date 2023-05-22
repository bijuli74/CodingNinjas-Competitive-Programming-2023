void pushZeroesEnd(int *a, int n){
    int pos_last_non0=0;
    for(int i=0; i<n; ++i){
        if(a[i]!=0){
            a[pos_last_non0++]=a[i];
        }
    }
    for(int i=pos_last_non0; i<n; ++i){
        a[i]=0;
    }
}
