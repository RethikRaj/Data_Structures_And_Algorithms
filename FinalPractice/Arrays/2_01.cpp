// check if array is sorted


#include <bits/stdc++.h>
using namespace std;

bool isSorted(vector<int>& arr) {
    int n = arr.size();
    if(n == 1){
        return true;
    }
    
    for(int i=1;i<n;i++){
        if(arr[i-1] > arr[i]){
            return false;
        }
    }
    return true;
}