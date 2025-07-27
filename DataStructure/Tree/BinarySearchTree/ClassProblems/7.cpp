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
    void storeInOrder(TreeNode* root,vector<int> &inorder){
        if(root != NULL){
            storeInOrder(root->left,inorder);
            inorder.push_back(root->val);
            storeInOrder(root->right,inorder);
        }
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> inorder;
        storeInOrder(root,inorder);

        return inorder[k-1];
    }
};


// Method 2 : On the way during inorder
class Solution {
public:
    void inOrderWithCount(TreeNode* root,int k,TreeNode* &ans,int &count){
        // base case
        if(root == NULL){
            return;
        }

        //  1 case me solve remainining recursion will handle
        // L
        inOrderWithCount(root->left,k,ans,count);
        // N
        count++;
        if(count == k){
            ans = root;
            return;
        }
        // R
        inOrderWithCount(root->right,k,ans,count);

    }

    int kthSmallest(TreeNode* root, int k) {
        TreeNode* ans = NULL;
        int count = 0;
        inOrderWithCount(root,k,ans,count);
        return ans->val;
    }
};
