/*
QUESTION:-
Given an integer array nums, find the subarray with the largest sum, and return its sum.

Example:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
*/

//BRUTE-FORCE CODE

/*
APPROACH:
1. Traversing through the array, from each element, we move ahead and keep adding elements and keep taking max of the maxsum and the current sum.
2. Return maxsum.
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for(int j = i; j < nums.size(); j++) {
                sum += nums[j];
                maxi = max(sum, maxi);
            }
        }
        return maxi;
    }
};

//Time Complexity : O(N^2)
//Space Complexity : O(1)

//OPTIMAL CODE

/*
APPROACH:
1. We traverse through the array, and keep adding every element to sum, and we keep taking max of the maxsum and the current sum.
2. If we reach a point where sum becomes negative, it will only decrease the further sums.
3. Hence, we initiate sum again from 0.
4. Return maxsum.
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxsum = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            maxsum = max(sum, maxsum);

            if(sum < 0) {
                sum = 0;
            }
        }
        return maxsum;
    }
};

//Time Complexity : O(N)
//Space Complexity : O(1)
