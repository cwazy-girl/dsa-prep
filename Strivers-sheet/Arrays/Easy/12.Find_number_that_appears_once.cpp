/*
QUESTION:-
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

Example:

Input: nums = [2,2,1]
Output: 1
*/

/*
APPROACH:
Since every element appears twice, xor-ing all elements would result into only the single element remaining.
*/

//CODE:
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            ans = ans^nums[i];
        }
        return ans;
    }
};

//Time Complexity : O(N)
//Space Complexity : O(1)
