#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    bool solutionOne(Node* root) {
        // Each element stores (node, expectedIndex) where expectedIndex is 
        // the index of this node if the tree were represented in an array
        queue<pair<Node*, int>> q;
        q.push({root, 0});  

        int actualIndex = 0; // Tracks BFS order index of nodes

        while (!q.empty()) {
            pair<Node*, int> front = q.front();
            q.pop();

            Node* node = front.first;          // Current node
            int expectedIndex = front.second;  // Expected index in complete binary tree

            // *Checking Completeness : If actual traversal index and expected index mismatch,it means some nodes are missing → not complete
            if (actualIndex != expectedIndex) {
                return false;
            }

            actualIndex++; // Increment index for next node

            // Check left child
            if (node->left != NULL) {
                // !Checking Heap property: parent >= left child
                if (node->left->data > node->data) {
                    return false;
                }
                // Push left child with index 2*i + 1
                q.push({node->left, 2 * expectedIndex + 1});
            }

            // Check right child
            if (node->right != NULL) {
                // !Checking Heap property: parent >= right child
                if (node->right->data > node->data) {
                    return false;
                }
                // Push right child with index 2*i + 2
                q.push({node->right, 2 * expectedIndex + 2});
            }
        }

        // If both completeness and heap property checks passed
        return true;
    }
  
    bool solutionTwo(Node* root){
        queue<Node*> q;
        q.push(root);

        bool isNullFound = false;

        while(!q.empty()){
            Node* node = q.front();
            q.pop();

            if(node == NULL){
                isNullFound = true;
            }
            else{
                if(isNullFound){ // *Checking Completeness
                    return false;
                }else{
                    // !Checking Heap property
                    if(node->left && node->left->data > node->data){
                        return false;
                    }
                    if(node->right && node->right->data > node->data){
                        return false;
                    }
                    
                    q.push(node->left);
                    q.push(node->right);
                }
            }
        }

        return true;
    }

    // Main function
    bool isMaxHeap(Node* tree) {
        return solutionOne(tree);
    }
};
