#include <iostream>
using namespace std;

int main(){
    int a = 10;
    int b = 20;

    cout << (a^b) << endl;

    int c = 10;

    cout << (a^c) << endl;


    char ch1 = 'A';
    char ch2 = 'z';
    char ch3 = 'A';

    char ch4 = ch1^ch2; // implicit type casting

    cout << (ch1^ch2) << endl; // 59
    cout << (ch1^ch3) << endl; // 0
    cout << ch4 << endl; // 59 => ;  (ascii)

    // Uses : 
    // 0. Whenever we need to eliminate duplicates
    // 1. find unique element
}