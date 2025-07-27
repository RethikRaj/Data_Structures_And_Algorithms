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
    int solve(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int leftSubTreeHeight = solve(root->left);
        int rightSubTreeHeight = solve(root->right);
        return 1 + max(leftSubTreeHeight,rightSubTreeHeight);
    }
    
    int maxDepth(TreeNode* root) {
        int ans = solve(root);
        return ans;
    }
};