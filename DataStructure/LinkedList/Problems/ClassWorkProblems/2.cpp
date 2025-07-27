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
    // method 2 : 
    ListNode* tortoiseHareMethod(ListNode* head){
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
                // update slow
                slow = slow->next;
            }
        }
        return slow;
    }


    // Method1 : 
    int getLength(ListNode* head){
        int length = 0;
        ListNode* ptr = head;
        while(ptr != NULL){
            length++;
            ptr = ptr->next;
        }
        return length;
    }

    ListNode* lengthFindAndProceedMethod(ListNode* head){
        int length = getLength(head);
        ListNode* ptr = head;
        for(int i=0;i<length/2;i++){
            ptr = ptr->next;
        }
        return ptr;
    }
    
    ListNode* middleNode(ListNode* head) {
        //return tortoiseHareMethod(head);
        return lengthFindAndProceedMethod(head);
    }
};

