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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;      // Final result: stores the zigzag level order traversal
        queue<TreeNode*> q;           // Queue to help with BFS traversal

        // Edge case: if root is NULL, return empty result
        if (root == NULL) return ans;

        q.push(root);                 // Start BFS with the root node
        bool leftToright = true;      // Flag to control direction: true -> left to right, false -> right to left

        while (!q.empty()) {
            int size = q.size();                  // Number of nodes at current level
            vector<int> currLevel(size);          // Current level values (pre-sized to handle zigzag indexing)

            // Process all nodes at the current level
            for (int i = 0; i < size; i++) {
                TreeNode* front = q.front();      // Get the front node
                q.pop();                          // Remove it from queue

                // Find index to insert value based on current direction
                // L to R then insert from start else insert from end
                int index = leftToright ? i : size - i - 1;
                currLevel[index] = front->val;

                // Add children to queue for next level
                if (front->left != NULL) {
                    q.push(front->left);
                }
                if (front->right != NULL) {
                    q.push(front->right);
                }
            }

            // After processing current level, toggle the direction for the next level
            leftToright = !leftToright;

            // Add the current level to final result
            ans.push_back(currLevel);
        }

        // Return complete zigzag traversal
        return ans;
    }

};