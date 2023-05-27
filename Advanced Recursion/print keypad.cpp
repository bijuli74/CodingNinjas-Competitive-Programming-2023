#include <iostream>
#include <string>
#include <vector>
using namespace std;
void printer(vector<string>& keypad, int n, string ans){
    if(n==0) {
        cout<<ans<<'\n';
        return;
    }
    int last_digit=n%10;
    string s=keypad[last_digit];

    for(int i=0; i<s.size(); ++i){
        printer(keypad, n/10, s[i]+ans);
    }
    if(s.size()==0)
        printer(keypad, n/10, ans);
}

void printKeypad(int n){
    vector<string> keypad(10);
    keypad = {"", "",   "abc",  "def", "ghi",
                                 "jkl", "mno", "pqrs", "tuv", "wxyz"};
    printer(keypad, n, "");

}
