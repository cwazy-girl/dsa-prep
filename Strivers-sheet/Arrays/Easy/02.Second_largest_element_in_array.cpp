/*
QUESTION:-
Given an array of integers nums, return the second-largest element in the array. If the second-largest element does not exist, return -1.

Example:

Input: nums = [8, 8, 7, 6, 5]
Output: 7
Explanation: The largest value in nums is 8, the second largest is 7.
*/

/*
APPROACH:
1. Initialise "temp" and "ans" as nums[0] and -1 respectively.
2. "temp" stores the largest element in the array and "ans" stores the second-largest element in the array.
3. Traversing through the array, if current element is greater than "temp", we update "ans" with the previous value of "temp" and update "temp" with the current element.
4. If current element is less than "temp", but greater than the already assigned value of "ans", we update "ans" with the current element.
5. Return ans.
*/

class Solution {
public:
    int secondLargestElement(vector<int>& nums) {
        int temp = nums[0];
        int ans = -1;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > temp) {
                ans = temp;
                temp = nums[i];
            }
            else if (nums[i] > ans && nums[i] != temp) {
                ans = nums[i];
            }
        }
        return ans;
    }
};

//Time Complexity : O(N)
//Space Complexity : O(1)
