#include <vector>
bool isPermutation(char a[], char b[]) {
    vector<int> fa(26, 0);
    int n=strlen(a), m=strlen(b);
    if(n!=m) return false;
    
    for(int i=0; i<n; ++i){
        ++fa[a[i]-'a'];
    }
    
    for(int i=0; i<m; ++i){
        --fa[b[i]-'a'];
    }
    
    for(int i=0; i<26; ++i){
        if(fa[i]>0) return false;
    }
    
    return true;
}
