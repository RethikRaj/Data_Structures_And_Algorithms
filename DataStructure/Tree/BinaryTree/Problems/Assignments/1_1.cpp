#include <iostream>
#include <vector>

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
    bool isMirrorTree(TreeNode* p,TreeNode* q){
        if(!p && !q){
            // both are null
            return true;
        }else if(p && q){
            // both are not null
            return (p->val == q->val) && isMirrorTree(p->left,q->right) && isMirrorTree(p->right,q->left);
        }else{
            // exactly one not null and another is NULL
            return false;
        }

    }

    bool isSymmetric(TreeNode* root) {
        return isMirrorTree(root->left,root->right);
    }
};