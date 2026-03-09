/*
QUESTION:-
Given an integer array nums, move all the 0's to the end of the array. The relative order of the other elements must remain the same.

Example:

Input: nums = [0, 1, 4, 0, 5, 2]
Output: [1, 4, 5, 2, 0, 0]
Explanation:
Both the zeroes are moved to the end and the order of the other elements stay the same.
*/

/*
APPROACH:
1. We initialise a variable, which will only be updated when a non-zero value occurs.
2. Traversing through the array, if we get a non-zero element, we swap it with the element at j, and update it with +1.
*/

//CODE:
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0) {
                swap(nums[j], nums[i]);
                j++;
            }
        }
    }
};

//Time Complexity : O(N)
//Space Complexity : O(1)
