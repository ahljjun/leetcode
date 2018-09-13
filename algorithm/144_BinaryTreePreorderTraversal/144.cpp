/*
Given a binary tree, return the preorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,2,3]
Follow up: Recursive solution is trivial, could you do it iteratively?
*/

class Solution {
public:
    // Recursive 
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        preorder_traverse_recursive(TreeNode* root, ret);
    }
    
    void preorder_traverse_recursive(TreeNode* root, vector<int>& ret) {
        if (!root)
            return;
        ret.push_back(root->val);
        preorder_traverse_recursive(root->left, ret);
        preorder_traverse_recursive(root->right, ret);
    }

    void preorder_traverse_iterative(TreeNode* root, vector<int>& ret) {
        if(root==NULL) return ;

        std::stack<TreeNode*> nodeStk;
        nodeStk.push(root);

        while(!nodeStk.empty()) {
            TreeNode* node = nodeStk.front();
            nodeStk.pop();
            ret.push_back(node->val);

            if(node->right)
                nodeStk.push(node->right);
            if(node->left)
                nodeStk.push(node->left);
        }
    }
};