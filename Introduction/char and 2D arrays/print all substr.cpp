void printSubstrings(char str[]) {
    int n=strlen(str);
    string s=str;
    for(int i=0; i<n; ++i){
        for(int len=1; len<=n-i; ++len)
            cout<<s.substr(i, len)<<'\n';
    }
}
