#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

bool isCycle(struct Node* &slow,struct Node* &fast){
    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        if(fast == slow){
            return true;
        }
    }
    return false;
}

int countNodesinLoop(struct Node *head){
    struct Node* slow = head;
    struct Node* fast = head;
    
    bool isCyclePresent = isCycle(slow,fast);
    
    if(isCyclePresent){
        // fix slow and move fast but by one step at a time
        int count = 1;
        fast = fast->next;
        while(fast != slow){
            count++;
            fast = fast->next;
        }
        return count;
    }
    else{
        return 0;
    }   
}
