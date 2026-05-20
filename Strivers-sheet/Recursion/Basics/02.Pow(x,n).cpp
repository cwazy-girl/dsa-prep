/*
QUESTION:-
Implement pow(x, n), which calculates x raised to the power n (i.e. x^n).

Example:
Input: x = 2.00000, n = -2
Output: 0.25000
*/

/*
APPROACH:
1. If n is 0, then return 1.
2. If n > 0, we check if n is even. If yes, we return the function recursively with x*x and n/2.
3. If no, we return the function recursively with x*x and n/2, multiplied by x {to compensate for the odd number of x}.
4. If n < 0, we return 1 / myPow(x, -n).
*/

//CODE:
class Solution {
public:
    double myPow(double x, long long n) {
        if(n == 0) return 1;

        if(n > 0) {
            if(n % 2 == 0) return myPow(x*x, n/2);
            else return myPow(x*x, n/2) * x;
        }
        else {
            return 1 / myPow(x, -1 * n);
        }
    }
};

//Time Complexity : O(logN) {Everytime, n gets halved}
//Space Complexity : O(logN) {recursive stack}
