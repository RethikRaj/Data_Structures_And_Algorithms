#include<iostream>
using namespace std;

int main(){
    // int -> Stack memory
    int a = 5;
    cout << a << endl;


    // int -> Heap memory
    int* p = new int;
    *p = 10;
    cout << "Address of heap : " << p << endl;
    cout<< *p << endl;
    // deallocate memory
    delete p;

    // can use p afterwards because it is in stack memory
    cout << p << endl; // still points to the same address;
    cout << *p << endl; // garbage.
    
    p = &a;
    cout << *p << endl;



    return 0;
}