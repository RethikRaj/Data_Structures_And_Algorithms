#include <iostream>
#include <unordered_map>
#include <vector>

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
    TreeNode* constructTree(vector<int>& inorder, vector<int>& postorder,int &postIndex,int inOrderStart,int inOrderEnd,unordered_map<int,int> &mp){
        // base cases
        if(postIndex < 0){
            return NULL;
        }
        if(inOrderStart > inOrderEnd){
            return NULL;
        }

        //  1 case me solve remainining recursion will handle
        // 1 case
        int element = postorder[postIndex];
        postIndex--;
        TreeNode* root = new TreeNode(element);
        // recursion
        int elementIndexInsideInOrder = mp[element];
        root->right = constructTree(inorder,postorder,postIndex,elementIndexInsideInOrder+1,inOrderEnd,mp);
        root->left = constructTree(inorder,postorder,postIndex,inOrderStart,elementIndexInsideInOrder-1,mp);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int inOrderStart = 0;
        int inOrderEnd = inorder.size()-1;
        int size = inorder.size();
        int postIndex = size-1;

        // create mapping of inorder : element->index
        unordered_map<int,int> mp;
        for(int i=0;i<size;i++){
            mp[inorder[i]] = i;
        }

        TreeNode* root = constructTree(inorder,postorder,postIndex,inOrderStart,inOrderEnd,mp); 
        return root;
    }
};

