#include <iostream>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



class compare{
    public:
        bool operator()(ListNode* a,ListNode* b){
            return a->val > b->val;
        }
};

class Solution {
public:
    void insertAtTail(ListNode* &head,ListNode* &tail,ListNode* &newNode){
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int totalRows = lists.size();
        ListNode* head = NULL;
        ListNode* tail = NULL;

        priority_queue<ListNode*,vector<ListNode*>,compare> pq;

        // Initial state
        for(int i=0;i<totalRows;i++){
            if(lists[i] != NULL){
                pq.push(lists[i]);
            }
        }

        // process
        while(!pq.empty()){
            // remove front
            ListNode* front = pq.top();
            pq.pop();

            // insertAtTail
            insertAtTail(head,tail,front);

            // check whether more elemnts are present in the front LL.
            if(front->next != NULL){
                pq.push(front->next);
            }
        }

        return head;
    }
};
