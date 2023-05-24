## Count Inversions
For a given integer array/list 'ARR' of size 'N' containing all distinct values, find the total number of 'Inversions' that may exist.
An inversion is defined for a pair of integers in the array/list when the following two conditions are met.
A pair ('ARR[i]', 'ARR[j]') is said to be an inversion when:

1. 'ARR[i] > 'ARR[j]' 
2. 'i' < 'j'

Where 'i' and 'j' denote the indices ranging from [0, 'N').

## Kth Smallest and Largest Element of Array
You are given an array ‘Arr’ consisting of ‘N’ distinct integers and a positive integer ‘K’. Find out Kth smallest and Kth largest element of the array. It is guaranteed that K is not greater than the size of the array.

## Sort 0 1 2
You are given an integer array/list(ARR) of size N. It contains only 0s, 1s and 2s. Write a solution to sort this array/list in a 'single scan'.
'Single Scan' refers to iterating over the array/list just once or to put it in other words, you will be visiting each element in the array/list just once.

## Sort an array in wave form
You have been given an unsorted array ‘ARR’.
Your task is to sort the array in such a way that the array looks like a wave array.
Example:
If the given sequence ‘ARR’ has ‘N’ elements then the sorted wave array looks like - 
‘ARR[0] >= ARR[1]’ and ‘ARR[1] <= ARR[2]’
‘ARR[2] >= ARR[3]’ and ‘ARR[3] <= ARR[4]’
‘ARR[4] >= ARR[5]’ and ‘ARR[5] <= ARR[6]’  And so on.
```
Sample Input 1:
2
5 
2 3 1 4 2
6
4 3 2 5 4 1
Sample Output 1:
2 1 3 2 4
4 3 5 2 4 1
```
## Sort By Kth Bit $
You are given an array/list ‘ARR’ of ‘N’ positive integers and an integer ‘K’. Your task is to group all the array elements with ‘K-th’ bit (rightmost bit is ‘1st’ bit) equal to 0 followed by all the elements with ‘K-th’ bit equal to 1.
Note 1: The relative order inside both the groups should remain as it was in the input.
Note 2: You have to return the modified array/list..

## Minimum number of swaps required to sort an array $
You have been given an array 'ARR' of 'N' distinct elements.
Your task is to find the minimum no. of swaps required to sort the array.
For example: For the given input array [4, 3, 2, 1], the minimum no. of swaps required to sort the array is 2, i.e. swap index 0 with 3 and 1 with 2 to form the sorted array [1, 2, 3, 4].

## Relative Sorting $
Given two arrays ‘ARR’ and ‘BRR’ of size ‘N’ and ‘M’ respectively. Your task is to sort the elements of ‘ARR’ in such a way that the relative order among the elements will be the same as those are in ‘BRR’. For the elements not present in ‘BRR’, append them in the last in sorted order.
For example
Consider the arrays as ARR = { 9, 5, 8, 4, 6, 5 } and BRR = { 8, 4, 5 }
The output for the above example  is { 8, 4, 5, 5, 6, 9 }.
Note:
Elements of ‘BRR’ are non repeating.

## Sorting the Skills
Send Feedback
There is a company named James Peterson & Co. The company has ‘n’ employees. The employees have skills, which is denoted with help of an integer. The manager of James Peterson & Co. wants to sort the employees on the basis of their skills in ascending order. He is only allowed to swap two employees which are adjacent to each other. He is given the skills of employees in an array of size ‘n’. He can swap the skills as long as the absolute difference between their skills is 1. You need to help the manager out and tell whether it is possible to sort the skills of employees or not.
Input Format:
First Line will have an integer ‘t’ denoting the no. of test cases.
First line of each test case contains an integer ‘n’ denoting the no. of employees in the company.
Second line of each test case contains ‘n’ integers.
Output Format:
For each test case, print “Yes” if it is possible to sort the skills otherwise “No”.
```
Constraints:
1 <= t <= 10^4
1 <= n <= 10^5
Sum of n over all test cases doesn't exceed 10^6
Sample Input:
2
4
1 0 3 2
3
2 1 0
Sample Output:
Yes
No
Explanation:
In first T.C., [1, 0, 3, 2] -> [0, 1, 3, 2] -> [0, 1, 2, 3]
In second T.C., [2, 1, 0] -> [1, 2, 0]  OR  [2, 1, 0] -> [2, 0, 1] So, it is impossible to sort.
```
## Murder $$
Once detective Saikat was solving a murder case. While going to the crime scene he took the stairs and saw that a number is written on every stair. He found it suspicious and decides to remember all the numbers that he has seen till now. While remembering the numbers he found that he can find some pattern in those numbers. So he decides that for each number on the stairs he will note down the sum of all the numbers previously seen on the stairs which are smaller than the present number. Calculate the sum of all the numbers written on his notes diary.
Answer may not fit in integer . You have to take long.
Input Format:
First line of input contains an integer T, representing number of test case.
For each test case, first line of input contains integer N, representing the number of stairs.
For each test case, second line of input contains N space separated integers, representing numbers written on the stairs.
```
Constraints
T<=10^5
1<=N<=10^5
All numbers will be between 0 and 10^9
Sum of N over all test cases doesn't exceed 5*10^5
Output Format
For each test case output one line giving the final sum for each test case.
Sample Input 1:
1
5
1 5 3 6 4
Sample Output 1:
15
```
Explanation:
For the first number, the contribution to the sum is 0.
For the second number, the contribution to the sum is 1.
For the third number, the contribution to the sum is 1.
For the fourth number, the contribution to the sum is 9 (1+5+3).
For the fifth number, the contribution to the sum is 4 (1+3).
Hence the sum is 15 (0+1+1+9+4).
