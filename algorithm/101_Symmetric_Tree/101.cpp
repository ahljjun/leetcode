/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.
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
 // 似乎比想象中的难
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return isSymmetric_1(root->left, root->right);
    }

    bool isSymmetric_1(TreeNode* left, TreeNode* right) {
        if (left && !right) return false;
        if (!left && right) return false;
        if (!left && !right) return true;

        return isSymmetric_1(left->left, right->right) && isSymmetric_1(left->right, right->left) && (left->val == right->val);
    }

    #include <queue>

    // the following seems work , but meet memory exceed limit 
    // when test data is large. since this is O(2^n)
    bool isSymmetric_iterative(TreeNode* root) {
        // use the level-order traversal , as I can  think of
        // convert the integer to string
        // 
        if (root == NULL) return true;
        if (!root->left && root->right) return false;
        if (root->left && !root->right) return false;

        // int : 完全二叉树时对应的位置
        std::queue<std::pair<int, TreeNode*>> nodeQ; 
        nodeQ.push(std::make_pair(1, root));
        int level = 0;
        std::vector<std::pair<int, TreeNode*>> levelVec;
        while(!nodeQ.empty()) {
            int start_pos = 1 << level;
            int end_pos = (1<<(level+1)) - 1;
            int qlen = nodeQ.size();
            for(int i=0; i < qlen; i++) {
                auto nodeInfo = nodeQ.front();
                nodeQ.pop();
                int pos = nodeInfo.first;
                TreeNode* node = nodeInfo.second;
                levelVec.push_back(std::move(nodeInfo));

                if (node->left) {
                    nodeQ.push(std::make_pair(2*pos, node->left));
                }
                if (node->right) {
                    nodeQ.push(std::make_pair(2*pos+1, node->right));
                }
            }

            if (!isSym(start_pos, end_pos, levelVec)) 
                return false;
            
            level++;
            levelVec.clear();
        }

        return true;
    }

    bool isSym(int start_pos, int end_pos, const vector<std::pair<int, TreeNode*>>& nodeVec) {
        if ((nodeVec.size()!=1) && (nodeVec.size() %2)) // got odd num of nodes except the root node level
            return false;
            
        for(int i=0, j = nodeVec.size()-1; i < j; ++i, --j) {
            auto iNode = nodeVec[i];
            auto jNode = nodeVec[j];
            //cout<< start_pos <<", "<<end_pos<<", "<<iNode.first<<", "<<jNode.first<<endl;
            if ( ((iNode.first - start_pos) != (end_pos - jNode.first)) || (iNode.second->val != jNode.second->val) )
                return false;
        }
        
        return  true;
    }

};

/*
     1
    2 3
  4 5 6 7 

  */