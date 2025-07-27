#include <iostream>
#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};




class Solution {
public:
    // Method 2 : TC:O(n) , SC:O(1)
    Node* solve2(Node* head){
        if(head == NULL){
            return NULL;
        }

        // Step 1 : Create a LL : A->Aclone
        Node* ptr = head;
        while(ptr != NULL){
            Node* cloneNode = new Node(ptr->val);
            cloneNode->next = ptr->next;
            ptr->next = cloneNode;
            ptr = ptr->next->next;
        }

        // Step 2 : Assign random links
        ptr = head;
        while(ptr != NULL){
            Node* clonePtr = ptr->next;
            clonePtr->random = (ptr->random) ? (ptr->random->next) : NULL;
            ptr = ptr->next->next;
        }

        // Step 3 : Detach old and cloned LL
        ptr = head;
        Node* cloneHead = ptr->next;
        while(ptr != NULL){
            Node* clonePtr = ptr->next;
            ptr->next = clonePtr->next;
            if(clonePtr->next)
                clonePtr->next = clonePtr->next->next;
            ptr = ptr->next;
        }
        return cloneHead;
    }
    
    // Method 1 : // TC :O(n), SC:O(n) ,Best way of coding
    Node* solve(Node* ptr,unordered_map<Node*,Node*> &mapping){
        // base case
        if(ptr == NULL){
            return NULL;
        }
        // 1 case me solve remaining recursion will handle
        Node* newNode = new Node(ptr->val);
        mapping[ptr] = newNode;
        Node* recHead = solve(ptr->next,mapping);
        // Backtrack
        newNode->next = recHead;
        if(ptr->random != NULL){
            newNode->random = mapping[ptr->random];
        }else{
            newNode->random = NULL;
        }
        return newNode;
    }

    Node* copyRandomList(Node* head) {
        // unordered_map<Node*,Node*> mapping; // originalAddress -> newAddress
        // Node* cloneHead = solve(head,mapping);
        // return cloneHead;

        return solve2(head);
    }
};

// Method 1: Worst way of coding
class Solution {
public:
    void solve(Node* ptr,Node* temp,unordered_map<Node*,Node*> &mapping){
        // base case
        if(ptr == NULL){
            temp->next = NULL;
            return;
        }
        // 1 case me solve remaining recursion will handle
        Node* newNode = new Node(ptr->val);
        temp->next = newNode;
        temp = newNode;
        mapping[ptr] = temp;
        solve(ptr->next,temp,mapping);
        // Backtrack
        if(ptr->random != NULL){
            temp->random = mapping[ptr->random];
        }else{
            temp->random = NULL;
        }
    }

    Node* copyRandomList(Node* head) {
        if(head == NULL){
            return NULL;
        }
        Node* finalHead = new Node(head->val);
        Node* temp = finalHead;
        unordered_map<Node*,Node*> mapping;
        mapping[head] = temp;
        solve(head->next,temp,mapping);
        if(head->random != NULL){
            finalHead->random = mapping[head->random];
        }
        else{
            finalHead->random = NULL;
        }
        return finalHead;
    }
};