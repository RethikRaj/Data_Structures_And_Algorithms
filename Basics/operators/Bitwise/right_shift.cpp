#include <iostream>
using namespace std;

int main(){
    int num = 10;

    cout << (num>> 1) << endl; // 10 / 2^1
    cout << (num>> 2) << endl; // 10 / 2^2
    cout << (num>> 3) << endl; // 10 / 2^3
    cout << (num>> 4) << endl; // 10 / 2^4


    // V.V.Important
    int number1 = -100;
    cout << (number1>>1) << endl; // output is -50 but theoretically it gives diff but compiler handles it internally in case signed


    unsigned int number2 = -100;
    cout << (number2>>1) << endl; 
}