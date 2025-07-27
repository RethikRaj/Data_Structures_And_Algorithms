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
    // Recursive standard way
    ListNode* solve(ListNode* ptr1,ListNode* ptr2){
        // Base case
        if(ptr1 == NULL) return ptr2;
        if(ptr2 == NULL) return ptr1;
        // 1 case me solve remaining recurion
        ListNode* temp = NULL;
        if(ptr1->val < ptr2->val){
            temp = ptr1;
            temp->next = solve(ptr1->next,ptr2);
        }
        else{
            temp = ptr2;
            temp->next = solve(ptr1,ptr2->next);
        }
        return temp;
    }

    // standard way to do
    ListNode* method2(ListNode* list1, ListNode* list2){
        if(list1 == NULL){
            return list2;
        }
        if(list2 == NULL){
            return list1;
        }

        ListNode* finalHead = new ListNode(INT_MIN); // imp : if initialized with NULL then i need to handle it separately so its easier this way
        ListNode* temp = finalHead;

        ListNode* ptr1 = list1;
        ListNode* ptr2 = list2;

        while(ptr1 != NULL && ptr2 != NULL){
            if(ptr1->val < ptr2->val){
                temp->next = ptr1;
                ptr1 = ptr1->next;
                temp = temp->next;
            }else{
                temp->next = ptr2;
                ptr2 = ptr2->next;
                temp = temp->next;
            }
        }
        // 2 cases psbl
        if(ptr1 != NULL){
            temp->next = ptr1;
        }
        if(ptr2 != NULL){
            temp->next = ptr2;
        }

        // finalHead->next is our ans
        return finalHead->next;
    }


    // based on my dry run : Not needed
    ListNode* method1(ListNode* list1, ListNode* list2){
        if(list1 == NULL){
            return list2;
        }
        if(list2 == NULL){
            return list1;
        }

        // Initialising pointers
        ListNode* finalHead = list1;
        ListNode* ptrMin = list1;
        ListNode* ptrMax = list2;
        if(list1->val > list2->val){
            finalHead = list2;
            ptrMin = list2;
            ptrMax = list1;
        }

        while(ptrMin->next != NULL){
            if(ptrMax->val < ptrMin->next->val){
                ListNode* forward = ptrMin->next;
                ptrMin->next = ptrMax;
                ptrMin = ptrMin->next;
                ptrMax = forward;
            }else{
                ptrMin = ptrMin->next;
            }
        } 
        // Out of loop -> connect;
        ptrMin->next = ptrMax;

        return finalHead;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //return method1(list1,list2);

        //return method2(list1,list2);

        return solve(list1,list2);
    }
};