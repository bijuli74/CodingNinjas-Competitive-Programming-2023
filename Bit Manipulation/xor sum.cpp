#include <bits/stdc++.h>
int xorSum(vector<int> &arr1, vector<int> &arr2)
{
    const int xors1 = accumulate(begin(arr1), end(arr1), 0, bit_xor<int>());
    const int xors2 = accumulate(begin(arr2), end(arr2), 0, bit_xor<int>());
    return xors1 & xors2;
}
// We can observe that (a1 & bi) XOR (a1 & bi) XOR ... XOR (an & bi) is the same as (a1 XOR a2 XOR ... XOR an) & bi.

// So, we calculate XOR sum of the first array xa. Then, the final result is (xa & b1) XOR (xa & b2) XOR ... XOR (xa & bm), resulting in a linear solution.
