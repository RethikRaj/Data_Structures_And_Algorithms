#include <bits/stdc++.h>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    Node* solve(Node* node, unordered_map<Node*, Node*> &mp) {
        // Base case: if the given node is NULL, return NULL
        if (node == NULL) {
            return NULL;
        }

        // Step 1: Create a copy of the current node with the same value
        Node* curr = new Node(node->val);

        // Step 2: Store the mapping of original node -> cloned node
        mp[node] = curr;


        // Step 3: Iterate over all neighbors of the current node
        for (Node* neighbour : node->neighbors) {
            // If this neighbor hasn’t been cloned yet, recursively clone it
            if (mp.find(neighbour) == mp.end()) {
                Node* recNode = solve(neighbour, mp);  // recursive DFS call
                curr->neighbors.push_back(recNode);
            } else {
                // If already cloned, directly use the stored mapping
                curr->neighbors.push_back(mp[neighbour]);
            }
        }

        // Return the cloned node
        return curr;
    }

    // Main function to start graph cloning
    Node* cloneGraph(Node* node) {
        // Map to store (original node -> cloned node) mapping
        unordered_map<Node*, Node*> mp;

        // Start DFS cloning from the given starting node
        return solve(node, mp);
    }
};
