/*
QUESTION:-
Given an array nums of n integers, return true if the array nums is sorted in non-decreasing order or else false.

Example:

Input : nums = [1, 2, 3, 4, 5]
Output : true
Explanation : For all i (1 <= i <= 4) it holds nums[i] <= nums[i+1], hence it is sorted and we return true.
*/

/*
APPROACH:
1. Traverse the array and check if there's any element which is greater than the next element.
2. If so, return false. Else, return true.
*/

class Solution{	
	public:
		bool isSorted(vector<int>& nums){
            for(int i = 0; i < nums.size() - 1; i++) {
                if(nums[i] > nums[i + 1]) {
                    return false;
                }
            }
            return true;
		}
};

//Time Complexity : O(N)
//Space Complexity : O(1)
