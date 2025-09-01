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

// Method 2 : Two Pointer Approach (IMP)
int removeDuplicates(vector<int>& nums) {
    int uniqueIndex = 0; // denotes the position of previous unique element's index

    // 'i' is used to traverse array
    for(int i=1;i<nums.size();i++){
        if(nums[i] != nums[uniqueIndex]){
            uniqueIndex++;
            nums[uniqueIndex] = nums[i];
        }
    }

    return uniqueIndex + 1;
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