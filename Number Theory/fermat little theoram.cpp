#define ull unsigned long long
const int mxA=500;
ull iv[mxA+1], f1[mxA+1], f2[mxA+1];
ull fermatLittle(int n, int r, int M){
    
    iv[1]=1;
    for(int i=2; i<=n; ++i)
        iv[i]=M-M/i*iv[M%i]%M;
    f1[0]=f2[0]=1;
    for(int i=1; i<=n; ++i){
        f1[i]=i*f1[i-1]%M;
        f2[i]=f2[i-1]*iv[i]%M;
    }

    return f1[n]*f2[r]%M*f2[n-r]%M;
}
