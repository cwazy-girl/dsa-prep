/*
QUESTION:-
Given an integer array nums of size n, sorted in ascending order with distinct values. The array has been right rotated an unknown number of times, between 0 and n-1 (including). Determine the number of rotations performed on the array.

Example:

Input : nums = [4, 5, 6, 7, 0, 1, 2, 3]
Output: 4
Explanation: The original array should be [0, 1, 2, 3, 4, 5, 6, 7]. So, we can notice that the array has been rotated 4 times.
*/

/*
APPROACH:
1. We use binary search to check if the mid element is greater than the end element. If yes, then we check the right part of the array to find the pivot point.
2. If no, we check the left part of the array from the mid point to find the pivot point.
3. end will return the pivot point, and hence the number of times array is rotated.
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
        return end;
    }
};

//Time Complexity : O(logN)
//Space Complexity : O(1)
