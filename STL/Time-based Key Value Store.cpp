/*
    Your Timebased object will be instantiated and called as such:

    Timebased* obj = new Timebased();
    obj->setKey(key,value,timestamp);
    string ans = obj->getValue(targetKey,targetTimestamp);
*/
#include <bits/stdc++.h>
using namespace std;
class Timebased {

    public:
      // Timebased() { 
      //     map<string, map<int, string, greater<int>>> m; 
      //     }
      map<string, map<int, string, greater<int>>> mp;
      void setKey(string key, string val, int timestamp) {
        mp[key][timestamp] = val;
    }

    string getValue(string targetKey, int targetTimestamp) {
      if (mp.count(targetKey) == 0)
        return "-1";

      auto it = mp[targetKey].lower_bound(targetTimestamp);
      if (it == mp[targetKey].end())
        return "-1";
      return it->second;
    }
};
