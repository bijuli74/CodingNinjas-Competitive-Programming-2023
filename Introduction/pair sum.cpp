#include <bits/stdc++.h>
int pairSum(int *a, int n, int x)
{
    int ans=0;
    for(int i=0; i<n; ++i){
        for(int j=i+1; j<n; ++j){
            if(a[j]== x-a[i]) ++ans;
        }
    }
    return ans;
}
