void swapAlternate(int *arr, int n)
{
    //Write your code here
    if(n&1) --n;
    for(int i=0; i<n-1; i+=2) swap(arr[i], arr[i+1]);
}
