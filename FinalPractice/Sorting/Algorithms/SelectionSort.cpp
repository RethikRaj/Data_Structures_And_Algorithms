#include <bits/stdc++.h>
using namespace std;

int findMinimumIndex(vector<int> &arr, int i){
    int n = arr.size();
    int minEleIndex = i;

    for(int j = i; j < n;j++){
        if(arr[j] < arr[minEleIndex]){
            minEleIndex = j;
        }
    }

    return minEleIndex;
}

void selectionSort(vector<int> &arr){
    int n = arr.size();

    for(int i = 0; i < n-1; i++){
        // Find minimum Index in [i, n-1]
        int minElementIndex = findMinimumIndex(arr, i);
        if(minElementIndex != i){
            swap(arr[i], arr[minElementIndex]);
        }
    }
}

int main(){
    vector<int> arr = {25, 10, 15, 37, 45};

    selectionSort(arr);

    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
}
