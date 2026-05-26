/*
QUESTION:-
Given the root of a binary tree, return the postorder traversal of its nodes' values.

Example:

Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]
Output: [4,6,7,5,2,9,8,3,1]
*/

/*
APPROACH:
Basic postorder traversal
*/

//CODE:
class Solution {
public:
    void postorder(TreeNode* root, vector<int>& post) {
        if(root == nullptr) return;

        postorder(root->left, post);
        postorder(root->right, post);
        post.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> post;
        postorder(root, post);

        return post;
    }
};

//Time Complexity : O(N)
//Space Complexity : O(h) {recursion stack depends on tree height}
