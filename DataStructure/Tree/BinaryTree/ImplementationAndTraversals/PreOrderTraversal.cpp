#include <iostream>
#include <vector>
#include <stack>

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

    void solveIterative(TreeNode* root,vector<int> &ans){
        if(root==NULL){
            return;
        }

        stack<TreeNode*> s;
        s.push(root); // initial state of stack

        while(!s.empty()){
            TreeNode* top = s.top();
            s.pop();
            // store ans
            ans.push_back(top->val);
            // first push right child if exists
            if(top->right != NULL){
                s.push(top->right);
            }

            if(top->left != NULL){
                s.push(top->left);
            }
        }
    }


    // Recursive
    void solve(TreeNode* root,vector<int> &ans){
        if(root != NULL){
            ans.push_back(root->val);
            solve(root->left,ans);
            solve(root->right,ans);
        }
    }


    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;

        solve(root,ans);

        //solveIterative(root,ans);

        return ans;
    }
};