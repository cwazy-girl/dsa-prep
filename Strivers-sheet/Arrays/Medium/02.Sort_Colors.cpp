/*
QUESTION:-
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

Example:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
*/

/*
APPROACH:
1. We initiate three pointers, one at the beginning of the array, one at the end, and one that will traverse through the array and check elements.
2. While our traversing pointer is <= to the end pointer, we check if the element is 0, 1, or 2.
3. If it's 0, we swap the element with the [start] element, and then increase both start and i {i because we have already checked the previous part of the array, and hence the swapped element must be 1}.
4. If it's a 2, we swap the element with [end] element, and decrease end. {no i increment because we have yet not checked the end part of the array, which is swapped and is now in the position of i.}
5. If it's a 1, we simply increase i by 1.
*/

//CODE:
class Solution {
public:
    void sortZeroOneTwo(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        int i = 0;
        while(i <= end) {
            if(nums[i] == 0) {
                swap(nums[i], nums[start]);
                start++;
                i++;
            }
            else if(nums[i] == 2) {
                swap(nums[i], nums[end]);
                end--;
            }
            else {
                i++;
            }
        }
    }
};

//Time Complexity : O(N)
//Space Complexity : O(1)
