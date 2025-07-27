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
    // Method 1 : With Insering NULL
    // level order -> L TO R
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> level;
        // edge case
        if(root == NULL){
            return ans;
        }

        queue<TreeNode*> q;
        // initialise the starting state of q
        q.push(root);
        q.push(NULL);//since level '0' is inserted in queue

        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();

            if(front == NULL){
                // store ans
                ans.push_back(level);
                level.clear();
                // all the nodes of the curr level is explored-> its child has been inserted into queue->if queue is not empty ->then since next level nodes are inserted into queue => insert NULL to indicate that level ends
                // DONT FORGET 
                if(!q.empty()){
                    q.push(NULL);
                }
            }else{
                // valid node -> may have valid childs 
                level.push_back(front->val); // add curr node to curr level
                if(front->left != NULL){
                    // left child is valid->push into queue
                    q.push(front->left);
                }
                if(front->right != NULL){
                    // right child is valid->push into queue
                    q.push(front->right);
                }
            }
        }
        return ans;
    }

    // R to L
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> level;
        // edge case
        if(root == NULL){
            return ans;
        }

        queue<TreeNode*> q;
        // initialise the starting state of q
        q.push(root);
        q.push(NULL);//since level '0' is inserted in queue

        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();

            if(front == NULL){
                // store ans
                ans.push_back(level);
                level.clear();
                // all the nodes of the curr level is explored-> its child has been inserted into queue->if queue is not empty ->then since next level nodes are inserted into queue => insert NULL to indicate that level ends
                // DONT FORGET 
                if(!q.empty()){
                    q.push(NULL);
                }
            }else{
                // valid node -> may have valid childs 
                level.push_back(front->val); // add curr node to curr level
                if(front->right != NULL){
                    // right child is valid->push into queue
                    q.push(front->right);
                }
                if(front->left != NULL){
                    // left child is valid->push into queue
                    q.push(front->left);
                }
            }
        }
        return ans;
    }


    // Method 2 :  Without inserting NULL
    // L to R
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;      // This will store the final level order traversal as a list of lists
        queue<TreeNode*> q;           // Queue to help with BFS traversal

        // Edge case: if the root is NULL, just return the empty result
        if (root == NULL) return ans;

        // Start with the root node in the queue
        q.push(root);

        // Continue the process until the queue becomes empty
        while (!q.empty()) {
            int size = q.size();          // Number of nodes at the current level
            vector<int> currLevel;        // List to store values of nodes at this level

            // Process all nodes at the current level
            for (int i = 0; i < size; i++) {
                TreeNode* front = q.front(); // Get the front node in the queue
                q.pop();                     // Remove it from the queue
                currLevel.push_back(front->val); // Add its value to the current level list

                // If the left child exists, add it to the queue for the next level
                if (front->left != NULL) {
                    q.push(front->left);
                }
                // If the right child exists, add it to the queue for the next level
                if (front->right != NULL) {
                    q.push(front->right);
                }
            }

            // After processing all nodes at the current level, add this level to the answer
            ans.push_back(currLevel);
        }

        // Return the complete level order traversal
        return ans;
    }

};