#include <iostream>
#include <unordered_map>

using namespace std;


class Solution {
public:
    void sanitizeMap(ListNode* temp,unordered_map<int,ListNode*> &mp,int currSum){
        int currSum2 = currSum;
        while(true){
            currSum2 += temp->val;
            if(currSum == currSum2){
                break;
            }
            mp.erase(currSum2);
            temp = temp->next;
        }
    }

    ListNode* removeZeroSumSublists(ListNode* head) {
        // Corner cases
        if(head == NULL){
            return NULL;
        }
        if(head->next == NULL && head->val == 0){
            return NULL;
        }

        unordered_map<int,ListNode*> mp;
        ListNode* ptr = head;
        int currSum = 0;
        while(ptr != NULL){
            currSum += ptr->val;
            if(currSum == 0){
                head = ptr->next;
                mp.clear();
            }else if(mp.find(currSum) != mp.end()){
                // currSum found in map
                ListNode* oldNode = mp[currSum];
                sanitizeMap(oldNode->next,mp,currSum);
                oldNode->next = ptr->next;
            }else{
                mp[currSum] = ptr;
            }
            ptr = ptr->next;
        }

        return head;
    }
};