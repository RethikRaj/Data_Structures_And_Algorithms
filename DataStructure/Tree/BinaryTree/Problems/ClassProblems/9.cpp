#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>


using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

class Solution{
    public:
    vector<int> topView(Node *root) {
        vector<int> ans;  // This will store the final answer: the top view node values

        if (root == NULL) return ans;  // Edge case: if the tree is empty, return empty vector

        // Queue to perform level order traversal (BFS)
        // Each element is a pair: (node, horizontal distance from root)
        queue<pair<Node*, int>> q;
        q.push(make_pair(root, 0));  // Root is at horizontal distance 0

        // Map to store the first node we encounter at each horizontal distance
        unordered_map<int, Node*> um;

        // Track the minimum and maximum horizontal distances we see
        int maxDist = INT_MIN;
        int minDist = INT_MAX;

        while (!q.empty()) {
            pair<Node*, int> frontPair = q.front();  // Get the front element of the queue
            q.pop();

            Node* frontNode = frontPair.first;       // Current node
            int frontNodeDist = frontPair.second;    // Current node's horizontal distance

            // Update min and max horizontal distances
            maxDist = max(maxDist, frontNodeDist);
            minDist = min(minDist, frontNodeDist);

            // If this horizontal distance is not already in the map,
            // it means this is the first node we see at this distance (i.e., top view)
            if (um.find(frontNodeDist) == um.end()) {
                um[frontNodeDist] = frontNode;
            }

            // Add the left child to the queue with horizontal distance -1
            if (frontNode->left != NULL) {
                q.push(make_pair(frontNode->left, frontNodeDist - 1));
            }

            // Add the right child to the queue with horizontal distance +1
            if (frontNode->right != NULL) {
                q.push(make_pair(frontNode->right, frontNodeDist + 1));
            }
        }

        // Collect the nodes from leftmost to rightmost horizontal distance
        for (int i = minDist; i <= maxDist; i++) {
            ans.push_back(um[i]->data);
        }

        return ans;  // Return the top view
    }

};