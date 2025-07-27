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


// Using the method learnt from segragate question
// TC : O(n) , SC : O(1)
class Solution {
public:
    ListNode* insertAtTail(ListNode* &head,ListNode* &tail,ListNode* toMove){
        if(head == NULL){
            head = toMove;
            tail = toMove;
        }else{
            tail->next = toMove;
            tail = toMove;
        }    
        return head;
    }

    ListNode* oddEvenList(ListNode* head) {
        ListNode* oddHead = NULL;
        ListNode* oddTail = oddHead;
        ListNode* evenHead = NULL;
        ListNode* evenTail = oddHead;
        
        ListNode* ptr = head;
        int count = 0;
        
        while(ptr != NULL){
            count++;
            ListNode* forward = ptr->next;
            ptr->next = NULL;
            if((count&1) == 0){
                head = insertAtTail(evenHead,evenTail,ptr);
            }else{
                head = insertAtTail(oddHead,oddTail,ptr);
            }
            
            ptr = forward;
        }
        
        if(oddHead != NULL){
            oddTail->next = evenHead;
            return oddHead;
        }else{
            return evenHead;
        }
    }
};



// TC : O(n) , SC:O(1)
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* store = head->next;
        ListNode* ptr1 = head;
        ListNode* ptr2 = head->next;

        while(ptr2!= NULL && ptr2->next != NULL){
            ptr1->next = ptr2->next;
            ptr2->next = ptr2->next->next;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        ptr1->next = store;
        return head;
    }   
};