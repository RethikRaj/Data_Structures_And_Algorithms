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
    int getHeightAndCheckBalanced(TreeNode* root,bool &isBalanced){
        if(root == NULL){
            return -1;
        }
        // 1 case me solve remaining recursion
        int leftSubTreeHeight = getHeightAndCheckBalanced(root->left,isBalanced);
        int rightSubTreeHeight = getHeightAndCheckBalanced(root->right,isBalanced);
        int currNodeHeight = 1+max(leftSubTreeHeight,rightSubTreeHeight);
        // check for curr Node ->Is it balanced ?
        if(isBalanced && abs(leftSubTreeHeight-rightSubTreeHeight) > 1){
            isBalanced = false;
        }
        return currNodeHeight;
    }

    bool isBalanced(TreeNode* root) {
        bool isBalanced = true;
        getHeightAndCheckBalanced(root,isBalanced);
        return isBalanced;
    }
};

// without using reference v