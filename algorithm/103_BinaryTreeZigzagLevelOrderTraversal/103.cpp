/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        std::queue<TreeNode*> nodeQ;
        if (!root) return ret;

        nodeQ.push(root);
        bool flip = false;
        while(!nodeQ.empty()) {
            vector<int> levelArr;
            int qlen = nodeQ.size();
            for(int i=0; i<qlen; i++) {
                TreeNode* node = nodeQ.front();
                nodeQ.pop();
                if (node) {
                    levelArr.push_back(node->val);
                    nodeQ.push(node->left);
                    nodeQ.push(node->right);
                }
            }

            if (flip) 
                std::reverse(levelArr.begin(), levelArr.end());

            ret.push_back(levelArr);
            flip = !flip;
        }

        return ret;
    }
};