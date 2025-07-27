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
    void solve(TreeNode* root,TreeNode* &tail){
        // base case
        if(root == NULL){
            return;
        }

        TreeNode* leftNode = root->left;
        TreeNode* rightNode = root->right;

        if(leftNode){
            root->left = NULL;
            root->right = leftNode;
            tail = root->right;
            solve(root->right,tail);
        }
        if(rightNode){
            tail->right = rightNode;
            tail = tail->right;
            solve(tail,tail);
        }
    }

    void flatten(TreeNode* root) {
        TreeNode* tail = root;
        solve(root,tail);
    }
};