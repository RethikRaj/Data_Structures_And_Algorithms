#include <iostream>
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

// method 1 :

class Solution1 {
public:
    void solve(TreeNode* root,int &sum){
        //  base case
        if(root == NULL){
            return;
        }

        // 1 case me solve remainining recursion will handle
        solve(root->right,sum);
        int temp = root->val;
        root->val = root->val + sum;
        sum += temp;
        solve(root->left,sum);
    }

    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        solve(root,sum);
        return root;
    }
};

// method 2 : Using the property that inorder of bst is sorted
class Solution2 {
public:
    void storeInOrder(TreeNode* root,vector<int> &inorder){
        if(root != NULL){
            storeInOrder(root->left,inorder);
            inorder.push_back(root->val);
            storeInOrder(root->right,inorder);
        }
    }

    void updateTree(TreeNode* root,vector<int> &inorder,int &index){
        if(root != NULL){
            updateTree(root->left,inorder,index);
            root->val = inorder[index];
            index++;
            updateTree(root->right,inorder,index);
        }
    }


    TreeNode* bstToGst(TreeNode* root) {

        // step 1 : Store inorder
        vector<int> inorder;
        storeInOrder(root,inorder);

        // step 2: update inorder array so that we get gst
        int sum = 0;
        for(int i=inorder.size()-1;i>=0;i--){
            sum += inorder[i];
            inorder[i] = sum;
        }

        // step 3 :update tree -> since we went as inorder and got sum so store the sum by again traversing in inorder
        int index = 0;
        updateTree(root,inorder,index);

        return root;
    }
};