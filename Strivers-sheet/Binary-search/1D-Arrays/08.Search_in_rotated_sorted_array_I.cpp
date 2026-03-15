/*
QUESTION:-
There is an integer array nums sorted in ascending order (with distinct values).
Prior to being passed to your function, nums is possibly left rotated at an unknown index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be left rotated by 3 indices and become [4,5,6,7,0,1,2].
Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

Example:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
*/

/*
APPROACH:
1. By using binary search, we find the pivot point, which is the smallest element in the rotated sorted array.
2. Now we check if our target is greater than the end element or smaller.
3. If it is smaller, we initiate start from pivot point. Else, we initiate end from pivot - 1 point.
4. Then we run the binary search accordingly.
*/

//CODE:
class Solution {
public:
    int search(vector<int>& nums, int target) {
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
        int pivot = end;
        if(target <= nums[nums.size() - 1]) {
            start = pivot;
            end = nums.size() - 1;
        }
        else {
            start = 0;
            end = pivot - 1;
        }
        while(start <= end) {
            int mid = start + (end - start)/2;
            if(nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] > target) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        return -1;
    }
};

//Time Complexity : O(N)
//Space Complexity : O(1)
