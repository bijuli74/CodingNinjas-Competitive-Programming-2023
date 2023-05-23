#include <bits/stdc++.h> 
//O(N)
int findPairSum(vector<int> a, int x){
    int k=-1; //rotate point
    int n = a.size();
    //finding the rotate point
    for(int i=0; i<n-1; ++i){
        if(a[i+1]<a[i]) {
            k=i;
            break;
        }
    };
    //rotating to sort the array if not already sorted
    if(k != -1) rotate(a.begin(), a.begin()+k+1, a.end());

    //finally searching in sorted array
    int i=0, j=n-1;
    // sort(a.begin(), a.end());
    while(i<j){
        if(a[i]+a[j]==x) return 1;
        else if(a[i]+a[j]>x) --j;
        else ++i;
    }
    return 0;
}
//Aproach 1
// int findPairSum(vector<int> arr, int target)
// {   
//     int n = arr.size();
//     map<int, int> mp;
//     for(int i=0; i<n; ++i){
//         if(!mp.count(arr[i])) mp[arr[i]]=1;
//         else mp[arr[i]]++;
//     }

//     for(int i=0; i<n; ++i){
//         if(arr[i]==target-arr[i]){
//             if(mp.count(arr[i])==2) return 1;
//         } else {
//             if(mp.count(target-arr[i])) return 1;
//         }
//     }
//     return 0;
// }
//Approach 2
// #define us unordered_set
// int findPairSum(vector<int> arr, int target)
// {
//     //Write your code here
//     int n=arr.size();
//     us<int>s;
//     for(int i=0;i<arr.size();i++)
//     {
//         if(s.find(target-arr[i])!=s.end())
//         {
//             return true;
//         }
//         s.insert(arr[i]);
//     }
//     return false;
// }
