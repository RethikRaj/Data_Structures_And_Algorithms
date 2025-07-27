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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // base case
        if(root == NULL){
            return NULL;
        }

        // 1 case me solve remaining recurison will handle
        // case 1 : p and q is in left sub tree => neglect right and select left
        if(p->val < root->val && q->val < root->val){
            TreeNode* leftRecAns = lowestCommonAncestor(root->left,p,q);
            return leftRecAns;
        }
        // case 2 : p and q is in right sub tree => neglect left and select right
        if(p->val > root->val && q->val > root->val){
            TreeNode* rightRecAns = lowestCommonAncestor(root->right,p,q);
            return rightRecAns;
        }
        // case 3: p is in left and q is in right 
        // case 4: q is in left and p is in right
        return root;
    }
};