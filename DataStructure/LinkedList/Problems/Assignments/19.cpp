#include <iostream>

using namespace std;

struct Node{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

// Recursive idea of two pointers
class Solution1{
    public:
    int getLength(Node* ptr){
        int len = 0;
        while(ptr != NULL){
            len++;
            ptr = ptr->next;
        }
        return len;
    }

    void solve(Node* &left,Node* right,int &count){
        if(right == NULL){
            return;
        }
        solve(left,right->next,count);
        if(count != 0){
            int temp = left->data;
            left->data = right->data-left->data;
            right->data = temp;
            left = left->next;
            count--;
        }
    }
    
    struct Node* modifyTheList(struct Node *head){
        // base case
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        int len = getLength(head);
        Node* ptr = head;
        int count = len/2;
        solve(ptr,ptr,count);
        return head;
        
    }
};


// Iterative solution
class Solution2{
    public:
    Node* reverseLL(Node* head){
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
    
    struct Node* modifyTheList(struct Node *head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        // step1 :find middle
        Node* slow = head;
        Node* fast = head->next;
        while(fast != NULL){
            fast = fast->next;
            if(fast != NULL){
                fast = fast->next;
                slow = slow->next;
            }
        }
        // slow points to 1st middle in even and mid node in odd
        // step 2:break LL
        Node* afterMid = slow->next;
        slow->next = NULL;
        
        // step 3 :reverse the second part of LL
        afterMid = reverseLL(afterMid);
        
        // step 4:solving
        Node* ptr1 = head;
        Node* ptr2 = afterMid;
        while(ptr1 != NULL && ptr2 != NULL){
            int temp = ptr1->data;
            ptr1->data = ptr2->data-ptr1->data;
            ptr2->data = temp;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        
        // step 5 :reverse the second part of LL
        afterMid = reverseLL(afterMid);
        
        // step 6 :merge
        ptr1 = head;
        while(ptr1->next != NULL){
            ptr1 = ptr1->next;
        }
        ptr1->next = afterMid;
        
        return head;
    }
};