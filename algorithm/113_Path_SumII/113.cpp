/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:

[
   [5,4,11,2],
   [5,8,4,5]
]

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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        // use DFS
        vector<vector<int>> ret;
        vector<int> pathValues;
        if (!root) return ret;
        pathValues.push_back(root->val);
        pathSum_helper(root, sum, root->val, pathValues, ret);
        
        return ret;
    }

    //DFS
    void pathSum_helper(TreeNode* root, int sum, int result, vector<int> pathValues, vector<vector<int>>&ret) {
        if (!root) {
            return;
        }

        if (!root->left && !root->right) {
            if(result == sum) {
                ret.push_back(pathValues);
            } // no need to add root->val again since parameter has already added it. note note note!
        } 

        if (root->left) {
            pathValues.push_back(root->left->val);
            pathSum_helper(root->left, sum, result+ root->left->val, pathValues, ret);
            pathValues.pop_back();
        }
        if (root->right) {
            pathValues.push_back(root->right->val);
            pathSum_helper(root->right, sum, result+ root->right->val, pathValues, ret);
            pathValues.pop_back();        
        }
    }  
};