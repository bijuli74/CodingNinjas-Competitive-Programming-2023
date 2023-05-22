#include <algorithm>
void removeConsecutiveDuplicates(char s[]) {
    int n=strlen(s);
    char prev='\0';
    int k=0;
    for(int i=0; i<n; ++i){
        if(prev!=s[i])
            s[k++]=s[i];
        
        prev=s[i];
    }
    
    s[k]='\0';
}
