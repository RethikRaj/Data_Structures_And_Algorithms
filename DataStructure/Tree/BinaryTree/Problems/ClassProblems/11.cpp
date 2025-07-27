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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    bool dfs(TreeNode* ptr1, ListNode* ptr2){
        if(ptr2 == NULL){
            // path found
            return true;
        }
        if(ptr1 == NULL){
            return false;
        }

        if(ptr1->val == ptr2->val){
            // continue search
            bool leftRecAns = dfs(ptr1->left,ptr2->next);
            bool rightRecAns = dfs(ptr1->right,ptr2->next);

            return leftRecAns || rightRecAns;
        }else{
            return false;
        }
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        if(root == NULL){
            return false;
        }

        // check path from current node
        bool option1 = dfs(root,head);
        // check path starting from left of curr node
        bool option2 = isSubPath(head,root->left);
        // check path starting from right of curr node
        bool option3 = isSubPath(head,root->right);

        return option1 || option2 || option3;
    }
};
