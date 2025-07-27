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
    // 2nd way of coding
    bool solve2(TreeNode* root, int targetSum,int &currPathSum){
        // base case
        if(root == NULL){
            return false;
        }
        // 1 case me solve remaining recursion will handle
        // 1 case
        currPathSum += root->val;
        //  check leaf node
        if(root->left == NULL && root->right == NULL){
            if(currPathSum == targetSum){
                // backtracking(IMPPP)
                currPathSum -= root->val;
                return true;
            }else{
                // backtraking (IMPPPPPP)
                currPathSum -= root->val;
                return false;
            }
        }
        // recursion
        bool leftRecAns = solve2(root->left,targetSum,currPathSum);
        bool rightRecAns = solve2(root->right,targetSum,currPathSum);
        // backtracking
        currPathSum -= root->val;
        return leftRecAns || rightRecAns;
    }


    // 1st way of coding
    void solve(TreeNode* root, int targetSum,bool &ans,int &currPathSum){
        // base case 
        if(root == NULL){
            return;
        }
        // 1 case me solve remainig recursion will handle
        // 1 case
        currPathSum += root->val;
        //  check leaf node
        if(root->left == NULL && root->right == NULL){
            if(currPathSum == targetSum){
                ans = true;
            }
        }
        // recursion
        solve(root->left,targetSum,ans,currPathSum);
        solve(root->right,targetSum,ans,currPathSum);
        // backtracking
        currPathSum -= root->val;
    }


    bool hasPathSum(TreeNode* root, int targetSum) {
        //  1st way
        // bool ans = false;
        // int currPathSum = 0;
        // solve(root,targetSum,ans,currPathSum);
        // return ans;

        // 2nd way
        int sum = 0;
        bool ans2 = solve2(root,targetSum,sum);
        return ans2;
    }
};