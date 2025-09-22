#include <bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



class CustomComparator {
public:
    bool operator()(ListNode* &a, ListNode* &b) {
        return a->val > b->val; 
    }
};

class Solution {
public:
    void insertAtTail(ListNode* &head, ListNode* &tail, ListNode* &newNode) {
        if (head == NULL) {
            head = tail = newNode; // first node
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        ListNode* head = NULL;
        ListNode* tail = NULL;

        // Min-heap to always get the smallest node among current heads
        priority_queue<ListNode*, vector<ListNode*>, CustomComparator> pq;

        // 1. Process first k elements =>Push first node of each list into heap
        for (int i = 0; i < k; i++) {
            if (lists[i] != NULL){
                pq.push(lists[i]);
            }
        }

        // Build merged list => Extract min and push next node from same list
        while (!pq.empty()) {
            ListNode* curr = pq.top(); 
            pq.pop();

            insertAtTail(head, tail, curr); // attach smallest node

            if (curr->next != NULL){
                pq.push(curr->next); // push next node from same list
            }
        }

        return head; // merged sorted list
    }
};
