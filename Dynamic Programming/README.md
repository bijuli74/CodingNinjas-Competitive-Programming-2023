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
