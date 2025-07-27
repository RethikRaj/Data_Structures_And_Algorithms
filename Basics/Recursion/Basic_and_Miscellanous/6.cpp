#include<iostream>
using namespace std;


void digitsPrint(int num){
    if(num == 0){
        return;
    }
    // Remaining recursion does
    digitsPrint(num/10);
    // 1 case me solve
    cout << num%10 << " ";
}


int main(){
    digitsPrint(3782398);
    return 0;
}
