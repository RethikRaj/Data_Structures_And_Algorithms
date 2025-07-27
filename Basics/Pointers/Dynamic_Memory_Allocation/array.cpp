#include<iostream>
using namespace std;

int main(){
    // Array -> stack memory
    int arr[4] = {0};
    cout << arr[0] << arr[1] << arr[2] << arr[3] << endl;

    // Array -> heap memory
    int* brr = new int[4];  // initialized with garbage
    cout << brr[0] << brr[1] << brr[2] << brr[3] << endl; 

    int* crr = new int[4]();// Initailized with zero
    cout << crr[0] << crr[1] << crr[2] << crr[3] << endl; 

    // Deallocate 
    delete[] brr;
    delete[] crr;
    
    return 0;
}