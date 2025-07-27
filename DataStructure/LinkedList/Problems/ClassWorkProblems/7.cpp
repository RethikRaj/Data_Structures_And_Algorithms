#include <iostream>
#include <vector>

using namespace std;

struct Node{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution{
    public:
    Node* reverse(Node* head){
        Node* prev = NULL;
        Node* curr = head;
        while(curr != NULL){
            Node* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }

    Node* addOne(Node *head) {
         // step 1 :reverse the list
        head = reverse(head);

        // step 2 : add one 
        Node* ptr = head;
        int carry = 1; // since we are adding one so lets take carry as one instead of zero
        while(ptr != NULL){
            int sum = ptr->data + carry;
            int digit = sum%10;
            carry = sum/10;
            ptr->data = digit;
            
            // Important will forget -> so dont
            if(ptr->next == NULL && carry != 0){
                Node* newNode = new Node(carry);
                ptr->next = newNode;
                ptr = newNode; // important
                // or do break;
            }
            
            ptr = ptr->next;
        }
        
        // step 3:reverse the list
        head = reverse(head);
        
        return head;
    }
};