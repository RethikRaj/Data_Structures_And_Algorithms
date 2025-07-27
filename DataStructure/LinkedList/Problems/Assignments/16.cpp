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

class Solution {
public:
    // Method 1
    ListNode* mergeNodes(ListNode* head) {
        ListNode* finalHead = new ListNode(INT_MIN);
        ListNode* temp = finalHead;

        ListNode* ptr = head->next;
        int sum = 0;
        while(ptr != NULL){
            if(ptr->val != 0){
                sum = sum + ptr->val;
            }
            else{
                ListNode* newNode = new ListNode(sum);
                temp->next = newNode;
                temp = temp->next;
                sum = 0;
            }
            ptr = ptr->next;
        }

        return finalHead->next;
    }

    // Method 2 
    ListNode* mergeNodes(ListNode* head) {
        ListNode* newLastNode = NULL;
        ListNode* slow = head;
        ListNode* fast = head->next;
        int sum = 0;
        while(fast != NULL){
            if(fast->val != 0){
                sum += fast->val;
            }
            else{
                slow->val = sum;
                sum = 0;
                newLastNode = slow;
                slow = slow->next;
            }
            fast = fast->next;
        }

        newLastNode->next = NULL;

        while(slow != NULL){
            ListNode* forward = slow->next;
            delete slow;
            slow = forward;
        }
        return head;
    }
};