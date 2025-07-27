#include <iostream>

using namespace std;

class StackNode{
    public:
        int data;
        StackNode* next;

        StackNode(int data){
            this->data = data;
            this->next = NULL;
        }
};

class MyStack{
    private:
        StackNode *top;

    public:
        void push(int x) {
            // insertAtHead
            StackNode* newNode = new StackNode(x);
            if(top == NULL){
                top = newNode;
            }else{
                newNode->next = top;
                top = newNode;
            }
        }

        int pop() {
            // delete at head
            if(top == NULL){
                return -1;
            }else if(top->next == NULL){
                int x = top->data;
                StackNode* temp = top;
                top = NULL;
                delete temp;
                return x;
            }else{
                int x = top->data;
                StackNode* temp = top;
                top = top->next;
                delete temp;
                return x;
            }
        }

        MyStack() { top = NULL; }
};