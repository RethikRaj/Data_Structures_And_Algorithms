#include <iostream>
using namespace std;

int removeElement(int nums[],int size, int val) {
    int index = 0;
    for(int i=0;i<size;i++){
        if(nums[i] != val){
            nums[index] = nums[i];
            index++;
        }
    }
    return index;
}

void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {10,5,1,12,10,12,1};
    int n = 7;
    
}