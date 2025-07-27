#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// method 1 :
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        bool isFirstNullArrived = false;

        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();

            if(front == NULL){
                if(isFirstNullArrived){
                    continue;
                }else{
                    isFirstNullArrived = true;
                }
            }
            else if(front != NULL){
                if(isFirstNullArrived){
                    return false;
                }else{
                    q.push(front->left);
                    q.push(front->right);
                }
            }
        }
        return true;
    }
};

// Method 2 :
class Solution {
public:
    int nodeCount(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        return 1+nodeCount(root->left)+nodeCount(root->right);
    }

    bool solve(TreeNode* root,int index,int &totalNodes){
        if(!root){
            return true;
        }
        // 1 case me solve remaining recursion will handle
        // N
        if(index > totalNodes){
            return false;
        }
        // L,R
        return solve(root->left,2*index,totalNodes) && solve(root->right,2*index+1,totalNodes);
    }

    bool isCompleteTree(TreeNode* root) {
        int totalNodes = nodeCount(root);
        int index = 1;
        bool ans = solve(root,index,totalNodes);
        return ans;
    }
};