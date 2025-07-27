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
    ListNode* deleteDuplicates(ListNode* head) {
        // LL is empty
        if(head == NULL){
            return head;
        }
        // single node
        if(head->next == NULL){
            return head;
        }
        // atleast 2 nodes in LL
        ListNode* prev = head;
        ListNode* temp = head->next;
        while(temp != NULL){
            if(prev->val == temp->val){
                prev->next = temp->next;
                temp->next = NULL;
                delete temp;
                // update temp : Imp
                temp = prev->next;
            }else{
                prev = prev->next;
                temp = temp->next;
            }
        }

        return head;
    }
};
