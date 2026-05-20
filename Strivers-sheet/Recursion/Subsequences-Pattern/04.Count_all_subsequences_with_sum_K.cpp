/*
QUESTION:-
Given an array nums and an integer k.Return the number of non-empty subsequences of nums such that the sum of all elements in the subsequence is equal to k.

Example:

Input : nums = [4, 9, 2, 5, 1] , k = 10
Output : 2
Explanation : The possible subsets with sum k are [9, 1] , [4, 5, 1].
*/

/*
APPROACH:
1. We create a new function count with arguments : vector nums, int k {target}, int i {to track elements of array}, int sum {to track the sum of present array}, int number {to track number of arrays with the given sum}.
2. If i has reached size of nums, if sum is k, do number++. Return.
3. We call the function recursively with i+1 {which indicates not taking the present element of the array}.
4. Now, we increament sum with nums[i]. And call the function recursively with i+1 {which indicates taking the present element of the array}.
5. Return.
6. In the original function, we create variable number and initialise it with 0.
7. We call the function count with arguments : nums, k, i = 0, sum = 0, number.
8. Return number.
*/

//CODE:
class Solution{
    public:
    void count(vector<int>& nums, int k, int i, int sum, int &number) {
        if(i == nums.size()) {
            if(sum == k) {
                number++;
            }
            return;
        }

        count(nums, k, i+1, sum, number);
        sum += nums[i];
        count(nums, k, i+1, sum, number);

        return;
    }

    int countSubsequenceWithTargetSum(vector<int>& nums, int k){
        int number = 0;
        count(nums, k, 0, 0, number);
        return number;
    }
};

//Time Complexity : O(2^N) {2^N subsequences of array}
//Space Complexity : O(N) {recursion stack}
