/*
QUESTION:-
Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

Example:

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4.
*/

/*
1. We use simple binary search in the question.
2. We take the mid element and check if its the target.
3. If yes, we return mid, else, we check if the target is greater than or less than the mid element.
4. If greater, we check on the right part of the array. Else, we check on the left part of the array.
*/

//CODE:
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
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

//Time Complexity : O(logN)
//Space Complexity : O(1)
