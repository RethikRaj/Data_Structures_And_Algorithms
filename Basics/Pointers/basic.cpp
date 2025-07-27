#include<iostream>

using namespace std;

int main(){
    char arr[] = "Rethik";
    char* ptr = arr;
    char* q = &arr[0];
    cout << "arr : " << arr << endl;
    cout << "ptr : " << ptr << endl;
    cout << "q : " << q << endl;
    cout << "ptr+2 : " << ptr+2 << endl;
    cout << "q+3 : " << q+3 << endl;
    cout << "&arr : " << &arr << endl;
    cout << "&ptr : " << &ptr << endl;
    cout << "&q : " << &q << endl;
    cout << "&arr[2] : " << &arr[2] << endl;
    cout << "*arr : " << *arr << endl;
    cout << "*ptr : " << *ptr << endl;
    cout << "*q : " << *q << endl;
    cout << "*(ptr+3) : " << *(ptr+3) << endl;


    int b = 5;
    //cout << *b << endl; => error


    // Size
    // int a = 5;
    // int* ptr = &a;
    // cout << "SIZE OF PTR IS : " << sizeof(ptr) << endl;
    // return 0;
}