#include <iostream>

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
    TreeNode* getInorderPredeccessor(TreeNode* root){
        // root is not NULL
        TreeNode* ptr = root;
        while(ptr->right != NULL){
            ptr = ptr->right;
        }
        return ptr;
    }

    TreeNode* getInorderSuccessor(TreeNode* root){
        // root is not NULL
        TreeNode* ptr = root;
        while(ptr->left != NULL){
            ptr = ptr->left;
        }
        return ptr;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        // base case
        if(root == NULL){
            return NULL;
        }


        if(root->val == key){
            // 4 cases psbl
            // case 1 : root is leaf node
            if(root->left == NULL && root->right == NULL){
                delete root;
                return NULL;
            }
            // case 2 : root has only left child
            if(root->left != NULL && root->right == NULL){
                TreeNode* temp = root->left;
                root->left = NULL; // node isolation
                delete root;
                return temp;
            }
            // case 3: root has only right child
            if(root->left == NULL && root->right != NULL){
                TreeNode* temp = root->right;
                root->right = NULL; // node isolation
                delete root;
                return temp;
            }
            // case 4: root has both left and right child
            if(root->left != NULL && root->right != NULL){
                // TreeNode* inOrderSuccessor = getInorderSuccessor(root->right);
                // root->val =  inOrderSuccessor->val;
                // root->right = deleteNode(root->right,inOrderSuccessor->val);
                // return root;

                TreeNode* inOrderPreDecessor = getInorderPredeccessor(root->left);
                root->val =  inOrderPreDecessor->val;
                // IMP 
                root->left = deleteNode(root->left,inOrderPreDecessor->val);
                return root;
            }
        }
        else{
            // move left or right
            if(key < root->val){
                root->left = deleteNode(root->left,key);
            }
            else{
                root->right = deleteNode(root->right,key);
            }
        }
        return root;
    }
};
