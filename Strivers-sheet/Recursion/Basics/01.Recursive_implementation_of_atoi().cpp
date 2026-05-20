/*
QUESTION:-
Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

The algorithm for myAtoi(string s) is as follows:
1. Whitespace: Ignore any leading whitespace (" ").
2. Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
3. Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
4. Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. Specifically, integers less than -2^31 should be rounded to -2^31, and integers greater than 2^31 - 1 should be rounded to 2^31 - 1.

Return the integer as the final result.

Example:

Input: s = " -042"
Output: -42
Explanation:
Step 1: "   -042" (leading whitespace is read and ignored)
Step 2: "   -042" ('-' is read, so the result should be negative)
Step 3: "   -042" ("042" is read in, leading zeros ignored in the result)
*/

/*
APPROACH:
1. In this approach, we do the atoi() problem using recursion.
2. We first create a new function, in which we take the string, i {for traversing through the string}, ans {to save the final ans}, and started {to know that the integer has started}.
3. If i has reached string length, we return sign * ans.
4. If ans has not started yet and character is ' ', then we return the function recursively with i+1.
5. If ans has not started yet and character is + or - : If its -, we return the function with i+1, and sign = -1. If its +, we return the function with i+1, and sign = 1.
6. Now, after all these cases, if the character is not a digit, we return sign * ans.
7. If its a digit, we create an int digit which stores the digit value.
8. If after multiplying by 10 and adding the digit, ans is greater than INT_MAX, then : If sign = 1, return INT_MAX. If sign = -1, return INT_MIN.
9. Update ans = ans * 10 + digit.
10. Return the function recursively with i+1 and started = true.
11. Now, in our original function, we return our initial function with arguments : string = s, i = 0, sign = 1, ans = 0, started = false.
*/

//CODE:
class Solution {
public:
    int check(string& s, int i, int sign, long long ans, bool started) {
        if(i == s.length()) return sign * ans;

        if(!started && s[i] == ' ') return check(s, i+1, sign, ans, false);

        if(!started && (s[i] == '-' || s[i] == '+')) {
            if(s[i] == '-') {
                return check(s, i+1, -1, ans, true);
            }
            return check(s, i+1, 1, ans, true);
        }

        if(!isdigit(s[i])) return sign * ans;

        int digit = s[i] - '0';

        if(ans > (INT_MAX - digit)/10) {
            if(sign == 1) return INT_MAX;
            else return INT_MIN;
        }
        
        ans = ans * 10 + digit;

        return check(s, i+1, sign, ans, true);
    }

    int myAtoi(string s) {
        return check(s, 0, 1, 0, false);
    }
};

//Time Complexity : O(N) {Traversing through the string only once}
//Space Complexity : O(N) {Recursion stack}
