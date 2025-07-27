#include <iostream>
using namespace std;

int main(){
    // Primitives
    int num = 5;
    cout << "Address of number : " << &num << endl;
    cout << "size of number : " << sizeof(num) << endl;

    // Arrays
    int arr[5] = {2,3,4,5,6};
    // Below all three gives same adress that is starting address of array
    cout << "Adress of arr : " << arr << endl;
    cout << "Adress of arr : " << &arr << endl;
    cout << "Adress of arr : " << &arr[0] << endl;

    cout << "Size of arr : " << sizeof(arr) << endl;


    // sizeof operator => evaluates at compile time
    int i = 20;
    cout << sizeof(i=i+10) << endl; // i = i+10 is not evaluated at all.
    cout << "Value of i is : " << i << endl;


    // assignment operator return value 
    int j = (i= i+10);
    cout << " value of j is : " << j << endl;


    return 0;
}
