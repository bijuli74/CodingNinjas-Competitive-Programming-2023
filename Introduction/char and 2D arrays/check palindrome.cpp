// #include<bits/stdc++.h>
bool checkPalindrome(char str[]) {
    
	for(int i=0, j=strlen(str)-1; i<j; ++i, --j){
      
        if(str[i]!=str[j]) return false;
    }
    return true;
    // return equal(s.begin(), s.end()-s.size()/2, s.rbegin());
}
