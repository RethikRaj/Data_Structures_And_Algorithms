#include <iostream>
#include <vector>

using namespace std;

// heapify the element present at this index
void heapify(int *arr,int n,int index){
    int left = 2*index;
    int right = 2*index+1;
    // to find largestIndex
    int largestIndex = index;

    if(left < n && arr[left] > arr[largestIndex]){
        largestIndex = left;
    }

    if(right < n && arr[right] > arr[largestIndex]){
        largestIndex = right;
    }

    // if index is not equal to largestIndex, then swap and recursion
    if(index != largestIndex){
        swap(arr[index],arr[largestIndex]);
        heapify(arr,n,largestIndex);
    }
}

void buildHeap(int *arr,int n){
    for(int i=n/2;i>=1;i--){
        heapify(arr,n,i);
    }
}

void heapSort(int *arr,int n){
    while(n-1 >= 1){
        // swap first and last
        swap(arr[1],arr[n-1]);
        // delete last
        n--;
        // heapify
        heapify(arr,n,1);
    }

}

void printHeap(int *arr,int n){
    for(int i=1;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    // INT_MIN is kept because all are based on 1-indexing
    int arr[] = {INT_MIN,50,10,20,40,55,60,45,30,47};
    int n = 10;
    // build heap
    buildHeap(arr,n);
    printHeap(arr,n);

    // heapsort
    heapSort(arr,n);
    printHeap(arr,n);

    return 0;
}