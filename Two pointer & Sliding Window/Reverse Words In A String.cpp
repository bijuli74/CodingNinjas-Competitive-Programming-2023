
#include <algorithm>
void reverseWords(string& s, int n) {
    int i = 0, j = 0;
     while (i < n) {
      while (i < j || i < s.length() && s[i] == ' ')
        ++i;
      while (j < i || j < s.length() && s[j] != ' ')
        ++j;
      reverse(begin(s) + i, begin(s) + j);
    }
 }
  // Trim leading, trailing, and middle spaces
string cleanSpaces(string& s, int n) {
    int i = 0, j = 0;

    while (j < n) {
      while (j < n && s[j] == ' ')  // Skip spaces
        ++j;
      while (j < n && s[j] != ' ')  // Keep non spaces
        s[i++] = s[j++];
      while (j < n && s[j] == ' ')  // Skip spaces
        ++j;
      if (j < n)  // Keep only one space
        s[i++] = ' ';
    }

    return s.substr(0, i);
  }

string reverseString(string s)
{
    reverse(begin(s), end(s));
    reverseWords(s, s.length());
    return cleanSpaces(s, s.length();
}
