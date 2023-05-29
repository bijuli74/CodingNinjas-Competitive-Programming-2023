## Find Prime Numbers
You are given a positive integer ‘N’. Your task is to print all prime numbers less than or equal to N.
Note: A prime number is a natural number that is divisible only by 1 and itself. Example - 2, 3, 17, etc.
You can assume that the value of N will always be greater than 1. So, the answer will always exist.

## Segmented Sieve Problem
In this problem you have to print all primes from given interval.

## Super Prime $
A number is called super-prime if it has exactly two distinct prime divisors
Example 10 , 6
You are supposed to find the count of super-prime numbers between 1 and N (inclusive).

## Ninja and Flowers $
Ninja wants to get N flowers and he will pay i + 1 amount of money for the Ith flower, example (if n=3 he will pay {2,3,4})
Now he wants to pack these N flowers in boxes of different colours. With one condition if the cost of a flower is a prime divisor of another flower they needed to be of a different colour.
As we know that ninja is a little money minded he wants to minimize the number of different colours of boxes that he needs.

## Special Prime
Special Prime is a prime number that can be written as the sum of two neighbouring primes and 1.
You are given an integer N and you are supposed to find the number special prime in the range: [1, N].
Example of special prime 19 = 7 + 11 + 1
Neighbouring primes are prime number such that there is no other prime number between them.

## Number Of Factors $
A number is called n-factorful if it has exactly n distinct prime factors. Given positive integers a, b, and n, your task is to find the number of integers between a and b, inclusive, that are n-factorful. We consider 1 to be 0-factorful.

## Sachin and Varun Problem
Varun and you are talking about a movie that you have recently watched while Sachin is busy teaching Number Theory. Sadly, Sachin caught Varun talking to you and asked him to answer his question in order to save himself from punishment. The question says:
Given two weights of a and b units, in how many different ways you can achieve a weight of d units using only the given weights? Any of the given weights can be used any number of times (including 0 number of times).
Since Varun is not able to answer the question, he asked you to help him otherwise he will get punished.
Note: Two ways are considered different if either the number of times a is used or a number of times b is used is different in the two ways.

## Totient function
You are given an integer N and are supposed to find the value of Euler toient function for N phi(N)

## GCD Sum
Consider all numbers from 1 to ‘N’, your task is to find the sum of gcd of all pairs (i, j) such that 1 <= i < j <= N.
For example for N = 3, all pairs are { (1, 2), (1, 3), (2, 3) }.
Note :
Gcd of two numbers (X, Y) is defined as the largest integer that divides both ‘X’ and ‘Y’. 

## Divisors of Factorial
Given a number, find the total number of divisors of the factorial of the number.
Since the answer can be very large, print answer modulo 10^9+7.

## Strange order
Given an integer n . Initially you have permutation p of size n : p[i] = i . To build new array a from p following steps are done while permutation p is not empty:
Choose maximum existing element in p and define it as x ; Choose all such y in p that gcd ( x , y ) ≠ 1 ; Add all chosen numbers into array a in decreasing order and remove them from permutation. Your task is to find a after p became empty.
Note: gcd ( a , b ) is the greatest common divisor of integers a and b .

## Card Game $
Vova again tries to play some computer card game.
The rules of deck creation in this game are simple. Vova is given an existing deck of n cards and a magic number k. The order of the cards in the deck is fixed. Each card has a number written on it; number ai is written on the i-th card in the deck.
After receiving the deck and the magic number, Vova removes x (possibly x = 0) cards from the top of the deck, y (possibly y = 0) cards from the bottom of the deck, and the rest of the deck is his new deck (Vova has to leave at least one card in the deck after removing cards). So Vova's new deck actually contains cards x + 1, x + 2, ... n - y - 1, n - y from the original deck.
Vova's new deck is considered valid iff the product of all numbers written on the cards in his new deck is divisible by k. So Vova received a deck (possibly not a valid one) and a number k, and now he wonders, how many ways are there to choose x and y so the deck he will get after removing x cards from the top and y cards from the bottom is valid?

## Find The Cube Free Number
A cube free number is a number who’s none of the divisor is a cube number (A cube number is a cube of a integer like 8 (2 * 2 * 2) , 27 (3 * 3 * 3) ). So cube free numbers are 1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12, 13, 14, 15, 17, 18 etc (we will consider 1 as cube free). 8, 16, 24, 27, 32 etc are not cube free number. So the position of 1 among the cube free numbers is 1, position of 2 is 2, 3 is 3 and position of 10 is 9. Given a positive number you have to say if its a cube free number and if yes then tell its position among cube free numbers.
Note: we will consider 1 as the 1st cube free number

## Euler Totient Function Sum
You are given a positive integer ‘N’, your task is to return an array/list of integers such that the sum of Euler Totient Function values of each integer of the array is equal to ‘N’.
Euler Totient Function:
In number theory, Euler's totient function counts the positive integers up to a given integer ‘N’ that is relatively prime to ‘N’.

## Find the good sets! $
You are given array a consisting of n distinct integers. A set s of numbers is called good if you can rearrange the elements in such a way that each element divides the next element in the order, i.e. 'si' divides 'si + 1', such that i < |s|, where |s| denotes size of set |s|.
Find out number of distinct good sets that you can create using the values of the array. You can use one value only once in a particular set; ie. a set cannot have duplicate values. Two sets are said to be different from each other if there exists an element in one set, which does not exist in the other.
As the answer could be large, print your answer modulo 10^9 + 7.

## Fibonacci Sum  $$
The fibonacci sequence is defined by the following relation:
 F(0) = 0
 F(1) = 1
 F(N) = F(N - 1) + F(N - 2), N >= 2
Your task is very simple. Given two non-negative integers N and M (N <= M), you have to calculate and return the sum (F(N) + F(N + 1) + ... + F(M)) mod 1000000007.

## Sehwag and ETF $$
Sehwag has been solving a lot of mathematical problems recently. He was learning ETF (Euler Totient Function) and found the topic quite interesting. So, he tried solving a question on ETF. He will be given two numbers L and R. He has to find the probability that the ETF of a number in the range [L, R] is divisible by a number K.
Input Format:
The first line contains an integer T, representing the number of test cases.
The next T lines will contain three integers L, R and K.

## Sanchit And Nuclear Reactor
Sanchit, an eccentric physicist, challenges his engineer friend Howard to solve a problem related to Sanchit's nuclear reactor. The reactor has a special condition where atoms reach a stable state when their number is a multiple of a prime number called the Cooper number. Howard needs to calculate the reactor's energy output after a given time T.
Input Format
The first line of input contains T(number of the test case), each test case follows as.
contian two space-separated integers N and M where M is a prime number.
Output Format
You have to determine the energy output after time T. As the number can be quite large so output it modulo Cooper number m.
```
Constraints:
1 <= T <= 100
1 <= N <= 10^18
1 <= M <= 10^4
Sample Input
2
1 5
2 5
Sample Output
1
2
Explanation
After 1 seconds, there is only 1 atom in the tank. Hence energy output is 1. After 2 seconds, there are 2 atoms which reacts to give energy output of 2.
```
## GCD Extreme
Given the value of N, you will have to find the value of G. The meaning of G is given in the following code
G=0;
for(i = 1 ; i < N ; i++)
   for(j = i+1 ; j <= N ; j++) 
       G+=gcd(i,j);
Here gcd() is a function that finds the greatest common divisor of the two input numbers.

## Innocent Swaps and His Emotions $$
There are only three phases in Swaps life: Sleep, Play and Study. Also, there are two types of emotions Swaps experiences: Happy and Sad. Each phase of his life brings either kind of emotions.
The sleep and the play phase makes Swaps happy whereas the study phase makes him sad. Quite obvious, isn't it? But we know that life isn't that great, one cannot be happy all the time.
Swaps, being a very sensitive guy, doesn't like to mix his emotions on a particular day. So each day, he is in exactly one of the three phases.
Given N which denotes the number of days and K which denotes the exact number of days Swaps needs to be happy out of these N days, can you tell him in how many ways can he achieve this? Since the output value can be very large, take modulo with 1000000007(10^9+7)

## Cubic Square
Varun is learning method of successive squaring so that he can calculate a^b mod m quickly. To give himself practice he wrote many tuples of a, b and m and went to school thinking that he will do it after school.
After school he found that tuples he wrote are modified by his little sister. His sister converted each b into base 3. Varun wrote everything in base 10.

## Find the N-th term
You want to get tutelage under the Ultimate Ninja Ankush, but for that you have to pass his test. His test is simple: he has given you a relation function, F(n) = 2*F(n-1) + 3*F(n-2),where F(0) = F(1) = 1 and wants you to find the ‘N’th term for the function.
The 'N'th term can be very large, return it after modulus 10^9 + 7.
For example:
Given ‘N’ = 3,
F(3) = 13,This is because F(0) = 1, F(1) = 1, Therefore F(2) = 2*F(1) + 3*F(1), therefore F(2) = 5, and F(3) = 2*F(2) + 3*F(1), therefore F(3) = 13.

## Find The Prime
Ninja is given a crucial task. He is given a positive integer ‘K’, and he has to tell the ‘Kth’ prime number.
For example:
The first prime number is ‘2’, and the second prime number is ‘3’.

## Remainder Check $$
You just learnt about the “mod” operation and you’re fascinated by it. ‘X’ mod ‘Y’ is defined as the remainder that ‘X’ leaves when divided by ‘Y’.
You are now given two integers ‘X’ and ‘Y’ and ‘Q’ queries of the type ‘L’, ’R’ and you want to find the number of integers ‘T’ in the range (L , R) (both ‘L’ and ‘R’ included) such that
( ( T mod X ) mod Y ) ≠ ( ( T mod Y ) mod X ) 
For example:
If ‘X’=4 and ‘Y’=6, and the range is [1,7], then the answer will be 2, as both 6 and 7 satisfy the above condition. 

## Boring Factorials
Sameer and Arpit want to overcome their fear of Maths and so they have been recently practising Maths problems a lot. Aman, their friend has been helping them out. But as it goes, Sameer and Arpit have got bored with problems involving factorials. Reason being, the factorials are too easy to calculate in problems as they only require the residue modulo some prime and that is easy to calculate in linear time. So to make things interesting for them, Aman - The Mathemagician, gives them an interesting task. He gives them a prime number P and an integer N close to P, and asks them to find N! modulo P. He asks T such queries.

## Numbers and Remainders
Ninja is learning about the mathematical division and remainders. So in curiosity, he forms two lists of numbers ‘ARR’ and ‘REM’ both having ‘N’ numbers. Now Ninja is interested in finding the minimum positive number ‘X’ such that ‘X’ satisfies the following condition for all ‘N’ values:
X % ‘ARR’[i] = ‘REM’[i] (Remainder of X / ARR[i] should be equal to  ‘REM’[i]).
You are given two arrays ‘ARR’ and ‘REM’ both having ‘N’ values corresponding to the numbers and remainders. Your task is to find the smallest positive integer ‘X’ fulfilling the given conditions.

## Income On Nth Day
Daulat Ram is an affluent business man. After demonetization, IT raid was held at his accommodation in which all his money was seized. He is very eager to gain his money back, he started investing in certain ventures and earned out of them. On the first day, his income was Rs. X, followed by Rs. Y on the second day. Daulat Ram observed his growth as a function and wanted to calculate his income on the Nth day.
The function he found out was FN = FN-1 + FN-2 + FN-1×FN-2
Given his income on day 0 and day 1, calculate his income on the Nth day (yeah Its that simple).

## Fermat Little Theorem
You are given two integers 'n' and 'r' and a prime number 'p'. Your task is to find (nCr) % p where nCr can be calculated as n! / (r! * (n - r)!).
Note :
N!  =  1 * 2 * 3 *... N

## Number Of Sequence
A sequence is called nice by a coding ninja if the following conditions are met:
0 <= ‘ARR’[k] <= k 
‘ARR’[k] = ‘ARR’[m] mod k, for all pairs of k,m such that k divides m.
You are given a sequence of integers ‘ARR’ where some numbers may be -1. Find and print the number of nice sequences you can create by changing each -1 to a non-negative integer. As this number can be quite large, your answer must be modulo it by 10 ^ 9 + 7.
For example:
Given ‘N’ = 3, 
'A' = {0, -1, -1} 
Then the answer is 6 because following sequences are possible:[0, 0, 0], [0, 1, 0], [0, 1, 1], [0, 1, 2], [0, 0, 1], [0, 0, 2].

## Factorial Again
Ninja Kate has finally calmed down and decides to forgive Little Ninja Deepu, but she will not forgive him just like that. Finally, she agrees to forgive him because he can solve a mathematical question for her.
She gives Ninja Deepu a large number ‘N’ and a prime number ‘P’ and asks him to calculate ((3 * ‘N’ ) ! / ( 3! ^ ‘N’ ) )% ‘P.’
Your task is to help Little Ninja Deepu get back together with Ninja Kate.
For example:
Given ‘N’ = 2, ‘P’ = 11. 
Then the answer will be 9. Because (6!) / (6 ^ 2) = 20, and 20 remainder 11 is 9. Therefore the answer is 9.

## Cover The Points
You are given ‘N’ points that you need to cover. To cover all the points from a point at ‘x’ to a point at ‘y’, the cost will be
c + (x − y)^2, where c is a constant. 
Given the points and the constant c, what is the minimum cost to cover all the points?
For Example:
If N=2 and C=3 and points are [1,2]. 

If we follow path 1 → 2, the total cost incurred would be (3+(1−2)^2)=4. We can prove that this is the minimum cost incurred.

Hence, the output will be 4.
```cpp
struct Line {
  int m, b;

  int eval(int x) { return m * x + b; }

  void init(int i, vector<int> &x, vector<int> &dp) {
    m = -int(2) * int(x[i - 1]);
    b = int(x[i - 1]) * int(x[i - 1]) + dp[i];
  }
};

double calcInter(const Line &a, const Line &b) {
  double r = (b.b - a.b) / double(a.m - b.m);

  return r;
}

int getMin(int x, int &sz, vector<double> &inters, vector<Line> &hull) {
  int i = 0;

  if (sz == 1) {
    i = 0;
  } else if (x < inters[sz - 2]) {
    i = sz - 1;
  } else {
    int lo = 0, hi = sz - 2, mi;
    while (lo < hi) {
      mi = (lo + hi) >> 1;

      if (inters[mi] > x) {
        lo = mi + 1;
      } else {
        hi = mi;
      }
    }

    i = lo;
  }

  return hull[i].eval(x);
}

int coverAllPoints(int n, int c, vector<int> &points) {
  vector<int> dp(n);
  vector<double> inters(n);

  dp[n - 1] = c;
  int sz = 0;

  vector<Line> hull(n);

  hull[sz++].init(n - 1, points, dp);

  for (int i = n - 2; i >= 0; --i) {
    dp[i] = c + (points[n - 1] - points[i]) * (points[n - 1] - points[i]);
    dp[i] = min(dp[i], getMin(points[i], sz, inters, hull) +
                           (points[i]) * (points[i]) + (c));

    if (i) {
      hull[sz++].init(i, points, dp);
    }

    if (sz - 2 >= 0) {
      inters[sz - 2] = calcInter(hull[sz - 1], hull[sz - 2]);
    }

    while (sz > 2 && inters[sz - 2] > inters[sz - 3]) {
      hull[sz - 2] = hull[sz - 1];
      sz--;

      if (sz - 2 >= 0) {
        inters[sz - 2] = calcInter(hull[sz - 1], hull[sz - 2]);
      }
    }
  }

  return dp[0];
}

// This is an implementation of a solution to the "Minimum Time to Collect All Keys" problem, where you are given the number of keys, n, and the cost of traveling one unit, c, and a list of the points at which the keys are located. The goal is to find the minimum time to collect all the keys, given that you start at one point and have to visit all other points exactly once.

// The solution uses dynamic programming, where dp[i] is an array that stores the minimum time to collect all keys starting from point i. The code uses a variant of the dynamic programming called "Convex Hull Optimization" to optimize the time complexity.

// The Line struct represents a line in the 2D space, and it has two properties: m which represents the slope of the line, and b which represents the y-intercept of the line. The eval function evaluates the line at a given x, and the init function initializes the line by setting the slope and y-intercept based on the values of i, x, and dp.

// The calcInter function calculates the intersection of two lines, a and b, and returns the x-coordinate of the intersection.

// The getMin function finds the line in the "convex hull" (a set of lines) with the minimum value of dp[i] for a given x.

// The coverAllPoints function implements the main logic of the solution. It starts by initializing dp[n-1] to c and creating the first line in the "convex hull". Then, it iterates over the remaining points in reverse order and calculates dp[i] as the minimum time to reach all keys starting from point i. The code uses the getMin function to find the line in the "convex hull" with the minimum value of dp[i] for a given x, and updates the "convex hull" as needed. Finally, it returns dp[0], which is the minimum time to reach all keys starting from the first point.
```

