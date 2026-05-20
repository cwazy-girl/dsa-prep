/*
QUESTION:-
A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).
Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, return it modulo 10^9 + 7.

Example:

Input: n = 1
Output: 5
Explanation: The good numbers of length 1 are "0", "2", "4", "6", "8".
*/

//RECURSIVE CODE:

/*
APPROACH:
1. In this, we create a new function with two arguments : n and index {to track which index we are at in the number}.
2. If index == n, that means we exceeded the digit string. Return 1.
3. If index is even, then for each of the even digits i.e. 5 times, we add count(n, index+1) to the ans. This creates one number at a time and adds 1 to answer. Hence, by recursion, we create all numbers one by one, and add 1 to ans.
4. If index is odd, then for each of the prime digits i.e. 4 times, we add count(n, index+1) to the ans.
5. Return ans % cont.
6. Now in the original function, return count(n, 0).
*/

class Solution {
public:
    int count(long long n, int index) {
        int ans = 0;
        if(index == n) return 1;

        if(index % 2 == 0) {
            for(int digit : {0, 2, 4, 6, 8}) {
                ans = ans + count(n, index + 1);
            }
        }
        else {
            for(int digit : {2, 3, 5, 7}) {
                ans = ans + count(n, index + 1);
            }
        }
        return ans % 1000000007;
    }

    int countGoodNumbers(long long n) {
        return count(n, 0);
    }
};

//Time Complexity : [exponential] {due to recursion}
//Space Complexity : O(N) {linear recursion stack}

//{In this approach, recursion tree grows so exponentially that it exceeds time limit even at small values of n.}

//OPTIMAL CODE:

/*
APPROACH:
1. In this approach, we first create a function for power of x.
2. In it, if n is 0, return 1. If n is even, return function called recursively with x*x % cont and n/2. If n is odd, return function called recursively with x*x % cont and n/2, multiplied by x, whole % cont.
3. Now in our original function, we find the number of even and odd places in the number.
4. For even places, there are 5 options : 0, 2, 4, 6, 8. For odd places, there are 4 options : 2, 3, 5, 7.
5. So, update even with power(5, even) % cont. Update odd with power(4, odd) % cont.
6. Return odd * even % cont.
{Make sure to always do % cont, so as to not go out of the range of 'long long'.}
*/

class Solution {
public:
    long long power(long long x, long long n) {
        if(n == 0) return 1;

        if(n % 2 == 0) return power((x*x) % 1000000007, n/2);
        else return (power((x*x) % 1000000007, n/2) * x) % 1000000007;
    }

    int countGoodNumbers(long long n) {
        long long even;
        long long odd = n/2;

        if(n % 2 == 0) {
            even = n/2;
        }
        else {
            even = n/2 + 1;
        }

        even = power(5, even) % 1000000007;
        odd = power(4, odd) % 1000000007;

        return (odd * even) % 1000000007;
    }
};

//Time Complexity : O(logN) {due to power function}
//Space Complexity : O(logN)
