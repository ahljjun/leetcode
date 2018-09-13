/*

Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
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
    //recursive version
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        inorderTraversal_recursive(root, ret);
        return ret;
    }

    void inorderTraversal_recursive(TreeNode* root, vector<int>& ret) {
        if (!root) return;

        std::stack<std::pair<TreeNode*, bool>> nodeStk;
        nodeStk.push(std::make_pair(root,false));

        while(!nodeStk.empty()) {
            auto nodePair = nodeStk.top();
            nodeStk.pop();
            TreeNode* node = nodePair.first;
            bool visited = nodePair.second;

            if (!visited) {
                //first meet, continue traverse
                if (node->right) 
                    nodeStk.push(std::make_pair(node->right, false));
                nodeStk.push(std::make_pair<node, true>);

                if (node->left) 
                    nodeStk.push(std::make_pair(node->left, false));
            } else {
                // this goes when traverse back, just print its value
                ret.push_back(node->val);
            }
        }
    }

};