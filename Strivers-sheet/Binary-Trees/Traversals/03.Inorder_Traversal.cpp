/*
QUESTION:-
Given the root of a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: root = [1,null,2,3]
Output: [1,3,2]
*/

/*
APPROACH:
Basic inorder traversal
*/

//CODE:
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& in) {
        if(root == nullptr) return;

        inorder(root->left, in);
        in.push_back(root->val);
        inorder(root->right, in);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> in;
        inorder(root, in);

        return in;
    }
};

//Time Complexity : O(N)
//Space Complexity : O(h) {recursion stack depends on tree height}
