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


// BC : O(logn) WC : O(n)
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // base case 
        if(root == NULL){
            TreeNode* newNode = new TreeNode(val);
            return newNode;
        }

        // 1 case me solve remaining recursion will solve
        if(val < root->val){
            // insert in left
            root->left = insertIntoBST(root->left,val);
        }else{
            // insert in right
            root->right = insertIntoBST(root->right,val);
        }
        return root;
    }
};
