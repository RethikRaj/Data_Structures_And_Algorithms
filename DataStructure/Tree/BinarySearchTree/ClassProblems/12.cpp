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

class Result{
public:
    bool isBST;
    int minVal;
    int maxVal;
    long long int sum;

    Result(bool isBST, int minVal, int maxVal, long long int sum){
        this->isBST = isBST;
        this->minVal = minVal;
        this->maxVal = maxVal;
        this->sum = sum;
    }
};

class Solution {
public:
    Result* solution(TreeNode* root, long long int &maxSum){
        if (root == NULL){
            return new Result(true, INT_MAX, INT_MIN, 0);
        }
        // PostOrder
        // L
        Result* leftRecAns = solution(root->left, maxSum);
        // N
        Result* rightRecAns = solution(root->right, maxSum);
        // R
        bool isCurrBST = leftRecAns->isBST && rightRecAns->isBST && (leftRecAns->maxVal < root->val) && (rightRecAns->minVal > root->val);
        int currMin = min(min(leftRecAns->minVal, rightRecAns->minVal), root->val);
        int currMax = max(max(leftRecAns->maxVal, rightRecAns->maxVal), root->val);
        long long int currSum = root->val + leftRecAns->sum + rightRecAns->sum;
        if(isCurrBST){
            maxSum = max(maxSum, currSum);
        }
        return new Result(isCurrBST, currMin, currMax, currSum);
    }

    int maxSumBST(TreeNode* root) {
        long long int maxSum = 0;
        solution(root, maxSum);
        return maxSum;
    }
};