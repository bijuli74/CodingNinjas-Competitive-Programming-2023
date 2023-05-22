void removeAllOccurrencesOfChar(char s[], char c) {
    // Write your code here
    int n=strlen(s);
    for(int i=0; i<n; ++i){
        if(s[i]==c){
            for(int j=i; j<n; ++j){
                s[j]=s[j+1];
            }
            --i; --n;
        }
        
    }
    
}
