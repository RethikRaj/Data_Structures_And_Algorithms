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

    ListNode* removePosition(ListNode* head,int position){
        if(head == NULL){
            return NULL;
        }
        else if(position == 1){
            ListNode* temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
        }
        else{
            ListNode* temp = head;
            for(int i=0;i<position-2;i++){
                temp = temp->next;
            }
            ListNode* toDelete = temp->next;
            temp->next = toDelete->next;
            toDelete->next = NULL;
            delete toDelete;
        }
        return head;
    }

    // Method 2 : 
    ListNode* twoPointer(ListNode* head,int n){
        if(head == NULL){
            return NULL;
        }
        ListNode* fast = head;
        for(int i=0;i<n;i++){
            fast = fast->next;
        }
        ListNode* slow = head;

        if(fast == NULL){
            // the node to be deleted is head
            ListNode* temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
            return head;
        }

        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        // slow points to before node of the node to be deleted
        ListNode* toDelete = slow->next;
        slow->next = toDelete->next;
        toDelete->next = NULL;
        delete toDelete;

        return head;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // int length = getLength(head);
        // int position = length-n+1;

        // return removePosition(head,position);


        return twoPointer(head,n);

    }

};