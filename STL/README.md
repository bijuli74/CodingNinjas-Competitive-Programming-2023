## Next Geater Element

Given an array, print the Next Greater Element (NGE) for every element. The Next greater Element for an element x, is the first greater element on right side of x in the array. Elements for which no greater element exist, consider next greater element as -1.
Input format :

Line 1 : Size of input array

Line 2 : Array elements (separated by space)

Constraints:
Time Limit: 1 second
Size of input array lies in the range: [1, 1000000]
Sample Input
```
5
3  8  1  2  0
```
Sample Output
```
8 -1  2 -1 -1
```
## k-largest element
You are given with an integer k and an array of integers that contain numbers in random order. You have to find k largest numbers from given array. You need to save them in an array and return it.
Note:
1. Time complexity should be O(n * logk) and space complexity should not be more than O(k).
2. Order of elements in the output is not important.

Sample Input 1:
```
13
2 12 9 16 10 5 3 20 25 11 1 8 6 
4
```
Sample Output 1:
```
12 16 20 25
```
## Valid pairs $
Given an array of integers and numbers k and m, write a function that returns true if given array can be divided into pairs such that the sum of every pair gives remainder m when divided by k.
Input format :
Line 1 : Integer N 
Line 2 : N integers separated be a single space
Line 3 : Integer K
Line 4 : Integer M
Output Format :
 Boolean
```
Constraints :
 1 <= N <= 10^4
 1 <= M < K <= 10^2
Sample Input :
4
2 1 5 7
9
3

Sample Output :
true
Explanation :
Pairs will be (2,1) and (5,7)
```
## Two sum $

You are given an array of integers 'ARR' of length 'N' and an integer Target. Your task is to return all pairs of elements such that they add up to Target.
Note:
We cannot use the element at a given index twice.
Follow Up:
Try to do this problem in O(N) time complexity. 
```
Constraints:
1 <= T <= 100
1 <= N <= 5000
-10 ^ 9 <= TARGET <=10 ^ 9
-10 ^ 9 <= ARR[i] <=10 ^ 9

Where 'T' denotes the number of test cases, 'N' represents the size of the array, 'TARGET' represents the sum required, and 'ARR[i]' represents array elements.

Time Limit: 1 sec.
Sample Input 1 :
2
4 9
2 7 11 13
5 1
1 -1 -1 2 2
Sample Output 1:
2 7
-1 2
-1 2
Explanation for Sample 1:
For the first test case, we can see that the sum of  2 and 7 is equal to 9 and it is the only valid pair.

For the second test case, there are two valid pairs (-1,2) and (-1,2), which add up to 1.
Sample Input 2 :
1
4 16
2 7 11 13
Sample Output 2 :
-1 -1
```
