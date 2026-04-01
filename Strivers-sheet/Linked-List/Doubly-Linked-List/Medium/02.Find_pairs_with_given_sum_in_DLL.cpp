/*
QUESTION:-
Given the head of a sorted doubly linked list of positive distinct integers, and a target integer, return a 2D array containing all unique pairs of nodes (a, b) such that a + b == target.
Each pair should be returned as a 2-element array [a, b] with a < b. The list is sorted in ascending order. If there are no such pairs, return an empty list.
1. 0 <= number of nodes <= 105
2. The linked list contains distinct values.

Example:

Input: head = [1, 2, 4, 5, 6, 8, 9], target = 7
Output: [[1, 6], [2, 5]]
Explanation: 1 + 6 = 7 and 2 + 5 = 7 are the valid pairs.
*/

/*
APPROACH:
1. We create an array to save our answer arrays. If our linked list is NULL, or has only one node, we return {}.
2. We intiate two listnodes, start and end. We initialise start from head, and move end to the last node.
3. While start does not become equal to or just next of end, we initialise sum as the sum of values in start and end.
4. If sum > target, that means we need a lower integer. So, we move end to end->prev.
5. If sum < target, that means we need a higher integer. So, we move start to start->next.
6. Else, we push {start->val, end->val} to our ans array, and move both start and end to next and prev respectively.
7. Return ans.
*/

//CODE:
class Solution {
public:
    vector<vector<int>> findPairsWithGivenSum(ListNode* head, int target) {
        vector<vector<int>> ans;

        if(!head || !head->next) return {};

        ListNode* start = head;
        ListNode* end = head;
        while(end->next != NULL) {
            end = end->next;
        }

        while(start != end && start->prev != end) {
            int sum = start->val + end->val;

            if(sum > target) {
                end = end->prev;
            }
            else if(sum < target){
                start = start->next;
            }
            else {
                ans.push_back({start->val, end->val});
                start = start->next;
                end = end->prev;
            }
        }
        return ans;
    }
};

//Time Complexity : O(N)
//Space Complexity : O(1)
