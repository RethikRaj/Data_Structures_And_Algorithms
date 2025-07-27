#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};


// Method 2 :
void insertAtTail(Node* &toMove,Node* &head,Node* &tail){
    if(head == NULL){
        head = tail = toMove;
    }else{
        tail->next = toMove;
        tail = toMove;
    }
}

Node* sortList(Node *head){
    // Initailize 3 separate LL to segregate 0's ,1's and 2's
    Node* zeroHead = NULL;
    Node* zeroTail = NULL;
    Node* oneHead = NULL;
    Node* oneTail = NULL;
    Node* twoHead = NULL;
    Node* twoTail = NULL;
    
    // traverse and create the 3 LL 
    Node* temp = head;
    while(temp != NULL){
        Node* toMove = temp;
        // update temp
        temp = temp->next;
        // isolate toMove
        toMove->next = NULL;
        
        // insert at Tail based on data
        if(toMove->data == 0){
            insertAtTail(toMove,zeroHead,zeroTail);
        }else if(toMove->data == 1){
            insertAtTail(toMove,oneHead,oneTail);
        } else if (toMove->data == 2) {
            insertAtTail(toMove, twoHead, twoTail);
        }
    }

    // Now merge these three LL => VIMP
    if(zeroHead != NULL){
        // zeroList is nonempty
        if(oneHead != NULL){
            // oneList is non-empty
            zeroTail->next = oneHead;
            oneTail->next = twoHead;
        }else{
            // oneList is empty;
            zeroTail->next = twoHead;
        }
        return zeroHead;
    }
    else{
        // zeroList is empty 
        if(oneHead != NULL){
            // oneList is non-empty
            oneTail->next = twoHead;
            return oneHead;
        }else{
            // oneList is empty
            return twoHead;
        }
    }
    
}


// Method 1 : Counting