## Nth Fibonacci Number
Nth term of Fibonacci series F(n), where F(n) is a function, is calculated using the following formula -
    F(n) = F(n-1) + F(n-2), 
    Where, F(1) =  1, 
           F(2) = 1
Provided N you have to find out the Nth Fibonacci Number.

## Staircase
A child is running up a staircase with n steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child can run up to the stairs. You need to return all possible number of ways.
Time complexity of your code should be O(n).
Since the answer can be pretty large print the answer % mod(10^9 +7)

## Digits Decoding
A few days back, Ninja encountered a string containing characters from ‘A’ to ‘Z’ which indicated a secret message. For security purposes he encoded each character of the string to its numeric value, that is, A = 1, B = 2, C = 3, till Z = 26 and combined them as a single sequence (SEQ) of digits of length N. Let's say the message was "LA", Ninja encoded it as 121 for L=12 and A=1.
Today, when he read the encoded secret message, he realised that he was not able to decode the original string. So, the Ninja is wondering in how many ways he can decode the numeric sequence to some valid string.
A valid string is a string with characters from A to Z and no other characters.

## Coin Change (Infinite Supply)
You are given an infinite supply supply of coins of each of denominations D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total number of ways W, in which you can make change for Value V using coins of denominations D

## Coin Change(Finite Supply)
Send Feedback
You are given an array of integers ‘coins’ denoting the denomination of coins and another array of integers ‘freq’ denoting the number of coins of each denomination.
You have to find the number of ways to make the sum ‘V’ by selecting some(or all) coins from the array.
The answer can be very large. So, return the answer modulo 1000000007.

## Ninja and Coins
Ninja is at a shop and wants to buy a gift whose value is ‘K’. Ninja has N coins, each having a different denomination. While paying the shopkeeper, he found that he could pay the price of the gift using other ways. Ninja wants to know what is the number of different combinations in which Ninja can pay the price. Can you help the ninja to find the number of ways to make the value of ‘K’ using these ‘N’ coins?
You are given an array ‘COINS’ having ‘N’ integers corresponding to the value of each denomination and an integer ‘K’ denoting the value of the gift. Your task is to find the number of different ways in which the value ‘K’ can be made using these ‘N’ coins. The answer can be very large.Return answer % (10^9 +7).

## Maze obstacles
Given a ‘N’ * ’M’ maze with obstacles, count and return the number of unique paths to reach the right-bottom cell from the top-left cell. A cell in the given maze has a value '-1' if it is a blockage or dead-end, else 0. From a given cell, we are allowed to move to cells (i+1, j) and (i, j+1) only. Since the answer can be large, print it modulo 10^9 + 7.
For Example :
Consider the maze below :
0 0 0 
0 -1 0 
0 0 0

There are two ways to reach the bottom left corner - 

(1, 1) -> (1, 2) -> (1, 3) -> (2, 3) -> (3, 3)
(1, 1) -> (2, 1) -> (3, 1) -> (3, 2) -> (3, 3)

Hence the answer for the above test case is 2.

## Min Cost Path
Given an integer matrix of size m*n, you need to find out the value of minimum cost to reach from the cell (0, 0) to (m-1, n-1).
From a cell (i, j), you can move in three directions : (i+1, j), (i, j+1) and (i+1, j+1).
Cost of a path is defined as the sum of values of each cell through which path passes.
