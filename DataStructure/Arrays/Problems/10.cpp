#include <iostream>
using namespace std;

// non decreasing order
int isSorted(int arr[],int size){
    int i=0,j=1;
    while(i<size && j<size){
        if(arr[i] > arr[j]){
            return 0;
        }else{
            i++;
            j++;
        }
    }
    return 1;
}

bool isSorted2(int arr[], int n) {
  for (int i = 1; i < n; i++) {
    if (arr[i] < arr[i - 1])
      return false;
  }

  return true;
}

bool isSorted3(int arr[], int n){
    int prev = arr[0];
        
    for(int i=1;i<n;i++){
        if (prev > arr[i]){
            return false;
        }
        prev = arr[i];
    }
    return true;
}