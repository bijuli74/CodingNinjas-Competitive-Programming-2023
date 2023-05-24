#include <bits/stdc++.h> 
long long merging(long long *A, int st, int mid, int ed){
   vector<long long>left, right;
   for(int i=st; i<=mid; ++i) left.push_back(A[i]);
   for(int i=mid+1; i<=ed; ++i) right.push_back(A[i]);
   int n=left.size(), m=right.size();

   long long cnt=0;
   int i=0, j=0, k=st;
    while(i<n && j<m){
        if(left[i]<=right[j]){
            A[k]=left[i];
            i++;
        }else{
            A[k]=right[j];
            j++;
            cnt+=(n-i);
        }
        k++;
    }
    while(i<n) A[k++]=left[i++];
    while(j<m) A[k++]=right[j++];

    return cnt;
}

long long mergesort(long long *A, int st, int ed){
    if(st>=ed) return 0;
    int mid = (st+ed)/2;
    long long ans=0;
    ans+=mergesort(A, st, mid);
    ans+=mergesort(A, mid+1, ed);

    ans+=merging(A, st, mid, ed);
    return ans;
}

long long getInversions(long long *arr, int n){
    return mergesort(arr, 0, n-1);

}
