#include <bits/stdc++.h>
using namespace std;

void heapify(int *input,int size, int index){
    int leftIndex = 2*index + 1;
    int rightIndex = 2*index + 2;

    int largestIndex = index;

    if(leftIndex < size && input[leftIndex] > input[largestIndex]){
        largestIndex = leftIndex;
    }

    if(rightIndex < size && input[rightIndex] > input[largestIndex]){
        largestIndex = rightIndex;
    }

    if(largestIndex != index){
        swap(input[largestIndex], input[index]);
        heapify(input, size, largestIndex);
    }
}

// BuildHeap(in-place)
void buildHeap(int* input, int size){
    for(int i = (size/2) - 1; i >=0 ;i--){
        heapify(input, size, i);
    }
}

int main() {
    int arr[] = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Original array: ";
    for(int i=0; i<n; i++) cout << arr[i] << " ";
    cout << "\n";

    buildHeap(arr, n);

    cout << "Array after buildHeap (Max-Heap): ";
    for(int i=0; i<n; i++) cout << arr[i] << " ";
    cout << "\n";

    return 0;
}