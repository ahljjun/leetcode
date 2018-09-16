/*
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        //for post-order , the root-node is at last
        // then divide those nodes to left subtree and right subtree,
        // we can recursively rebuild the tree
        //dumpSubtree(inorder);
        //dumpSubtree(postorder);
        int size = postorder.size();
        assert(inorder.size() == size);
        if (size == 0) {
            return NULL;
        }
        
        assert(size > 0);
        int rootVal = postorder[size-1];
        TreeNode* rootNode = new TreeNode(rootVal);
        if (size == 1) {
            return rootNode;
        }

        // according the root value , split into left subtree and right subtree
        vector<int> left_inorder;
        vector<int> right_inorder;
        int i;
        for(i=0; i<size; i++) {
            if (inorder[i] == rootVal) {
                break;
            }
            left_inorder.push_back(inorder[i]);
        }

        for(i=i+1;i<size; i++) {
            right_inorder.push_back(inorder[i]);
        }

        // get subtree's post order
        vector<int> left_postorder;
        vector<int> right_postorder;
        for(i=0;i<left_inorder.size(); i++) {
            left_postorder.push_back(postorder[i]);
        }

        for(;i<size-1; i++) {
            right_postorder.push_back(postorder[i]);
        }

        TreeNode* leftChild = buildTree(left_inorder, left_postorder);
        TreeNode* rightChild = buildTree(right_inorder, right_postorder);

        rootNode->left = leftChild;
        rootNode->right = rightChild;

        return rootNode;
    }
    
private:
    void dumpSubtree(vector<int> vec) {
        std::cout<<"[";
        std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, ","));
        std::cout<<"]\n";
    }
};