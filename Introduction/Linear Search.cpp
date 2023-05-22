#include<bits/stdc++.h>
int linearSearch(int *arr, int n, int x)
{
    auto it = find(arr, arr+n, x);
    if(it != arr+n) return it-arr;
    return -1;
}
