#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};


class Solution{
  public:
    Node* findIntersection(Node* head1, Node* head2){
        unordered_set<int> list2;
        Node* ptr = head2;
        while(ptr != NULL){
            list2.insert(ptr->data);
            ptr = ptr->next;
        }
        
        ptr = head1;
        Node* finalHead = new Node(INT_MIN);
        Node* temp = finalHead;
        while(ptr != NULL){
            if(list2.count(ptr->data) == 1){
                
                temp->next = ptr;
                temp = temp->next;
            }
            ptr = ptr->next;
        }
        temp->next =  NULL;
        return finalHead->next;
    }

    // if duplicates present
    Node* findIntersectionDuplicate(Node* head1, Node* head2){
        unordered_map<int,int> mapping;
        Node* ptr = head2;
        while(ptr != NULL){
            mapping[ptr->data] += 1;
            ptr = ptr->next;
        }
        
        ptr = head1;
        Node* finalHead = new Node(INT_MIN);
        Node* temp = finalHead;
        while(ptr != NULL){
            if(mapping[ptr->data] != 0){
                temp->next = ptr;
                temp = temp->next;
                mapping[ptr->data] -= 1;
            }
            ptr = ptr->next;
        }
        temp->next = NULL; // important step dont forget
        return finalHead->next;
    }
};