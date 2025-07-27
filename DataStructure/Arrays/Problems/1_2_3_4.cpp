#include <iostream>
#include <limits.h>
using namespace std;

void countZeroAndOne(int arr[],int size){
    int zeroCount = 0;
    int oneCount = 0;
    for(int i=0;i<size;i++){
        if(arr[i] == 0){
            zeroCount++;
        }else if(arr[i] == 1){
            oneCount++;
        }
    }
    cout << "ZeroCount: " << zeroCount << endl;
    cout << "oneCOunt: " << oneCount << endl;
}

int findMinInArray(int arr[],int size){
    int minValue = INT_MAX;
    for(int i=0;i<size;i++){
        minValue = min(minValue,arr[i]);
    }
    return minValue;
}

int findMaxInArray(int arr[],int size){
    int maxValue = INT_MIN;
    for(int i=0;i<size;i++){
        maxValue = max(maxValue,arr[i]);
    }
    return maxValue;
}

void reverseAnArray(int arr[],int size){
    int left = 0;
    int right = size-1;
    while(left < right){
        swap(arr[left],arr[right]);
        left++;
        right--;
    }
}

void extremePrint(int arr[],int size){
    int left = 0;
    int right = size-1;
    while(left <= right){
        if(left == right){
            cout << arr[left] << " ";
        }
        else{
            cout << arr[left] << " ";
            cout << arr[right] << " ";
        }
        left++;
        right--;
    }
    cout << endl;
}

void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    

    
}