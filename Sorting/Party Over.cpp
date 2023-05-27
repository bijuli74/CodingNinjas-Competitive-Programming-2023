vector<string> ninjaParty(vector<string> &a)
{
    int n=a.size();
    for(string& s: a){
        reverse(s.begin(), s.end());
    }
    sort(begin(a), end(a));
    for(string& s: a){
        reverse(s.begin(), s.end());
    }
    return a;
}
