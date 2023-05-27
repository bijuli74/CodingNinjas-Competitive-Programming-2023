## All Subsets Generation
You are given an array ‘arr’ of ‘N’ distinct integers. Your task is to find all the non-empty subsets of the array.
Note: You can return the subsets in any order, you don’t have to specifically sort them.

## Permutations of a String
You are given a string 'STR' consisting of lowercase English letters. Your task is to return all permutations of the given string in lexicographically increasing order.
String A is lexicographically less than string B, if either A is a prefix of B (and A ≠ B), or there exists such i (1 <= i <= min(|A|, |B|)), that A[i] < B[i], and for any j (1 <= j < i) A[i] = B[i]. Here |A| denotes the length of the string A.
For example :
If the string is “bca”, then its permutations in lexicographically increasing order are { “abc”, “acb”, “bac”, “bca”, “cab”, “cba” }.

## Combination Sum
You are given an array/list ARR of N distinct positive integers. You are also given a non-negative integer B.
Your task is to find all unique combinations in the array whose sum is equal to B. A number can be chosen any number of times from array/list ARR.
Elements in each combination must be in non-decreasing order.
For example:
Let the array ARR be [1, 2, 3] and B = 5. Then all possible valid combinations are-

(1, 1, 1, 1, 1)
(1, 1, 1, 2)
(1, 1, 3)
(1, 2, 2)
(2, 3)

## Print Keypad - String
Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.

## Print Series
You have given two positive integers N and K. Your task is to print a series of numbers i.e subtract K from N until it becomes 0 or negative then add K until it becomes N. You need to do this task without using any loop.
For Example:
For  N = 5 , K = 2 
Series = [ 5, 3, 1, -1, 1, 3, 5]

## Family Structure
Aakash is a member of Ninja club. He has a weird family structure. Every male member (M) gives birth to a male child first and then a female child, whereas every female (F) member gives birth to a female child first and then to a male child. Aakash analyses this pattern and wants to know what will be the Kth child in his Nth generation. Can you help him?

## E. Creating Expression1
Given two numbers N,Xand an array Aof Nnumbers. Determine if there is a way to put '+' or '-' signs between every two numbers in the array Ain order to make an expression that is equal to X

Note: Solve this problem using recursion.

Input
First line contains two numbers N
 and X
 (1≤N≤20,−109≤X≤109)

Second line contains N
 distinct numbers A1,A2,....AN
 (1≤Ai≤105)

Output
Print "YES" if you can put '+' or '-' signs between every two number to create an expression that is equal to X
 otherwise, print "NO".
## Return Subsets Sum to K $
Given an integer array 'ARR' of size 'N' and an integer 'K', return all the subsets of 'ARR' which sum to 'K'.
Subset of an array 'ARR' is a tuple that can be obtained from 'ARR' by removing some (possibly all) elements of 'ARR'.
Note :
The order of subsets is not important. 
The order of elements in a particular subset should be in increasing order of the index.

## Count derangements
A Derangement is a permutation of ‘N’ elements, such that no element appears in its original position. For example, an instance of derangement of {0, 1, 2, 3} is {2, 3, 1, 0}, because 2 present at index 0 is not at its initial position which is 2 and similarly for other elements of the sequence.
Given a number ‘N’, find the total number of derangements possible of a set of 'N’ elements.

## Verbal Arithmetic Puzzle $
You are given an array of the strings “words” of size 'M' and another string “result”. You have to treat it as an equation in which the left side is represented by the array “words” and the right side is represented by the string "result". Your task is to determine whether the equation is solvable or not under the following conditions:
1. Each character is decoded as a digit in the range [0, 9].
2. Each character must have only one mapping, and every pair of characters must map to different digits.
3. Each element of the array “words” and the string “result” are decoded as one number without the leading zeros.
4. The sum of the numbers on the left-hand side (words) must equal the number on the right-hand side (result).
