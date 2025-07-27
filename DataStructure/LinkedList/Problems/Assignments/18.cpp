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

// Changing Links : ALL in one solution
class Solution {
public:
    void solve(ListNode* ptr,int &indexFromStart,int &indexFromEnd,ListNode* &bwd1,ListNode* &kThNodeFromStart,ListNode* &bwd2,ListNode* &kThNodeFromEnd,int k){
        // base case
        if(!ptr) return;

        // 1 case me solve remaining recursion will handle
        cout << ptr->val << endl;
        if(indexFromStart == k-1){
            bwd1 = ptr;
        }else if(indexFromStart == k){
            kThNodeFromStart = ptr;
        }
        indexFromStart++;
        solve(ptr->next,indexFromStart,indexFromEnd,bwd1,kThNodeFromStart,bwd2,kThNodeFromEnd,k);
        cout << ptr->val << endl;
        if(indexFromEnd == k+1){
            bwd2 = ptr;
        }else if(indexFromEnd == k){
            kThNodeFromEnd = ptr;
        }
        indexFromEnd++;
    }

    ListNode* swapNodes(ListNode* head, int k) {
        if(!head){return NULL;}

        // set pointers : Here i used recursion refer next solution for iterative 
        int indexFromStart = 1;
        int indexFromEnd = 1;
        ListNode* bwd1 = NULL;
        ListNode* kThNodeFromStart = NULL;
        ListNode* bwd2 = NULL;
        ListNode* kThNodeFromEnd = NULL;
        solve(head,indexFromStart,indexFromEnd,bwd1,kThNodeFromStart,bwd2,kThNodeFromEnd,k);
        ListNode* fwd1 = kThNodeFromStart->next;
        ListNode* fwd2 = kThNodeFromEnd->next;

       

        if(bwd1 == NULL){
            head =  kThNodeFromEnd;
        }else{
            bwd1->next = kThNodeFromEnd;
        }   
        if(kThNodeFromEnd == fwd1){
            kThNodeFromEnd->next = kThNodeFromStart;
        }else{
            kThNodeFromEnd->next = fwd1;
        }
        if(bwd2 == NULL){
            head = kThNodeFromStart;
        }else{
            bwd2->next = kThNodeFromStart;
        }   
        if(kThNodeFromStart == fwd2){
            kThNodeFromStart->next =  kThNodeFromEnd;
        }else{
            kThNodeFromStart->next = fwd2;
        }
        return head;
    }
};

// Changing links
class Solution {
public:
    int getLength(ListNode* ptr){
        if(ptr == NULL){
            return 0;
        }
        return 1+getLength(ptr->next);
    }

    ListNode* swapNodes(ListNode* head, int k) {
        int n = getLength(head);
        int lpos = k;
        int rpos = n-k+1;
        if(rpos < lpos){
            swap(lpos,rpos);
        }
        // case 1
        if(head == NULL || head->next == NULL){
            return head;
        }
        // case 2
        if(lpos == rpos){
            return head;
        }

        // case 3 
        if(n == 2){
            ListNode* ptr = head->next;
            ptr->next = head;
            head->next = NULL;
            head = ptr;
            return head;
        }

        // set pointers
        ListNode* bwd1 = NULL;
        ListNode* ptr1 = head;
        ListNode* fwd1 = NULL;
        ListNode* bwd2 = NULL;
        ListNode* ptr2 = head;
        ListNode* fwd2 = NULL;

        for(int i=0;i<lpos-1;i++){
            bwd1 = ptr1;
            ptr1 = ptr1->next;
        }

        for(int i=0;i<rpos-1;i++){
            bwd2 = ptr2;
            ptr2 = ptr2->next;
        }
        fwd1 = ptr1->next;
        fwd2 = ptr2->next;
        

        // case 4
        if(lpos == 1){
            cout << "HI " << fwd2;
            // k == 1 or k == n
            ptr2->next = fwd1;
            bwd2->next = ptr1;
            ptr1->next = fwd2;
            head = ptr2;
            return head;
        }

        int noOfNodesBetweenSwappingNodes = rpos-lpos-1;
        // case 5
        if(noOfNodesBetweenSwappingNodes == 0){
            bwd1->next = ptr2;
            ptr2->next = ptr1;
            ptr1->next = fwd2;
            return head;
        }else{
            // case 6 : general case
            bwd1->next = ptr2;
            ptr2->next = fwd1;
            bwd2->next = ptr1;
            ptr1->next = fwd2;
            return head;
        }

    }
};

// Brute Force Solution
class Solution {
public:
    // Recursive Brute Force solution
    void solve(ListNode* ptr,int &indexFromStart,int &indexFromEnd,ListNode* &kThNodeFromStart,ListNode* &kThNodeFromEnd,int k){
        if(ptr == NULL){return;}

        if(indexFromStart == k){
            kThNodeFromStart = ptr;
        }
        indexFromStart++;
        solve(ptr->next,indexFromStart,indexFromEnd,kThNodeFromStart,kThNodeFromEnd,k);
        if(indexFromEnd == k){
            kThNodeFromEnd = ptr;
        }
        indexFromEnd++;
    }

    // Iterative Brute Force
    int getLength(ListNode* head){
        ListNode* ptr = head;
        int len = 0;
        while(ptr != NULL){
            len++;
            ptr = ptr->next;
        }
        return len;
    }

    void swapNodesIterative(ListNode* head, int k) {
        int n = getLength(head);
        int index = 1;
        ListNode* ptr = head;
        int maximum = max(k,n-k+1);
        int minimum = min(k,n-k+1);
        ListNode* nodeA = NULL;
        ListNode* nodeB = NULL;
        while(index < maximum){
            if(index == minimum){
                nodeA = ptr;
            }
            index++;
            ptr = ptr->next;
        }
        nodeB = ptr;

        if(nodeA && nodeB){
            int temp = nodeA->val;
            nodeA->val = nodeB->val;
            nodeB->val = temp;
        }
        
        //return head;
    }

    // Main
    ListNode* swapNodes(ListNode* head, int k) {
        if(head == NULL){
            return NULL;
        }

        // int indexFromStart = 1;
        // int indexFromEnd = 1;
        // ListNode* kThNodeFromStart = NULL;
        // ListNode* kThNodeFromEnd = NULL;
        // solve(head,indexFromStart,indexFromEnd,kThNodeFromStart,kThNodeFromEnd,k);
        // int temp = kThNodeFromStart->val;
        // kThNodeFromStart->val = kThNodeFromEnd->val;
        // kThNodeFromEnd->val = temp;
        // return head;


        swapNodesIterative(head,k);
        return head;
    }
};