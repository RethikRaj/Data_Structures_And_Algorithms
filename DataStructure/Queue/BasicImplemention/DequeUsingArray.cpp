#include<iostream>

using namespace std;

class Deque{
    private:
        int* arr;
        int size;
        int front;
        int rear;

    public:
        Deque(int capacity){
            arr = new int[capacity];
            size = capacity;
            front = -1;
            rear = -1;
        }

        void pushFront(int val){
            if(front == 0){
                // No space to insert at front
                cout << "Overflow" << endl;
            }else if(front == -1 && rear == -1){
                // Queue is empty => Inserting first element
                front++;rear++;
                arr[front] = val;
            }else{
                // Normal flow
                front--;
                arr[front] = val;
            }
        }

        void pushBack(int val){
            if(rear == size-1){
                cout << "Overflow" << endl;
            }else if(front == -1 && rear == -1){
                rear++;front++;
                arr[rear] = val;
            }else{
                rear++;
                arr[rear] = val;
            }
        }

        void popFront(){
            if(front == -1 && rear == -1){
                // queue is empty
                cout << "Underflow" << endl;
            }else if(front == rear){
                // single element in queue
                arr[front] = -1; //not compulsory
                front = rear = -1;
            }else{
                arr[front] = -1; //not compulsory
                front++;
            }
        }

        void popBack(){
            if(front == -1 && rear == -1){
                // queue is empty
                cout << "Underflow" << endl;
            }else if(front == rear){
                // single element
                arr[rear] = -1;
                rear = front = -1;
            }else{
                // Normal
                arr[rear] = -1;
                rear--;
            }
        }
};