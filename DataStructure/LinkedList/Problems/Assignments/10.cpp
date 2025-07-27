#include <iostream>

using namespace std;


class SinglyLinkedListNode {
    public:
    int data;
    SinglyLinkedListNode* next;
};


// Method 1 : 
int getLength(SinglyLinkedListNode* head){
    SinglyLinkedListNode* ptr = head;
    int length = 0;
    while(ptr != NULL){
        length++;
        ptr = ptr->next;
    }
    return length;
}


int getNode(SinglyLinkedListNode* llist, int positionFromTail) {
    int length = getLength(llist);
    int index = length-positionFromTail-1;
    SinglyLinkedListNode* ptr = llist;
    for(int i=0;i<index;i++){
        ptr = ptr->next;
    }
    return ptr->data;
}


// Method 2 :
int getNode2(SinglyLinkedListNode* llist, int positionFromTail) {
    SinglyLinkedListNode* slow = llist;
    SinglyLinkedListNode* fast = llist;
    for(int i=0;i<positionFromTail+1;i++){
        fast = fast->next;
    }
    while(fast != NULL){
        fast = fast->next;
        slow = slow->next;
    }
    return slow->data;
}

// Method 3 : Using recursion
void solve(SinglyLinkedListNode* ptr,int positionFromTail,int &indexFromEnd,int &ans){
    if(ptr == NULL){
        return;
    }
    solve(ptr->next,positionFromTail,indexFromEnd,ans);
    indexFromEnd++;
    if(indexFromEnd == positionFromTail){
        ans = ptr->data;
    }
}

int getNode3(SinglyLinkedListNode* llist, int positionFromTail) {
   int indexFromEnd = -1;
   int ans = INT_MIN;
   solve(llist,positionFromTail,indexFromEnd,ans);
   return ans;
}
