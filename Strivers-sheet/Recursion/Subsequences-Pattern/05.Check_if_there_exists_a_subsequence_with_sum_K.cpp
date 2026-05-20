/*
QUESTION:-
Given an array nums and an integer k. R﻿eturn true if there exist subsequences such that the sum of all elements in subsequences is equal to k else false.

Example:

Input : nums = [1, 2, 3, 4, 5] , k = 8
Output : Yes
Explanation : The subsequences like [1, 2, 5] , [1, 3, 4] , [3, 5] sum up to 8.
*/

/*
APPROACH:
1. We create a new function count with arguments : vector nums, int k {target}, int i {to track the array}, int sum {to track the sum of the current array} and bool exist {to track if we've found any such sum}.
2. If exist is already true, return.
3. If we've found the sum as k, exist = true and return.
4. If i has reached size of nums, return.
5. We call the function recursively with i+1 {i.e. we did not take the current element}.
6. Update sum by adding the current element.
7. Recursively call the function with i+1 {i.e. we took the current element}.
8. Return.
9. Now, in the original function, we create bool exist as false, and then call the count function with arguments : nums, k, i = 0, sum = 0, exist.
10. Return exist.
*/

//CODE:
class Solution{
    public:
    void count(vector<int>& nums, int k, int i, int sum, bool &exist) {
        if(exist) return;

        if(sum == k) {
            exist = true;
            return;
        }

        if(i == nums.size()) {
            return;
        }

        count(nums, k, i+1, sum, exist);
        sum += nums[i];
        count(nums, k, i+1, sum, exist);
        return;
    }

    bool checkSubsequenceSum(vector<int>& nums, int k) {
        bool exist = false;
        count(nums, k, 0, 0, exist);
        return exist;
    }
};

//Time Complexity : O(2^N) {all possible subsets of the array}
//Space Complexity : O(N) {recursion stack}
