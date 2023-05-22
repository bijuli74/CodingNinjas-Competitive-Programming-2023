void trimSpaces(char s[]) {
    int n=strlen(s);
    for(int i=0; i<n; ++i){
        if(s[i]==' '){
            for(int j=i; j<n; ++j){
                s[j]=s[j+1];
            }
            --i; --n;
        }
        
    }
    
}
