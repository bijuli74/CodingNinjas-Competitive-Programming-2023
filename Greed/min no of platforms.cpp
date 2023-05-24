int calculateMinPatforms(int at[], int dt[], int n) {
    int ans=0;
    sort(at, at+n);
    sort(dt, dt+n);
    for(int i=0, j=0; i<n; ++i)
        if(at[i] <= dt[j]) ++ans;
        else ++j;
    return ans;
}
