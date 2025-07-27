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
    // same code as below but in lakshay sir way
    bool isSameTree2(TreeNode* p, TreeNode* q) {
        if(!p && !q){
            // both are null
            return true;
        }else if(p && q){
            // both are not null
            return (p->val == q->val) && isSameTree2(p->left,q->left) && isSameTree2(p->right,q->right);
        }else{
            // exactly one not null and another is NULL
            return false;
        }
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        // base case
        if((p==NULL && q != NULL) || (q==NULL && p != NULL)){
            return false;
        }
        if(p == NULL && q== NULL){
            return true;
        }

        // here we are guaranteed that p & q both are non null
        // 1 case me handle , remaining recursion handles
        // 1 case
        bool currNodeStatus = (p->val == q->val);
        bool leftRecAns = isSameTree(p->left,q->left);
        bool rightRecAns = isSameTree(p->right,q->right);
        // backtracking
        if(currNodeStatus && leftRecAns && rightRecAns){
            return true;
        }else{
            return false;
        }
    }
};


// brute force approach : 65/66 testcase passed
class Solution {
public:
    void preOrder(TreeNode* root,vector<int> &arr){
        if(root != NULL){
            arr.push_back(root->val);
            preOrder(root->left,arr);
            preOrder(root->right,arr);
        }
    }

    void inOrder(TreeNode* root,vector<int> &arr){
        if(root != NULL){
            inOrder(root->left,arr);
            arr.push_back(root->val);
            inOrder(root->right,arr);
        }
    }

    bool bruteForce(TreeNode* p,TreeNode* q){
        vector<int> preOrder1;
        vector<int> preOrder2;

        vector<int> inOrder1;
        vector<int> inOrder2;

        preOrder(p,preOrder1);
        preOrder(q,preOrder2);
        inOrder(p,inOrder1);
        inOrder(q,inOrder2);

        if(preOrder1.size() != preOrder2.size()){
            return false;
        }

        for(int i=0;i<preOrder1.size();i++){
            if((preOrder1[i] != preOrder2[i]) || (inOrder1[i] != inOrder2[i])){
                return false;
            }
        }

        return true;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return bruteForce(p,q);
    }
};