
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Node{
    public:
        int key;
        int value;
        Node* next;
        Node* prev;

        Node(int key, int value){
            this->key = key;
            this->value = value;
            this->next = NULL;
            this->prev = NULL;
        }
};

// Method 1 : Without dummy head and dummy tail
class LRUCache {
public:
    int capacity;
    unordered_map<int,Node*> ump;
    Node* head;
    Node* tail;

    void insertAtHead(Node* ptr){
        if(head == NULL){
            head = ptr;
            tail = ptr;
        }else{
            ptr->next = head;
            head->prev = ptr;
            head = ptr;
        }
    }

    void deleteNode(Node* ptr){
        if(ptr == head && ptr == tail){
            // single node
            head = NULL;
            tail = NULL;
        }
        else if(ptr == head){
            Node* nextNode = head->next;
            nextNode->prev = NULL;
            // isolation
            head->next = NULL;
            // assigning head
            head = nextNode;
        }else if(ptr == tail){
            Node* prevNode = tail->prev;
            prevNode->next = NULL;
            // isolation
            tail->prev = NULL;
            // assigning tail
            tail = prevNode;
        }else{
            Node* prevNode = ptr->prev;
            Node* nextNode = ptr->next;
            prevNode->next = nextNode;
            nextNode->prev = prevNode;
            // isolation
            ptr->prev = NULL;
            ptr->next = NULL;
        }

        
    }

    LRUCache(int capacity) {
        this->capacity = capacity;
        this->head = NULL;
        this->tail = NULL;
    }
    
    int get(int key) {
        if(ump.find(key) != ump.end()){
            Node* ptr = ump[key];
            deleteNode(ptr);
            insertAtHead(ptr);
            return ptr->value;
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(ump.find(key) != ump.end()){
            Node* ptr = ump[key];
            ptr->value = value;
            deleteNode(ptr);
            insertAtHead(ptr);
        }else{
            if(this->capacity == ump.size()){
                Node* lastNode = tail;
                ump.erase(lastNode->key);
                // delelete last node
                deleteNode(lastNode);
            }

            Node* newNode = new Node(key, value);
            ump[key] = newNode;
            insertAtHead(newNode);
        }
    }
};

// Method 2 : With dummy head and dummy tail


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */