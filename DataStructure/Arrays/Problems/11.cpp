#include <iostream>
#include <vector>
using namespace std;

// Method 1 : Counting Method 
int removeDuplicatesFromSortedArray(int arr[],int size){
    int uniqueCount = 0;
    for(int i=0;i<size;i++){
        arr[uniqueCount] = arr[i];
        uniqueCount++;
        while(i<size-1 && arr[i] == arr[i+1]){
            i++;
        }
    }
    return uniqueCount;
}

// Method 2 : Two Pointer Approach
int removeDuplicates(vector<int>& arr) {
    int index = 1;
    int uniqueCount = 1; // since 1st element is always unique;
    while(index < arr.size()){
        if(arr[index] != arr[uniqueCount-1]){
            arr[uniqueCount] = arr[index];
            uniqueCount++;
        }
        index++;
    }
    return uniqueCount;

    // Method2 to write same code above
    // int uniquePosition = 0;
    // int index = 1;
    // while(index < arr.size()){
    //     if(arr[index] != arr[uniquePosition]){
    //         uniquePosition++;
    //         arr[uniquePosition] = arr[index];
    //     }
    //     index++;
    // }
    // return uniquePosition + 1;
}

void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {5,5,5,5,5,7,9,9,9,11,11,12};
    int n = 12;

    printArray(arr,n);

    int uniqueCount = removeDuplicatesFromSortedArray(arr,n);

    printArray(arr,uniqueCount);
    
}