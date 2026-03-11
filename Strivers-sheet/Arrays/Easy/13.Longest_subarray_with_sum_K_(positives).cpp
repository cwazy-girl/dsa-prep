/*
QUESTION:-
Given an positive array nums of size n and an integer k, find the length of the longest sub-array that sums to k. If no such sub-array exists, return 0.

Example:

Input: nums = [10, 5, 2, 7, 1, 9],  k=15
Output: 4
Explanation:
The longest sub-array with a sum equal to 15 is [5, 2, 7, 1], which has a length of 4. This sub-array starts at index 1 and ends at index 4, and the sum of its elements (5 + 2 + 7 + 1) equals 15. Therefore, the length of this sub-array is 4.
*/

/*
APPROACH:
1. We use the sliding window approach in the question and traverse the array via two variables, start and end.
2. We keep adding elements till its >= given sum.
3. If its greater, we subtract the element at the "start" position, and continue it till we get the sum equal to given sum.
4. If its equal, we compare it to the previous ans updation and end - start + 1 (the sliding window length).
5. We return the max value of the sliding window after traversing through the array.
*/

//CODE:
class Solution{
public:
    int longestSubarray(vector<int> &nums, int k){
        int start = 0;
        int sum = 0;
        int ans = 0;
        for(int end = 0; end < nums.size(); end++) {
            sum += nums[end];
            while(sum > k) {
                sum -= nums[start];
                start++;
            }
            if (sum == k) {
                ans = max(ans, end - start + 1);
            }
        }
        return ans;
    }
};

//Time Complexity : O(N)
//Space Complexity : O(1)
