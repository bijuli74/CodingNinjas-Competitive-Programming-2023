long long countValues(long long x) {
    long long n=x;
    long long cnt=0;
    while(x>0){
        cnt++;
        x=x/2;

    }
    long long nxt_pow = ((long long) 1<<cnt);
    long long ans = nxt_pow-1;
    return ans-n;
}
