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
    void solve(TreeNode* root, int val,TreeNode* &ans){
        // base case
        if(root == NULL){
            ans = NULL;
            return;
        }

        // 1 case me solve remaininig recursion will handle
        if(root->val == val){
            ans = root;
            return;
        }

        if(val < root->val){
            solve(root->left,val,ans);
        }else{
            solve(root->right,val,ans);
        }

    }

    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* ans = NULL;
        solve(root,val,ans);
        return ans;
    }
};