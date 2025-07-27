#include <iostream>
#include <vector>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *right;
    TreeNode *left;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Sorted List => Using Inorder
// TC :O(n)
class Solution {
public:
    int getLength(ListNode* head){
        ListNode* ptr = head;
        int count = 0;
        while(ptr != NULL){
            count++;
            ptr = ptr->next;
        }
        return count;
    }

    TreeNode* solve(ListNode* &ptr,int n){
        // base case
        if(ptr == NULL || n <= 0){
            return NULL;
        }

        // 1 case me ssolve remainining recursion will handle
        // L
        TreeNode* leftSubTree = solve(ptr,n/2);
        // N
        TreeNode* newNode = new TreeNode(ptr->val);
        newNode->left = leftSubTree;
        // MIMP step => ptr is like index => Pass by reference (Refer question 9)
        ptr = ptr->next;
        // R
        TreeNode* rightSubTree = solve(ptr,n-n/2-1);
        newNode->right = rightSubTree;
        return newNode;
    }


    TreeNode* sortedListToBST(ListNode* head) {
        int n = getLength(head);
        TreeNode* root = solve(head,n);
        return root;
    }
};



// TC : O(n2)
class Solution {
public:

    ListNode* getMid(ListNode* head,ListNode* &prevToMid){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL){
            fast = fast->next;
            if(fast != NULL){
                fast = fast->next;
                prevToMid = slow;
                slow = slow->next;
            }
        }
        return slow;
    }

    TreeNode* solve(ListNode* head){
        // base case
        if(head == NULL){
            return NULL;
        }
        
        //  1 case me solve remaininig recursion will handle
       
        ListNode* prevToMid = NULL;
        ListNode* mid  = getMid(head,prevToMid);

        TreeNode* newNode = new TreeNode(mid->val);


        // left recursion
        if(prevToMid != NULL){
            prevToMid->next = NULL;
            // recursion
            newNode->left = solve(head);
        }else{
            newNode->left = NULL;
        }

        // right recursion
        newNode->right = solve(mid->next);
        return newNode;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        TreeNode* root = solve(head);
        return root;
    }
};

