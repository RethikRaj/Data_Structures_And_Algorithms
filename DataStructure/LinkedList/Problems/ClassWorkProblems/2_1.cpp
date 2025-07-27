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
    ListNode* findMiddle(ListNode* head,ListNode* &prevToMid){
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

    ListNode* deleteMiddle(ListNode* head) {
        ListNode* prevToMid = NULL;
        ListNode* mid = findMiddle(head,prevToMid);
        if(prevToMid == NULL){
            // mid is at head
            head = head->next;
            mid->next = NULL;
            delete mid;
        }else{
            prevToMid->next = mid->next;
            mid->next = NULL;
            delete mid;
        }

        return head;
    }
};
