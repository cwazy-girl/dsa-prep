/*
QUESTION:-
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

Example:

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
*/

/*
APPROACH:
Basic level order traversal, with for loop for each level to push all nodes in one vector, and then pushing that vector to the ans vector.
*/

//CODE:
class Solution {
public:
    void leveltraversal(TreeNode* root, vector<vector<int>>& ans) {
        queue<TreeNode*> q;
        if(root == nullptr) return;

        q.push(root);

        while(!q.empty()) {
            vector<int> level;
            int size = q.size();

            for(int i = 0; i < size; i++) {
                TreeNode* temp = q.front();
                q.pop();

                level.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            ans.push_back(level);
        }
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        leveltraversal(root, ans);

        return ans;
    }
};

//Time Complexity : O(N)
//Space Complexity : O(N) {worst case is the queue holds all nodes at the last level}
