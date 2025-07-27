#include <iostream>
#include <vector>
using namespace std;


// Counting Approach , actuallty it is two pointer approach;
void moveZeroesToEnd(int arr[],int size){
    int nonZeroElements = 0; // it acts as a pointer to next nonZeroPos
    for(int index=0;index<size;index++){ // i is a looping variable
        if(arr[index] != 0){
            arr[nonZeroElements] = arr[index];
            nonZeroElements++;
        }
    }

    // place zeroes
    int i = nonZeroElements;
    while(i < size){
        arr[i] = 0;
        i++;
    }
}

// Two Pointer Approach
void moveZeroesToEndTwoPointer(vector<int>& nums) {
    int j;
    // Find first zero and place j
    for(int i = 0;i<nums.size();i++){
        if(nums[i] == 0){
            j = i;
            break;
        }
    }

    int i = j+1;
    while(i < nums.size()){
        if(nums[i] != 0){
            swap(nums[i],nums[j]);
            j++;
        }
        i++;
    }
}



void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {9,23,0,0,0,1,2,3,5,0};
    int n = 10;
    
}