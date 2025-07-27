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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,unordered_map<int,int> &mp,int IS,int IE,int &index){
        // 1 case me solve remaining recursion will handle
        int z = mp[preorder[index]];
        TreeNode* newNode = new TreeNode(preorder[index]);
        
        // build left tree
        int IEnew = z-1;
        if(IS > IEnew){
            newNode->left = NULL;
        }else{
            index = index+1;
            newNode->left = solve(preorder,inorder,mp,IS,IEnew,index);
        }
        
        // build right tree
        int ISnew = z+1;
        if(ISnew > IE){
            newNode->right = NULL;
        }else{
            index = index+1;
            newNode->right = solve(preorder,inorder,mp,ISnew,IE,index);
        }
        return newNode;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int IS = 0;
        int IE = inorder.size()-1;
        int index = 0;

        // create a map of inOrder (element->index)
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }

        // solve
        TreeNode* root = solve(preorder,inorder,mp,IS,IE,index);
        return root;
    }
};

// same logic but easy code
class Solution {
public:
    TreeNode* constructTree(unordered_map<int,int> &valMap, vector<int>& preorder, vector<int>& inorder, int &preOrderIndex, int inorderStart, 
    int inorderEnd, int size) {
        //base case
        if(preOrderIndex >= size) {
            return NULL;
        }
        if(inorderStart > inorderEnd) {
            return NULL;
        }

        //process the first element of preorder as root
        //step1: get element from preorder and create root node for it 
        int element = preorder[preOrderIndex];
        preOrderIndex++;
        TreeNode* root = new TreeNode(element);
        //step2: find this element inside inorder and call for left and rigth 
        int elementIndexInsideInorder = valMap[element];
        //inorder left part -> index inorderStart to elementIndexInsideInorder-1
        //inorder right part -> index elementIndexInsideInorder+1 to inorderEnd
        root->left = constructTree(valMap,preorder, inorder, preOrderIndex, inorderStart, elementIndexInsideInorder-1,size);
        root->right = constructTree(valMap, preorder, inorder, preOrderIndex, elementIndexInsideInorder+1 , inorderEnd, size);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndex = 0;
        int inorderStart = 0;
        int inorderEnd = inorder.size()-1;
        int size = inorder.size();

        unordered_map<int,int> mp; //element ->index
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        TreeNode* root = constructTree(mp,preorder, inorder, preIndex, inorderStart, inorderEnd, size);
        return root;
    }
};
