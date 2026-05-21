/*
QUESTION:-
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.
The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.
The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

Example:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
*/

/*
APPROACH:
1. We create a new function combination with arguments : vector arr, int target, int i {to track the array}, vector final {to save the current array}, vector ans {to save the list of appropriate arrays}.
2. If target has reached 0, we push final in ans, and return.
3. If i has reached arr size or target has become negative, that means that is not our required sum. So, return.
4. First, push the current element in final, and call the function recursively with target - arr[i] {since that is decreased from our target} and i {not i+1 because we can use the element multiple times}.
5. Now, pop the element, and call the function recursively with i+1 {since now, we are not using that element}.
6. Return.
7. Now, in the original function, we create an ans vector and final vector, and call our function combination with arguments : candidates, target, i = 0, final, ans.
8. Return ans.
*/

//CODE:
class Solution {
public:
    void combination(vector<int>& arr, int target, int i, vector<int> &final, vector<vector<int>>& ans) {
        if(target == 0) {
            ans.push_back(final);
            return;
        }

        if(i == arr.size() || target < 0) {
            return;
        }

        final.push_back(arr[i]);
        combination(arr, target - arr[i], i, final, ans);
        final.pop_back();
        combination(arr, target, i+1, final, ans);
        return;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> final;
        combination(candidates, target, 0, final, ans);

        return ans;
    }
};

//Time Complexity : O(N^target) {at each step, we may choose among N candidates}
//Space Complexity : O(target)
