#include <iostream>
#include <vector>
#include <math.h>
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
        int count = 0;
        while(ptr != NULL){
            ptr = ptr->next;
            count++;
        }
        return count;
    }

    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int length = getLength(head);
        vector<ListNode*> ans(k);

        if(head == NULL){
            return ans;
        }

        int remainingNodes = length;
        int remainingParts = k;
        
        for(int i=0;i<k;i++){
            ListNode* ptr = head;
            if(ptr == NULL){
                break;
            }
            int toMove = ceil(((float)remainingNodes/remainingParts))-1;
            for(int i=0;i<toMove;i++){
                ptr = ptr->next;
            }
            
            ListNode* forward = ptr->next;
            ptr->next = NULL;
            ans[i] = head;
            head = forward;
           
            remainingNodes -= (toMove+1);
            remainingParts -= 1;
        }

        return ans;
    }
};