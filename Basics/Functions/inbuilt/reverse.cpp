#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

void printVector(vector<int>& v){
    for(int i=0;i<v.size();i++){
        cout << v[i] << " " ;
    }
    cout << endl;
}

void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout << arr[i] << " " ;
    }
    cout << endl;
}

int main(){
    
    // Reversing an array
    int arr[] = {1,2,3,4,5};
    int n = 5;
    cout << "Array before reverse : ";
    printArray(arr,5);
    reverse(arr,arr+n);
    cout << "Array after reverse : " ;
    printArray(arr,5);

    // Reversing a vector
    vector<int> v = {10,20,30,40,50};
    cout << "Vector before reverse : ";
    printVector(v);
    reverse(v.begin(),v.end());
    cout << "Vector after reverse : ";
    printVector(v);


    // Reversing a string
    string str = "hello";

    // Print the original string
    cout << "Original string: " << str << endl;

    // Reverse the string
    reverse(str.begin(), str.end());

    // Print the reversed string
    cout << "Reversed string: " << str << endl;


    return 0;
}