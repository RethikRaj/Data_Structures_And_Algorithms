#include <iostream>
#include <unordered_map>

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
    // Method 2 :
    bool tortoiseHareMethod(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL){
            fast = fast->next;
            if(fast != NULL){
                fast = fast->next;
                slow = slow->next;
            }
            if(fast == slow){
                return true;
            }
        }
        return false;
    }

    // Method 1 :
    bool visitingMethod(ListNode* head){
        unordered_map<ListNode*,bool> mapping;
        ListNode* temp = head;  

        while(temp != NULL){
            if(mapping[temp] == true){
                // already visited node
                return true;
            }else{
                // unvisited node
                mapping[temp] = true;
            }
            temp = temp->next;
        }
        return false;
    }

    bool hasCycle(ListNode *head) {
        //return visitingMethod(head);

        return tortoiseHareMethod(head);
    }
};
