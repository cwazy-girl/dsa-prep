/*
QUESTION:-
Given an array of integers nums, return the value of the largest element in the array

Example:

Input: nums = [3, 3, 6, 1]
Output: 6
Explanation: The largest element in array is 6.
*/

/*
APPROACH:
1. Initialise "ans" with the first element of the array.
2. Traverse the entire array and update "ans" if any element is greater than ans.
3. Return ans.
*/

class Solution {
public:
    int largestElement(vector<int>& nums) {
        int ans = nums[0];
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > ans) {
                ans = nums[i];
            }
        }
        return ans;
    }
};

//Time Complexity = O(N)
//Space Complexity = O(1)
