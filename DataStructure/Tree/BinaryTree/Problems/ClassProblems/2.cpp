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


// Method 1 : TC : O(n^2),SC:O(n)
class Solution {
public:
    int getHeight(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int leftSubTreeHeight = getHeight(root->left);
        int rightSubTreeHeight = getHeight(root->right);
        return 1 + max(leftSubTreeHeight,rightSubTreeHeight);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        // base case
        if(root == NULL){
            return 0;
        }
        // 1 case me solve remaining recursion
        int option1 = diameterOfBinaryTree(root->left);
        int option2 = diameterOfBinaryTree(root->right);
        // 1 case
        int option3 = getHeight(root->left) + getHeight(root->right);
        int maxDiameter = max(option1,max(option2,option3));
        return maxDiameter;
    }
};

// TC : O(n), SC:O(n)
class Solution {
public:
    int solve(TreeNode* root,int &maxDia){
        if(root == NULL){
            return 0;
        }
        // 1 case me solve remaining recursion
        int leftHeight = solve(root->left,maxDia);
        int rightHeight = solve(root->right,maxDia);
        int height = 1 + max(leftHeight,rightHeight);
        int diameter = leftHeight+rightHeight;
        if(maxDia < diameter){
            maxDia = diameter;
        }
        return height;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxDia = INT_MIN;
        int heightOfTree = solve(root,maxDia);
        return maxDia;
    }
};