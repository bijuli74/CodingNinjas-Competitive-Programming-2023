## Search in Rotated Sorted Array
Aahad and Harshit always have fun by solving problems. Harshit took a sorted array consisting of distinct integers and rotated it clockwise by an unknown amount. For example, he took a sorted array = [1, 2, 3, 4, 5] and if he rotates it by 2, then the array becomes: [4, 5, 1, 2, 3].
After rotating a sorted array, Aahad needs to answer Q queries asked by Harshit, each of them is described by one integer Q[i]. which Harshit wanted him to search in the array. For each query, if he found it, he had to shout the index of the number, otherwise, he had to shout -1.
For each query, you have to complete the given method where 'key' denotes Q[i]. If the key exists in the array, return the index of the 'key', otherwise, return -1.
Note:
Can you solve each query in O(logN) ?

## Aggressive Cows
You are given an array 'arr' consisting of 'n' integers which denote the position of a stall.
You are also given an integer 'k' which denotes the number of aggressive cows.
You are given the task of assigning stalls to 'k' cows such that the minimum distance between any two of them is the maximum possible.

## Recycling Pens
You have 'N' empty pens whose refills have been used up. You have 'R' rupees in your pocket. You have two choices of operations that you can perform each time.
1) Recycle 1 empty pen and get 'K' rupees as a reward.
2) Buy 1 refill for 'C' rupees and combine it with 1 empty pen to make one usable pen.
Your task is to find the maximum number of usable pens that you can get.
For example if you have 'N' = 5 , 'R' = 10 , 'K' = 2 , 'C' = 3. You can recycle one pen and get 2 rupees as a reward so you will have a total of 12 rupees. Now you can buy 4 refills and combine it with 4 pens to make it usable. So your answer is 4.

## Painter's Partition Problem
Given an array/list of length ‘N’, where the array/list represents the boards and each element of the given array/list represents the length of each board. Some ‘K’ numbers of painters are available to paint these boards. Consider that each unit of a board takes 1 unit of time to paint.
You are supposed to return the area of the minimum time to get this job done of painting all the ‘N’ boards under a constraint that any painter will only paint the continuous sections of boards.

## Smart Intervals
You are given an array of intervals, where intervals[i] = [start(i), end(i)] and each start(i) is unique.
The smart interval for an interval ‘i’ is an interval ‘j’ such that start(j) is greater than or equal to end(i) and start(j) should be minimum.
Your task is to return an array of smart interval indices for each interval. If no smart interval exists for an interval ‘i’, then place -1 at index ‘i’ in the output array.
```
Sample Input 1:
1
3
1 2
2 3
3 4
Sample output 1:
1 2 -1
Explanation of Sample output 1:
Smart interval for the interval [1, 2] is [2, 3] because the start point of [2, 3] is equal to the end point of [1, 2]. The index of [2, 3] is 1.
Smart interval for the interval [2, 3] is [3, 4] because the start point of [3, 4] is equal to the end point of [2, 3]. The index of [3, 4] is 2.
Smart interval for the interval [3, 4] does not exist. Hence, -1.
Therefore, the final answer is [1, 2, -1]. 
```

## Shopping Options
You are given the list of costs of pants in an array “pants”, shirts in an array “shirts”, shoes in an array “shoes”, and skirts in an array “skirts”. You are also given a budget amount ‘X’ to spend. You want to buy exactly 1 item from each list. Your task is to determine the total number of possible combinations that you can buy, given that the total amount of your purchase does not exceed your budget amount
