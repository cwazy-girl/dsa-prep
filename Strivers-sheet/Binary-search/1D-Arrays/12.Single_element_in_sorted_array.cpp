/*
QUESTION:-
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.
Return the single element that appears only once.

Example:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
*/

/*
APPROACH:
1. Using binary search, we check if the mid is odd. If it is, we decrease it by 1, because every duplicate term must start from an even index.
2. Now, if the next element is equal to the mid element, that means the array is having only duplicates till now. So, we check the right part of the array.
3. If it is not equal, that means it might be equal to the past term or might be the single term. Hence, we check the left part of the array, including mid.
4. We return [end], because that contains the single element.
*/

//CODE:
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;

        while(start < end) {
            int mid = start + (end - start)/2;
            
            if(mid % 2 == 1) {
                mid--;
            }

            if(nums[mid] == nums[mid + 1]) {
                start = mid + 2;
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
