/*
QUESTION:-
Given an integer array nums sorted in non-decreasing order, remove all duplicates in-place so that each unique element appears only once.
Return the number of unique elements in the array.
If the number of unique elements be k, then, change the array nums such that the first k elements of nums contain the unique values in the order that they were present originally.

Example:
Input: nums = [-2, 2, 4, 4, 4, 4, 5, 5]
Output: 4
Explanation:
Resulting array = [-2, 2, 4, 5, _, _, _, _]
There are 4 distinct elements in nums and the elements marked as _ can have any value.
*/

/*
APPROACH:
1. We initialise a pointer which points to the last unique element reached, while checking through the array.
2. We traverse through the array and check whether the current element is not equal to the last unique element.
3. If yes, we update the pointer to +1, and swap the element at the pointer and the current element.
4. We return j + 1, because pointer is initialised from 0.
*/

//CODE:
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 0;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] != nums[j]) {
                j++;
                swap(nums[i], nums[j]);
            }
        }
        return j + 1;
    }
};

//Time Complexity : O(N)
//Space Complexity : O(1)
