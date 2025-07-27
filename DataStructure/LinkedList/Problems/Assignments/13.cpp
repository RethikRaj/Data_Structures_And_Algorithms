#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node *next, *prev;
    Node(int val){
        this->data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class Solution{
public:
    Node * removeDuplicates(struct Node *head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        Node* ptr = head;
        while(ptr != NULL && ptr->next != NULL){
            if(ptr->data == ptr->next->data){
                Node* toDelete = ptr->next;
                ptr->next = toDelete->next;
                if(toDelete->next != NULL)
                    toDelete->next->prev = ptr;
                toDelete->next = NULL;
                toDelete->prev = NULL;
                delete toDelete;
            }
            else{
                ptr = ptr->next;
            }
        }
        return head;
    }
};
