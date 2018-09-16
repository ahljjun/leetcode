/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its depth = 3.
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
    int maxDepth(TreeNode* root) {
        /*
        if (root==NULL) return 0; 
        m_depth = 1;
        int depth = 1;
        maxDepth_top_down(root, depth);

        return m_depth;
        */
        //return maxDepth_bottom_up(root);
        return maxDepth_iterative(root);
    }
    
    void maxDepth_top_down(TreeNode* root, int depth) {
        if (root == NULL) return;

        // Pre-Traversal
        if (!root->left && !root->right) { 
            // this is the leaf node
            m_depth = std::max(m_depth, depth);// the depth is already added in the recursive parameter
            return;
        }
        
        maxDepth_top_down(root->left, depth+1);
        maxDepth_top_down(root->right, depth+1); 
    }
    
    int maxDepth_bottom_up(TreeNode* root) {
        if (root==NULL) return 0;
        if (!root->left && !root->right) return 1;
        
        int left_depth  = maxDepth_bottom_up(root->left);
        int right_depth = maxDepth_bottom_up(root->right);
        return 1+std::max(left_depth, right_depth); // POST-Travseral 
    }
    
    int maxDepth_iterative(TreeNode* root) {
        if (root==NULL) return 0;
        std::stack<std::pair<TreeNode*, int>> nodeStk;
        nodeStk.push(std::make_pair(root, 1));
        int max_depth = 1;
        while(!nodeStk.empty()) {
            auto nodeInfo = nodeStk.top();
            nodeStk.pop();
            TreeNode* node = nodeInfo.first;
            int node_depth = nodeInfo.second;
            //max_depth = std::max(max_depth, node_depth);
            if (node_depth > max_depth) 
                max_depth = node_depth;

            if (node->right) {
                nodeStk.push(std::make_pair(node->right, node_depth+1));
            }
            if (node->left) {
                nodeStk.push(std::make_pair(node->left, node_depth+1));
            }
        }
        
        return max_depth;
    }
    
private:
    int m_depth;
};