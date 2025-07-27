#include <iostream>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Iterative solution by reversing ,then doubling, then reversing
class Solution {
public:
    ListNode* reverseLL(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr != NULL){
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }

    ListNode* doubleIt(ListNode* head) {
        // Step 1 : Reverse LL
        head = reverseLL(head);
        
        // Step 2 : multiply by 2
        int carry = 0;
        ListNode* ptr = head;
        while(ptr != NULL){
            int product = ptr->val*2 + carry;
            int digit = product%10;
            carry = product/10;
            ptr->val = digit;
            if(ptr->next == NULL && carry != 0){
                ListNode* newNode = new ListNode(carry);
                ptr->next = newNode;
                ptr = newNode;
            }
            ptr =ptr->next;
        }
        
        // Step 3 : reverse LL;
        head = reverseLL(head);

        return head;
    }
};

// Recursive solution
class Solution {
public:
    void solve(ListNode* ptr,int &carry){
        // base case
        if(ptr == NULL){
            return;
        }
        // 1 case me solve remaining recursion handles
        solve(ptr->next,carry);
        int product = ptr->val*2 + carry;
        int digit = product%10;
        carry = product/10;
        ptr->val = digit;
    }

    ListNode* doubleIt(ListNode* head) {
        int carry = 0;
        solve(head,carry);
        if(carry != 0){
            ListNode* newNode = new ListNode(carry);
            newNode->next = head;
            head = newNode;
        }
        return head;
    }
};

