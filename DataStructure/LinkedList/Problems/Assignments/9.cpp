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


// Method 2 : Observations : newLastNode , newHead , oldTail connect to head;
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

    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        int n = getLength(head);
        k = k%n;
        if(k==0){return head;}
        // find newLastNode and newHead;
        ListNode* newLastNode = head;
        for(int i=0;i<n-k-1;i++){
            newLastNode = newLastNode->next;
        }
        ListNode* newHead = newLastNode->next;
        newLastNode->next = NULL;

        // move to oldtail and connect oldtail to head;
        ListNode* ptr = newHead;
        while(ptr->next != NULL){
            ptr =ptr->next;
        }
        ptr->next = head;

        // Update head to newHead
        head = newHead;

        return newHead;
    }
};


// Method 1 : Reversing Method
class Solution {
public:
    ListNode* reverse(ListNode* head){
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

    int getLength(ListNode* head){
        ListNode* ptr = head;
        int len = 0;
        while(ptr != NULL){
            len++;
            ptr = ptr->next;
        }
        return len;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        int n = getLength(head);
        k = k%n;
        // Move n-k times
        ListNode* backward = NULL;
        ListNode* ptr = head;
        for(int i=0;i<n-k;i++){
            backward = ptr;
            ptr = ptr->next;
        }

        // Separate as two lists -> first n-k elements(head to backward), then next k elements (ptr to end)
        backward->next = NULL;
        // reverse from ptr to end;
        ListNode* rHead1 = reverse(head);
        ListNode* rHead2 = reverse(ptr);
        
        // assign pointers->Join reversed lists
        head->next = rHead2;
        head = rHead1;

        // reverse whole list again
        head = reverse(head);
        return head;
    }
};

