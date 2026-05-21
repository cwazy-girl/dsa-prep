/*
QUESTION:-
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
Each number in candidates may only be used once in the combination.
Note: The solution set must not contain duplicate combinations.

Example:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
*/

/*
APPROACH:
1. We create a helper function combination2 with arguments : vector arr (sorted), int target, int i {to track the array}, vector final, vector ans.
2. If target has reached 0, we push final into ans and return.
3. In the for loop starting from j = i to size of array {this is to avoid duplicates at same level of recursion}, we check if j > i and element at that index is equal to the element at the previous index, continue.
4. If arr[j] is greater than target, that means all the elements ahead will also be greater than target. So, break.
5. We push the current element in final, and call the function recursively with target - arr[j] and j+1 {since we cannot repeat the same element}.
6. Then, we pop the element. {We do not call the function again because the loop already handles not taking elements.}
7. In the original function, we first sort our array "candidates", and create two vectors : final and ans.
8. We call our helper function combination2 with arguments : candidates, target, i = 0, final, ans.
9. Return ans.
*/

//CODE:
class Solution {
public:
    void combination2(vector<int>& arr, int target, int i, vector<int>& final, vector<vector<int>>& ans) {
        if(target == 0) {
            ans.push_back(final);
            return;
        }

        for(int j = i; j < arr.size(); j++) {
            if(j > i && arr[j-1] == arr[j]) continue;

            if(arr[j] > target) break;

            final.push_back(arr[j]);
            combination2(arr, target - arr[j], j+1, final, ans);
            final.pop_back();
        }
        return;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> final;
        combination2(candidates, target, 0, final, ans);
        
        return ans;
    }
};

//Time Complexity : O(2^N) {for each element, we can either take it or not take it}
//Space Complexity : O(N) {recursion stack}
