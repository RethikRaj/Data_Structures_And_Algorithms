#include <iostream>
#include <unordered_set>

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

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL){
            return NULL;
        }
        
        int lenA = getLength(headA);
        int lenB = getLength(headB);
        // ptrMax points to LL with max length while ptrMin points to LL with min length
        ListNode* ptrMax = headA; 
        ListNode* ptrMin = headB;
        if(lenA < lenB){
            ptrMax = headB;
            ptrMin = headA;
        }
        
        // move ptrMax by abs(lenA-lenB);
        for(int i=0;i<abs(lenA-lenB);i++){
            ptrMax = ptrMax->next;
        }
        
        while(ptrMin != NULL && ptrMax != NULL){
            if(ptrMin == ptrMax){
                return ptrMin;
            }
            ptrMin = ptrMin->next;
            ptrMax = ptrMax->next;
        }
        return NULL;
    }
};


// Method 2:
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> mp;

        ListNode* ptr1 = headA;
        ListNode* ptr2 = headB;

        while(ptr1 != NULL && ptr2 != NULL){
            if(mp.find(ptr1) != mp.end()){
                return ptr1;
            }else{
                mp.insert(ptr1);
            }

            if(mp.find(ptr2) != mp.end()){
                return ptr2;
            }else{
                mp.insert(ptr2);
            }

            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        while(ptr1 != NULL){
            if(mp.find(ptr1) != mp.end()){
                return ptr1;
            }else{
                mp.insert(ptr1);
            }
            ptr1 = ptr1->next;
        }

        while(ptr2 != NULL){
            if(mp.find(ptr2) != mp.end()){
                return ptr2;
            }else{
                mp.insert(ptr2);
            }
            ptr2 = ptr2->next;
        }

        return NULL;
    }
};
