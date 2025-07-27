#include <iostream>
#include <vector>

using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};




void solve(Node* root,vector<int> &ans,int level){
    // base case
    if(root == NULL){
        return;
    }
    //  1 case me solve remaining recursion will handle
    // 1 case
    if(level == ans.size()){
        ans.push_back(root->data);
    }
    // recursion
    solve(root->left,ans,level+1);
    solve(root->right,ans,level+1);
}

vector<int> leftView(Node *root){
   vector<int> ans;
   int level = 0;
   solve(root,ans,level);
   return ans;
}
