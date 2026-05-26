/*
QUESTION:-
Given the root of a binary tree, return the preorder traversal of its nodes' values.

Example:

Input: root = [1,null,2,3]
Output: [1,2,3]
*/

/*
APPROACH:
Basic preorder traversal
*/

//CODE:
class Solution {
public:
    void preorder(TreeNode* root, vector<int>& ans) {
        if(root == nullptr) return;

        ans.push_back(root->val);
        preorder(root->left, ans);
        preorder(root->right, ans);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }
};

//Time Complexity : O(N)
//Space Complexity : O(h) {recursion stack depends on tree height}
