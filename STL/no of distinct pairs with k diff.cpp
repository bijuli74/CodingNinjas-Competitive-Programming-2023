#include <bits/stdc++.h> 
int kDiffPairs(vector < int > & arr, int n, int k) {
    
    sort(arr.begin(),arr.end(),greater<int>());
    int ans = 0;
    set<int> seen;
    set<pair<int,int>> s;
    
    for(int i=0;i<n;i++){
      if (seen.count(arr[i] + k) > 0) {
        s.insert(make_pair(arr[i], arr[i] + k));
      }
      seen.insert(arr[i]);
    }
    return s.size();
}

/*
	Time complexity: O(N) 
	Space complexity: O(N)
	
	Where 'N' is the size of the array.
*/

#include<unordered_map>

int kDiffPairs(vector < int > & arr, int n, int k) {

    // Initialise a hashmap to store frequencies.
    unordered_map < int, int > mp;

    // Initialise a variable to store the count.
    int count = 0;

    // Start traversing through the vector.
    for (int i = 0; i < n; i++) {

        // If difference is not equal to zero.
        if (k != 0) {
            if (mp.find(arr[i]) != mp.end()) {

                // Number present in map.
                continue;
            }
            if (mp.find(k + arr[i]) != mp.end()) {

                // Number with difference equal to k found.
                count++;
            }
            if (mp.find(arr[i] - k) != mp.end()) {

                // Number with difference equal to k found.
                count++;
            }

            // Increase frequency.
            mp[arr[i]]++;
        }

        // If k is equal to zero.
        else {

            // Increase frequency.
            mp[arr[i]]++;

            // If frequency equal to two.
            if (mp[arr[i]] == 2) {

                // Pair with difference equal to zero found.
                count++;
            }
        }
    }

    // Return count.
    return count;
}

// #include <bits/stdc++.h> 
// int kDiffPairs(vector < int > & arr, int n, int k) {
    
 // Fails one edges case !!!
    
//     map<int,int> m;
//     int ans = 0;
//     for(int i=0;i<n;i++){
//         m[arr[i]]++;
//     }
    
//     for(auto i : m){
//         if(m.count(i.first+k)>0){
//             ans++;
//         }
//     }
//     return ans;
    
// }
