#include<bits/stdc++.h>
int findSecondLargest(int *a, int n)
{
    if(n<=1) return INT_MIN;
    sort(a, a+n);
    if(a[0]==a[n-1]) return INT_MIN;
    for(int i=n-1; i>=1; --i){
        if(a[i]!=a[i-1])
            return a[i-1];
    }
}
