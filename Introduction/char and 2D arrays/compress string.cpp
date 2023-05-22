string getCompressedString(string &s) {
    string ans;
    for(int i=0; i<s.size(); ++i){
        int cnt=1;
        ans.push_back(s[i]);
        while(s[i]==s[i+1]){
            ++cnt;
            ++i;
        }
        char ch = cnt+'0';
        if(ch!='1'){
            ans.push_back(ch);
        }
            
    }
    
    return ans;
    
}
