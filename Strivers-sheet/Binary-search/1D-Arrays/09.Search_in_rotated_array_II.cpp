/*
QUESTION:-
There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).
Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.
You must decrease the overall operation steps as much as possible.

Example:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
*/

/*
APPROACH:
1. Through binary search, we check if mid element is target. If yes, we return true.
2. If no, we check if the start, mid and end element are all the same. If yes, that would create confusion in choosing the sorted part of the array. So we decrease the range by start++ and end--.
3. If the first element is lesser than mid element, that means the left part of the array is sorted.
4. If so, we check if target lies between start and mid. If yes, we check the left part of the array. If no, we check the right part of the array.
5. If not, then the right part of the array is sorted. We check if target is between mid and end. If yes, we check the right part of the array, else, the left part.
6. If the loop runs and nothing is returned, that means element does not exist. So, we return false.
*/

//CODE:
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;

        while(start <= end) {
            int mid = start + (end - start)/2;

            if(nums[mid] == target)
                return true;

            if(nums[start] == nums[mid] && nums[mid] == nums[end]) {
                start++;
                end--;
            }

            else if(nums[start] <= nums[mid]) {
                if(nums[start] <= target && target < nums[mid])
                    end = mid - 1;
                else
                    start = mid + 1;
            }

            else {
                if(nums[mid] < target && target <= nums[end])
                    start = mid + 1;
                else
                    end = mid - 1;
            }
        }

        return false;
    }
};

//Time Complexity : O(logN)
//Space Complexity : O(1)
