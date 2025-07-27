#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* left, * right;
};

class Solution {
  public:  
    int solve(Node* root){
        // base case
        if(root == NULL){
            return 0;
        }
        // 1 case me solve remaining recursion will handle
        int leftSum = solve(root->left);
        int rightSum = solve(root->right);
        // IMP STEP : STORE THE CURRNODE VALUE
        int currNodeValue = root->data;
        // update currNode to the sum of leftSubtree and rightSubTree
        root->data = leftSum + rightSum;
        
        // return sum of leftSum,rightSum,and oldCurrNodeValue
        return leftSum + rightSum + currNodeValue;
    }
    
    
    void toSumTree(Node *node){
        solve(node);
        
    }
};