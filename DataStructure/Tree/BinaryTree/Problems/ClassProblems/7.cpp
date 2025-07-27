#include <iostream>
#include <vector>

using namespace std;

struct Node{
    int data;
    Node* left, * right;
};

class Solution {
public:
    void leftBoundary(Node* root,vector<int> &ans){
        // base cases
        if(root == NULL){
            return;
        }
        // since we dont want to include leaf node
        if(root->left == NULL && root->right == NULL){
            return;
        }
        
        // 1 case me solve remaininig recursion
        ans.push_back(root->data);
        // give preference to left subtree over right -> that is if left subtree exists then move left , if not exists then move right
        if(root->left != NULL){
            leftBoundary(root->left,ans);
        }else{
            leftBoundary(root->right,ans);
        }
    }
    
    void leafBoundary(Node* root,vector<int> &ans){
        // base cases
        if(root == NULL){
            return;
        }
        
        if(root->left == NULL && root->right == NULL){
            ans.push_back(root->data);
        }
        leafBoundary(root->left,ans);
        leafBoundary(root->right,ans);
    }
    
    void rightBoundary(Node* root,vector<int> &ans){
        // base cases
        if(root == NULL){
            return;
        }
        // since we dont want to include leaf node
        if(root->left == NULL && root->right == NULL){
            return;
        }
        // 1 case me solve remaininig recursion
        // give preference to right subtree over left -> that is if right subtree exists then move right , if not exists then move left
        if(root->right != NULL){
            rightBoundary(root->right,ans);
        }else{
            rightBoundary(root->left,ans);
        }
        // since needed in reverse order
        ans.push_back(root->data);
    }

    vector<int> boundary(Node *root){
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        
        // step 1: store root node
        ans.push_back(root->data);
        // step 2: store left boundary without leaf nodes
        leftBoundary(root->left,ans);
        // step 3
        // 3a) store leaf nodes in left subtree
        leafBoundary(root->left,ans);
        // 3b) store leaf nodes in right subtree
        leafBoundary(root->right,ans);
        // step 4: store right boundary without leaf nodes
        rightBoundary(root->right,ans);
        
        return ans;
    }
};