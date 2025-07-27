#include <iostream>
using namespace std;

// Best:
void rightShiftByOne(int arr[],int size){
    // step1 : Store
    int temp = arr[size-1];

    // Step 2 => shift -> arr[i] = arr[i-1]
    for(int i=size-1;i>=1;i--){
        arr[i] = arr[i-1];
    }
    // Copy temp to 0th index
    arr[0] = temp;
}

// other:
void rightShiftByOne2(int arr[],int size){
    int temp1 = arr[size-1];
    int temp2;
    for(int i=0;i<size-1;i++){
        temp2 = arr[i];
        arr[i] = temp1;
        temp1 = temp2;
    }
    arr[size-1] = temp1;
}


void leftShiftByOne(int arr[],int size){
    int temp = arr[0];
    for(int i=0;i < size-1 ;i++){
        arr[i] = arr[i+1];
    }
    arr[size-1] = temp;
}

void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {10,20,30,40,50,60,70};
    int n = 7;
    //rightShiftByOne(arr,n);
    rightShiftByOne2(arr,n);
    printArray(arr,n);

    return 0;
}