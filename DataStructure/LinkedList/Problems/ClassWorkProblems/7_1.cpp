#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};




class Solution {
public:
    int getLength(ListNode* head){
        ListNode* ptr = head;
        int len = 0;
        while(ptr != NULL){
            len++;
            ptr = ptr->next;
        }
        return len;
    }

    ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) {
        int len1 = getLength(head1);
        int len2 = getLength(head2);
        // Initialising pointers
        ListNode* ptrMax = head1;
        ListNode* ptrMin = head2;
        ListNode* finalHead = head1;
        if(len2 > len1){
            ptrMax = head2;
            ptrMin = head1;
            finalHead = head2;
        }
        // adding
        int carry = 0;
        while(ptrMin != NULL){
            int sum = ptrMin->val + ptrMax->val + carry;
            int digit = sum%10;
            carry = sum/10;
            ptrMax->val = digit;
            
            if(ptrMin->next == NULL && carry != 0){
                while(ptrMax->next != NULL){
                    ptrMax = ptrMax->next;
                    int sum_ = ptrMax->val + carry;
                    int digit_ = sum_%10;
                    carry = sum_/10;
                    ptrMax->val = digit_;
                }
                if(ptrMax->next == NULL && carry != 0){
                    ListNode* newNode = new ListNode(carry);
                    ptrMax->next = newNode;
                    ptrMax = newNode;
                }
            }
            
            ptrMin = ptrMin->next;
            ptrMax = ptrMax->next;
        }
        
        return finalHead;
    }
};
