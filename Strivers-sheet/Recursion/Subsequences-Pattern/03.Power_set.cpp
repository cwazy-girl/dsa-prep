/*
QUESTION:-
Given an array of integers nums of unique elements. Return all possible subsets (power set) of the array.
Do not include the duplicates in the answer.

Example:

Input : nums = [1, 2, 3]
Output : [ [ ] , [1] , [2] , [1, 2] , [3] , [1, 3] , [2, 3] , [1, 2 ,3] ]
*/

/*
APPROACH:
1. We create a new function power with the arguments : nums, int i {to track the given array}, answer vector, subset vector.
2. If i has reached size of nums, we push subset in ans, and return.
3. Now, we first call the function recursively with i+1 {which denotes that we did not take that element of the array}.
4. Now, we push the element in subset, and call the function recursively with i+1 {which denotes that we took that element of the array}.
5. Return. {This function will create all kinds of subset of the given array.}
6. Now, in the original function, we create two vectors, ans and subset, and call our power function with arguments : nums, i = 0, ans, subset.
7. Return ans.
*/

//CODE:
class Solution {
public:	
    void power(vector<int> &nums, int i, vector<vector<int>> &ans, vector<int> subset) {
        if(i == nums.size()) {
            ans.push_back(subset);
            return;
        }

        power(nums, i+1, ans, subset);
        subset.push_back(nums[i]);
        power(nums, i+1, ans, subset);

        return;
    }
    
    vector<vector<int> > powerSet(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        power(nums, 0, ans, subset);
        return ans;
    }
};

//Time Complexity : O(N * 2^N) {2^N subsets with possibly N elements in all}
//Space Complexity : O(N) {recursion stack}
