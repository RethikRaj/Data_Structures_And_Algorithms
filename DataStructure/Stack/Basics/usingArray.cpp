#include <iostream>

using namespace std;

class Stack{
    public:
        int* arr;
        int size;
        int top;

        Stack(int capacity){
            arr = new int[capacity];
            size = capacity;
            top = -1;
        }

        void push(int val){
            if(top == size-1){
                // stack is already full -> if insert leads to stack overflow
                cout << "Stack Overflow" << endl;
            }else{
                top++;
                arr[top] = val;
            } 
        }

        void pop(){
            if(top == -1){
                // stack is empty -> No elements in stack
                cout << "Stack underflow" << endl;
            }else{
                arr[top] = -1; // not mandatory
                top--;
            }
        }

        int getSize(){
            return top+1;
        }

        bool isEmpty(){
            return top == -1;
        }

        int getTop(){
            if(top == -1){
                cout << "There is no element at the top since stack is empty" << endl;
                return INT_MIN;
            }
            return arr[top];
        }
};