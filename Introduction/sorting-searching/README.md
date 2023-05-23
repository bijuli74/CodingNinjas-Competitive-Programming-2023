## Binary Search
You are given an integer array 'A' of size 'N', sorted in ascending order. You are also given an integer 'target'.
Your task is to write a function to search for 'target' in the array 'A'. If it exists, return its index in 0-based indexing. Otherwise, return -1.
Note: You must write an algorithm whose time complexity is O(logN).

## Bubble Sort
Provided with a random integer array/list(ARR) of size N, you must sort this array using 'Bubble Sort'.
Note:
Change in the input array/list itself. You don't need to return or print the elements.

## Insertion Sort
Provided with a random integer array/list(ARR) of size N, you have been required to sort this array using 'Insertion Sort'.

## Merge Two Sorted Arrays
You have been given two sorted arrays/lists(ARR1 and ARR2) of size N and M respectively, merge them into a third array/list such that the third array is also sorted.

## Push Zeros to end
You have been given a random integer array/list(ARR) of size N. You have been required to push all the zeros that are present in the array/list to the end of it. Also, make sure to maintain the relative order of the non-zero elements.

## Rotate array
You have been given a random integer array/list(ARR) of size N. Write a function that rotates the given array/list by D elements(towards the left).
Sample Input 1:
```
1
7
1 2 3 4 5 6 7
2
```
Sample Output 1:
```
3 4 5 6 7 1 2
```

## Second Largest in array
You have been given a random integer array/list(ARR) of size N. You are required to find and return the second largest element present in the array/list.
If N <= 1 or all the elements are same in the array/list then return -2147483648 or -2 ^ 31(It is the smallest value for the range of Integer)

Sample Input 3:
```
2
2
6 6
4
90 8 90 5
```
Sample Output 3:
```
-2147483648
8
```
## Check Array Rotation
You have been given an integer array/list(ARR) of size N. It has been sorted(in increasing order) and then rotated by some number 'K' (K is greater than 0) in the right hand direction.
Your task is to write a function that returns the value of 'K', that means, the index from which the array/list has been rotated.
Sample Input 1:
```
1
6
5 6 1 2 3 4
```
Sample Output 1:
```
2
```
## Sort 0 1 2
You are given an integer array/list(ARR) of size N. It contains only 0s, 1s and 2s. Write a solution to sort this array/list in a 'single scan'.
'Single Scan' refers to iterating over the array/list just once or to put it in other words, you will be visiting each element in the array/list just once.

## Sum of Two Arrays
Two random integer arrays/lists have been given as ARR1 and ARR2 of size N and M respectively. Both the arrays/lists contain numbers from 0 to 9(i.e. single digit integer is present at every index). The idea here is to represent each array/list as an integer in itself of digits N and M.
You need to find the sum of both the input arrays/list treating them as two integers and put the result in another array/list i.e. output array/list will also contain only single digit at every index.

Constraints :
```
1 <= t <= 10^2
0 <= N <= 10^5
0 <= M <= 10^5
```
Time Limit: 1 sec 
Sample Input 1:
```
1
3
6 2 4
3
7 5 6
```
Sample Output 1:
```
1 3 8 0
```
Sample Input 2:
```
2
3
8 5 2
2
1 3
4
9 7 6 1
3
4 5 9
```
Sample Output 2:
```
0 8 6 5
1 0 2 2 0 
```
## Find pair sum in rotated sorted array
Alice and Bob always loved to play with arrays. Alice took a sorted array and rotated it clockwise for a
certain number of times.
For Example:
Alice took a sorted array =
and if she rotates it by 3,
becomes: [8, 18, 11, 4, 6].
then the array
After rotating a sorted array, Alice gave a number 'K' to Bob and asked him to search for a pair in an
array whose sum is equal to K. Since Bob was busy preparing for his semester exams, he asked you to
help him.
You are given an array of integers ARR and a number K. Your task is to find out whether there exists a
pair in the array ARR with sum K or not. If there exists a pair then you can return TRUE else retum FALSE;
