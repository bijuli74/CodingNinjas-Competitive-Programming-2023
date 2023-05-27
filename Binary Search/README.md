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

## Traffic Lights $
There is a street of length ‘X’ with 'X' slots numbered from 0 to 'X' (0,1,…, ’X’). Initially, there are no traffic lights in these slots. Later ‘N’ sets of traffic lights are added to the street one after another. The ‘POS’ array tells the position of the ‘i’th light.
Your task is to calculate the length of the longest passage without traffic lights after each addition.
For example:
Given:- ‘X’ = 5 and ‘N’ = 2.
‘POS’[] = 3, 4
The output will be 3 and 3.
Initially, there are no lights, and we install a light at position three; therefore, there is a segment between the 3 and 6. 
Then we install a light at position four; therefore, the largest gap becomes between 0 to 3.

## Glowing Bulbs $
Send Feedback
There are an infinite number of electric bulbs. Each bulb is assigned a unique integer starting from 1. There are ‘N’ switches also and each switch is labeled by a unique prime number. If a switch labeled with prime integer ‘p’ is turned ON, then all the bulbs having a number that is multiple of ‘p’ will start glowing. For example, if we turn ON the switch labelled 2, then all the bulbs having numbers 2, 4, 6, 8, 10, ... i.e all bulbs with numbers as multiples of 2 will start glowing.
You are given an array/list ‘LABELS’ consisting of ‘N’ unique prime integers representing the label of the switches and an integer ‘K’. Your task is to find the integer assigned to Kth glowing bulb from the start when all these ‘N’ switches are turned ON.
Note :
1. Some bulbs can glow by multiple switches and some are not glowed by any switch.
2. If any of the switches that can glow a bulb is turned ‘ON’, then the corresponding bulb will glow.
Example :
Consider 3 switches with labels [3, 5,  7] and we need to find the 5th glowing bulb from the start after turning these 3 switches ON.
We can see that bulbs numbered  3, 6, 9, 15, 18 …  will glow if the switch having label 3 is turned ON.
The bulbs numbered 5, 10, 15, 20 … will glow if the switch having label 5 is turned ON.
The bulbs numbered 7, 14, 21, 28 … will glow if the switch having label 7 is turned ON.
It implies that bulbs numbered 3, 5, 6, 7, 9, 10, 14, 15, 18, 20, 21… will glow when these three switches are turned ON.
The 5th glowing bulb from start is assigned integer 9. Thus, we should return 9.
