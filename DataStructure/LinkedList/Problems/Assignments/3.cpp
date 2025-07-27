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

// Best Method : without need of high pointer
// TC : 
class Solution {
public:
    ListNode* getMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next; // Important ,because i needed 1st middle node in case of even
        while(fast != NULL){
            fast = fast->next;
            if(fast != NULL){
                fast = fast->next;
                slow = slow->next;
            }
        }
        return slow; 
    }

    ListNode* mergeTwoSortedLists(ListNode* head1,ListNode* head2){
        ListNode* ptr1 = head1;
        ListNode* ptr2 = head2;
        ListNode* finalHead = new ListNode(INT_MIN);
        ListNode* temp = finalHead;
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

        if(ptr1 != NULL){
            temp->next = ptr1;
        }
        if(ptr2 != NULL){
            temp->next = ptr2;
        }
        return finalHead->next;
    }

    ListNode* mergeSort(ListNode* head){
        // base case
        if(head == NULL || head->next == NULL){
            return head;
        }
        // 1 case me solve remaining recursion
        // divide
        ListNode* mid = getMiddle(head);
        ListNode* afterMid = mid->next;
        mid->next = NULL; // this step is needed so that while merging i can use NULL condition check

        // Solve->Sort
        ListNode* left = mergeSort(head);
        ListNode* right = mergeSort(afterMid);
        
        // Combine/conquer
        ListNode* mergeHead = mergeTwoSortedLists(left,right);
        return mergeHead;
    }

    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};


class Solution {
public:
    ListNode* getMiddle(ListNode* low,ListNode* high){
        ListNode* slow = low;
        ListNode* fast = low;
        while(fast != high){
            fast = fast->next;
            if(fast != high){
                fast = fast->next;
                slow = slow->next;
            }
        }
        return slow; 
    }

    ListNode* mergeTwoSortedLists(ListNode* head1,ListNode* head2){
        ListNode* ptr1 = head1;
        ListNode* ptr2 = head2;
        ListNode* finalHead = new ListNode(INT_MIN);
        ListNode* temp = finalHead;
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

        if(ptr1 != NULL){
            temp->next = ptr1;
        }
        if(ptr2 != NULL){
            temp->next = ptr2;
        }
        return finalHead->next;
    }

    ListNode* mergeSort(ListNode* low,ListNode* high){
        // base case
        if(low == high){
            return low;
        }
        // 1 case me solve remaining recursion
        // divide
        ListNode* mid = getMiddle(low,high);
        ListNode* afterMid = mid->next;
        mid->next = NULL; // this step is needed so that while merging i can use NULL condition check
        ListNode* head1 = mergeSort(low,mid);
        ListNode* head2 = mergeSort(afterMid,high);
        // Combine/conquer
        ListNode* ansHead = mergeTwoSortedLists(head1,head2);
        return ansHead;
    }

    ListNode* sortList(ListNode* head) {
        if(head == NULL){
            return head;
        }

        ListNode* low = head;
        ListNode* high = head;
        while(high->next != NULL){
            high = high->next;
        }
        head = mergeSort(low,high);
        return head;
    }
};
