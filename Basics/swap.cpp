#include <iostream>
using namespace std;

void swapTemp(int* firstNumber,int* secondNumber){
    int temp = *firstNumber;
    *firstNumber = *secondNumber;
    *secondNumber = temp;
}

void swapXor(int* firstNumber,int* secondNumber){
    // int temp = *firstNumber ^ *secondNumber;
    // *firstNumber = temp ^ *firstNumber;
    // *secondNumber = temp ^ *secondNumber;

    *firstNumber = *firstNumber ^ *secondNumber;
    *secondNumber = *firstNumber ^ *secondNumber;
    *firstNumber = *firstNumber ^ *secondNumber;    
}

void swapOneStep(int* firstNumber,int* secondNumber){
    *secondNumber = (*firstNumber+*secondNumber) - (*firstNumber = *secondNumber); // b = (a+b) - (a=b)
}

int main(){
    int a = 10;
    int b = 5;
    cout << "Value  of a and b before swap " << a << " " << b << endl;
    //swap(a,b); // inbuilt
    //swapTemp(&a,&b);
    //swapXor(&a,&b);
    swapOneStep(&a,&b);
    cout << "Value  of a and b after swap " << a << " " << b << endl;


    return 0;
}