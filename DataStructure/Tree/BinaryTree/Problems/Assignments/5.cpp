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
    void solve(TreeNode* root,vector<int> &ans){
        TreeNode* curr = root;

        while(curr){
            // if no left child
            if(curr->left == NULL){
                // visit curr
                ans.push_back(curr->val);
                // move right
                curr = curr->right;
            }
            else{// left child is NOT NULL 
                // inorder predecessor
                TreeNode* pred = curr->left;
                while(pred->right != curr && pred->right != NULL){
                    pred = pred->right;
                }

                // Linking step
                // havenot visited left sub tree
                if(pred->right == NULL){
                    pred->right = curr;
                    curr = curr->left;
                }
                // Unlinking step
                else{// left subtree already visted
                    // visit curr
                    ans.push_back(curr->val);
                    // unlink
                    pred->right = NULL;
                    // move right
                    curr = curr->right;
                }
            }
        }
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        solve(root,ans);
        return ans;
    }
};