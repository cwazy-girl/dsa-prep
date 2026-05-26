/*
QUESTION:-
Given a binary tree with root node. Return the In-order,Pre-order and Post-order traversal of the binary tree.

Example:

Input : root = [1, 3, 4, 5, 2, 7, 6 ]
Output : [ [5, 3, 2, 1, 7, 4, 6] , [1, 3, 5, 2, 4, 7, 6] , [5, 2, 3, 7, 6, 4, 1] ]
Explanation : The In-order traversal is [5, 3, 2, 1, 7, 4, 6].
The Pre-order traversal is [1, 3, 5, 2, 4, 7, 6].
The Post-order traversal is [5, 2, 3, 7, 6, 4, 1].
*/

/*
APPROACH:
Basic preorder, inorder and postorder traversals
*/

//CODE:
class Solution{
	public:
		void preinpost(TreeNode* root, vector<int>& pre, vector<int>& ino, vector<int>& post) {

            if(root == nullptr) return;

            pre.push_back(root->data);
            preinpost(root->left, pre, ino, post);
            ino.push_back(root->data);
            preinpost(root->right, pre, ino, post);
            post.push_back(root->data);
        }
        
        vector<vector<int>> treeTraversal(TreeNode* root){
            vector<vector<int>> ans;
            vector<int> pre, ino, post;

            preinpost(root, pre, ino, post);

            ans.push_back(ino);
            ans.push_back(pre);
            ans.push_back(post);

            return ans;
		}
};

//Time Complexity : O(N)
//Space Complexity : O(N)
