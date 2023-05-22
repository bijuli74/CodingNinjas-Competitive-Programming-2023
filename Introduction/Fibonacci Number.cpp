bool checkMember(int n){
    int f0=0, f1=1;
    int N=1e5;
    int memo[N];
    memo[0]=1, memo[1]=1;
    if(n==0 || n==1) return 1;
    for(int i=2; i<N; ++i){
        memo[i]=memo[i-1]+memo[i-2];
        if(memo[i]==n) return 1;
        if(memo[i]>n) return 0;
    }
    return 0;
}
