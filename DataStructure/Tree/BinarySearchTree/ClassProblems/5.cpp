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
    bool twoSumUtility(vector<int> arr,int target){
        int i=0,j=arr.size()-1;
        while(i < j){
            int sum = arr[i]+arr[j];
            if(sum < target){
                i++;
            }else if(sum > target){
                j--;
            }else{
                // sum == target
                return true;
            }
        }
        return false;
    }

    void inOrder(TreeNode* root,vector<int> &inorder){
        if(root != NULL){
            inOrder(root->left,inorder);
            inorder.push_back(root->val);
            inOrder(root->right,inorder);
        }
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        inOrder(root,inorder);
        return twoSumUtility(inorder,k);
    }
};