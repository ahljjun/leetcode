/*
Given a binary tree, return the postorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [3,2,1]
Follow up: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        postorderTraversal_iterative(root, ret);

        return ret;
    }

    void postorderTraversal_iterative(TreeNode* root, vector<int> &ret) {
        if (!root) return;

        std::stack<std::pair<TreeNode*, bool>> nodeStk;
        nodeStk.push(std::make_pair(root, false));

        while(!nodeStk.empty()) {
            auto nodeInfo = nodeStk.top();
            TreeNode* node = nodeInfo.first;
            bool visited = nodeInfo.second;
            nodeStk.pop();

            if (!visited) {
                // push the node itself first
                nodeStk.push(std::make_pair(node, true));

                if (node->right) 
                    nodeStk.push(std::make_pair(node->right, false));

                if (node->left) 
                    nodeStk.push(std::make_pair(node->left, false));

            } else {
                ret.push_back(node->val);
            }
        }
    }
};
