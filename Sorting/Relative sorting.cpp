#include <bits/stdc++.h>
vector<int> relativeSorting(vector<int> &a, vector<int> &b, int n, int m)
{
    map<int, int> mp;
    for(int i: a) mp[i]++;
    int k=0;
    for (int i : b) {
      while (mp[i]-- > 0)
        a[k++] = i;
    }
    for(auto it: mp){
        while(it.second-- >0)
            a[k++]=it.first;
    }
    return a;
}
