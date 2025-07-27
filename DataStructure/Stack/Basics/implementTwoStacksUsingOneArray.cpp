#include <iostream>

using namespace std;

class Stack{
    public:
        int* arr;
        int size;
        int top1;
        int top2;

        Stack(int capacity){
            arr = new int[capacity];
            size = capacity;
            top1 = -1;
            top2 = size;
        }

        void push1(int val){
            if(top2-top1 == 1){
                // no space available
                cout << "Stack Overflow" << endl;
            }else{
                top1++;
                arr[top1] = val;
            }
        }

        void push2(int val){
            if(top2-top1==1){
                // no space available
                cout << "Stack Overflow" << endl;
            }else{
                top2--;
                arr[top2] = val;
            }
        }

        void pop1(){
            if(top1 == -1){
                cout << "Stack 1 Underflow" << endl;
            }else{
                arr[top1] = -1;
                top1--;
            }
        }

        void pop2(){
            if(top2 == size){
                cout << "Stack 2 Underflow" << endl;
            }else{
                arr[top2] = -1;
                top2++;
            }
        }

        int getTop1(){
            if(top1 == -1){
                cout << "Stack1 is empty" << endl;
                return -1;
            }else{
                return arr[top1];
            }
        }

        int getTop2(){
            if(top2 == size){
                cout << "Stack2 is empty" << endl;
                return -1;
            }else{
                return arr[top2];
            }
        }
};

int main(){

    Stack s(5);
    s.pop1();
    s.pop2();

    s.push1(10);
    cout << s.getTop1() << endl;
    s.push1(20);
    cout << s.getTop1() << endl;
    s.push1(30);
    cout << s.getTop1() << endl;
    s.push1(40);
    cout << s.getTop1() << endl;

    s.push2(100);
    cout << s.getTop2() << endl;
    s.push2(200);
    cout << s.getTop2() << endl;
    s.push2(300);
    cout << s.getTop2() << endl;
    s.push2(400);
    cout << s.getTop2() << endl;

    s.pop1();
    cout << s.getTop1() << endl;
    s.pop2();
    cout << s.getTop2() << endl;
    return 0;
}