#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void solveRecursive(ListNode* ptr,vector<int> &ans,stack<int> &s){
        if(ptr == NULL){
            return;
        }
        // go till last
        // recursion
        solveRecursive(ptr->next,ans,s);
        // 1 case
        int curr = ptr->val;
        while(!s.empty() && s.top() <= curr){
            s.pop();
        }
        // store ans which is at the top of stack
        if(s.top() == INT_MAX){
            ans.push_back(0);
        }else{
            ans.push_back(s.top());
        }

        // push curr
        s.push(curr);
    }

    ListNode* reverseLL(ListNode* ptr){
        ListNode* prev = NULL;
        ListNode* curr = ptr;
        while(curr != NULL){
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }

    void solveIterative(ListNode* head,vector<int> &ans){
        // step1 : Reverse
        head = reverseLL(head);

        // step 2 : FIND PGE (previous greater element)
        stack<int> s;
        s.push(INT_MAX);
        ListNode* ptr = head;
        while(ptr != NULL){
            int curr = ptr->val;
            while(!s.empty() && s.top() <= curr){
                s.pop();
            }
            // store ans
            if(s.top() == INT_MAX){
                ans.push_back(0);
            }else{
                ans.push_back(s.top());
            }
            // push curr
            s.push(curr);
            ptr = ptr->next;
        }
    }

    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        if(head == NULL){
            return ans;
        }

        // recursive solution
        // stack<int> s;
        // s.push(INT_MAX);
        // solveRecursive(head,ans,s);
        // reverse(ans.begin(),ans.end()); // since i am doing push_back in code reverse in needed
        // return ans;

        // iterative solution
        solveIterative(head,ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};