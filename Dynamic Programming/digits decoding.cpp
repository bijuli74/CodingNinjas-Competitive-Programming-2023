#include <vector>
const int M=1e9+7;

 bool isValid(char c) {
    return c != '0';
  }

  bool isValid(char c1, char c2) {
    return c1 == '1' || c1 == '2' && c2 < '7';
  }

int decodingDigits(string s)
{   
    int n = s.length();
    vector<long long> dp(n+1);
    dp[n]=1; //empty string
    dp[n-1]=isValid(s[n-1]);

    for(int i=n-2; ~i; --i){
        if(isValid(s[i]))
            dp[i]= (dp[i]+dp[i+1])%M;
        if(isValid(s[i], s[i+1]))
            dp[i] = (dp[i]+dp[i+2])%M;
    }
    return dp[0]%M;

}
 
