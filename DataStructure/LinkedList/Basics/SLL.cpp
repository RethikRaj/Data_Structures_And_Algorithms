#include <iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* next;

        // constructor
        Node(int value){
            this->data = value;
            this->next = NULL;
        }
};

// return the head of the LL after insertion (Although here it is not needed since i pass it by reference)
Node* insertAtHead(int value,Node* &head,Node* &tail){
    // LL is empty -> head and tail both points to null
    // Inserting first Node
    if(head == NULL && tail == NULL){
        // Create a new Node
        Node* newNode = new Node(value);
        // point head and tail to newNode
        head = newNode;
        tail = newNode;
    }
    else{// LL is not empty
        // Create a new Node
        Node* newNode = new Node(value);
        // connect this newNode to head node
        newNode->next = head;
        // update head to newNode;
        head = newNode;
    }

    return head;
}

// return the head of the LL after insertion (Although here it is not needed since i pass it by reference)
Node* insertAtTail(int value,Node* &head,Node* &tail){
    if(head == NULL && tail == NULL){
        // LL is empty
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
    }else{
        // LL is not empty
        Node* newNode = new Node(value);
        tail->next = newNode;
        tail = newNode;
    }
    return head;
}

void printLL(Node* ptr){
    while(ptr != NULL){
        cout << ptr->data << "->";
        ptr = ptr->next;
    }
    cout << "NULL" << endl; 
}

int getLength(Node* ptr){
    int len = 0;
    while(ptr != NULL){
        len++;
        ptr = ptr->next;
    }
    return len;
}

void insertAtPosition(int value,int position,Node* &head,Node* &tail){
    // assume ->valid positions is given that is position is [1,length+1].
    if(position == 1){
        head = insertAtHead(value,head,tail);
    }
    else if(position == getLength(head)+1){
        head = insertAtTail(value,head,tail);
    }else{
        
        Node* ptr = head;    
        // reach ptr to position-1 => do ptr = ptr->next (position-2 times)
        for(int i=0;i<position-2;i++){
            ptr = ptr->next;
        }
        // Create a new Node
        Node* newNode = new Node(value);
        newNode->next = ptr->next;
        ptr->next = newNode;
    }
}

// insertAtEnd(without using tail)
Node* insertAtEnd(Node *head, int x) {
    Node* ptr = head;
    // special case
    if(ptr == NULL){
        Node* newNode = new Node(x);
        head = newNode;
        return head;
    }
    // Reach to last node
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    // Create a new Node;
    Node* newNode = new Node(x);
    ptr->next = newNode;
    return head;
}


bool searchLL(Node* &head,int target){
    Node* ptr = head;
    while(ptr != NULL){
        if(ptr->data == target){
            return true;
        }
        ptr = ptr->next;
    }
    // if ireach here then i traversed entire LL and target is not found;
    return false;
}

int searchLLPosition(Node* &head,int target){
    Node* ptr = head;
    int pos = 1;
    while(ptr != NULL){
        if(ptr->data == target){
            return pos;
        }
        pos++;
        ptr = ptr->next;
    }
    return -1;
}

void deleteFromLL(Node* &head,int position){
    // LL is empty 
    if(head == NULL){
        cout << "There is nothing to delete" << endl;
        return;
    }
    else{
        // 2 cases 
        if(position == 1){
            Node *temp = head;
            head = temp->next;
            temp->next = NULL; // isolate the node to be deleted
            delete temp;
        }else{
            Node* prev = head;
            for(int i=0;i<position-2;i++){
                prev = prev->next;
            }
            Node* toDelete = prev->next;
            prev->next = toDelete->next;
            toDelete->next = NULL; // isolate the node to be deleted
            delete toDelete;
        }
    }
}

void deleteFromLLTarget(Node* &head,int target){
    int position = searchLLPosition(head,target);
    deleteFromLL(head,position);
}

// Method 2 to delete from LL given a target
Node* searchNode(Node* head,int x,Node* &prev){
    Node* ptr = head;
    while(ptr != NULL){
        if(ptr->data == x){
            return ptr;
        }
        // Update prev before moving ptr
        prev = ptr;
        ptr = ptr->next;
    }
    return NULL;
}

Node* deleteFromLLTarget2(Node* head, int x){
    Node* prev = NULL;
    Node* curr = searchNode(head,x,prev);
    if(curr == NULL){
        // element not found 
        return head;
    }
    else if(prev == NULL){
        // target is present at 0th index -> curr points to head
        head = curr->next;
        curr->next = NULL;
        delete curr;
    }
    else{
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
    return head;
}


int main(){
    Node* head= NULL;
    Node* tail = NULL;
    head = insertAtHead(10,head,tail);
    printLL(head);
    head = insertAtHead(20,head,tail);
    printLL(head);
    head = insertAtHead(30,head,tail);
    printLL(head);
    head = insertAtTail(140,head,tail);
    printLL(head);
    head = insertAtTail(150,head,tail);
    printLL(head);
    head = insertAtTail(160,head,tail);
    printLL(head);
    insertAtPosition(50,3,head,tail);
    printLL(head);
    insertAtPosition(1000,1,head,tail);
    printLL(head);
    insertAtPosition(2000,getLength(head)+1,head,tail);
    printLL(head);
    cout << searchLL(head,140) << endl;
    cout << searchLL(head,30) << endl;
    cout << searchLLPosition(head,140) << endl;
    cout << searchLLPosition(head,30) << endl;

    // Deletion
    // deleteFromLL(head,1);
    // printLL(head);
    // deleteFromLL(head,3);
    // printLL(head);
    deleteFromLLTarget(head,1000);
    printLL(head);
    deleteFromLLTarget(head,50);
    printLL(head);


    return 0;
}
