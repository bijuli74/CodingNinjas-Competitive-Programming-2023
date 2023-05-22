#include <vector>
char highestOccurringChar(char s[]) {
    vector<int> f(26, 0);
    int n=strlen(s);
    for(int i=0; i<n; ++i)
        ++f[s[i]-'a'];
  
  // ans = max_element(begin(f), end(f))-f.begin() + 'a';
    char ans=s[0];
    int tmp=-1;
    for(int i=0; i<n; ++i){
        int c=s[i]-'a';
        if(f[c]>tmp) {
            ans=c+'a';
            tmp=f[c];
        }
    }
    return ans;
}
