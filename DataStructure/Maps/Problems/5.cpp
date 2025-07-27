#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Node{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};


class Solution {
  public:
    struct Node* makeUnion(struct Node* head1, struct Node* head2) {
        map<int,Node*> mp;
        
        Node* ptr = head1;
        while(ptr != NULL){
            mp[ptr->data] = ptr;
            ptr = ptr->next;
        }
        
        ptr = head2;
        while(ptr != NULL){
            mp[ptr->data] = ptr;
            ptr = ptr->next;
        }
        
        Node* head = NULL;
        Node* tail = NULL;
        
        for(auto it : mp){
            if(head == NULL){
                head = it.second;
                tail = it.second;
            }else{
                tail->next = it.second;
                tail = it.second;
            }
        }
        
        tail->next = NULL; // imp step
        
        return head;
        
    }
};

