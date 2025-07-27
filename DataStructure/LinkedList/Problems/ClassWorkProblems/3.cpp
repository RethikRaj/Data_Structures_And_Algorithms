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
    ListNode* getMiddle(ListNode* head,ListNode* &prevToMid){
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL){
            // move fast 1 step
            fast = fast->next;
            // check null
            if(fast != NULL){
                // move fast 1 step
                fast = fast->next;
                // since now fast has moved 2 steps
                // update prevToMid
                prevToMid = slow;
                // update slow
                slow = slow->next;
            }
        }
        return slow;
    }

    ListNode* reverseList(ListNode* mid){
        ListNode* prev = NULL;
        ListNode* curr = mid;

        while(curr != NULL){
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {
        // LL is empty 
        if(head == NULL){
            return true;
        }
        // Single element
        if(head->next == NULL){
            return true;
        }

        
        // getMiddle and prevToMid;
        ListNode* prevToMid = NULL;
        ListNode* mid = getMiddle(head,prevToMid);

        // Dissociate
        prevToMid->next = NULL;
        
        // reverse 2nd half , that is , from mid to end;
        ListNode* secondHalfHead = reverseList(mid);

        ListNode* ptr1 = head;
        ListNode* ptr2 = secondHalfHead;

        // since always length of firsthalf <= length of secondhalf => while comparing it is enough to have condition that ptr1 != NULL instead of having(ptr != NULL && ptr2 != NULL)
        while(ptr1 != NULL){
            if(ptr1->val != ptr2->val){
                return false;
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        } 
        return true;
    }
};