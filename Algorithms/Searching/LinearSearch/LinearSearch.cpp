#include <iostream>
using namespace std;

// The below function prints the first index of the target element
bool linearSearch(int arr[],int size,int target){
    for(int i=0;i<size;i++){
        if(arr[i] == target){
            cout << "The index of the target element is : " << i << endl;
            return true;
        }
    }
    return false;
}

// // The below function returns the first index of the target element
bool linearSearchLast(int arr[],int size,int target){
    for(int i=size-1;i>=0;i--){
        if(arr[i] == target){
            cout << "The index of the target element is : " << i << endl;
            return true;
        }
    }
    return false;
}

int main(){
    int arr[] = {2,4,21,34,56,23,89,35,23,90,100,23,34};
    int size = 13;
    int target = 23;
    bool isFound = linearSearch(arr,size,target);
    bool isFound2 = linearSearchLast(arr,size,target);

    return 0;
}