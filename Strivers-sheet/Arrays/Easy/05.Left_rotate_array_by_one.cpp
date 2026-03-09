/*
QUESTION:-
Given an integer array nums, rotate the array to the left by one.

Example:

Input: nums = [1, 2, 3, 4, 5]
Output: [2, 3, 4, 5, 1]
Explanation:
Initially, nums = [1, 2, 3, 4, 5]
Rotating once to left -> nums = [2, 3, 4, 5, 1]
*/

/*
APPROACH:
1. Store the first element of the array in a temperory variable.
2. Traverse the array till second-last element and update every element of the array with the next element.
3. Update the last element with the value stored in the temperory variable.
*/

//CODE:
class Solution {
public:
    void rotateArrayByOne(vector<int>& nums) {
        int temp = nums[0];
        for(int i = 0; i < nums.size(); i++) {
            nums[i] = nums[i + 1];
        }
        nums[nums.size() - 1] = temp;
    }
};

//Time Complexity : O(N)
//Space Complexity : O(1)
