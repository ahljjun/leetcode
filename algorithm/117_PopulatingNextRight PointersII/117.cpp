/*
Given a binary tree

struct TreeLinkNode {
  TreeLinkNode *left;
  TreeLinkNode *right;
  TreeLinkNode *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
Recursive approach is fine, implicit stack space does not count as extra space for this problem.
Example:

Given the following binary tree,

     1
   /  \
  2    3
 / \    \
4   5    7
After calling your function, the tree should look like:

     1 -> NULL
   /  \
  2 -> 3 -> NULL
 / \    \
4-> 5 -> 7 -> NULL
*/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

// The following is the wrong solution. 
// it will skip lots of nodes since next pointer to wrong (more distance) node
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root==NULL) return;

        std::queue<TreeLinkNode*> nodeQ;
        for(auto node=root; node != NULL; node = node->next) {
            if (node->left) 
                nodeQ.push(node->left);
            if (node->right) 
                nodeQ.push(node->right);  
        }

        TreeLinkNode* prev = NULL;
        TreeLinkNode* next = NULL;
        while(!nodeQ.empty()) {
            auto node = nodeQ.front();
            nodeQ.pop();
            if (prev == NULL) {
                prev = node;
            } else {
                prev->next = node;
                prev = node;
            }
        }
    connect(root->left);
    connect(root->right);
};

// The previous code performance is poor
// see following
// https://leetcode.com/explore/learn/card/data-structure-tree/133/conclusion/1016/discuss/156319/Simple-Recursive-Cpp-solution-(13ms)
// treat it like recursive linked list at hierachle levels.

