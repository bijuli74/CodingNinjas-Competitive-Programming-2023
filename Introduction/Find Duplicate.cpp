#include <algorithm>
int duplicateNumber(int *arr, int n)
{	
   sort(arr, arr+n);
    for(int i=0; i<n-1; ++i){
        if(arr[i]==arr[i+1]) return arr[i];
    }
}
