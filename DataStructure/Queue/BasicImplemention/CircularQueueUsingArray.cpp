#include<iostream>

using namespace std;

class CircularQueue{
    private:
        int* arr;
        int size;
        int front;
        int rear;

    public:
        CircularQueue(int capacity){
            arr = new int[capacity];
            size = capacity;
            front= -1;
            rear = -1;
        }

        void push(int val){
            // 4 cases : Overflow,first element,circular nature,normal flow
            if((front == 0 && rear == size-1) || (rear == front-1)){
                cout << "Overflow" << endl;
            }else if(front == -1 && rear == -1){
                front++;
                rear++;
                arr[rear] = val;
            }else if(rear == size-1 && front != 0){ // front != 0 is not needed actually
                rear = 0;
                arr[rear] = val;
            }else{
                rear++;
                arr[rear] = val;
            }
        }

        void pop(){
            // 4 cases : Underflow,single element,circular nature,normal flow
            if(front == -1 && rear == -1){
                cout << "Underflow" << endl;
            }else if(front == rear){
                arr[front] = -1;
                front = rear = -1;
            }else if(front == size-1){
                arr[front] = -1;
                front = 0;
            }else{
                arr[front] = -1;
                front++;
            }
        }

        int getFront(){
            if(front == -1){
                cout << "Queue is empty" << endl;
                return -1;
            }else{
                return arr[front];
            }
        }

        int getBack(){
            if(rear == -1){
                cout << "Queue is empty" << endl;
                return -1;
            }else{
                return arr[rear];
            }
        }

        int getSize(){
            
        }

        bool isEmpty(){
            return (front == -1 && rear == -1);
        }
};