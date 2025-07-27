#include <iostream>
#include <vector>
using namespace std;


// Method 1 : Two Pointer Method
void moveZeroesToFront(vector<int>& arr){
    int n = arr.size();
    int nonZeroPos = n-1; // pointer to next nonZeroPos
    for(int index=n-1;index>=0;index--){ // index
        if(arr[index] != 0){
            arr[nonZeroPos] = arr[index];
            nonZeroPos--;
        }
    }
    
    // Place zeroes
    for(int i=0;i<=nonZeroPos;i++){
        arr[i] = 0;
    }
}

// Method 2
void moveZeroesToFrontTwoPointer(vector<int>& arr){
    int n = arr.size();
    int j;
    // Find the last zero and place j.
    for(int i=n-1;i>=0;i--){
        if(arr[i] == 0){
            j = i;
            break;
        }
    }
    
    int i = j-1;
    while(i>=0){
        if(arr[i] != 0){
            swap(arr[i],arr[j]);
            j--;
        }
        i--;
    }
}