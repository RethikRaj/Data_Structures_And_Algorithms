#include <bits/stdc++.h>
using namespace std;

class BubbleSort{

    void bubbleSortIterative(vector<int> &arr){
        int n = arr.size();

        // ith iteration === Place (i+1) largest element at its correct position
        for(int i = 0; i < n - 1; i++){
            bool isSwapped = false;
            // Now perform bubble up
            for(int j = 0; j < n-i-1; j++){
                if(arr[j] > arr[j+1]){
                    swap(arr[j], arr[j+1]);
                    isSwapped = true;
                }
            }

            if(!isSwapped){
                // Already sorted
                return;
            }
        }
    }

    // This function denotes => Place kth largest element at its correct position
    void bubbleSortHybridRecursion(vector<int> &arr, int k){
        
    }


};