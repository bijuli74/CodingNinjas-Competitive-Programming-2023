#include <algorithm>
#include <vector>
using namespace std;

void reverseEachWord(char s[]) {
	vector<string> w;
    string str="";
    int n=strlen(s);
    for(int i=0; i<n; ++i){
        if(s[i]==' '){
            w.push_back(str);
            str="";
        }else{
            str+=s[i];
        }
    }
        
        w.push_back(str);
        
        string ans="";
        for(auto word: w){
            reverse(word.begin(), word.end());
            ans+=word;
            ans+=" ";
        }
        ans.pop_back();
        for(int i=0; i<n; ++i){
            s[i]=ans[i];
        }
        
}

