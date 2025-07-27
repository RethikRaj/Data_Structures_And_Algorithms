#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node* bottom;
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->bottom = NULL;
    }
};


Node* mergeTwoSortedLists(Node* head1,Node* head2){
    if(!head1) return head2;
    if(!head2) return head1;
    
    Node* ptr1 = head1;
    Node* ptr2 = head2;
    Node* finalHead = new Node(INT_MIN);
    Node* temp = finalHead;
    while(ptr1 && ptr2){
        if(ptr1->data < ptr2->data){
            temp->bottom = ptr1;
            temp = temp->bottom;
            ptr1 = ptr1->bottom;
        }else{
            temp->bottom = ptr2;
            temp = temp->bottom;
            ptr2 = ptr2->bottom;
        }
    }
    if(ptr1){
        temp->bottom = ptr1;
    }
    if(ptr2){
        temp->bottom = ptr2;
    }
    return finalHead->bottom;
}

// merge from first -> method1
Node *flatten(Node *root) {
    // Base case
    if(root == NULL || root->next == NULL){
        return root;
    }
    // 1 case me solve remaining recursion will handle
    Node* ptr1 = root;
    Node* ptr2 = root->next;
    Node* mergeHead = mergeTwoSortedLists(ptr1,ptr2);
    mergeHead->next = root->next->next; // important step
    return flatten(mergeHead);
}

// method2 : merge from last
Node *flatten2(Node *root) {
    if(root == NULL){
        return root;
    }
    
    Node* ans = flatten2(root->next);
    Node* mergedHead = mergeTwoSortedLists(root,ans);
    return mergedHead;
}