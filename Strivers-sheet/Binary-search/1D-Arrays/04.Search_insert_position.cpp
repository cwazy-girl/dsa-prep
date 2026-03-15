/*
QUESTION:-
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

Example:

Input: nums = [1,3,5,6], target = 2
Output: 1
*/

/*
APPROACH:
1. Using binary search, we check if the mid element is target. If yes, we return mid.
2. If mid is greater than target, we check the left part of the array. Else, we check the right part of the array.
3. If mid is yet not returned, that means the target does not exist in the array.
4. In that case, start contains the index of the element just greater than the target.
5. Return start.
*/

//CODE:
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        while(start <= end) {
            int mid = start + (end - start)/2;
            if(nums[mid] == target) {
                return mid;
            }
            else if(nums[mid] > target) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        return start;
    }
};

//Time Complexity : O(logN)
//Space Complexity : O(1)
