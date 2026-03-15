/*
QUESTION:-
A peak element is an element that is strictly greater than its neighbors.
Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.
You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

Example:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
*/

/*
APPROACH:
1. Using binary search, we check if the mid element is lesser than the next element. If yes, we check the right part of the array.
2. If no, we check the left part of the array, including mid (since that might be the peak element).
3. Return end.
*/

//CODE:
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        while(start < end) {
            int mid = start + (end - start)/2;
            if(nums[mid] < nums[mid+1]) {
                start = mid+1;
            }
            else {
                end = mid;
            }
        }
        return end;
    }
};

//Time Complexity : O(logN)
//Space Complexity : O(1)
