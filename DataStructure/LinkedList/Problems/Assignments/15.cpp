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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans(2,-1);
        if(head == NULL || head->next == NULL || head->next->next == NULL){
            return ans;
        }
        // Atleast 3 nodes is present
        ListNode* prev = head;
        ListNode* ptr = head->next;
        int firstCPIndex = -1;
        int lastCPIndex = -1;
        int noOfCP = 0;
        int index = 0;
        int minDistanceBetweenCPTillNow = INT_MAX;
        while(ptr->next != NULL){
            bool isCP = ((prev->val < ptr->val && ptr->next->val < ptr->val) || (prev->val > ptr->val && ptr->next->val > ptr->val));
            if(isCP){
                noOfCP++;
                if(noOfCP == 1){
                    firstCPIndex = index;
                }
                else{
                    // only when noOfCP >= 2 we need to update minDistanceBetweenCP
                    minDistanceBetweenCPTillNow = min(minDistanceBetweenCPTillNow,index-lastCPIndex);
                }
                lastCPIndex = index;
            }
            // updating
            index++;
            prev = ptr;
            ptr = ptr->next;
        }
        if(noOfCP < 2){
            return ans;
        }else{
            ans[0] = minDistanceBetweenCPTillNow;
            ans[1] = lastCPIndex-firstCPIndex;
            return ans;
        }
    }
};