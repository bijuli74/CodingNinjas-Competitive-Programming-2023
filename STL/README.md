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
## First and last position of element in the sorted array

You are given a non-decreasing array 'arr' consisting of 'n' integers and an integer 'x'. You need to find the first and last position of 'x' in the array.
Note:
1. The array follows 0-based indexing, so you need to return 0-based indices.
2. If 'x' is not present in the array, return {-1 -1}.
3. If 'x' is only present once in the array, the first and last position of its occurrence will be the same.
```
Sample Input 1:
5
-10 -5 -5 -5 2
-5
Sample Output 1:
1 3
```
## Time-based Key Value Store $
You are given a stream of tuples which constitute three things ‘Key’, ‘Val’, and the ‘Timestamp’.
Your task is to implement the ‘TimeBased’ class having the two functions:
1) The first function is ‘setKey(string Key, string Val, int Timestamp)’, which stores the ‘Key’ and the ‘Val’ along with the ‘Timestamp’.

2) The second function is ‘getValue(string TargetKey, int TargetTimestamp)’, which returns the value of ‘Val’ associated with the ‘TargetKey’ such that its ‘Timestamp’ value is less than or equal to the ‘TargetTimestamp’. If there are multiple values of ‘Val’, return the value of ‘Val’ with the highest value of ‘Timestamp’ among the valid ones. If there is no valid value of ‘Val’ return “-1” as a string.
‘Timestamps’ will always be in strictly increasing order.
Input format:
The first line of input contains an integer ‘T’, denoting the number of test cases. 

The first line of each test case contains an integer ‘N’, representing the total number of queries.

Then the next ‘N’ lines contain ‘N’ queries. A query can be of two types:
1 Key Val Timestamp  → stores the Key and the Val along with the Timestamp
2 TargetKey TargetTimestamp → returns the value of ‘Val’
Output format:
For each test case, print the value of ‘Val’ for each query of type 2 only, output the answer to the query in a single line.

```
Sample Input 1:
 2
 4
 1 abc def 10
 1 abc ghi 20
 2 abc 10
 2 abc 5
 3
 1 bbb ccc 5
 1 ddd ccc 5
 2 ddd 6 
Sample Output 1:
 def  -1
 ccc
 
 Sample Input 2:
2
3
1 yyy zzz 3
1 yyy xxx 4
2 yyy 4
4
2 fff 13
1 fff ggg 13
1 fff hhh 14
2 fff 14 
Sample Output 2:
xxx
-1 hhh
 ```
## Overlapping Intervals
You have been given the start and end times of 'N' intervals. Write a function to check if any two intervals overlap with each other.
Note :
If an interval ends at time T and another interval starts at the same time, they are not considered overlapping intervals.
```
Sample Input 2 :
2
1
100
200
2
2 1
3 4
Sample Output 2 :
false
true
```
## Maximum length pair chain
You are given ‘N’ pairs of integers in which the first number is always smaller than the second number i.e in pair (a,b) -> a < b always. Now we define a pair chain as the continuous arrangement of pairs in which a pair (c,d) can follow another pair (a,b) only when b < c.
Find the length of the longest pair chain that can be formed using the given pairs.
Example:
Given Pairs =  [3,4], [1,2], [2,3].

The length of the maximum chain will be 2. The longest chain is [1,2] -> [3,4].

## Closest Distance Pair $

You are given an array containing 'N' points in the plane. The task is to find out the distance of the closest points.
Note :
Where distance between two points (x1, y1) and (x2, y2) is calculated as [(x1 - x2) ^ 2] + [(y1 - y2) ^ 2].
Input Format :
The first line contains a single integer 'N' denoting the number of points.

The next 'N' lines contain two integers separated by a single space, where the first integer represents the x coordinate and the second integer represents the y coordinate.
Output Format :
The only line contains the minimum distance between the 'N' points.
Note:
You do not need to print anything, it has already been taken care of. Just implement the given function.
```
Constraints :
2 <= 'N' <= 10^5
-10^5 <= 'x' <= 10^5 
-10^5 <= 'y' <= 10^5

Time Limit: 1 sec
Sample Input 1:
5
1 2
2 3
3 4
5 6
2 1
Sample Output 1:
2
Explanation of Sample Output 1:
We have 2 pairs which are probable answers (1, 2) with (2, 3) and (2, 3) with (3, 4). The distance between both of them is equal to 2.
```
## No of distinct pairs in array whose difference is K $
Problem Statement
Suggest Edit
Ninja has been asked to organize a dance competition. Ninja decided that he will take individual entries
and then will divide them into pairs. As part of the entry, he asked the participants to choose any number.
Ninja then thought of a creative method to divide them into pairs. He decided that he would select a
number 'K', and then select numbers from the list that have a difference equal to 4K'.
You need to help Ninja in finding the number of distinct pairs from the numbers with differences equal to
Example:
Let us suppose the numbers are chosen by participants: [2, 6, 5, 2, 3] and K =
3, then
the distinct pairs having differences equal to K are: [2, 5] and [3, 6] so print 2.
Note:
The list of
pairs.
For example
are: (2, 3)
numbers can contain duplicate numbers, you need to print only the distinct
[2,
and
2,
3, 4] and K =
1, so you need to print 2 as the two distinct pairs
