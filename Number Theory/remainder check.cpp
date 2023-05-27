/*
Time Complexity: O(X*Y + Q)
Space Complexity: O(X*Y)
where 'X' and 'Y' are the given numbers
and 'Q' is the number of queries.
*/
// Returns number of valid integers on the range [0,t].
int countTill(int t, int len, vector<int> &pref)
{
return (t / len) * pref[len - 1] + pref[t % len];
}
vector<int> countValidNumbers(int x, int y, int q, vector<pair<int, int>> queries)
{
// Vector to be returned.
vector<int> ret(q);
// Length of our array
int len = x * y;
// Prefix sum array computation.
vector<int> pref(len);
pref[0] = 0;
for (int i = 1; i < len; ++i)
{
pref[i] = pref[i - 1];
if ((i % x) % y != (i % y) % x)
pref[i]++;
}
for (int i = 0; i < q; ++i)
{
int l = queries[i].first;
int r = queries[i].second;
// Number of valid integers ON [L,R] will be [0,R] - [0,L-1].
int ans = countTill(r, len, pref) - countTill(l - 1, len, pref);
ret[i] = ans;
}
return ret;
}
