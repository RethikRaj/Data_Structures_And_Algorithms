#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}



class Solution {
  public:
    int minValue(Node* root) {
        if(root == NULL){
            return -1;
        }
        
        Node* ptr = root;
        while(ptr->left != NULL){
            ptr = ptr->left;
        }
        return ptr->data;
    }

    int maxValue(Node* root){
        if(root == NULL){
            return -1;
        }

        Node* ptr = root;
        while(ptr->right != NULL){
            ptr = ptr->right;
        }
        return ptr->data;
    }
};