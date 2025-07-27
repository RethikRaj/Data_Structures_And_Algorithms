#include <iostream>

using namespace std;

//  * Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseListRecursive(ListNode* &prev,ListNode* &curr){
        // Base Case
        if(curr == NULL){
            return prev;
        }
        // 1 case me solve remaining recursion takes care
        // 1 case -> 1 pointer reverse
        ListNode* forward = curr->next;
        curr->next = prev;
        // Update 
        prev = curr;
        curr = forward;
        // recursion
        return reverseListRecursive(prev,curr);
    }

    ListNode* reverseListIterative(ListNode* &head){
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL){
            ListNode* forward = curr->next;
            curr->next = prev;
            // Update 
            prev = curr;
            curr = forward;
        }

        return prev;
    }

    ListNode* reverseList(ListNode* head) {
        //return reverseListIterative(head);

        // revursive
        ListNode* prev = NULL;
        ListNode* curr = head;
        return reverseListRecursive(prev,curr);
    }
};