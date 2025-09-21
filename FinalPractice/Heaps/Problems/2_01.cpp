#include <bits/stdc++.h>
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
    bool solutionOne(TreeNode* root) {
        // Each node is paired with its "expected index" as if it were in a complete binary tree array
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});  

        int actualIndex = 0; // The current node's position (in traversal order)

        while (!q.empty()) {
            pair<TreeNode*, int> front = q.front();
            q.pop();

            TreeNode* node = front.first;      // Current node
            int expectedIndex = front.second;  // Expected index of this node

            // If the current traversal index doesn't match expected index,
            // then the tree has missing nodes before this position → not complete
            if (actualIndex != expectedIndex) {
                return false;
            }

            actualIndex++; // Move to next node number in traversal

            // Push left child with index = 2 * i + 1
            if (node->left != NULL) {
                q.push({node->left, 2 * expectedIndex + 1});
            }

            // Push right child with index = 2 * i + 2
            if (node->right != NULL) {
                q.push({node->right, 2 * expectedIndex + 2});
            }
        }

        // If no mismatch in indices found, it's a complete binary tree
        return true;
    }

    bool solutionTwo(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);

        bool isNullFound = false;

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node == NULL){
                isNullFound = true;
            }
            else{
                if(isNullFound){
                    return false;
                }else{
                    q.push(node->left);
                    q.push(node->right);
                }
            }
        }

        return true;

    }

    bool isCompleteTree(TreeNode* root) {
       // return solutionOne(root);

        return solutionTwo(root);
    }
};
