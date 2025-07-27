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


// Method 1 : checking whether inorder is sorted on the way
class Solution {
public:
    void solve(TreeNode* root,long long int &prev,bool& ans){
        // base case
        if(root == NULL){
            return;
        }
        //  1 case me remainining recursion will handle
        // L
        solve(root->left,prev,ans);
        // N
        if(prev >= root->val){
            ans = false;
            return;
        }else{
            prev = root->val;
        }
        // R
        solve(root->right,prev,ans);
    }

    bool isValidBST(TreeNode* root) {
        long long int prev = (long long int)INT_MIN-1;
        bool ans = true;
        solve(root,prev,ans);
        return ans;
    }
};

// Method 1.2: store inorder and check whether it is sorted
class Solution {
public:
    void storeInorder(TreeNode* root,vector<int> &inorder){
        if(root != NULL){
            storeInorder(root->left,inorder);
            inorder.push_back(root->val);
            storeInorder(root->right,inorder);
        }
    }

    bool checkSorted(vector<int> &arr){
        int i = 0;
        while(i <= arr.size()-2){
            if(arr[i] >= arr[i+1]){
                return false;
            }
            i++;
        }
        return true;
    }

    bool isValidBST(TreeNode* root) {
        if(root->left == NULL && root->right == NULL){
            return true;
        }

        vector<int> inorder;
        storeInorder(root,inorder);

        // check whether inorder is sorted or not
        return checkSorted(inorder);

    }
};

// Method 2 : Using Postorder 
// Logic : largest value of left subtree(Inorder predecessor) must be less than root.val and smallest value of right subtree(Inorder successor) must be greater than root.val
class Result{
    public:
        bool status; // isBST
        long long int mini;
        long long int maxi;

        Result(bool status,long long int mini,long long int maxi){
            this->status = status;
            this->mini = mini;
            this->maxi = maxi;
        }
};


class Solution {
public:

    Result* solution(TreeNode* root) {
        if (root == nullptr) {
            return new Result(true, LLONG_MAX, LLONG_MIN);
        }

        Result* left_rec_ans = solution(root->left);
        Result* right_rec_ans = solution(root->right);

        bool curr_status = true;
        if (left_rec_ans->maxi >= root->val) {
            curr_status = false;
        }
        if (right_rec_ans->mini <= root->val) {
            curr_status = false;
        }

        bool final_status = curr_status && left_rec_ans->status && right_rec_ans->status;
        int final_mini = min((long long int)root->val, min(left_rec_ans->mini, right_rec_ans->mini));
        int final_maxi = max((long long int)root->val, max(left_rec_ans->maxi, right_rec_ans->maxi));

        return new Result(final_status, final_mini, final_maxi);
    }

    bool isValidBST(TreeNode* root) {
        return solution(root)->status;
    }
};