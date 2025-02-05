## Odd Frequency
You are given an array of size N with all elements with even frequency except one and you are supposed to find this element.

```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int ans=0;
        for(int i=0; i<n; ++i){
            int a; cin>>a;
            ans ^=a;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
```

## Element that Appears Once
You are given an arbitrary array ‘arr’ consisting of N non-negative integers, where every element appears thrice except one. You need to find the element that appears only once.

```cpp
int elementThatAppearsOnce(vector<int> arr) {
	int ans=0;
	int mask, onesCount;
	for(int i=0; i<31; ++i){
		onesCount=0;
		mask = (1<<i);
		for(int j=0; j<arr.size(); ++j){
			if(arr[j] & mask) ++onesCount;
		}
		if(onesCount%3 != 0) 
			ans |= mask;

	}
	return ans;
}
```

## Find The Repeating And Missing Number
You are given an array 'nums' consisting of first N positive integers. But from the N integers, one of the integers occurs twice in the array, and one of the integers is missing. You need to determine the repeating and the missing integer.

```cpp
vector<int> findRepeatingAndMissingNumbers(vector<int> nums)
{
    vector<int>v;
    int n = nums.size();
    for(int i=0;i<n;i++){
        int j = abs(nums[i])-1;
        if(nums[j]>=0){
            nums[j] *= -1;
        }else{
            v.push_back(abs(nums[i])); //repeated number
        }
    }
    for(int i=0;i<n;i++){
        if(nums[i]>0){
            v.push_back(i+1); //missing number
        }
    }
    return v;
}
```

## Unset ith Bit
You are given two integers N and i. You need to make ith bit of binary representation of N to 0 and return the updated N.
Counting of bits start from 0 from right to left.

```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int n, i; cin>>n>>i;
        n &= ~(1 << i);
        cout<<n<<'\n';
    }
    return 0;
}
```

## Clear All Bits From MSB
You are given two integers N and i. You need to clear all bits from MSB to ith bit (start i from right to left) and return the updated N.
Counting of bits starts from 0 from right to left.

```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t=1; cin>>t;
    while(t--){
        int n, i; cin>>n>>i;
        n &= ( ~((1<<32) - (1<<i)) );
        cout<<n<<'\n';
    }
    return 0;
}
```

## XOR of Natural Numbers
You are given an integer N and asked to find the Xor of first N natural numbers.

```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        if(n==0) cout<<0<<'\n';
        if(n%4==0) cout<<n<<'\n';
        if(n%4==1) cout<<1<<'\n';
        if(n%4==2) cout<<n+1<<'\n';
        if(n%4==3) cout<<0<<'\n';

    }
    return 0;
}
```

## Pairwise Sum of Hamming Distance
You are given an array ARR having N integers. Your task is to find the sum of Hamming Distance for each pair of the array elements.
Hamming Distance for two given integers 'A' and 'B' is defined as the minimum number of bits that needs to be toggled to make both the integers equal.
For example:
Consider A=4 and B=7
Binary representation of 4 = 100
Binary representation of 7 = 111
For the given example, if we flip the values of the last two least significant bits of A to 1 then A will become 7. As we can change the value of A to B by 2 flips. Therefore the Hamming Distance, in this case, is 

```cpp
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
```

## Xor Sum
You are given two arrays, ‘arr1’ of size 'N' and ‘arr2’ of size 'M'. You need to create an array of bitwise AND of all the possible pairs between the elements of both arrays, and your task is to find the XOR sum of the array. The XOR sum of an array is equal to the XOR of all elements of the array.
Note:
The XOR sum of [A, B, C] is equal to A XOR B XOR C.

```cpp
#include <bits/stdc++.h>
int xorSum(vector<int> &arr1, vector<int> &arr2)
{
    const int xors1 = accumulate(begin(arr1), end(arr1), 0, bit_xor<int>());
    const int xors2 = accumulate(begin(arr2), end(arr2), 0, bit_xor<int>());
    return xors1 & xors2;
}
// We can observe that (a1 & bi) XOR (a1 & bi) XOR ... XOR (an & bi) is the same as (a1 XOR a2 XOR ... XOR an) & bi.

// So, we calculate XOR sum of the first array xa. Then, the final result is (xa & b1) XOR (xa & b2) XOR ... XOR (xa & bm), resulting in a linear solution.
```

## Ninja and the task
Given an integer 'X' your task is to count the number of integer values 'Y' such that ('X' ^ 'Y') > 'X' and 0 < 'Y' < 'X'.
Where ( ^ ) is the bitwise xor operator.
EXAMPLE:
Input: 'X' = 2
Output: 1

There is only one value of 'Y' = 1 satisfies the condition ('X' ^ 'Y') > 'X' and 0 < 'Y' < 'X'

```cpp
long long countValues(long long x) {
    long long n=x;
    long long cnt=0;
    while(x>0){
        cnt++;
        x=x/2;

    }
    long long nxt_pow = ((long long) 1<<cnt);
    long long ans = nxt_pow-1;
    return ans-n;
}
```

## Find First Set Bit
You are given an integer N. You need to return an integer M, in which only one bit is set which at the position of a lowest set bit of N (from right to left).
```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){

  int t;
  cin >> t;
  while (t--) {
    int n, ans;
    cin >> n;
    ans = n & ~(n-1);
    cout<<ans<<'\n';

    // if (n == 0)
    //   return -1;
    // int mask;
    // for (int i = 0; i < 32; ++i) {
    //   mask = (1 << i);
    //   if (n & mask){
    //       ans |= (1<<i);
    //       cout<<ans<<endl;
    //       break;

    //   }
    // }
  }
  return 0;
}
```