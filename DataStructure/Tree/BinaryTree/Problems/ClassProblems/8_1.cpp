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
    void solve(TreeNode* root,vector<int> &ans,int level){
        // base case
        if(root == NULL){
            return;
        }
        // 1 case
        if(ans.size() == level){
            ans.push_back(root->val);
        }
        // recursion
        solve(root->right,ans,level+1);
        solve(root->left,ans,level+1);
    }

    vector<int> rightSideView(TreeNode* root) {
        int level = 0;
        vector<int> ans;
        solve(root,ans,level);
        return ans;
    }
};