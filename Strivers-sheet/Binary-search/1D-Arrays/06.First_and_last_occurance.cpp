/*
QUESTION:-
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].

Example:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
*/

/*
APPROACH:
Apply binary search separately for first and last occurance.
*/

//CODE:
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1;
        int last = -1;
        int start = 0;
        int end = nums.size() - 1;
        
        while(start <= end) {
            int mid = start + (end-start)/2;
            if(nums[mid] > target) {
                end = mid - 1;
            }
            else if (nums[mid] < target) {
                start = mid + 1;
            }
            else {
                first = mid;
                end = mid - 1;
            }
        }
        start = 0;
        end = nums.size() - 1;
        while(start <= end) {
            int mid = start + (end-start)/2;
            if(nums[mid] > target) {
                end = mid - 1;
            }
            else if (nums[mid] < target) {
                start = mid + 1;
            }
            else {
                last = mid;
                start = mid + 1;
            }
        }
        return {first, last};
    }
};

//Time Complexity : O(logN)
//Space Complexity : O(1)
