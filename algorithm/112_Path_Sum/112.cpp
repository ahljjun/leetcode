/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        // use pre-order traversal
        if (!root) return false;
        return hasPathSum_helper(root, root->val, sum);
    }

    bool hasPathSum_helper(TreeNode* root, int result, int sum) {
        if (!root) {
            return false;
        }

        if (!root->left && !root->right) {
            return result == sum; // no need to add root->val again since parameter has already added it. note note note!
        } 
        
        bool left_has = false;
        bool right_has = false;
        if (root->left)
            left_has = hasPathSum_helper(root->left, result+ root->left->val, sum);
        if (root->right)
            right_has = hasPathSum_helper(root->right, result+root->right->val, sum);  //

        return left_has || right_has ;
    }     
};