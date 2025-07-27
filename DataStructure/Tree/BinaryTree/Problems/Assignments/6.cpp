#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
#include <iostream>
using namespace std;

// Definition of binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Helper class to store a node along with its horizontal distance (HD) and level (depth)
class Temp {
public:
    TreeNode* node; // Pointer to the tree node
    int HD;         // Horizontal distance from root
    int level;      // Depth level of the node

    Temp(TreeNode* node, int HD, int level) {
        this->node = node;
        this->HD = HD;
        this->level = level;
    }
};

// Custom comparator for the priority queue to determine node processing order
class CustomComparator {
public:
    bool operator()(Temp* &t1, Temp* &t2) {
        // If level and HD are equal, the node with smaller value should come first
        if(t1->level == t2->level && t1->HD == t2->HD){
            return (t1->node)->val > (t2->node)->val;
        }
        // If only levels are equal, node with smaller HD should come first
        if(t1->level == t2->level){
            return t1->HD > t2->HD;
        }
        // Node with smaller level should come first
        return t1->level > t2->level;
    }
};

// Main solution class
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans; // If tree is empty, return empty answer

        // Priority queue to process nodes in required order
        priority_queue<Temp*, vector<Temp*>, CustomComparator> pq;
        pq.push(new Temp(root, 0, 0)); // Start with root at HD = 0 and level = 0

        // Map to store nodes grouped by their HD
        unordered_map<int, vector<int>> um;
        int minHD = INT_MAX; // Track minimum HD
        int maxHD = INT_MIN; // Track maximum HD

        // BFS traversal using priority queue
        while(!pq.empty()) {
            int size = pq.size(); // Number of nodes at the current "batch"
            for(int i = 0; i < size; i++) {
                Temp* top = pq.top();
                pq.pop();

                TreeNode* topNode = top->node;

                // Insert the node value into map based on its HD
                if(um.find(top->HD) == um.end()){
                    vector<int> v;
                    v.push_back(topNode->val);
                    um[top->HD] = v;
                } else {
                    um[top->HD].push_back(topNode->val);
                }

                // Update min and max HD seen so far
                minHD = min(top->HD, minHD);
                maxHD = max(top->HD, maxHD);

                // Push left child into queue with updated HD and level
                if (topNode->left != NULL){
                    pq.push(new Temp(topNode->left, top->HD - 1, top->level + 1));
                }

                // Push right child into queue with updated HD and level
                if (topNode->right != NULL){
                    pq.push(new Temp(topNode->right, top->HD + 1, top->level + 1));
                }
            }
        }

        // Collect nodes in vertical order from minHD to maxHD
        for(int i = minHD; i <= maxHD; i++){
            ans.push_back(um[i]);
        }

        return ans;
    }
};
