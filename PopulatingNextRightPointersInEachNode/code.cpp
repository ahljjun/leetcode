/*
 * https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
 *
 *
 *
 */

/*
 *Definition for binary tree with next pointer.
 *struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 *
 */
class Solution {
    public:
        void connect(TreeLinkNode *root) {
            if ( !root )
                return;

            for(TreeLinkNode *pNode = root->left;pNode != NULL; pNode=pNode->next){
                TreeLinkNOde *curLevelNOde = pNode;
                while(curLevelNode){
                    curLevelNode->left->right = curLevelNode->right;
                    if(curLevelNode->next)
                        curLevelNode->right->next = curLevelNode->next->right;

                    curLevelNode = curLevelNode->next;
                }
            }
        }

};
 *   }
