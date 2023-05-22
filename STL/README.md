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
