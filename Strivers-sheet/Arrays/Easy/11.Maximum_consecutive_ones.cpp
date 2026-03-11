/*
QUESTION:-
Given a binary array nums, return the maximum number of consecutive 1's in the array.

Example:

Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.
*/

/*
APPROACH:
1. We initiate two variables, count and maxcount.
2. Count will count the number of consecutive ones, and maxcount will keep track of the maximum that count has been to.
3. Traversing through the array, if element is 1, we update count by +1, else we backtrack count to 0.
4. maxcount is updated to the maximum of both count and the previous maxcount.
5. Return maxcount.
*/

//CODE:

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int maxcount = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1) {
                count++;
            }
            else {
                count = 0;
            }
            maxcount = max(count, maxcount);
        }
        return maxcount;
    }
};

//Time Complexity : O(N)
//Space Complexity : O(1)
