#include <iostream>

using namespace std;

class Node{
    public:
        Node* prev;
        int data;
        Node* next;

        Node(int data){
            this->prev = NULL;
            this->data = data;
            this->next = NULL;
        }
};

int getLength(Node* head){
    Node* ptr = head;
    int length = 0;
    while(ptr != NULL){
        length++;
        ptr = ptr->next;
    }
    return length;
}

void insertAtHead(int data,Node* &head,Node* &tail){
    if(head == NULL && tail == NULL){
        // LL is empty
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }else{
        // LL is not empty
        Node* newNode = new Node(data);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void insertAtTail(int data,Node* &head,Node* &tail){
    if(head == NULL && tail == NULL){
        // LL is empty
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        // LL is not empty
        Node* newNode = new Node(data);
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

void insertAtPosition(int data,int position,Node* &head,Node* &tail){
    int length = getLength(head);
    if(position == 1){
        insertAtHead(data,head,tail);
        return;
    }
    else if(position == length+1){
        insertAtTail(data,head,tail);
        return;
    }
    else{
        Node* ptr = head;
        for(int i=0;i<position-2;i++){
            ptr = ptr->next;
        }
        // Method 1 :
        // Node* newNode = new Node(data);
        // newNode->next = ptr->next;
        // newNode->prev = ptr;
        // ptr->next->prev = newNode;
        // ptr->next = newNode;

        // Method 2 :

        Node* newNode = new Node(data);
        Node* forward = ptr->next;
        
        newNode->prev = ptr;
        ptr->next = newNode;
        forward->prev = newNode;
        newNode->next = forward;
    }
}

void print(Node* head){
    Node* ptr = head;
    while(ptr != NULL){
        cout << ptr->data << "<->";
        ptr = ptr->next;
    }
    cout << "NULL" << endl;
}

void printReverse(Node* tail){
    Node* ptr = tail;
    while(ptr != NULL){
        cout << ptr->data << "<->";
        ptr = ptr->prev;
    }
    cout << "NULL" << endl;
}

bool searchLL(Node* head,int target){
    Node* ptr = head;
    while(ptr != NULL){
        if(ptr->data == target){
            return true;
        }
        ptr = ptr->next;    
    }
    return false;
}

void deleteAtPosition(int position,Node* &head){
    int length = getLength(head);
    
    if(head == NULL){
        // LL is empty
        cout << "nothing to delete " << endl;
    }
    else if(head->next == NULL){
        // single node
        Node* temp= head;
        head = NULL;
        delete temp;
    }
    else if(position == 1){
         // delete head node
        Node* temp = head;
        head = temp->next;
        temp->next = NULL;
        head->prev = NULL; // just because of this step it is needed for separate handling of single node otherwsie null pointer exception
        delete temp;
    }
    else if(position == length){
         // delete last node
        Node* backward = head;
        for(int i=0;i<position-2;i++){
            backward = backward->next;
        }
        Node* curr = backward->next; // node to be deleted
        backward->next = NULL;
        curr->prev = NULL;
        delete curr;
    }
    else{
        // others
        Node* backward = head;
        for(int i=0;i<position-2;i++){
            backward = backward->next;
        }
        Node* curr = backward->next; // node to be deleted
        Node* forward = curr->next;
        backward->next = forward;
        forward->prev = backward;
        curr->next = NULL;
        curr->prev = NULL;
        delete curr;
    }
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(10,head,tail);
    print(head);
    insertAtHead(20,head,tail);
    print(head);
    insertAtHead(30,head,tail);
    print(head);
    //printReverse(tail);
    insertAtTail(100,head,tail);
    print(head);
    insertAtTail(200,head,tail);
    print(head);
    insertAtTail(300,head,tail);
    print(head);

    insertAtPosition(3000,2,head,tail);
    print(head);

    deleteAtPosition(7,head);
    print(head);


    return 0;
}
