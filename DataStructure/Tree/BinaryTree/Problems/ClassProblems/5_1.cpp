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
    void solve(TreeNode* root, int targetSum,int sum,vector<int> &path,vector<vector<int>> &ans){
        // base case
        if(root == NULL){
            return;
        }
        // 1 case me solve remaining recursion will handle
        // 1 case
        sum += root->val;
        path.push_back(root->val);
        // check leaf node
        if(root->left == NULL && root->right == NULL){
            if(sum == targetSum){
                ans.push_back(path);
            }
            // backtracking
            path.pop_back();
            return;
        }
        // recursion
        solve(root->left,targetSum,sum,path,ans);
        solve(root->right,targetSum,sum,path,ans);
        // backtracking
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        int sum = 0;
        solve(root,targetSum,sum,path,ans);
        return ans;
    }
};