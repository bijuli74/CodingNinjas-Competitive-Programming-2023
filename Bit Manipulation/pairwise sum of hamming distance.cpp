#include <bits/stdc++.h>

long long int sumOfHammingDistance(int *arr, int n) {
    long long ans=0;
    int mask=1;

    for(int i=0; i<30; ++i){
      int onesCount =
          count_if(arr, arr + n, [&](int num) { return num & mask; });
      int zerosCount = n - onesCount;
      ans += onesCount * zerosCount;
      mask <<= 1;
    }
    return ans*2;
}
