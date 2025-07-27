#include <iostream>
#include <vector>
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