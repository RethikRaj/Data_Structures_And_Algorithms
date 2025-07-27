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
        int length = 0;
        while(ptr != NULL){
            length++;
            ptr = ptr->next;
        }
        return length;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        // LL is empty
        if(head == NULL){
            return head;
        }
        // LL has single node
        if(head->next == NULL){
            return head;
        }
        
        // LL has atleast 2 nodes
        
        // Important will forget
        int length = getLength(head);
        if(length < k){
            // leave the nodes as it is -> Dont reverse them
            return head;
        }

        // 1 case me solve remaining recursion
        // 1 case is that i reverse 1 group->k nodes-> i need to reverse k links
        ListNode* prev = NULL;
        ListNode* curr = head;
        for(int i=0;i<k;i++){
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        // curr points to the start of the remaining LL
        // recursion
        if(curr != NULL){
            ListNode* recHead = reverseKGroup(curr,k);
            // connect
            head->next = recHead; 
        }
        // prev denotes the head of the total LL.
        return prev;
    }
};