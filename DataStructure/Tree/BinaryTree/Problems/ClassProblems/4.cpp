#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    TreeNode* getLCA(TreeNode* root, TreeNode* &p, TreeNode* &q){
        // Base case
        if(root == NULL){
            return NULL;
        }
        // 1 case me solve remaining recursion will handle
        // 1 case
        if(root == p){
            return p;
        }
        if(root == q){
            return q;
        }
        // recursion
        TreeNode* leftRecAns = getLCA(root->left,p,q);
        TreeNode* rightRecAns = getLCA(root->right,p,q);
        // Backtracking
        if(leftRecAns==NULL && rightRecAns == NULL){
            return NULL;
        }else if(leftRecAns==NULL){
            return rightRecAns;
        }else if(rightRecAns == NULL){
            return leftRecAns;
        }else{
            // both are NOT NULL -> (leftRecAns == p && rightRecAns == q) (or) (leftRecAns == q && rightRecAns == p)
            return root;
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return getLCA(root,p,q);
    }
};