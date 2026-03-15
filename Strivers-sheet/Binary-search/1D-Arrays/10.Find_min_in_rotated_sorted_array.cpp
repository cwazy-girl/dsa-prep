/*
QUESTION:-
Given the sorted rotated array nums of unique elements, return the minimum element of this array.

Example:

Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.
*/

/*
APPROACH:
1. We use binary search to check if the mid element is greater than the end element. If yes, then we check the right part of the array to find the pivot point.
2. If no, we check the left part of the array from the mid point to find the pivot point.
3. [end] will return the pivot point.
*/

//CODE:
class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        while(start < end) {
            int mid = start + (end - start)/2;
            if(nums[mid] > nums[end]) {
                start = mid + 1;
            }
            else {
                end = mid;
            }
        }
        return nums[end];
    }
};

//Time Complexity : O(logN)
//Space Complexity : O(1)
