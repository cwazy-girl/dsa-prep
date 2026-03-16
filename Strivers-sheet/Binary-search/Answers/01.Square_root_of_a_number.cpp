/*
QUESTION:-
Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

Example:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
*/

/*
APPROACH:
1. Using binary search from 0 to the given integer, we check if mid multiplied by itself is equal to the given integer.
2. If yes, return mid.
3. If no, if the product is lesser, we save mid in a variable (because we need to find floor of sqrt(x)) and check the right side of the array.
4. Else, we check the left side of the array.
5. Return ans.
*/

//CODE:
class Solution {
public:
    int mySqrt(int x) {
        long long start = 0;
        long long end = x;
        long long ans = 0;

        while(start <= end) {
            long long mid = start + (end - start) / 2;

            if(mid * mid == x) {
                return mid;
            }
            else if(mid * mid < x) {
                ans = mid;
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return ans;
    }
};

//Time Complexity : O(logN)
//Space Complexity : O(1)
