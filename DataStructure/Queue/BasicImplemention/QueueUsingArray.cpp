#include<iostream>

using namespace std;

class Queue{
    private:
        int *arr;
        int size;
        int front; // deletion
        int rear; // insertion 
    
    public:
        Queue(int capacity){
            arr = new int[capacity];
            size = capacity;
            front = -1;
            rear = -1;
        }

        void push(int val){
            if(rear == size-1){
                // Queue is full
                cout << "Overflow" << endl;
            }else if(front == -1 && rear == -1){
                // inserting first element 
                front = rear = 0;
                arr[rear] = val;
            }else{
                rear++;
                arr[rear] = val;
            }
        }

        void pop(){
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

        int getFront(){
            if(front == -1){
                cout << "Queue is empty";
                return -1;
            }else{
                return arr[front];
            }
        }

        int getRear(){
            if(rear == -1){
                cout << "Queue is empty";
                return -1;
            }else{
                return arr[rear];
            }
        }

        int getSize(){
            //  returns the number of elements inside a queue
            if(front == -1 && rear == -1){
                return 0;
            }else{
                return rear-front+1;
            }
            
        }

        bool isEmpty(){
            return (front == -1 && rear == -1);
        }

};

int main(){
    Queue q(5);

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(20);

    return 0;
}