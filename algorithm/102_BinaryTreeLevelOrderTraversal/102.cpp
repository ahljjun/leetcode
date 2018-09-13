/*

Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        std::queue<TreeNode*> nodeQ1;
        std::queue<TreeNode*> nodeQ2;
        nodeQ1.push(root);
        do {
            vector<int> levelArr;
            while(!nodeQ1.empty()) {
                TreeNode* node = nodeQ1.front();
                nodeQ1.pop();
                if (node) {
                    levelArr.push_back(node->val);
                    nodeQ2.push(node->left);
                    nodeQ2.push(node->right);
                }
            }
            if (!levelArr.empty())
                ret.push_back(levelArr);
            std::swap(nodeQ1, nodeQ2);
        } while(!nodeQ1.empty());

        return ret;
    } 
};