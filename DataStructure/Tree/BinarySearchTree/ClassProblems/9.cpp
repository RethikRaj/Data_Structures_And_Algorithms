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


// InOrder Approach : TC : (n)
class Solution {
public:
    TreeNode* solve(vector<int>& nums,int &index,int n){
        // base case
        if(index >= nums.size() || n <= 0){
            return NULL;
        }
        // 1 case me solve remainining recursion will handle
        // L
        TreeNode* leftSubTree = solve(nums,index,n/2);
        // N
        TreeNode* newNode = new TreeNode(nums[index]);
        newNode->left = leftSubTree;
        // update index => DONT FORGET
        index++;
        // R
        TreeNode* rightSubTree = solve(nums,index,n-n/2-1);
        newNode->right = rightSubTree;
        return newNode;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int index = 0;
        int n = nums.size();
        TreeNode* root = solve(nums,index,n);
        return root;
    }
};

// PreOrder Approach : TC:O(n)
class Solution {
public:
    TreeNode* solve(vector<int>& nums,int s,int e){
        // base case
        if(s > e){
            return NULL;
        }
        //  1 case me solve remainining recursion will handle
        int mid = s+(e-s)/2;
        TreeNode* newNode = new TreeNode(nums[mid]);
        // recursion
        newNode->left = solve(nums,s,mid-1);
        newNode->right = solve(nums,mid+1,e);
        return newNode;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;

        TreeNode* root = solve(nums,start,end);
        return root;
    }
};