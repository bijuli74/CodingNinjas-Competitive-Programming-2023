## Max Sum of K Consecutive Elements
given an array of ‘N’ integers. You have to find the maximum sum over all subarrays of size ‘K’.
For example:
If N=3, K=2 and array elements are [ -100, 20, 40 ]. Following are the subarrays of size 2:
[ -100, 20 ] having sum = -100 + 20 = -80.
[ 20, 40 ] having sum = 20 + 40 = 60.

The maximum sum between -80 and 60 is 60. Hence, the output is 60.
Sample Input 1 :
```
2
3 2 
-100 20 40
2 1
12 -34
Sample output 1 :
60
12
```
Explanation For Sample Output 1:
For the first test case,
N=3, K=2 and array elements are [ -100, 20,40 ]. Following are the subarrays of size 2:
[-100, 20] having sum = -100 + 20 = -80.
[20, 40] having sum = 20 + 40 = 60.

The maximum sum between -80 and 60 is 60. Hence, the output is 60.

For the second test case,
N=2, K=1 and array elements are [ 12, -34 ]. Following are the subarrays of size 1:
[12] having sum =12.
[-34] having sum = -34.

The maximum sum between 12 and -34  is 12. Hence, the output is 12.
