#include <iostream>
#include <stack>

using namespace std;

struct Node{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};


class Solution{
    public:
    // TC: O(n),SC:O(1)
    Node* reverseDLL(Node * head){
        Node* prev = NULL;
        Node* curr = head;
        while(curr != NULL){
            Node* forward = curr->next;
            curr->next = prev;
            curr->prev = forward;
            prev = curr;
            curr = forward;
        }
        return prev;
    }

    // Method 2 : Using stack : TC :O(n),SC:O(n)
    Node* reverse_DLL(Node* head){
        Node* temp = head;
        stack<int> s;
        while(temp != nullptr){
            s.push(temp->data);
            temp = temp->next;
        }
        temp = head;
        while(temp != nullptr){
            temp->data = s.top();
            s.pop();
            temp = temp->next;
        }
        return head;
    }
};