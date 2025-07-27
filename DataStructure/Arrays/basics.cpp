#include <iostream>
using namespace std;

int main(){
    // static array creation 
    int arr[1000]; // initialised with garbage values
    // base address or starting address
    cout << arr << endl;
    cout << &(arr[0]) << endl;


    // initialisation
    int brr[] = {1,2,3,4,5};
    int crr[5] = {1,2,3,4,5};
    int drr[5] = {1,2}; // remaining elements is taken as zero;
    // int err[5] = {1,2,3,4,5,6,7} // error


    // fill array with elements => fill(starting_address,ending_adress to which you want to fill,value)
    int grr[5];
    fill(arr,arr+5,20);
    cout << arr[0] << " " << arr[1] << " " << arr[2] << " " << arr[3] << " " << arr[4] << endl;
    fill(arr+2,arr+4,10);
    cout << arr[0] << " " << arr[1] << " " << arr[2] << " " << arr[3] << " " << arr[4] << endl;

    // dynamic array
    int n;
    cin >> n;
    int* frr = new int[n];
    
}