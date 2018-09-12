/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Given the following binary tree:  root = [3,5,1,6,2,0,8,null,null,7,4]
        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
         7   4

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of of nodes 5 and 1 is 3.


Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself
             according to the LCA definition.

Note:

All of the nodes' vals will be unique.
p and q are different and both vals will exist in the binary tree.


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

#include <iostream>
#include <stack>
#include <map>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    //TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class btree{
public:
    btree();
    ~btree();

    void insert(int key);
    TreeNode *search(int key);
    void destroy_tree();
    void inorder_print();
    void postorder_print();
    void preorder_print();
    void traverseList(TreeNode* root, TreeNode* p, stack<TreeNode*>&stk, bool &found);
    TreeNode* getRoot() {return root;}
    TreeNode* lowestCommonAncestor(TreeNode* p, TreeNode* q);
private:
    void destroy_tree(TreeNode *leaf);
    void insert(int key, TreeNode *leaf);
    TreeNode *search(int key, TreeNode *leaf);
    void inorder_print(TreeNode *leaf);
    void postorder_print(TreeNode *leaf);
    void preorder_print(TreeNode *leaf);

    TreeNode *root;
};


btree::btree(){
    root = NULL;
}

btree::~btree(){
    destroy_tree();
}

void btree::destroy_tree(TreeNode *leaf){
    if(leaf != NULL){
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
        delete leaf;
    }
}

void btree::insert(int key, TreeNode *leaf){

    if(key < leaf->val){
        if(leaf->left != NULL){
            insert(key, leaf->left);
        }else{
            leaf->left = new TreeNode;
            leaf->left->val = key;
            leaf->left->left = NULL;
            leaf->left->right = NULL;
        }
    }else if(key >= leaf->val){
        if(leaf->right != NULL){
            insert(key, leaf->right);
        }else{
            leaf->right = new TreeNode;
            leaf->right->val = key;
            leaf->right->right = NULL;
            leaf->right->left = NULL;
        }
    }

}

void btree::insert(int key){
    if(root != NULL){
        insert(key, root);
    }else{
        root = new TreeNode;
        root->val = key;
        root->left = NULL;
        root->right = NULL;
    }
}

TreeNode *btree::search(int key, TreeNode *leaf){
    if(leaf != NULL){
        if(key == leaf->val){
            return leaf;
        }
        if(key < leaf->val){
            return search(key, leaf->left);
        }else{
            return search(key, leaf->right);
        }
    }else{
        return NULL;
    }
}

TreeNode *btree::search(int key){
    return search(key, root);
}

void btree::destroy_tree(){
    destroy_tree(root);
}

void btree::inorder_print(){
    inorder_print(root);
    cout << "\n";
}

void btree::inorder_print(TreeNode *leaf){
    if(leaf != NULL){
        inorder_print(leaf->left);
        cout << leaf->val << ",";
        inorder_print(leaf->right);
    }
}

void btree::postorder_print(){
    postorder_print(root);
    cout << "\n";
}

void btree::postorder_print(TreeNode *leaf){
    if(leaf != NULL){
        postorder_print(leaf->left);
        postorder_print(leaf->right);
        cout << leaf->val << ",";
    }
}

void btree::preorder_print(){
    preorder_print(root);
    cout << "\n";
}

void btree::preorder_print(TreeNode *leaf){
    if(leaf != NULL){
        cout << leaf->val << ",";
        preorder_print(leaf->left);
        preorder_print(leaf->right);
    }
}


void btree::traverseList(TreeNode* root, TreeNode* p, stack<TreeNode*>&stk, bool &found) {
    if (root == NULL) {
        found = false;
        return ;
    }
    else if ( root == p ) {
        found = true;
        return;
    }
    else { // root!=p
        found = true;
    }

    std::cout<<"push: "<<root->val<<", p: "<<root<<std::endl;
    stk.push(root);
    traverseList(root->left, p, stk, found);
    if ( !found ) 
        traverseList(root->right, p, stk, found);   

    if (!found){
        std::cout<<"pop: "<<root->val<<std::endl;
        stk.pop();
    }
}

TreeNode* btree::lowestCommonAncestor(TreeNode* p, TreeNode* q)
{
    std::stack<TreeNode*> stkp;
    bool found = true;
    traverseList(root, p, stkp, found);

    found = true;
    std::stack<TreeNode*> stkq;
    traverseList(root, q, stkq, found);

    //all parents of TreeNode p are stored on the stack 
   
    std::map<TreeNode*, bool> parentMap; 
    while(!stkp.empty()) {
        TreeNode* p = stkp.top();
        parentMap.insert(std::make_pair(p, true)); 
        stkp.pop();
    }

    while(!stkq.empty()) {
        TreeNode* p = stkq.top();
        if (parentMap.find(p) != parentMap.end()) {
            return p;
        } 
        stkq.pop();
    }
}


int main(){

    //btree tree;
    btree *tree = new btree();

    tree->insert(10);
    tree->insert(6);
    tree->insert(14);
    tree->insert(5);
    tree->insert(8);
    tree->insert(11);
    tree->insert(18);

    tree->preorder_print();
    tree->inorder_print();
    tree->postorder_print();


    //search 6
    TreeNode* p = tree->search(18);
    TreeNode* q = tree->search(5);
    TreeNode* ret = tree->lowestCommonAncestor(p, q);
    std::cout<<"ret: "<<ret<<", val:"<<ret->val<<std::endl;

/*
    std::stack<TreeNode*> stk;
    bool found = true;
    tree->traverseList(tree->getRoot(), node, stk, found);

    if (stk.empty()) {
        std::cout<<"empty stack"<<std::endl;
    } else {
        while(!stk.empty()) {
            TreeNode* p = stk.top();
            std::cout<<"val: "<<p->val<<", p: "<<p<<std::endl;
            stk.pop();
        }
    }
*/
    delete tree;
}

/*
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    // find p first
    bool found = true;
    traverseList(root, p, found);
}
*/